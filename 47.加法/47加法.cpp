// 47加法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int Add(int a,int b){
	int s, c;
	do{
		s = a^b;
		c = (a&b) << 1;
		a = s;
		b = c;

	} while (c != 0);
	
	return s;
}
int _tmain(int argc, _TCHAR* argv[])
{	
	cout << Add(3, 10);
	return 0;
}

