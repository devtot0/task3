#include "CImg.h"
#include "M.h"
#include <iostream>

using namespace std;

int main() {

	CImg<int> image("lenabw.bmp");
	//vector<vector<maskItem>> mask{ {one,one,one},{one,one,one},{one,one,one} };
	vector<vector<maskItem>> mask{ {one,inactive,inactive},{one,zero,inactive},{one,inactive,inactive} };
	auto result = hmt(image, mask);
	result.save("lena_hmt.bmp");
	// result = closing(image, mask);
	//result.save("lenaC.bmp");

	return 0;
}