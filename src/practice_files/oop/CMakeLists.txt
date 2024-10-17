# Add source files in subdir1
file(GLOB SUBDIR_OOP_SOURCES "*.cpp")

add_library(subdir_oop_library ${SUBDIR_OOP_SOURCES})

target_include_directories(subdir_oop_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(subdir_oop_library PRIVATE fmt::fmt)

