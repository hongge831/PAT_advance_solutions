#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int toll[25] = { 0 };//the additional one refer to the sum of others
struct data{
	string name;
	int month, day, hour, min, status, totalTime;
};
bool cmp(data a, data b){
	return a.name != b.name ? a.name < b.name : a.totalTime < b.totalTime;
}
float computeMoney(data a){
	float re = 0.0;
	re += a.day * 60 * toll[24] + toll[a.hour] * a.min;
	for (int i = 0; i < a.hour; i++)
	{
		re += toll[i]*60;
	}
	return re / 100;
}
int main(){
	/*initialize the toll arr*/
	for (int i = 0; i < 24; i++)
	{
		cin >> toll[i];
		toll[24] += toll[i];
	}
	/*input the information of customer's active*/
	int n;
	string temp;
	cin >> n;
	vector<data> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].name;
		scanf_s("%d:%d:%d:%d", &v[i].month, &v[i].day, &v[i].hour, &v[i].min);
		v[i].totalTime = v[i].day * 24 * 60 + v[i].hour * 60 + v[i].min;
		cin >> temp;
		v[i].status = temp == "on-line" ? 1 : 0;
	}
	/*sort the customer's arr*/
	sort(v.begin(), v.end(), cmp);
	/*select the right combination insert the map*/
	map<string, vector<data>> mp;
	map<string, vector<data>>::iterator it;
	for (int i = 1; i < n; i++)
	{
		if (v[i - 1].name == v[i].name &&v[i - 1].status == 1 && v[i].status == 0){
			mp[v[i - 1].name].push_back(v[i - 1]);
			mp[v[i - 1].name].push_back(v[i]);
		}
	}
	float t = 0.0, totalMoney = 0.0;
	int time;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		printf("%s %02d\n", it->first.c_str(), it->second[0].month);
		for (int i = 0; i < it->second.size(); i += 2)
		{
			time = it->second[i + 1].totalTime - it->second[i].totalTime;
			t = computeMoney(it->second[i + 1]) - computeMoney(it->second[i]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", it->second[i].day, it->second[i].hour, it->second[i].min, it->second[i + 1].day, it->second[i + 1].hour, it->second[i + 1].min, time, t);
			totalMoney += t;
		}
		printf("Total amount: $%.2f\n", totalMoney);
		totalMoney = 0.0;

	}
	return 0;
}