#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>//to avoid the strcmp error
using namespace std;
struct info{
	char name[10];
	int age, wealth;
};
vector<info> vt,v;
vector<int> label;
bool cmp(info &a, info &b){
	if (a.wealth != b.wealth){
		return a.wealth > b.wealth;
	}
	else if (a.age != b.age){
		return a.age < b.age;
	}
	else{
		return (strcmp(a.name, b.name) < 0);
	}
}
int main(){
	int n, k, num, ageMax, ageMin;
	scanf_s("%d %d", &n, &k);
	label.resize(201, 0);
	info temp;
	for (int i = 0; i < n; i++)
	{
		//when input string or charType Arr,should add buff size
		//'10' should be removed when submitting the code to PAT
		scanf_s("%s %d %d", temp.name, 10, &temp.age, &temp.wealth);
		vt.push_back(temp);
	}
	sort(vt.begin(), vt.end(), cmp);
	//pruning should after sort
	for (int i = 0; i < vt.size(); i++)
	{
		if (label[vt[i].age] < 100){
			label[vt[i].age]++;
			v.push_back(vt[i]);
		}
	}
	int m, count;
	for (int j = 0; j < k; j++)
	{
		count = 0;
		scanf_s("%d %d %d", &m, &ageMin, &ageMax);
		printf("Case #%d:\n", j + 1);
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].age <= ageMax && v[i].age >= ageMin && count < m){
				printf("%s %d %d\n", v[i].name, v[i].age, v[i].wealth);
				count++;
			}
		}
		if (count == 0){
			printf("None\n");
		}
	}
	return 0;
}