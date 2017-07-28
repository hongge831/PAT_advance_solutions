#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	string re[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	string str,s;
	int sum = 0;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		sum += str[i] - '0';
	}
	s = to_string(sum);
	cout << re[s[0]-'0'];
	for (int i = 1; i < s.size(); i++)
	{
		cout << ' '<<re[s[i]-'0'];
	}
	return 0;
}