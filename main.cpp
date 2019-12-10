#include <opencv2/opencv.hpp>

int main( int argc, char** argv )
{
    char* imageName = argv[1];
    cv::Mat image;
    image = imread( imageName, cv::IMREAD_COLOR );

    if( argc != 2 || !image.data )
    {
        printf( " No image data \n " );
        return -1;
    }

    cv::Mat gray_image;
    cv::cvtColor( image, gray_image, cv::COLOR_BGR2GRAY );
    cv::imwrite( "..\\Gray_Image.jpg", gray_image );

    cv::namedWindow( imageName, cv::WINDOW_KEEPRATIO );
    cv::namedWindow( "Gray image", cv::WINDOW_KEEPRATIO );

    cv::imshow( imageName, image );
    cv::imshow( "Gray image", gray_image );

    cv::waitKey( 0 );
    return 0;
}
