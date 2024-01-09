find_package(OpenGL)
find_package(GLUT)

set(WORLD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE PATH "World Include dirs")

set(WORLD_INCLUDE_DIRS
        ${WORLD_INCLUDE_DIR}
        ${OpenGL_INCLUDE_DIRS}
        ${GLUT_INCLUDE_DIRS}
)

file(GLOB WORLD_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
file(GLOB WORLD_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

include_directories(${WORLD_INCLUDE_DIRS})

add_library(World STATIC ${WORLD_SOURCES} ${WORLD_HEADERS})
target_link_libraries(World OpenGL::GL OpenGL::GLU ${GLUT_LIBRARIES} )
