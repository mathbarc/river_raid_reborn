find_package(OpenGL)
find_package(GLUT)

set(MODELS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE PATH "Models Include dirs")

set(MODELS_INCLUDE_DIRS
        ${MODELS_INCLUDE_DIR}
        ${WORLD_INCLUDE_DIR}
        ${OpenGL_INCLUDE_DIRS}
        ${GLUT_INCLUDE_DIRS}
)

file(GLOB MODELS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
file(GLOB MODELS_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

include_directories(${MODELS_INCLUDE_DIRS})

add_library(Models STATIC ${MODELS_SOURCES} ${MODELS_HEADERS})
target_link_libraries(Models OpenGL::GL OpenGL::GLU ${GLUT_LIBRARIES} World)




