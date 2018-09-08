project(common C CXX)

add_subdirectory(lexical_analyzer)

add_library(${PROJECT_NAME} OBJECT $<TARGET_OBJECTS:lexical_analizer>)
