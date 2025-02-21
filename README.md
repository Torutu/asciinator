# Asciinator

Asciinator is a tool that converts image files (currently `.jpg .jpeg .png .bmp`) into ASCII art. The program reads an image, process it, and generates ASCII art, which can then be saved to a text file.

## Features
- only works on Linux distributions (Debian, Ubuntu, etc...)
- Converts images into ASCII art
- Customizable block size (between 1-100)
- doesn't rely on any dependencies

## Installation

### Step 1: download the version that works on your system and extract
-[Linux Version](https://github.com/Torutu/asciinator/releases/download/v0.1/linux_asciinator.tar.gz)

-[Windows Version](https://github.com/Torutu/asciinator/releases/download/v0.1/win_asciinator.tar.gz)
### Step 2: Run the Program
linux(debian, ubuntu, etc...)
```bash
./asciinator <block size> <image_filename.jpg>
```
windows
```cmd
.\asciinatr <block size> <image_filename.jpg>
```
for example
```bash
./asciinator 5 cat.jpg
```
and the output will be saved in `result.txt` on the same directory

- `<block size> 1 - 100`:  A value of `1` will print one ASCII character for each pixel, resulting in more **detailed output**. A value of `100` will print one ASCII character for every 100 pixels, producing a less detailed and more **compressed output**.
- `<image_filename>`:The image file that will be converted to ASCII art
## Avilable Makefile Commands
- `make`: Builds the project and creates the asciinator executable.
- `make clean`: Cleans the build by removing object files.
- `make fclean`: Removes the asciinator executable and object files.
- `make re`: Cleans and rebuilds the project.
## Uninstallation
```bash
make fclean
```
---
## Update
- removed 'opencv' dependencies, now the program can be used without the need to install opencv(it would take 1gb of memory space)

## Pseudocode

1. Check Command Line Arguments:
   * if the number of arguments is not 3, print a usage message and exit
   * extract `blockSize` from argument and convert it to an integer.
   * if `blockSize` is not between 1 and 100, print and error message and exit.
   * extract the `imageFilename` from the command line argument.
   * Check if the filename has a valid image extension and ends with `.jpg .jpeg .png .bmp`
   * if invalid, print an error message and exit.
3. Generating ASCII ART:
   * Use `stb_image` to load the image as grayscale.
   * divide the image into blocks(arrays) by dividing it into rows and cols, `asciiArt[rows][cols]` <- the array of each block
   * Process each block in the image:
     * loop over each row `y` and col `x`
       * Initialize `total` to store the sum of the block intensities
       * Loop through each pixel in each block
         * get the actual pixel position `(px, py)`.
         * after looping through a block we add its intensity to `total`.
       * Get the `average intensity` of the block.
       * Assign an `ASCII character` to the block depends on its `intensity`.
       * Store the character in an array
4. Save ASCII Art to a File:
   * Open the outputfile `result.txt` (always check for failure when opening files)
   * Write each row of the ASCII character to the file.
   * close the file
5. Cleanup and Exit
   * Free image memory and print.
   * Print a success message.
