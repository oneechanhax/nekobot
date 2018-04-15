
#
#
# Welcome to the cmake lists file.
#
#

cmake_minimum_required (VERSION 2.6)
project (betterthangravity CXX)

# Add cathooks source files except the modules, we add those selectivly
file(GLOB_RECURSE SOURCE_FILES "src/*.c*")

# Flags we use for every build type
set(CMAKE_CXX_STANDARD 17)

# Default compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -ggdb -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-s -mtune=generic -O3")

add_subdirectory(sleepy-discord)

#include_directories(${INCLUDE_DIRS})
add_executable(betterthangravity ${SOURCE_FILES})

target_include_directories(betterthangravity PUBLIC "include/sleepy_discord/" "include/sleepy_discord/IncludeNonexistent/")

target_link_libraries(betterthangravity c stdc++ sleepy-discord)
