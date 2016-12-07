#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

String windows = "/media/argen/5A50DBA250DB82E5/KGFI/image processing/contour/";

int main() {
    Mat original = imread(windows + "lena.png", 1); if (!original.data)  return -1;
    Mat gray = Mat(cvSize(original.rows, original.cols), CV_8UC1);
    Mat result = Mat(cvSize(original.rows, original.cols), CV_8UC1);
    cvtColor(original, gray, CV_RGB2GRAY);

    for(int x = 0; x < gray.rows; x++) {
        for (int y = 0; y < gray.cols; y++) {
            if  ((gray.at<uchar>(x, y) >= 128 && gray.at<uchar>(x, y - 1) <  128) ||
                 (gray.at<uchar>(x, y) <  128 && gray.at<uchar>(x, y - 1) >= 128))
                   result.at<uchar>(x, y) = 255;
            if ((x != 0) && (gray.at<uchar>(x, y) >= 128 && gray.at<uchar>(x - 1, y) <  128) ||
                            (gray.at<uchar>(x, y) <  128 && gray.at<uchar>(x - 1, y) >= 128))
                             result.at<uchar>(x, y) = 255;
        }
    }
    namedWindow("original", CV_WINDOW_AUTOSIZE);
    namedWindow("lena", CV_WINDOW_AUTOSIZE);
    namedWindow("result", CV_WINDOW_AUTOSIZE);

    imwrite(windows + "contour.jpg", result);
    imshow("original", original);
    imshow("lena", gray);
    imshow("result", result);
    waitKey(0);
    return 0;

}