cmake_minimum_required(VERSION 3.5)


#########################################################
# PROJECT BUILD
#########################################################
project(labyrinth_opengl_cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)


#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if (NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif (NOT GLUT_FOUND)


#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if (NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif (NOT OPENGL_FOUND)


#########################################################
# Include Files
#########################################################
set(SOURCE_FILES src/Main.cpp src/object/Object.cpp src/object/Object.h src/object/Wall.cpp src/object/Wall.h src/object/Floor.cpp src/object/Floor.h src/object/Texture.cpp src/object/Texture.h src/window/Window.cpp src/window/Window.h src/scene/Labyrinth.cpp src/scene/Labyrinth.h src/scene/Home.cpp src/scene/Home.h src/scene/Scene.cpp src/scene/Scene.h)
add_executable(labyrinth_opengl_cpp ${SOURCE_FILES})


########################################################
# Linking & stuff
#########################################################
target_link_libraries(labyrinth_opengl_cpp ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
