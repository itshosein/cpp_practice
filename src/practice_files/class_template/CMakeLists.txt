# Add source files in subdir1
file(GLOB SUBDIR_CLASS_TEMPLATE_SOURCES "*.cpp")

add_library(subdir_class_template_library ${SUBDIR_CLASS_TEMPLATE_SOURCES})

target_include_directories(subdir_class_template_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(subdir_class_template_library PRIVATE fmt::fmt)

