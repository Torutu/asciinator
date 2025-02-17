// ascii_art.h
#ifndef ASCII_ART_H
#define ASCII_ART_H

#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>
#include <fstream>


// Function to map pixel intensity to ASCII character
char mapToAscii(int intensity);

// Function to check if the filename ends with .jpg
bool hasJpgExtension(const std::string& filename);

// Function to generate ASCII art from the image
void generateAsciiArt(const std::string& imageFilename, int blockSize, const std::string& outputFilename);

#endif // ASCII_ART_H
