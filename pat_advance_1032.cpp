#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
struct data{
	char c;
	int next;
	bool flag = false;//magic step
};
vector<data> v(100001);
int main(){
	int n1, n2, n, a, b;
	cin >> n1 >> n2 >> n;
	data temp;
	char cdata;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %c %d", &a, &cdata, &b);
		v[a].c = cdata;
		v[a].next = b;
	}
	while (n1 != -1){
		v[n1].flag = true;
		n1 = v[n1].next;
	}
	while (n2 != -1){
		if (v[n2].flag == true){
			printf("%05d", n2);
			return 0;
		}n2 = v[n2].next;
	}
	printf("-1");
	return 0;

}