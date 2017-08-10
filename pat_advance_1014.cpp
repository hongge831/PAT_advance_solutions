#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct winQueue {
	int popTime = 0, endTime = 0;//the first person end service time & last person end service time
	queue<int> qu;
};
int main(){
	int n, m, k, q, index = 1;
	cin >> n >> m >> k >> q;
	vector<int> Time(k + 1);
	vector<winQueue> windows(n + 1);
	vector<int> result(k + 1, 0);
	vector<bool> isSorry(k + 1, false);
	for (int i = 1; i <= k; i++)
	{
		cin >> Time[i];
	}
	/*initialize the queue inside the yellow line*/
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (index <= k){
				windows[j].qu.push(Time[index]);
				//time of first one in each queue is the popTime
				if (i == 1){
					windows[j].popTime = Time[index];
				}
				/*there should be very careful,when anyone can be served if thire start serve time is before 17.00*/
				/*so the first one must be served even its time more than 540,before the first one push into the queue*/
				/*the endtime of queue is zero*/
				if (windows[j].endTime >= 540){
					isSorry[index] = true;
				}
				windows[j].endTime += Time[index];
				result[index] = windows[j].endTime;
				index++;
			}
		}
	}

	/*if k>m*n we should take the additional people into consideration*/
	while (index <= k){
		int minPopTime = windows[1].popTime, minNumWin = 1;
		/*find the minimun popTime then pop it*/
		for (int i = 2; i <= n; i++)
		{
			if (windows[i].popTime < minPopTime){
				minPopTime = windows[i].popTime;
				minNumWin = i;
			}
		}
		/*pop & push operation*/
		windows[minNumWin].qu.pop();
		windows[minNumWin].popTime += windows[minNumWin].qu.front();//update the popTime
		windows[minNumWin].qu.push(Time[index]);
		if (windows[minNumWin].endTime >= 540){
			isSorry[index] = true;
		}windows[minNumWin].endTime += Time[index];
		result[index] = windows[minNumWin].endTime;
		index++;
	}
	/*query the result*/
	int temp;
	for (int i = 0; i < q; i++)
	{
		cin >> temp;
		if (isSorry[temp] == true){
			printf("Sorry\n");
		}
		else{
			printf("%02d:%02d\n", result[temp] / 60 + 8, result[temp] % 60);
		}
	}
	return 0;
}