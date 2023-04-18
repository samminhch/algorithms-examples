source_directory="./src"
build_directory="./build"

build()
{
    # add debug flags if it's specified
    local flags=("$@")

    echo "Flags: ${flags[@]}"

    if [ ! -d "$build_directory" ];
    then
        mkdir "$build_directory"
    fi

    for file in "$source_directory"/*;
    do
        echo "Found file: $file"
        file_name="${file##*/}"
        file_name="${file_name%.*}"

        gcc "${source_directory}/$file_name".c "${flags[@]}" -o "${build_directory}/${file_name}".out 
    done
}

clean()
{
    if [ -d "$build_directory" ];
    then
        rm -rf "$build_directory"
        echo "Build clean succeeded"
    fi
}

if [ $# -eq 1 ] && [ $1 == "clean" ];
then
    clean
else
    build "$@"
fi
