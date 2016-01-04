# Top level cmake file
cmake_minimum_required(VERSION 2.6)
project(SDLTutorials)

# use our modified FindSDL2* modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SDLTutorials_SOURCE_DIR}/cmake")
MESSAGE(STATUS "CMAKE MODULE PATH: " ${CMAKE_MODULE_PATH})

# output directory for binaries
set(BIN_DIR ${SDLTutorials_SOURCE_DIR}/bin)


# bump warning levels for clang, gcc, msvc.
# set debug/optimization flags
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()


# look up SDL2 and add to our include path
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(include)

# build lesssons
add_subdirectory(Lesson0)
add_subdirectory(Lesson1)
