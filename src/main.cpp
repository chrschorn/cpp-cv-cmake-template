#include <iostream>

#include <opencv2/opencv.hpp>

#include <utils.hpp>


int main (int argc, char *argv[]) 
{ 
    const auto answer = getAnswer();

    // Hello world
    std::cout << "Hello, world! " << answer << std::endl;

    // OpenCV test window
    cv::Mat image(500, 500, CV_8UC3, cv::Scalar::all(0));
    cv::putText(image, std::to_string(answer), cv::Point(0, image.rows - 1), cv::FONT_HERSHEY_SIMPLEX, 5, cv::Scalar(255, 0, 0));
    cv::imshow("", image);
    cv::waitKey();
    
    return 0; 
}
