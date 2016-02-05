# declare the project
# CXX means C++.
project(vector CXX)


# Require make version 2.8 minimum
cmake_minimum_required(VERSION 2.8)


# Enable compilation with c++11
# Turn on all warnings and make them errors.
# Also enable a set of sanitizers to handle various
# kinds of undefined behaviors.
#
# TODO: Can we check for compiler support?
#
# NOTE: If these cause errors when compiling, just
# comment out the next line.
#set(SAN_FLAGS "-fsanitize=address -fsanitize=undefined -fsanitize=leak")
set(CMAKE_CXX_FLAGS "-Wall -std=c++14 ${SAN_FLAGS}")


# Declares the executable to be built from source files
#
# TODO: Add your files.
add_executable(hw3 main.cpp vector.cpp test.cpp)

set(files vector.hpp)
# This creates a new target for the make program. After
# including this, you can write:
#
#   make printout
#
# And the build system will assemble a PDF containing the
# formatted text in the files listed above. The PDF will
# be created in the build directory and is named "printout.pdf".
# DO NOT MODIFY THIS COMMAND
add_custom_target(printout
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMAND a2ps -Afill -o- ${files} | ps2pdf - ${CMAKE_BINARY_DIR}/printout.pdf)



