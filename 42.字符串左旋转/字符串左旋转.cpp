// 字符串左旋转.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string LeftRotateString(string str, int n) {
	string ret = str;

	if (str.size() <= 1)
		return ret;
	if (n>ret.size())
		n %= ret.size();
	for (int i = 0, j = n - 1; i<j; i++, j--)
		swap(ret[i], ret[j]);


	for (int i = n, j = ret.size() - 1; i<j; i++, j--)
		swap(ret[i], ret[j]);

	for (int i = 0, j = ret.size() - 1; i<j; i++, j--)
		swap(ret[i], ret[j]);


	return ret;
}


int _tmain(int argc, _TCHAR* argv[])
{
	string str = "abcXYZdef";
	cout<< LeftRotateString(str, 2);
	return 0;
}

