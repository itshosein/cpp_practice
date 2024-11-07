# Add source files in subdir1
file(GLOB SUBDIR_EXCEPTION_HANDLING_SOURCES "*.cpp")

add_library(subdir_exception_handling_library ${SUBDIR_EXCEPTION_HANDLING_SOURCES})

target_include_directories(subdir_exception_handling_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(subdir_exception_handling_library PRIVATE fmt::fmt)

