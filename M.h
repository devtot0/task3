#pragma once
#include "CImg.h"
#include <vector>
using namespace cimg_library;
using namespace std;
enum maskItem {
	zero,
	one,
	inactive
};


CImg<int> dilation(CImg<int> &image, vector<vector<maskItem>> mask);
CImg<int> erosion(CImg<int> &image, vector<vector<maskItem>> mask);
CImg<int> opening(CImg<int> &image, vector<vector<maskItem>> mask);
CImg<int> closing(CImg<int> &image, vector<vector<maskItem>> mask);
CImg<int> hmt(CImg<int> &image, vector<vector<maskItem>> mask);

