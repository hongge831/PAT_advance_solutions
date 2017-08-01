#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
struct info{
	string id="";
	int ulock;
	int lock;
};
int main(){
	int n;
	cin >> n;
	int hour, min, sec,total;
	info maxId, minId,temp;
	minId.ulock = 86400;
	maxId.lock = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp.id;
		scanf_s("%d:%d:%d",&hour,&min,&sec);
		total = hour * 3600 + min * 60 + sec;
		if (total < minId.ulock){
			minId.id = temp.id;
			minId.ulock = total;
		}
		scanf_s("%d:%d:%d", &hour, &min, &sec);
		total = hour * 3600 + min * 60 + sec;
		if (total > maxId.lock){
			maxId.id = temp.id;
			maxId.lock = total;
		}
	}
	cout << minId.id << ' ' << maxId.id << endl;

	return 0;
}