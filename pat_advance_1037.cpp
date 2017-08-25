#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vc, vp;
bool cmp(int a, int b){
	return a < b;
}
int main(){
	int nc, np, tempIn, sum = 0;
	cin >> nc;
	for (int i = 0; i < nc; i++)
	{
		cin >> tempIn;
		vc.push_back(tempIn);
	}
	cin >> np;
	for (int i = 0; i < np; i++)
	{
		cin >> tempIn;
		vp.push_back(tempIn);
	}
	sort(vc.begin(), vc.end(), cmp);
	sort(vp.begin(), vp.end(), cmp);
	int i = 0, j = 0;
	while (i < vc.size() && j < vp.size() && vc[i] < 0 && vp[j] < 0){
		sum += vc[i] * vp[j];
		i++; j++;
	}
	i = vc.size() - 1; j = vp.size() - 1;
	while (vc[i] > 0 && vp[j] > 0){
		sum += vc[i] * vp[j];
		i--; j--;
	}
	cout << sum;
	return 0;
}
