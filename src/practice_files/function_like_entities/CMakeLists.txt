# Add source files in subdir1
file(GLOB SUBDIR_fle_SOURCES "*.cpp")

add_library(subdir_function_like_entities_library ${SUBDIR_fle_SOURCES})

target_include_directories(subdir_function_like_entities_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(subdir_function_like_entities_library PRIVATE fmt::fmt)

