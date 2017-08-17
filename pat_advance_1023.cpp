#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	string str;
	cin >> str;
	vector<int> re(10);
	vector<int> result;
	int ge = 0, shi = 0;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		re[str[i] - '0']++;
		ge = shi + ((str[i] - '0') * 2) % 10;
		shi = ((str[i] - '0') * 2) / 10;
		re[ge]--;
		result.push_back(ge);
	}
	if (shi != 0)
		result.push_back(shi);
	int i;
	for (i = 0; i < 10; i++)
	{
		if (re[i] != 0){
			cout << "No" << endl;
			break;
		}
	}
	if (i == 10){
		cout << "Yes" << endl;
	}
	for (int j = result.size() - 1; j >= 0; j--)
	{
		cout << result[j];
	}



	return 0;
}