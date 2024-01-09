find_package(OpenGL)
find_package(GLUT)


set(INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${MODELS_INCLUDE_DIR}
        ${WORLD_INCLUDE_DIR}
        ${OpenGL_INCLUDE_DIRS}
        ${GLUT_INCLUDE_DIRS}
)

file(GLOB GAME_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

include_directories(${INCLUDE_DIRS})

add_executable(River_Raid_Reborn ${GAME_SOURCES})
target_link_libraries(River_Raid_Reborn ${OpenGL_LIBRARIES} ${GLUT_LIBRARIES} World Models)
