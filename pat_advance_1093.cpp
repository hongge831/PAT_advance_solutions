#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
	int patCount = 0, atCount = 0, tCount = 0;
	string str;
	cin >> str;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] == 'T'){
			tCount++;
		}
		if (str[i] == 'A'){
			atCount = (atCount + tCount) % 1000000007;//be careful
		}
		if (str[i] == 'P'){
			patCount = (patCount + atCount) % 1000000007;
		}
	}cout << patCount << endl;
	return 0;
}