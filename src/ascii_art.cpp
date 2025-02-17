#include "../inc/ascii_art.h"

// Function to map pixel intensity to ASCII character
char mapToAscii(int intensity) {
    const char* asciiChars = "@#S%?*+;:,. ";
    int index = (intensity * (strlen(asciiChars) - 1)) / 255;
    return asciiChars[index];
}

// Function to check if the filename ends with .jpg
bool hasJpgExtension(const std::string& filename) {
    const std::string extension = ".jpg";
    return filename.length() >= extension.length() &&
           filename.compare(filename.length() - extension.length(), extension.length(), extension) == 0;
}

// Function to generate ASCII art from the image
void generateAsciiArt(const std::string& imageFilename, int blockSize, const std::string& outputFilename) {
    // Load the grayscale image
    cv::Mat image = cv::imread(imageFilename, cv::IMREAD_GRAYSCALE);

    // Check if the image is loaded correctly
    if (image.empty()) {
        std::cerr << "Error: Could not open or find the image!" << std::endl;
        return;
    }

    // Define block size
    int rows = image.rows / blockSize;
    int cols = image.cols / blockSize;

    // 2D array to store the ASCII representation (dimensions: rows x cols)
    std::vector<std::vector<char>> asciiArt(rows, std::vector<char>(cols));

    // Loop through blocks
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            int total = 0;

            // Calculate the average intensity of the current block
            for (int i = 0; i < blockSize; i++) {
                for (int j = 0; j < blockSize; j++) {
                    int px = x * blockSize + j;
                    int py = y * blockSize + i;

                    if (px < image.cols && py < image.rows) {
                        total += image.at<uchar>(py, px);
                    }
                }
            }

            // Calculate average intensity for the block
            int avgIntensity = total / (blockSize * blockSize);

            // Map the intensity to an ASCII character and store it in the 2D array
            asciiArt[y][x] = mapToAscii(avgIntensity);
        }
    }

    // Open the result.txt file for writing
    std::ofstream outputFile(outputFilename); //needs #include <fstream>

    // Check if the file is open
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open the result.txt file for writing!" << std::endl;
        return;
    }

    // Write ASCII art to the file
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            outputFile << asciiArt[y][x] << " ";
        }
        outputFile << std::endl;
    }

    // Close the file after writing
    outputFile.close();

    std::cout << "ASCII art has been saved to " << outputFilename << "!" << std::endl;
}
