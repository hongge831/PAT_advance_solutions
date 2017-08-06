#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct info{
	int id;
	int needtime;
};
int main(){
	int n, m, k, q;
	cin >> n >> m >> k >> q;//m is the queue's largest size
	vector<queue<info>> vq(n);//number of bank windows
	vector<int> v(k + 1, 0);//every customer's depart time
	vector<int> loc;
	int cnt = 1;
	info temp;
	/*make every queue full*/
	while (vq[0].size() < m){
		for (int i = 0; i < n; i++)
		{
			if (cnt < k){
				cin >> temp.needtime;
				temp.id = cnt++;
				vq[i].push(temp);
			}
		}
	}
	/*simulate the procedure of forming line*/

	int min = 99999, minlast = 0;
	for (int i = 0; i < n; i++)
	{
		if (vq[i].front().needtime < min){
			min = vq[i].front().needtime;
			loc.push_back(i);
		}
	}
	for (int i = 0; i < loc.size(); i++)
	{
		v[loc[i]] = min + minlast;
		vq[loc[i]].pop();
	}
	minlast = min;





	return 0;
}
