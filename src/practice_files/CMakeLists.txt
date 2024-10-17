# Add source files in subdir1
file(GLOB SUBDIRPRACTICES_SOURCES "*.cpp")

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


add_library(subdir_practices_library ${SUBDIRPRACTICES_SOURCES})

# Add the include directory for practice_files (public so it's visible to upper-level targets)
target_include_directories(subdir_practices_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(subdir_practices_library PRIVATE fmt::fmt)





