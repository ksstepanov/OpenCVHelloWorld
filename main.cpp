#include <QtGui/QApplication>
#include "mainwindow.h"
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>


using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    //return a.exec();


    //if( argc != 2)
    //{
    // cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
    // return -1;
    //}


    Mat image;
    char* imageInName = "frame1.ppm";
    char* imageOutName = "frame1_grey.ppm";
    image = imread(imageInName, CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

     Mat gray_image;
     //cvtColor( image, gray_image, CV_RGB2GRAY );
     cvtColor(image,gray_image,CV_RGB2GRAY);
     imwrite( imageOutName, gray_image );

     namedWindow( imageInName, CV_WINDOW_NORMAL );
     namedWindow( imageOutName, CV_WINDOW_NORMAL );

     imshow( imageInName, image );
     imshow(imageOutName , gray_image );

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;

}


