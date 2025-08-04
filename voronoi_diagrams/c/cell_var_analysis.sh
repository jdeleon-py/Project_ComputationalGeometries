#!/bin/bash

# === CONFIGURATION ===
EXECUTABLE=./test_cell_area   # Path to your C executable
OUTPUT_FILE=cell_data_norm_1024.txt      # File to store the output
RUNS=1101                    # Number of times to run the executable

# === RUN LOOP ===
echo "Running $EXECUTABLE $RUNS times..."
echo "---- Output Start ----" > "$OUTPUT_FILE"

for ((i = 1; i <= RUNS; i++)); do
	seed=$RANDOM
	$EXECUTABLE "$seed" >> "$OUTPUT_FILE"
done
echo "Done. Output saved to $OUTPUT_FILE"
