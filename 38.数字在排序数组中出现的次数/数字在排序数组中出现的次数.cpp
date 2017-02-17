// 数字在排序数组中出现的次数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

int GetNumberOfK(vector<int> data, int k) {
	int left = 0;
	int right = data.size() - 1;
	int mid = (right - left) / 2 + left;
	int count = 0;
	if (data.size() == 0 || k<data[0] || k>data[data.size() - 1])
		return 0;
	while (data[mid] != k && left<right){
		
		if (data[mid]>k){
			right = mid;
		}
		else{
			left = mid;
		}
		mid = (right - left) / 2 + left;
	}
	if (data[mid] != k)
		return 0;
	for (int i = mid; i >= 0 && data[i] == k; i--)
		count++;
	for (int i = mid + 1; i<data.size() && data[i] == k; i++)
		count++;
	return count;

}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 1, 1, 1, 2, 2, 2, 2, 3, 4, 4, 5, 7 };

	vector<int> data(a, a+sizeof(a)/sizeof(int));
	cout << GetNumberOfK(data, 7);
	return 0;
}

