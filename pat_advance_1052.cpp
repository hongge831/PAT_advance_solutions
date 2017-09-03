#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct data{
	int value;
	int adr;
}v[100000], res[100004];
bool cmp(data & a, data &b){
	return a.value < b.value;
}
int main(){
	int n, addBegin;
	cin >> n >> addBegin;
	int adr, value, next;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d %d", &adr, &value, &next);
		v[adr].value = value;
		v[adr].adr = next;
	}
	int loc = addBegin, num = 0;
	data temp;
	while (true){
		temp.adr = loc;
		temp.value = v[loc].value;
		res[num++] = temp;
		if (v[loc].adr == -1 || loc==-1){
			break;
		}
		loc = v[loc].adr;
	}
	if (res[0].adr == -1){
		printf("0 -1");
		return 0;
	}
	sort(res, res + num, cmp);
	printf("%d %05d\n", num, res[0].adr);
	for (int i = 0; i < num; i++)
	{
		if (i != num - 1)
			printf("%05d %d %05d\n", res[i].adr, res[i].value, res[i + 1].adr);
		else
			printf("%05d %d %d\n", res[i].adr, res[i].value, -1);

	}
	return 0;
}