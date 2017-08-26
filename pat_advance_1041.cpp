#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> vmap(100002, 0), vin(100002, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> vin[i];
		vmap[vin[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (vmap[vin[i]] == 1){
			cout << vin[i]; return 0;
		}
	}cout << "None";
}