#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct data{
	int cTim, pTime;
};
bool cmp(data a, data b){
	return a.cTim < b.cTim;
}
int main(){
	int n, k;
	cin >> n >> k;
	vector<data> v;
	vector<int> windows(k, 28800);
	data temp;
	int hour, min, sec, p, totalTime;
	int waitTime = 0;
	/*input data match the requirment*/
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d:%d:%d %d", &hour, &min, &sec, &p);
		if (p > 60)
			p = 60;
		totalTime = hour * 3600 + min * 60 + sec;
		if (totalTime > 61200)
			continue;
		temp.cTim = totalTime;
		temp.pTime = p*60;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	/*begin operation*/
	int index = 0;
	while (index < v.size()){
		int minTime = windows[0], minNum = 0;
		/*find the minimun window*/
		for (int i = 1; i < k; i++)
		{
			if (minTime > windows[i]){
				minTime = windows[i];
				minNum = i;
			}
		}
		if (v[index].cTim < windows[minNum]){
			waitTime += windows[minNum] - v[index].cTim;
			windows[minNum] += v[index].pTime;
		}
		else{
			windows[minNum] = v[index].cTim + v[index].pTime;
		}
		index++;

	}
	if (waitTime == 0){
		printf("0.0\n");
	}
	else{
		printf("%.1f", waitTime / 60.0 / v.size());
	}
	return 0;
}