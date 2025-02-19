#include "../inc/ascii_art.hpp"

int main(int argc, char** argv) {
    // Check if an image filename is provided as a command line argument
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << "<block size>(1-100) <image_filename>" << std::endl;
        return -1;
    }

    std::string imageFilename = argv[2];

    // Ensure the image file has a .jpg extension
    if (!hasValidImageExtension(imageFilename)) {
        std::cerr << "Error: The file must be a .jpg image!" << std::endl;
        return -1;
    }

    // Load block_size from settings file
	int blockSize = std::atoi(argv[1]);
	if(blockSize < 1 || blockSize > 100) {
		std::cerr << "Error: Block size must be between 1 and 100!" << std::endl;
		return -1;
	}

    // Generate ASCII art and save it to result.txt
    generateAsciiArt(imageFilename, blockSize, "result.txt");

    return 0;
}
