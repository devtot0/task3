#include "M.h"

CImg<int> dilation(CImg<int>& image, vector<vector<maskItem>> mask)
{
	CImg<int> result = image;
	for (int x = 1; x < image.width() - 1; x++)
	{
		for (int y = 1; y < image.height() - 1; y++)
		{
			bool isMax = false;
			for (int i = 0; i < mask.size(); i++)
			{
				for (int j = 0; j < mask[0].size(); j++)
				{
					if (mask[i][j] == inactive) {
						continue;
					}
					if (mask[i][j] == one && image(x+i-1,y+j-1,0)==255) {
						isMax = true;
						break;
					}					
				}
				if (isMax) {
					break;
				}
			}
			if (isMax) {
				for (int c = 0; c < image.spectrum(); c++) {
					result(x, y, 0, c) = 255;
				}
			}
		}
	}
	return result;
}

CImg<int> erosion(CImg<int>& image, vector<vector<maskItem>> mask)
{
	CImg<int> result = image;
	for (int x = 1; x < image.width() - 1; x++)
	{
		for (int y = 1; y < image.height() - 1; y++)
		{
			bool isMin = false;
			for (int i = 0; i < mask.size(); i++)
			{
				for (int j = 0; j < mask[0].size(); j++)
				{
					if (mask[i][j] == inactive) {
						continue;
					}

					if (mask[i][j] == one && image(x + i - 1, y + j - 1, 0) == 0) {
						isMin = true;
						break;
					}
				}
				if (isMin) {
					break;
				}
			}
			if (isMin) {
				for (int c = 0; c < image.spectrum(); c++) {
					result(x, y, 0,c) = 0;
				}				
			}
		}
	}
	return result;
}

CImg<int> opening(CImg<int>& image, vector<vector<maskItem>> mask)
{
	CImg<int> temp;
	temp = erosion(image, mask);
	return dilation(temp, mask);

}

CImg<int> closing(CImg<int>& image, vector<vector<maskItem>> mask)
{
	CImg<int> temp;
	temp = dilation(image, mask);
	return erosion(temp, mask);
}

CImg<int> hmt(CImg<int>& image, vector<vector<maskItem>> mask)
{
	CImg<int> result = image;
	for (int x = 1; x < image.width() - 1; x++)
	{
		for (int y = 1; y < image.height() - 1; y++)
		{
			bool isMin = false;
			bool isMax = false;
			for (int i = 0; i < mask.size(); i++)
			{
				for (int j = 0; j < mask[0].size(); j++)
				{
					if (mask[i][j] == inactive) {
						continue;
					}

					if (mask[i][j] == one && image(x + i - 1, y + j - 1, 0) == 0) {
						isMin = true;
						break;
					}
					if (mask[i][j] == zero && image(x + i - 1, y + j - 1, 0) == 255) {
						isMax = true;
						break;
					}
				}
				if (isMin || isMax) {
					break;
				}
			}
			if (isMin) {
				for (int c = 0; c < image.spectrum(); c++) {
					result(x, y, 0, c) = 0;
				}
			}
			if (isMax) {
				for (int c = 0; c < image.spectrum(); c++) {
					result(x, y, 0, c) = 255;
				}
			}
		}
	}
	return result;
}
