#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int sum = 0,before = 0, after;
	for (int i = 0; i < n; i++)
	{
		cin >> after;
		if (after > before){
			sum += (after - before) * 6 + 5;
		}
		else{
			sum += (before - after) * 4 + 5;
		}
		before = after;
	}
	cout << sum;
	return 0;
}
