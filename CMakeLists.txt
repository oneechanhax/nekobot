
cmake_minimum_required (VERSION 3.6)
project (nekobot)

# Not reccomended but I do it anyway
file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.c*")

set(CCOMMON_FLAGS "-mtune=generic -O3")

set(CMAKE_CXX_FLAGS_DEBUG "${CCOMMON_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g3 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CCOMMON_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")

add_subdirectory(sleepy-discord)
set_target_properties(sleepy-discord PROPERTIES LINKER_LANGUAGE CXX)
add_executable(nekobot ${SOURCE_FILES})

target_link_libraries(nekobot)
