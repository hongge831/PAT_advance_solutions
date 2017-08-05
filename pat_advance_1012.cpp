#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int flag = -1;
//if the question relate to search in big scale ,array is one of the best choice
int searchArr[10000000] = { 0 };
char searchArr2[10000000] = { ' ' };
char c[4] = { 'A', 'C', 'M', 'E' };
struct info{
	int id;
	int socre[4];
	int rank[4];
};
bool cmp(const info a, const info b){
	return a.socre[flag] > b.socre[flag];
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<info> v(n);
	/*input the data*/
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].id;
		for (int j = 0; j < 3; j++)
		{
			cin >> v[i].socre[j + 1];
			sum += v[i].socre[j + 1];
		}
		v[i].socre[0] = (sum) / 3 + 0.5;//round the average
		sum = 0;
	}
	/*compute the rank of each subject*/
	for (int i = 0; i < 4; i++)
	{
		flag = i;
		sort(v.begin(), v.end(), cmp);
		v[0].rank[i] = 1;
		for (int j = 1; j < n; j++)
		{
			//if the same sore, skip the same rank
			if (v[j].socre[i] != v[j - 1].socre[i]){
				v[j].rank[i] = j + 1;
			}
			else{
				v[j].rank[i] = v[j - 1].rank[i];
			}
		}
	}
	/*prepare the search operation*/
	int best = n + 1, loc = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//find the best rank by the order of A C M E
			if (v[i].rank[j] < best){
				best = v[i].rank[j];
				loc = j;
			}
			else if (v[i].rank[j] == best){
				if (j < loc){
					loc = j;
				}
			}
		}
		searchArr[v[i].id] = best;
		searchArr2[v[i].id] = c[loc];
		//this step is most forgetable, be careful!!
		best = n + 1;
		loc = 0;
	}
	/*search the result*/
	int searchId;
	for (int i = 0; i < m; i++)
	{
		cin >> searchId;
		if (searchArr[searchId] == 0){
			printf("N/A\n");
		}
		else{
			printf("%d %c\n", searchArr[searchId], searchArr2[searchId]);
		}
	}
	return 0;
}