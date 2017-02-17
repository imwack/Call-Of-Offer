// 数组中的逆序对.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
int Merge(vector<int> &data, vector<int> &copy, int start, int end){
	if (start == end){
		copy[start] = data[start];
		return 0;
	}
	int mid = (end - start)/2 + start;
	int left = Merge(data, copy, start, mid) % 1000000007;
	int right = Merge(data, copy, mid + 1, end) % 1000000007;

	int count = 0;
	int curEnd = end;
	int j = end;
	int i = mid;
	while (i >= start && j >mid){
		if (data[i]>data[j]){
			count += j - mid;
			copy[curEnd--] = data[i--];
			if (count>1000000007)
				count %= 1000000007;
		}
		else{
			copy[curEnd--] = data[j--];
		}
	}
	for (; i >= start; --i)
		copy[curEnd--] = data[i];
	for (; j >mid; --j)
		copy[curEnd--] = data[j];
	for (int k = start; k <= end; k++)
		data[k] = copy[k];
	return left + right + count;
}
int InversePairs(vector<int> data) {
	if (data.empty() || data.size() == 0)
		return 0;
	vector<int> copy(data);
	int count = Merge(data, copy, 0, data.size() - 1);
	return count % 1000000007;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 0 };
	vector<int> data(a, a + 8);
	int count = InversePairs(data);
	cout << count;
	return 0;
}

