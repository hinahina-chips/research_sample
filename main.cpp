#include <opencv2/opencv.hpp>

#ifdef _DEBUG
#pragma comment(lib, "opencv_world470d.lib")
#else
#pragma comment(lib, "opencv_world470.lib")
#endif

using namespace cv;
using namespace std;

int main(void) {
	// �摜�̓ǂݍ���
	Mat image = imread("input.jpg");

    // �~�̒��S���W�Ɣ��a��ݒ�
    Point center(image.cols / 2, image.rows / 2);
    int radius = min(image.cols, image.rows) / 2;

    // �����摜���쐬
    Mat blackImage(image.size(), CV_8UC3, Scalar(0, 0, 0));

    // �~�`�̃}�X�N���쐬
    circle(blackImage, center, radius, Scalar(255, 255, 255), -1);

    // �}�X�N��K�p���Č��̉摜�������h��
    Mat maskedImage;
    image.copyTo(maskedImage, blackImage);

    // ���ʂ̕\��
    imshow("Masked Image", maskedImage);
    waitKey(0);

    return 0;
}
