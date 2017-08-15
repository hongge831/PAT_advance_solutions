
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

### [1014. Waiting in Line (30)](https://www.patest.cn/contests/pat-a-practise/1014)

　　这种模拟类型的题目真的很烦心，没有一个很清晰的思路真的难以搞定。之前一直认为要模拟整个过程知道所有人都出队完毕。后来仔细一想觉得只要吧每个人入队完毕且计算他们的出队时间即可。这里非常值得注意的是每个信息都最好分开保存，多开个vector就多开个，思路清晰最重要，而不是以为追求精简的代码。嗯就是这样！！！**另外**针对这题有个非常值得注意的地方就是，所有人只要在17：:00之前被服务到，无论他的服务时间多长就可以！
```c++
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
```

### [1016. Phone Bills (25)](https://www.patest.cn/contests/pat-a-practise/1016)

　　这道题也是很揪心的一道题，总的来说也是一道很复杂的现实处理题。处理好每个细节很重要，特别是对map的使用特别值得记忆。
```C++
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
```
### [1017. Deepest Root (25)](https://www.patest.cn/contests/pat-a-practise/1017)

　　并查集和树的最长根应用，第一次运用并查集，学到了。另外这道题不能用邻接矩阵表示图，会超时。这里需要复习一下邻接矩阵和邻接表的DFS算法区别。写了好几次DFS感觉还是不熟练。这里给出两个并查集的参考：[地址一](http://blog.csdn.net/dellaserss/article/details/7724401/)#####[地址二](http://blog.csdn.net/u013167299/article/details/44245853)#####
```c++
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> pre;
vector<int> temp;
vector<vector<int>> v;
vector<bool> visit;
int maxHeight = 0;
void init(){
	for (int i = 0; i < pre.size(); i++)
	{
		pre[i] = i;
	}
}
/*union-find sets with path compression*/
int find(int x){
	if (x != pre[x]){
		pre[x] = find(pre[x]);
	}return pre[x];
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if (pre[x] != pre[y]){
		pre[x] = pre[y];
	}
}
/*dfs*/
void dfs(int node,int height){
	if (height > maxHeight){
		temp.clear();
		maxHeight = height;
		temp.push_back(node);
	}
	else if(height ==  maxHeight){
		temp.push_back(node);
	}
	visit[node] = true;
	for (int i = 0; i < v[node].size(); i++)
	{
		if (!visit[v[node][i]]){
			dfs(v[node][i], height + 1);
		}
	}
}

int main(){
	int n;
	cin >> n;
	pre.resize(n+1);
	v.resize(n+1);
	init();
	int a, b;
	for (int i = 1; i <= n-1; i++)
	{
		cin >> a >> b;
		merge(a, b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (pre[i] == i){
			sum++;
		}
	}
	if (sum > 1){
		printf("Error: %d components", sum);
	}
	else{
		visit.resize(n+1,false);
		set<int> st;
		dfs(1, 1);
		for (int i = 0; i < temp.size(); i++)
		{
			st.insert(temp[i]);
		}
		int s = temp[0];
		temp.clear(); maxHeight = 0; fill(visit.begin(), visit.end(), false);
		dfs(s, 1);
		for (int i = 0; i < temp.size(); i++)
		{
			st.insert(temp[i]);
		}
		for (set<int>::iterator it = st.begin(); it != st.end(); it++)
			printf("%d\n", *it);
	}

	return 0;
}

```

### [1022. Digital Library (30)](https://www.patest.cn/contests/pat-a-practise/1022)

　　这道题我想法还是很巧妙的，需要把每一个相关的query和ID关联起来，所以只需要把输入的每个属性作为map的key即可。