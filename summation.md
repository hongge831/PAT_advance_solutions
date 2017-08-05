
# PAT_Advance_Practice Summation By YFF #

### [1003. Emergency (25)](https://www.patest.cn/contests/pat-a-practise/1003)


　　这道题是典型的Dijkstra算法的练习，思路比较常规。最短路径不止一条时需要对路径条数进行另外处理。
```C
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define inf 99999999
#define M 501//大小定义与系统堆栈有关
using namespace std;
int  edg[M][M];//这里涉及的空间数量比较大故需要定义为全局变量存储在系统数据区，避免运行时系统堆栈溢出
int main(){
	int n, m, c1, c2;//点数，边数，起点，终点
	/*定义边集，距离集，某点最短路径的条数，点上的权重，任一点权重之和*/
	int dis[M], num[M], dotw[M], dotsum[M], path[M];//此题不需要path，但是为了联系加上path
	bool col[M];//初始值是true
	cin >> n >> m >> c1 >> c2;
	/*根据条件初始化各矩阵*/
	fill(edg[0], edg[0] + M*M, inf);//初始化图边集
	fill(dis, dis + M, inf);//初始化最小距离数组
	fill(num, num + M, 0);
	fill(dotw, dotw + M, 0);
	fill(path, path + M, -1);
	fill(col, col + M, false);
	//初始化点的权重
	for (int i = 0; i < n; i++)
	{
		cin >> dotw[i];
	}
	//初始化边矩阵（带权边）
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		edg[b][a] = c;
		edg[a][b] = c;
	}
	/*dis,num,dotsum,path初始化*/
	dis[c1] = 0;
	num[c1] = 1;//自己到自己算一种走法
	dotsum[c1] = dotw[c1];
	while (true)
	{
		int u = -1, min = inf;
		for (int j = 0; j < n; j++)
		{
			if (col[j] == false && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		//找不到退出循环，算法结束
		if (u == -1)
			break;
		col[u] = true;
		for (int v = 0; v < n; v++)
		{
			if (col[v] == false && edg[u][v] != inf){
				if (dis[u] + edg[u][v] < dis[v]){
					dis[v] = dis[u] + edg[u][v];
					path[v] = u;
					dotsum[v] = dotsum[u] + dotw[v];
					num[v] = num[u];
				}
				//如果相等则dis和path都不用变直接使得num中对应的点数量加1，且选一个比较大的dotsum留下来
				else if (dis[u] + edg[u][v] == dis[v]){
					num[v] = num[u] + num[v];
					if (dotsum[u] + dotw[v] > dotsum[v]){
						dotsum[v] = dotsum[u] + dotw[v];
					}

				}
			}

		}
	}
	cout << num[c2] << ' ' << dotsum[c2];
	return 0;
}
```
### **[1010. Radix (25)](https://www.patest.cn/contests/pat-a-practise/1010)**

　　这道题真的真的好多坑，测试点居然有19个，简直丧心病狂。我目前才得15分，继续努力，经过好久的努力终于AC了，感谢网友，尴尬！！**另外我以后写代码将用英语注释，装逼的同时锻炼一下英语表达能力，大神勿喷。**

　　=======贴出两个思路地址，我只参考了思路没有参考代码。 [地址一](http://blog.csdn.net/by21010/article/details/50683247)  [地址二](http://blog.csdn.net/baidu_25107219/article/details/46700669)


```c++
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int map[200];
int findLargestNum(string str){
	int re = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (re < map[str[i]]){
			re = map[str[i]];
		}
	}return re + 1;
}
long long convertToDecimal(string str, long long radix){
	long long d = 1, re = 0;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		re += map[str[i]] * d;
		d *= radix;
	}
	return re;
}

long long binarySearch(long long low, long long high, string n2, long long t){
	long long mid, res = -1;
	while (low <= high){
		mid = (low + high) / 2;
		long long num2 = convertToDecimal(n2, mid);
		if (num2 < 0 || num2 > t){
			mid -= 1;
			high = mid;
		}
		else if (num2 < t){
			mid += 1;
			low = mid;
		}
		else if (num2 == t){
			return mid;//there doesn't exit any more 'mid' when num2==t, there is only one,so return the re directly
		}
	}
	return res;

}

int main(){
	/*read in the input data*/
	long long tag, radix;
	string n1, n2;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2)swap(n1, n2);
	/*initialize the arr map[]*/
	for (char c = '0'; c <= 'z'; c++)
	{
		if (c <= '9'&&c >= '0'){
			map[c] = c - '0';
		}
		else if (c <= 'z'&&c >= 'a'){
			map[c] = c - 'a' + 10;
		}
	}
	/*compute the lowest radix of n2*/
	long long low;
	low = findLargestNum(n2);
	/*convert the n1 to decimal number*/
	long long t, high;//n1's decimal number is the highest radix of n2 when n2 is a two digit number
	t = convertToDecimal(n1, radix);
	high = max(t, low) + 1;//
	/*binary search for the matched radix for n2*/
	long long result;
	result = binarySearch(low, high, n2, t);

	/*print the result*/
	if (result == -1){
		printf("Impossible\n");
	}
	else{
		printf("%ld\n", result);
	}
	return 0;
}
```

### [1012. The Best Rank (25)](https://www.patest.cn/contests/pat-a-practise/1012)
　　这道题关于排序需要注意几个细节，第一若排名相同的情况下一定要根据题意确定有无并列。比如，只能出现排名为1 1 3 4的情况。另外遇到这种复杂的排序题一定要使用sort算法更加简便。
```c++
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
```
### [1013. Battle Over Cities (25)](https://www.patest.cn/contests/pat-a-practise/1013)

　　这也是一道典型的关于图遍历的题目，和之前两道（1003和1004）相比，这道题更加贴近原始的图遍历算法。如果将树也看作为一种特殊的图结构，那么树结构更适合用于链接表的存储方式，而图更加适合连接矩阵的存储方式。dfs的算法还需多联系。**另外**值得关注的点是有时候用**全局变量**会使得代码变短，但是调试的不能看到全局变量的变化情况。
```c++
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void dfs(int i, vector<vector<int>> &v, vector<bool> &isVisit){
	int size = v[1].size();
	isVisit[i] = true;
	for (int j = 0; j < size; j++)
	{
		if (v[i][j] != 0 && isVisit[j] == false){
			dfs(j, v, isVisit);
		}
	}

}
int main(){
	int n, m, k;//n:total numbers of cities;m:numbers of roads;k:numbers of cities should be checked
	cin >> n >> m >> k;
	vector<vector<int>> v(n+1, vector<int>(n+1, 0));
	vector<bool> isVisit(n+1, false);
	int a, b;//the location of city in the map
	/*initialize the map*/
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}
	/*DFS*/
	int point, cnt = 0;
	for (int i = 1; i <= k; i++)
	{
		cin >> point;
		isVisit[point] = true;
		for (int j = 1; j <= n; j++)
		{
			if (isVisit[j] == false){
				dfs(j, v,isVisit);
				cnt++;
			}
		}
		isVisit[point] = false;
		cout << cnt-1 << endl;
		cnt = 0;
		fill(isVisit.begin(), isVisit.end(), false);
	}


	return 0;
}
```