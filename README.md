# Asciinator

Asciinator is a tool that converts image files (currently `.jpg`) into ASCII art using OpenCV. The program reads an image, process it, and generates ASCII art, which can then be saved to a text file.

## Features
- only works on Linux distributions (Debian, Ubuntu, etc...)
- Converts `.jpg` images into ASCII art
- Customizable block size (between 1-100)
- Easy installation of OpenCV dependencies using `Makefile`

## Requirements
- C++11 or later
- OpenCV 4.0 or later (the makefile should do it already)
- pkg-config (for detecting OpenCV libraries)

## Installation

### Step 1: Clone the repository
```bash
git clone https://github.com/yourusername/asciinator.git
cd asciinator
```
### Step 2: Install OpenCV
```bash
make install_opencv
```
### Step 3: Compile the Project
```bash
make
```
### Step 4: Run the Program
```bash
./asciinator <block size> <image_filename.jpg>
```
for example
```bash
./asciinator 5 cat.jpg
```
and the output will be saved in `result.txt` on the same directory

- `<block size> 1 - 100`:  A value of `1` will print one ASCII character for each pixel, resulting in more **detailed output**. A value of `100` will print one ASCII character for every 100 pixels, producing a less detailed and more **compressed output**.
- `<image_filename>`:The `.jpg` image file will be converted to ASCII art
## Avilable Makefile Commands
- `make install_opencv`: Installs the necessary OpenCV dependencies.
- `make rm_opencv`: Removes OpenCV from your system.
- `make`: Builds the project and creates the asciinator executable.
- `make clean`: Cleans the build by removing object files.
- `make fclean`: Removes the asciinator executable and object files.
- `make re`: Cleans and rebuilds the project.
## Uninstallation
```bash
make rm_opencv
make fclean
```
