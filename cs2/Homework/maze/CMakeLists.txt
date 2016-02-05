
cmake_minimum_required(VERSION 3.3)

# This creates a new target for the make program. After
# including this, you can write:
#
#     make printout
#
# And the build system will assemble a PDF containing the
# formatted text in the files listed above. The PDF will
# be created in the build directory and is named "printout.pdf".
#
# To use this, add the following to this file:
#
#     add_printout(f1.hpp f1.cpp f2.hpp f2.cpp ...)
#
# Where f1 and f2 are the files that you want to include
# in the printout. Note that header files should always
# precede their source files.
#
# DO NOT MODIFY THIS.
macro(add_printout)
  add_custom_target(printout
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMAND a2ps -Afill -o- ${ARGN} | ps2pdf - ${CMAKE_BINARY_DIR}/printout.pdf)
endmacro()


# Configure the project and compiler
project(maze CXX)
set(CMAKE_CXX_FLAGS -std=c++1y)


# Check for and configure curses or ncurses.
find_package(Curses)
if(CURSES_FOUND)
  include_directories(CURSES_INCLUDE_DIR)
endif()


set(lib
  vector.cpp
  list.cpp
  queue.cpp
  table.cpp
  maze.cpp
  visitor.cpp
  generate.cpp
  search.cpp
  bfs.cpp
  dfs.cpp
  generate.cpp
  iostream.cpp)
add_library(core STATIC ${lib})


# Build a maze program that runs on the terminal.
add_executable(maze main.cpp)
target_link_libraries(maze core)


# If supported, build a maze program that runs
# using curses.
if(CURSES_FOUND)
  add_executable(maze-curses curses-main.cpp curses.cpp)
  target_link_libraries(maze-curses core ${CURSES_LIBRARIES})
endif()


# TODO: Make sure that these are the files you want
# to submit.

add_printout(queue.hpp queue.cpp bfs.hpp bfs.cpp dfs.hpp dfs.cpp)
