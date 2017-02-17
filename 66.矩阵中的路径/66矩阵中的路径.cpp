// 66矩阵中的路径.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
bool hasPath(char* matrix, int rows, int cols, char* str, int row, int col, int &curLen, bool *isVisited);
bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == NULL || rows <= 0 || cols <= 0 || str == NULL)
		return false;
	bool *isVisited = new bool[rows*cols];
	memset(isVisited, 0, rows*cols);
	int curLen = 0;
	for (int row = 0; row<rows; row++){
		for (int col = 0; col<cols; col++){
			if (hasPath(matrix, rows, cols, str, row, col, curLen, isVisited))
				return true;
		}
	}
	delete[]isVisited;
	return false;
}
bool hasPath(char* matrix, int rows, int cols, char* str, int row, int col, int &curLen, bool *isVisited){
	if (str[curLen] == '\0')
		return true;
	bool find = false;
	if (row >= 0 && col >= 0 && row<rows && col<cols &&		//边界检查
		matrix[row*cols + col] == str[curLen] &&				//值相同
		isVisited[row*cols + col] == false)					//未被访问过
	{
		curLen++; 		isVisited[row*cols + col] = true;
		find = hasPath(matrix, rows, cols, str, row - 1, col, curLen, isVisited) ||
			hasPath(matrix, rows, cols, str, row + 1, col, curLen, isVisited) ||
			hasPath(matrix, rows, cols, str, row, col - 1, curLen, isVisited) ||
			hasPath(matrix, rows, cols, str, row, col + 1, curLen, isVisited);
		if (!find){
			curLen--;	isVisited[row*cols + col] = false;
		}
	}
	return find;

}

int _tmain(int argc, _TCHAR* argv[])
{
	char *matrix = "ABCESFCSADEE";
	char *str = "ABCCED";
	hasPath(matrix, 3, 4, str);
	return 0;
}

