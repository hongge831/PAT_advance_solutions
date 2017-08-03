
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