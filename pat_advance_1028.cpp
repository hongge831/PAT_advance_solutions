#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct stuData{
	int id;
	string name = "";
	int score;
};
bool cmp1(stuData &a, stuData &b){
	return a.id < b.id;
}
/*pay attention to the compare of name it should be <= rather than <*/
bool cmp2(stuData &a, stuData &b){
	return a.id != b.id ? a.name <= b.name : a.id > b.id;
}
bool cmp3(stuData &a, stuData &b){
	return a.score != b.score ? a.score < b.score : a.id < b.id;
}
int main(){
	int n, c;
	cin >> n >> c;
	stuData temp;
	vector<stuData> v;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &temp.id);
		cin >> temp.name;
		scanf_s("%d", &temp.score);
		v.push_back(temp);
	}
	switch (c)
	{
	case 1:sort(v.begin(), v.end(), cmp1); break;
	case 2:sort(v.begin(), v.end(), cmp2); break;
	case 3:sort(v.begin(), v.end(), cmp3); break;
	}
	for (int i = 0; i < v.size(); i++)
	{
		printf("%06d %s %d\n", v[i].id, v[i].name.c_str(), v[i].score);
	}

	return 0;
}