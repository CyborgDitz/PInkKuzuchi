cmake_minimum_required(VERSION 3.15)
project(hello_raylib_with_cmake C)

set(CMAKE_C_STANDARD 23)

include(FetchContent)

function(include_dependency libName gitURL gitTag)
    FetchContent_Declare(
            ${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG ${gitTag}
            GIT_SHALLOW TRUE
            GIT_PROGRESS TRUE
    )
    FetchContent_MakeAvailable(${libName})
endfunction()

# Declare raylib as a dependency
set(LIB1 raylib)
find_package(raylib QUIET)

if (NOT raylib_FOUND)
    message(STATUS "Fetching raylib from GitHub...")
    include_dependency(raylib https://github.com/raysan5/raylib.git 4.5.0)
else()
    message(STATUS "Using locally installed raylib")
endif()

# Create executable with sources
add_executable(PinkKuzuchi src/main.c
        main.c
        main.h)

# Link raylib to your target
target_link_libraries(PinkKuzuchi PRIVATE raylib)

# Explicitly add the raylib include directory if raylib is fetched
if (NOT raylib_FOUND)
    # This will set the include directory for raylib if it's fetched into the build folder
    target_include_directories(PinkKuzuchi PRIVATE ${CMAKE_BINARY_DIR}/raylib/src)
else()
    # If raylib is installed locally, use the locally installed include directory
    target_include_directories(PinkKuzuchi PRIVATE ${raylib_INCLUDE_DIRS})
endif()

