#include <stdio.h>
#include <iostream>
#include <vector>
#define M 2002
using namespace std;
struct info{
	int expo = 0;
	double coef = 0.0;
};

void init_ploy(int n, vector<info> &a){
	info temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp.expo;
		cin >> temp.coef;
		a.push_back(temp);
	}
}
int main(){
	int n;
	vector<info> a, b;
	cin >> n;
	init_ploy(n, a);
	cin >> n;
	init_ploy(n, b);
	int loc = 0;
	double coef;
	vector<double> re(M);
	fill(re.begin(), re.end(), 0);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			loc = a[i].expo + b[j].expo;
			coef = a[i].coef*b[j].coef;
			re[loc] = re[loc] + coef;
		}
	}
	int cnt = 0;
	for (int i = 0; i<re.size(); i++)
	{
		if (re[i] != 0)
			cnt++;
	}cout << cnt;
	for (int i = re.size()-1; i >= 0; i--)
	{
		if (re[i] != 0){
			printf(" %d %.1f",i,re[i]);
		}
	}
	return 0;
}
