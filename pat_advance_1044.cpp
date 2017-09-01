#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v, result;
int mmin, m;
int findValue(int i, int &right){
	int left = i;
	while (left < right){
		int mid = (left + right) / 2;
		if (v[mid] - v[i - 1] >= m){
			right = mid;//errorable place, it's different from finding value
		}
		else{
			left = mid + 1;
		}
	}
	return v[right] - v[i - 1];
}
int main(){
	/*data input*/
	int n, temp, sum = 0;
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &temp);
		sum += temp;
		v[i] = sum;
	}
	/*algorithm begin*/
	int j, res = 0;
	mmin = v[n];//OR set the mmin's initial value >10^e8
	for (int i = 1; i <= n; i++)
	{
		j = n;
		res = findValue(i, j);//binary search
		if (res >= m){
			if (res > mmin)//remove the res that larger than mmin
				continue;
			if (res < mmin){
				mmin = res;
				result.clear();
			}
			result.push_back(i);
			result.push_back(j);
		}
	}
	/*print result*/
	for (int i = 1; i < result.size(); i += 2)
	{
		printf("%d-%d\n", result[i - 1], result[i]);
	}
	return 0;
}