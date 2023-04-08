cmake_minimum_required(VERSION 3.16)
project(GameEngine LANGUAGES C CXX)

set(GLFW D:/Development/glfw-3.3.8.bin.WIN64/include/GLFW/)
set(GLAD D:/Development/GLAD/GL3/include/)
set(GLADS D:/Development/GLAD/GL3/src/glad.c)
set(LIB D:/Development/glfw-3.3.8.bin.WIN64/lib-mingw-w64/glfw3.dll)
set(SOURCES src/glad.c src/main.cpp )

set(INCLUDE ${PROJECT_SOURCE_DIR}/include/)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/glad.c"
        )


link_libraries(${LIB})
include_directories(${GLFW} ${GLAD} ${INCLUDE})

add_executable(GameEngine ${all_SRCS})
