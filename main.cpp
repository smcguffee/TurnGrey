// main.cpp
// Created on: Feb 19, 2018
// Author: smcguffee

#include "main.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    String colorImageName( "" );
    String greyImageName( "" );
    if( argc > 2)
    {
        colorImageName = argv[1];
        greyImageName = argv[2];
    }
    else
    {
        cerr << "Usage: " << argv[0] << " colorImageFile outputGreyVersion" << endl;
    }
    Mat colorImage;
    colorImage = imread( colorImageName, IMREAD_COLOR ); // Read the file
    if( colorImage.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the colorImage" << std::endl ;
        return -1;
    }
    Mat gray_image;
    cvtColor( colorImage, gray_image, COLOR_BGR2GRAY );
    imwrite( greyImageName, gray_image );
    namedWindow( "Grey: " + greyImageName, WINDOW_AUTOSIZE );
    imshow( "Grey: " + greyImageName, gray_image );
    namedWindow( "Color: " + colorImageName, WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Color: " + colorImageName, colorImage );                // Show our colorImage inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}
