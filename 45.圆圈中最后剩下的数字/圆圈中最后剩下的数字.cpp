// ԲȦ�����ʣ�µ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<list>
#include<vector>
using namespace std;

//n Ϊ����  mΪ����
int LastRemaining(int n, int m)
{
	if (n == 0 || m == 0)
		return -1;
	int fn1 = 0;
	int fn2 = 0;
	for (int i = 2; i <= n; i++){
		fn2 = (fn1 + m) % i;
		fn1 = fn2;
		cout << fn2 << endl;
	}
	return fn2;
}
int _tmain(int argc, _TCHAR* argv[])
{
	LastRemaining(100, 10);
	return 0;
}

