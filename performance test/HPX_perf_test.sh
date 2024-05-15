#!/bin/bash

LOCALITIES=( 4 8 20 40 ) 
# 指定包含可执行文件的目录
executables_directory="exec1106_forall"

# Loop over the specified core counts
for loc in "${LOCALITIES[@]}"; do
echo "Running test with $loc cores..."
thread=$((40/$loc))
echo "Running test with $thread threads..."
    for executable in "$executables_directory"/*; do
        if [ -x "$executable" ]; then
            output_file="$(basename "$executable")_$loc-1113_forall_threads=$thread.log"
            touch "$output_file"

            echo "Running : mpirun -n $loc "$executable" --backend-args="--hpx:threads=$thread", waiting"
            mpirun -n $loc "$executable" --backend-args="--hpx:threads=$thread" >> "$output_file" 2>&1
            #mpirun -n 1 "$executable" --backend-args="--hpx:ini=hpx.max_background_threads!=i"  >> "$output_file" 2>&1
            echo "Completed running $executable"
        fi
    done
done