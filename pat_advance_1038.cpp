#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
bool cmp(string a, string b){
	return a + b < b + a;
}
int main(){
	int n;
	cin >> n;
	string temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(),cmp);
	string s="";
	for (int i = 0; i < v.size(); i++)
	{
		s += v[i];
	}
	while (s.length() != 0 && s[0] == '0'){
		s.erase(s.begin());
	}
	if (s.length() == 0){
		cout << 0;
	}
	else{
		cout << s;
	}

	return 0;
}
