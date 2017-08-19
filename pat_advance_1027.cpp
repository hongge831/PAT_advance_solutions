#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
char c[13] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C' };
int main(){
	int r, g, b;
	cin >> r >> g >> b;
	vector<char> v;
	v.push_back('#');
	v.push_back(c[r / 13]);
	v.push_back(c[r % 13]);
	v.push_back(c[g / 13]);
	v.push_back(c[g % 13]);
	v.push_back(c[b / 13]);
	v.push_back(c[b % 13]);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	return 0;
}