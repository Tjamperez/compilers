#!/bin/bash

# Define the starting and ending numbers of the range
start_number=1
end_number=160

echo "Processing archives..."

# Create an array to store the results
results=()

# Loop through each number in the range
for (( number=start_number; number<=end_number; number++ ))
do
    # Format the number to be three digits with leading zeros if necessary
    padded_number=$(printf "%03d" $number)

    # Construct the file path based on the current number
    file_path="./e2_all/E2/asl${padded_number}"

    # Check if the file exists before attempting to process it
    if [ -f "$file_path" ]; then
        # Run etapa2 with the contents of the file
        etapa2_output=$(cat "$file_path" | ./etapa2)

        # Capture the exit status of etapa2
        return_status=$?

        # Determine the output format based on the return status
        if [ $return_status -eq 0 ]; then
            result="$padded_number,0"  # Successful execution
        else
            result="$padded_number,1"  # Execution with error
        fi

        # Append the result to the array
        results+=("$result")
	fi
done

echo "Finished processing archives."

# Write the results to a new CSV file
output_file="./e2_all/e2_CSV_LOG/script_output.csv"

echo "Writing results to $output_file..."

# Output the results array to the CSV file
printf "%s\n" "${results[@]}" > "$output_file"

echo "Results written to $output_file."

# Compare the generated results with e2_esperado.csv
expected_file="./e2_all/e2_CSV_LOG/e2_esperado.csv"

if [ -f "$expected_file" ]; then
    echo "Comparing results with $expected_file..."

    # Read each line from e2_esperado.csv and compare with results
    while IFS=',' read -r archive_name expected_status
    do
        # Check if the archive name is within the processed range
        if [[ "$archive_name" =~ ^asl([0-9]+)$ ]]; then
            padded_number="${BASH_REMATCH[1]}"
            found=false

            # Loop through the results to find a match
            for result in "${results[@]}"
            do
                if [[ "$result" == "$padded_number,$expected_status" ]]; then
                    found=true
                    break
                fi
            done

            # Display discrepancy if the result was not found
            if [ "$found" == false ]; then
                echo "Discrepancy found: $archive_name (Expected: $expected_status)"
            fi
        fi
    done < "$expected_file"
else
    echo "Expected file not found: $expected_file"
fi
