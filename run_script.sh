#!/bin/bash
clear
build_location=build/mingw-debug
build="false"

while [[ "$#" -gt 0 ]]; do
    case "$1" in
    --build)
        # ${1:-"defaultValue"}
        build="true"
        shift
        ;;
    esac
    shift # Move to the next argument
done

if [[ -f ./$build_location/src/output.exe ]]; then {
    echo "Deleting previous output file..."
    rm ./build/mingw-debug/src/output.exe
    if [ $? -eq 0 ]; then {
        echo "The file deleted successfully."
    }; else {
        echo "Could not delete the file."
    }; fi
}; fi

if [[ "$build" == "true" && -d ./$build_location ]]; then {
    echo "$build"
    echo "Deleting build folder..."
    rm -rf ./$build_location
    if [ $? -eq 0 ]; then {
        echo "build folder deleted successfully."
    }; else {
        echo "Could not delete the build folder."
    }; fi
}; fi

cmake -S . -B $build_location --preset=default
echo "******* (cmake -S . -B $build_location --preset default) done *******"

cmake --build $build_location
echo "******* (cmake --build $build_location) done *******"

if [[ $? -eq 0 ]]; then {
    # clear
    echo "app output{"
    ./$build_location/src/output.exe # Adjust if needed
    echo "}"
}; else {
    echo "Build failed."
}; fi
