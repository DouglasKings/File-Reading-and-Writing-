#include <stdio.h> // Include the standard I/O library
#include <unistd.h> // Include the unistd.h for access function and F_OK constant

// Function prototype declaration
void readFileAndWriteToFile(const char* inputFile, const char* outputFile);

int main() {
    // Define the paths to the input and output files
    const char* inputFile = "input.txt";
    const char* outputFile = "output.txt";

    // Check if the input file exists before proceeding
    if (access(inputFile, F_OK) == -1) {
        perror("Error checking input file existence");
        return 1; // Return an error code to indicate failure
    }

    // Call the function to perform reading and writing
    readFileAndWriteToFile(inputFile, outputFile);

    printf("Operation completed successfully.\n");

    return 0;
}

// Function definition
void readFileAndWriteToFile(const char* inputFile, const char* outputFile) {
    FILE *inFile, *outFile; // Declare pointers for input and output files

    // Open the input file
    inFile = fopen(inputFile, "r");
    if (inFile == NULL) {
        perror("Error opening input file"); // Print error message if file couldn't be opened
        return; // Exit the function early
    }

    // Open the output file
    outFile = fopen(outputFile, "w");
    if (outFile == NULL) {
        perror("Error opening output file"); // Print error message if file couldn't be opened
        fclose(inFile); // Close the input file if the output file couldn't be opened
        return; // Exit the function early
    }

    // Read from the input file and write to the output file
    char buffer[1024]; // Buffer to hold text read from the input file
    while (fgets(buffer, sizeof(buffer), inFile)) { // Read until end of file
        fputs(buffer, outFile); // Write the buffer to the output file
    }

    // Close the files
    fclose(inFile);
    fclose(outFile);
}