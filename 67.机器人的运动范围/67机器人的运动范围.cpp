// 67机器人的运动范围.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
bool isSumLegal(int row, int col, int k){
	int sum1=0, sum2=0;
	while (row){
		sum1 += row % 10;
		row /= 10;
	}
	while (col){
		sum2 += col % 10;
		col /= 10;
	}
	return sum1 + sum2>k?false:true;
}
void movingCountCore(int threshold, int rows, int cols, int row, int col, int &count, bool *isVisit)
{
	if (row < rows &&row >= 0 && col >= 0 && col < cols && !isVisit[row*cols + col]){
		bool legal = isSumLegal(row, col, threshold);
		if (legal){
			count++;
			isVisit[row*cols + col] = true;
			movingCountCore(threshold, rows, cols, row - 1, col, count, isVisit);
			movingCountCore(threshold, rows, cols, row + 1, col, count, isVisit);
			movingCountCore(threshold, rows, cols, row, col - 1, count, isVisit);
			movingCountCore(threshold, rows, cols, row, col + 1, count, isVisit);
		}
	}
}
int movingCount(int threshold, int rows, int cols)
{
	bool *isVisit = new bool[rows*cols];
	int count = 0;
	memset(isVisit, 0, sizeof(bool)*rows*cols);
	int row = 0, col = 0;
	movingCountCore(threshold, rows, cols, row, col, count, isVisit);
	return count;

}
int _tmain(int argc, _TCHAR* argv[])
{
	cout << movingCount(18, 100, 100);
	return 0;
}

