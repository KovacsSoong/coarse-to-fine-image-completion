/* pyramid.h
 * both Gaussian and Laplace pyramid included.
 */

#ifndef _PYRAMID_H_
#define _PYRAMID_H_

#include <opencv2\opencv.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace cv;

class Pyramid {
public:
	Pyramid(Mat& src);  // [v1.1] use kernel provided by opencv

	void get_gaussian_pyramid();
	void get_laplace_pyramid();
	Mat get_real_image(const int dst_level);  // combine Gaussian and Laplace
	void save_images();

	~Pyramid() {
		// kernel.~Kernel(); [v1.0]
		GImages.clear();
		LImages.clear();
	}

private:
	int level;  // "level" should be no more than 9
	typedef vector<Mat> GPyramid;
	typedef vector<Mat> LPyramid;
	// images in Gaussian pyramid: "level",
	// images in Laplace pyramid: "level" - 1
	GPyramid GImages;  // Gaussian pyramid
	LPyramid LImages;  // Laplace pyramid
};

#endif