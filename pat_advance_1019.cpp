#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> v){
	if (v.size() > 0){
		cout << v[v.size()-1];
		for (int i = v.size() - 2; i >=0; i--)
		{
			cout << ' ' << v[i];
		}
	}
}
int main(){
	int n1,n, b;
	cin >> n1 >> b;
	n = n1;
	vector<int> v;
	while (n){
		v.push_back(n%b);
		n /= b;
	}
	int i = 0, j = v.size()-1;
	for (; i <= j; i++, j--)
	{
		if (v[i] != v[j])
			break;
	}
	if (i <= j){
		printf("No\n");
		print(v);
	}
	else{
		printf("Yes\n");
		if (n1 == 0){
			cout << '0';//如果是0输出零
		}
		print(v);
	}

	return 0;
}
