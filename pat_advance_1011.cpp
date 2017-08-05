#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	char c[3] = { 'W', 'T', 'L' };
	float max[3] = { 0.0 };
	float temp;
	int k = 0, loc = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> temp;
			if (max[k] < temp){
				max[k] = temp;
				loc = j;
			}
		}
		cout << c[loc] << ' ';
		k++;
	}
	temp = (max[0] * max[1] * max[2]*0.65 - 1) * 2;
	printf("%.2f",temp);


	return 0;
}