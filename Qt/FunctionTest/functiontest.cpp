#include "functiontest.h"
#include <QtWidgets>
#include <opencv2/opencv.hpp>
using namespace cv;

QVideoFrame MyFilterRunable::run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags)
{
    if(input->isValid()){
            input->map(QAbstractVideoBuffer::ReadWrite);
            /// QVideoFrame to cv::Mat
            Mat cvImg = Mat(input->height(),input->width(), CV_8UC3,input->bits(),input->bytesPerLine());

            /// Apply Filter
            Mat edges;

            /// to grayscale
            cvtColor(cvImg, edges, COLOR_YUV2GRAY_420);

            /// apply filters
            GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
            Canny(edges, edges, 0, 30, 3);

            cv::putText(cvImg,"putStr",Point(200,200),3,1,Scalar(255,0,0));

            /// convert to YUV420
            cvtColor(edges,edges, COLOR_GRAY2RGB);
            cvtColor(edges,edges, COLOR_RGB2YUV_I420);

            ///  what to do here to send back the modified frame .....   ???
            input->unmap();
        }

         return *input;
}
