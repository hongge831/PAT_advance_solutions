#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int color[201];
vector<int> v,dp;//when time is sparse, use arr instead of vector, arr is time saver
int main(){
	int n, m, l;
	cin >> n >> m;//scanf is much better
	int temp;
	for (int i = 1; i <= m; i++)
	{
		scanf_s("%d",&temp);
		color[temp] = i;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		scanf_s("%d",&temp);
		if (color[temp] != 0){
			v.push_back(color[temp]);
		}
	}
	/*dynamic procedure begin*/
	dp.resize(v.size());
	int ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (v[i] >= v[j]){
				dp[i] = max(dp[j]+1,dp[i]);
			}
		}
		ans = max(ans,dp[i]);	
	}
	printf("%d",ans);
	return 0;
}