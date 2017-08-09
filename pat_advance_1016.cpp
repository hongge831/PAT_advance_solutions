#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct info{
	string name;
	string time;
	string status;
};

void initToll(int toll[]){
	for (int i = 0; i < 24; i++)
	{
		cin >> toll[i];
	}
}
void inputV(vector<info> &v){
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i].name;
		cin >> v[i].time;
		cin >> v[i].status;
	}
}
//this template function must have two return result
bool cmp(const info &a, const info &b){
	if (strcmp(a.name.c_str(), b.name.c_str()) > 0){
		return true;
	}
	else if (strcmp(a.name.c_str(), b.name.c_str()) == 0){
		if (strcmp(a.time.c_str(), b.time.c_str()) < 0){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
		
}
bool cmp2(const info &a, const info &b){
	if (strcmp(a.name.c_str(), b.name.c_str()) < 0){
		return true;
	}
	else if (strcmp(a.name.c_str(), b.name.c_str()) == 0){
		if (strcmp(a.time.c_str(), b.time.c_str()) < 0){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}

}
int computeDT(int dd,int hour,int min,int dd2,int hour2,int min2){
	return (dd2 - dd) * 24 * 60 + (hour2 - hour) * 60 + min2 - min;

}
float computeMN(int toll[], int dd, int hour, int min, int dd2, int hour2, int min2){
	return 0.0;
}
int main(){
	int toll[24];
	initToll(toll);
	int n; cin >> n;
	vector<info> v(n);
	vector<info> v2;
	inputV(v);
	sort(v.begin(),v.end(),cmp);
	int bef = n-1, last = n-1;
	int month, dd, hour, min, month2, dd2, hour2, min2;
	while (bef > 0){
		while (v[last].status != "off-line" && last>0){
			last--;
		}bef = last - 1;
		if (bef>0&&v[bef].name == v[last].name && v[bef].status == "on-line"){
			v2.push_back(v[bef]);
			v2.push_back(v[last]);
			last = bef - 1;
		}
		else{
			bef--;
		}
	}sort(v2.begin(), v2.end(), cmp2);
	int diffmin;
	float sum = 0.0,money=0;
	bool flag = true;
	for (int i = 0; i < v2.size(); i+=2)
	{
		sscanf_s(v2[i].time.c_str(), "%d:%d:%d:%d", &month, &dd, &hour, &min);
		sscanf_s(v2[i+1].time.c_str(), "%d:%d:%d:%d", &month2, &dd2, &hour2, &min2);
		diffmin = computeDT(dd,hour,min,dd2,hour2,min2);
		money = computeMN(toll, dd, hour, min, dd2, hour2, min2);
		sum += money;
		if (flag){
			printf("%s %02d\n", v2[i].name.c_str(), month);
			flag = false;
		}
		
		printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", dd, hour, min, dd2, hour2, min2, diffmin, money);
		if ((i + 2) < v2.size()){
			if (v2[i + 2].name != v2[i].name){
				printf("Total amount: %.2f\n", sum);
				flag = true;
			}
		}
	}


	
	return 0;
}