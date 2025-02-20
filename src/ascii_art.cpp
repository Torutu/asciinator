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
    const char* asciiChars = "@#S%?O+;:,. ";
    int index = (intensity * (strlen(asciiChars) - 1)) / 255;
    return asciiChars[index];
}

// Load image using stb_image and generate ASCII art
void generateAsciiArt(const std::string& imageFilename, int blockSize, const std::string& outputFilename) {
    int width, height, channels;
    
    // Load image (force 1 channel for grayscale)
    unsigned char* image = stbi_load(imageFilename.c_str(), &width, &height, &channels, 1);
    
    if (!image) {
        std::cerr << "Error: Could not load image: " << imageFilename << std::endl;
        return;
    }

    // Calculate ASCII output dimensions
    int rows = height / blockSize;
    int cols = width / blockSize;
    std::vector<std::vector<char>> asciiArt(rows, std::vector<char>(cols));

    // Process blocks
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            int total = 0;

            // Sum up pixel intensities in the block
            for (int i = 0; i < blockSize; i++) {
                for (int j = 0; j < blockSize; j++) {
                    int px = x * blockSize + j;
                    int py = y * blockSize + i;

                    if (px < width && py < height) {
                        total += image[py * width + px]; // Access pixel intensity
                    }
                }
            }

            // Compute average intensity
            int avgIntensity = total / (blockSize * blockSize);
            asciiArt[y][x] = mapToAscii(avgIntensity);
        }
    }

    // Save ASCII art to a file
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open output file for writing!" << std::endl;
        stbi_image_free(image);
        return;
    }

    for (const auto& row : asciiArt) {
        for (char c : row) {
            outputFile << c << " ";
        }
        outputFile << "\n";
    }

    outputFile.close();
    stbi_image_free(image); // Free image memory
    std::cout << "ASCII art saved to " << outputFilename << "!" << std::endl;
}
