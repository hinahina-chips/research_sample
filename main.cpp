#include <opencv2/opencv.hpp>

#ifdef _DEBUG
#pragma comment(lib, "opencv_world470d.lib")
#else
#pragma comment(lib, "opencv_world470.lib")
#endif

using namespace cv;
using namespace std;

int main(void) {
	// 画像の読み込み
	Mat image = imread("input.jpg");

    // 円の中心座標と半径を設定
    Point center(image.cols / 2, image.rows / 2);
    int radius = min(image.cols, image.rows) / 2;

    // 黒い画像を作成
    Mat blackImage(image.size(), CV_8UC3, Scalar(0, 0, 0));

    // 円形のマスクを作成
    circle(blackImage, center, radius, Scalar(255, 255, 255), -1);

    // マスクを適用して元の画像を黒く塗る
    Mat maskedImage;
    image.copyTo(maskedImage, blackImage);

    // 結果の表示
    imshow("Masked Image", maskedImage);
    waitKey(0);

    return 0;
}
