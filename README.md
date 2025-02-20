# Asciinator

Asciinator is a tool that converts image files (currently `.jpg`) into ASCII art. The program reads an image, process it, and generates ASCII art, which can then be saved to a text file.

## Features
- only works on Linux distributions (Debian, Ubuntu, etc...)
- Converts `.jpg` images into ASCII art
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
- `<image_filename>`:The `.jpg` image file will be converted to ASCII art
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
