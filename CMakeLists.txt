cmake_minimum_required(VERSION 3.26)
project(rubiks-cube)

set(CMAKE_CXX_STANDARD 23)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/baz606/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

set(RAYLIB_GUI_VERSION 4.0)
find_package(raygui ${RAYLIB_GUI_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raygui_FOUND) # If there's none, fetch raygui
    include(FetchContent)
    FetchContent_Declare(
            raygui
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/baz606/raygui/archive/refs/tags/${RAYLIB_GUI_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raygui)
    if (NOT raygui_POPULATED) # Have we downloaded raygui yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raygui)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        # Copy over raygui.h over to raylib_SOURCE_DIR
        configure_file(
                ${raygui_SOURCE_DIR}/src/raygui.h ${raylib_SOURCE_DIR}/src
        )
    endif()
endif()


# include header files directories
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/actors)
include_directories(${CMAKE_SOURCE_DIR}/src/actors/base)
include_directories(${CMAKE_SOURCE_DIR}/src/components)
include_directories(${CMAKE_SOURCE_DIR}/src/components/base)

# Our Project

add_executable(${PROJECT_NAME} src/main.cpp
        src/Game.h
        src/Game.cpp
        src/actors/base/Actor.cpp
        src/actors/base/Actor.h
        src/components/base/Component.cpp
        src/components/base/Component.h
        src/components/DrawComponent.cpp
        src/components/DrawComponent.h)
#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

#add_executable(raylib_test main.cpp)
