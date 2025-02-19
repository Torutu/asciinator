// ascii_art.hpp
#ifndef ASCII_ART_HPP
#define ASCII_ART_HPP

#include <string>
#include <iostream>
#include <fstream>


// Function to map pixel intensity to ASCII character
char mapToAscii(int intensity);

// Function to check if the file's extensions
bool hasValidImageExtension(const std::string& filename);

// Function to generate ASCII art from the image
void generateAsciiArt(const std::string& imageFilename, int blockSize, const std::string& outputFilename);

#endif // ASCII_ART_HPP
