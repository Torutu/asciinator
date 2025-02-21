#define STB_IMAGE_IMPLEMENTATION
#include "../inc/stb_image.h" // stb_image for image loading
#include "../inc/ascii_art.hpp"

bool hasValidImageExtension(const std::string& filename) {
    static const std::vector<std::string> validExtensions = {
        ".jpg", ".jpeg", ".png", ".bmp"
    };

    for (const auto& ext : validExtensions) {
        if (filename.size() > ext.size() && filename.substr(filename.size() - ext.size()) == ext) {
            return true;
        }
    }
    return false;
}

// ASCII characters from darkest to lightest
char mapToAscii(int intensity) {
    const char* asciiChars = "@#S%?O+;:,. "; // Characters representing different intensity levels
    int index = (intensity * (strlen(asciiChars) - 1)) / 255; // Scale intensity to map within the ASCII array
    return asciiChars[index]; // Return corresponding ASCII character
}

// Load image using stb_image and generate ASCII art
void generateAsciiArt(const std::string& imageFilename, int blockSize, const std::string& outputFilename) {
    int width, height, channels;

    // Load image using stb_image, forcing 1 channel (grayscale)
    unsigned char* image = stbi_load(imageFilename.c_str(), &width, &height, &channels, 1);
    
    if (!image) { // Check if the image failed to load
        std::cerr << "Error: Could not load image: " << imageFilename << std::endl;
        return; // Exit function if image loading fails
    }

    // Calculate the number of ASCII rows and columns based on block size
    int rows = height / blockSize; // Each ASCII row corresponds to a block of pixels
    int cols = width / blockSize;  // Each ASCII column corresponds to a block of pixels

    // Create a 2D vector to store the ASCII characters
    std::vector<std::vector<char>> asciiArt(rows, std::vector<char>(cols));

    // Process each block in the image
    for (int y = 0; y < rows; y++) { // Iterate over ASCII rows
        for (int x = 0; x < cols; x++) { // Iterate over ASCII columns
            int total = 0; // Initialize sum of pixel intensities in this block

            // Sum up pixel intensities within the block
            for (int i = 0; i < blockSize; i++) { // Iterate over pixels in the block vertically
                for (int j = 0; j < blockSize; j++) { // Iterate over pixels in the block horizontally
                    int px = x * blockSize + j; // Calculate pixel's x-coordinate in the image
                    int py = y * blockSize + i; // Calculate pixel's y-coordinate in the image

                    if (px < width && py < height) { // Ensure we do not access out-of-bounds pixels
                        total += image[py * width + px]; // Access pixel intensity (grayscale)
                    }
                }
            }

            // Compute average intensity for the block
            int avgIntensity = total / (blockSize * blockSize);
            
            // Convert the average intensity into an ASCII character and store it
            asciiArt[y][x] = mapToAscii(avgIntensity);
        }
    }

    // Save ASCII art to a file
    std::ofstream outputFile(outputFilename); // Open output file for writing
    if (!outputFile.is_open()) { // Check if file opening failed
        std::cerr << "Error: Could not open output file for writing!" << std::endl;
        stbi_image_free(image); // Free allocated memory for the image
        return; // Exit function
    }

    // Write the ASCII art to the file
    for (const auto& row : asciiArt) { // Iterate over each row of ASCII characters
        for (char c : row) { // Iterate over each character in the row
            outputFile << c << " "; // Write character to file with spacing to prevent stretching
        }
        outputFile << "\n"; // Move to the next line in the file
    }

    outputFile.close(); // Close the file after writing

    stbi_image_free(image); // Free image memory allocated by stb_image

    std::cout << "ASCII art saved to " << outputFilename << "!" << std::endl; // Inform user of success
}
