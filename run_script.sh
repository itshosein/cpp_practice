#!/bin/bash
clear
# if [ -f ./build/src/output.exe ]; then {
#     echo "Deleting previous output file..."
#     rm ./build/mingw-debug/src/output.exe
#     if [ $? -eq 0 ]; then {
#         echo "The file deleted successfully."
#     } else {
#         echo "Could not delete the file."
#     } fi
# } fi

cmake -S . -B build/mingw-debug --preset=default
echo "******* (cmake -S . -B build/mingw-debug --preset default) done *******"

cmake --build build/mingw-debug
echo "******* (cmake --build build/mingw-debug) done *******"

if [ $? -eq 0 ]; then {
    # clear
    echo "app output{"
    ./build/mingw-debug/src/output.exe  # Adjust if needed
    echo "}"
} else {
    echo "Build failed."
} fi