// #include <opencv2/opencv.hpp>
// #include <iostream>
 
//  int main() {
//      // Load the image
//      cv::Mat image = cv::imread("ea.jpg");
 
//      // Check if the image was loaded correctly
//      if (image.empty()) {
//          std::cerr << "Could not open or find the image.\n";
//          return -1;
//      }
 
//      // Convert to grayscale (black & white)
//      cv::Mat grayscale;
//      cv::cvtColor(image, grayscale, cv::COLOR_BGR2GRAY);
 
//      // Save the new image
//      cv::imwrite("grayscale.jpg", grayscale);
 
//      std::cout << "Converted image saved as grayscale.jpg\n";
//      return 0;
//  }
 
#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Load the grayscale image
    cv::Mat image = cv::imread("ea.jpg", cv::IMREAD_GRAYSCALE);

    // Check if the image is loaded correctly
    if (image.empty()) {
        std::cerr << "Error: Could not open or find the image!" << std::endl;
        return -1;
    }

    // for (int y = 0; y < image.rows; y++) {
    //     for (int x = 0; x < image.cols; x++) {
    //         std::cout << "Pixel at (" << x << "," << y << "): " << (int)image.at<uchar>(y, x) << std::endl;
    //     }
    // }
    
    std::cout << "Image size: " << image.size() << std::endl;

    return 0;
}
