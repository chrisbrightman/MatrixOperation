cmake_minimum_required(VERSION 3.10)
project(MatrixOperations)

set(CMAKE_CXX_STANDARD 14)

IF(CXX="g++")
    add_compile_options("-ggdb")

endif()

file(GLOB libmatrix_src "src/libmatrix/*.cpp" "src/libmatrix/*.h")
file(GLOB libtp_src "src/libtp/*.cpp" "src/libtp/libtp/*.h")
file(GLOB libmatrix_test "test/libmatrix_test/*.cpp")
file(GLOB libtp_test "test/libtp_test/*.cpp")

add_executable(MatrixOperations "src/main.cpp")

add_library(libmx SHARED ${libmatrix_src})

add_library(libtp SHARED ${libtp_src})

target_link_libraries(MatrixOperations libmx libtp)

##################
## adding gtest ##
##################

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

add_executable(matrix_tests ${libmatrix_test})
target_link_libraries(matrix_tests gtest libmx libtp)
add_executable(tp_test ${libtp_test})
target_link_libraries(tp_test gtest libtp)
