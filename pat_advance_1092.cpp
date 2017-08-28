#include <stdio.h>
#include<iostream>
#include<string>
#define M 100
using namespace std;
int main(){
	string in1, in2;
	int count[M] = { 0 };
	int yescount = 0, nocount = 0;
	cin >> in1 >> in2;
	int size1 = in1.size();
	int size2 = in2.size();
	for (int i = 0; i < size1; i++)
	{
		if (in1[i] >= '0'&&in1[i] <= '9'){
			count[in1[i] - '0'] += 1;
		}
		else if (in1[i] >= 'a'&&in1[i] <= 'z'){
			count[in1[i] - 'a' + 10] += 1;
		}
		else if (in1[i] >= 'A'&&in1[i] <= 'Z'){
			count[in1[i] - 'A' + 36] += 1;
		}
	}
	for (int j = 0; j < size2; j++)
	{
		if (in2[j] >= '0'&&in2[j] <= '9'){
			if (count[in2[j] - '0']>0){
				count[in2[j] - '0'] -= 1;
				yescount += 1;
			}
			else{
				nocount += 1;
			}
		}
		else if (in2[j] >= 'a'&&in2[j] <= 'z'){
			if (count[in2[j] - 'a'+10] > 0){
				count[in2[j] - 'a'+10] -= 1;
				yescount += 1;
			}
			else{
				nocount += 1;
			}
		}
		else if (in2[j] >= 'A'&&in2[j] <= 'Z'){
			if (count[in2[j] - 'A' + 36] > 0){
				count[in2[j] - 'A' + 36] -= 1;
				yescount += 1;
			}
			else{
				nocount += 1;
			}
		}
	}
	if (nocount == 0){
		cout << "Yes " << size1 - yescount;
	}
	else{
		cout << "No " << nocount;
	}



	return 0;
}