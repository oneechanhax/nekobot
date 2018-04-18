
#
#
# Welcome to the cmake lists file.
#
#

cmake_minimum_required(VERSION 2.6)
project(betterthangravity)

# Add cathooks source files except the modules, we add those selectivly
file(GLOB_RECURSE SOURCE_FILES "src/*.c*")

# Flags we use for every build type
set(CMAKE_CXX_STANDARD 17)

# Default compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -ggdb -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-s -mtune=generic -O3")

# Dependancies
find_package(OpenSSL REQUIRED)
#set(USE_SYSTEM_CURL ON)
add_subdirectory(cpr) # why both? I dont really know...
add_subdirectory(sleepy-discord)

add_executable(betterthangravity ${SOURCE_FILES})

message(STATUS ${CPR_INCLUDE_DIRS})
target_include_directories(betterthangravity PUBLIC "sleepy-discord/include/" "${CPR_INCLUDE_DIRS}" "websocketpp/" "sleepy-discord/include/sleepy_discord/IncludeNonexistent/")
target_link_libraries(betterthangravity c stdc++ sleepy-discord ${OPENSSL_SSL_LIBRARY} ${CPR_LIBRARIES})
