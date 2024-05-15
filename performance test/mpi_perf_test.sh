#!/bin/bash

localities=(2 4 8 16 24 32 40)

# 指定包含可执行文件的目录
executables_directory="newexec"

for locality in "${localities[@]}"; do
    for executable in "$executables_directory"/*; do
        if [ -x "$executable" ]; then
            output_file="$(basename "$executable")_output_localities= ${locality}.log"
            touch "$output_file"

            echo "Running $executable with $locality localities"
            echo "Running : mpirun -n "$locality" "$executable" , waiting"
            mpirun -n "$locality" "$executable" >> "$output_file" 2>&1
            echo "Completed running $executable"
        fi
    done
done