
#################
## thread pool ##
#################
configure_file(CMakeList.txt.in threadpool/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G ${CMAKE_GENERATOR} .
    RESULT_VARIABLE tpresult
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/threadpool )
if (tpresult) 
    message(FATAL_ERROR "There was an issue generating threadPool: ${tpresult}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE tpresult
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/threadpool )
if(tpresult)
    message(FATAL_ERROR "Building threadPool failed: ${tpresult}")
endif()

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/threadpool-src
    ${CMAKE_CURRENT_BINARY_DIR}/threadpool-build
    EXCLUDE_FROM_ALL)

#`add_library(tp INTERFACE IMPORTED)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/threadpool-src/threadPool)

add_library(libmx STATIC cpuMatrix.cpp cpuMatrix.h matrix.cpp matrix.h )

add_executable(MatrixOperations main.cpp windowsMacro.h )

target_link_libraries(MatrixOperations libmx tp)
