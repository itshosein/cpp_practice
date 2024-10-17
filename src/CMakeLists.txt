find_package(fmt CONFIG REQUIRED)

function(add_subdirectory_recursive dir)
    file(GLOB children RELATIVE ${dir} ${dir}/*)
    foreach(child ${children})
        if(IS_DIRECTORY ${dir}/${child} AND NOT ${child} STREQUAL "include")
            # Recursively add subdirectories
            add_subdirectory(${dir}/${child})
            add_subdirectory_recursive(${dir}/${child})
        endif()
    endforeach()
endfunction()

add_subdirectory_recursive(${CMAKE_CURRENT_SOURCE_DIR})


# Find all .cpp files in the src directory
file(GLOB SOURCES "*.cpp")


# Add an executable target (the output file name is "output")
add_executable(output ${SOURCES})

# Optional: Add any libraries here if needed
# target_link_libraries(roaster some_library)
target_link_libraries(output PRIVATE fmt::fmt subdir_practices_library subdir_oop_library)
