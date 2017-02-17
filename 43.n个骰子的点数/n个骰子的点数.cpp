// n个骰子的点数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

#define MAXNUM 6

//f(n,sum) = f(n-1,sum-1)+f(n-1,sum-2)+  ...  +f(n-1,sum-6)
//f(1,1) = f(1,2) = ... = f(1,6) = 1
int CalculateTimes(int n, int sum){
	if (sum < n || sum>n*MAXNUM)
		return 0;
	if (n == 1)
		return 1;
	return CalculateTimes(n - 1, sum - 1) + CalculateTimes(n - 1, sum - 2) + CalculateTimes(n - 1, sum - 3) + CalculateTimes(n - 1, sum - 4) + CalculateTimes(n - 1, sum - 5) + CalculateTimes(n - 1, sum - 6);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 5;	//5次
	int minSum =  n;
	int maxSum = n * MAXNUM;
	int *count = new int[5 * MAXNUM ];
	int totalTimes = pow(double(MAXNUM), 5);
	for (int i = minSum; i <= maxSum; i++){
		count[i-6] = CalculateTimes(n, i);
		cout << count[i - 6]*1.0/totalTimes << endl;
	}
	return 0;
}

