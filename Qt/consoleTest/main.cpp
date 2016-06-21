#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

using namespace std;

int main(int argc,char *argv[])
{
    cv::Mat img = cv::imread("D:/File/Background/final fantasy.jpg");
    if(!img.empty())
        cv::imshow("show image..",img);
    else
        cout << " Empty image.." << endl;
    cv::waitKey(0);
    return 0;
}
