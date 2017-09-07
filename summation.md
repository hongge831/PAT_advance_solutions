
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

### [1018. Public Bike Management (30)](https://www.patest.cn/contests/pat-a-practise/1018)
　　刷了这么些题目了，我感觉自己的思维还是没有很好的得到转变。这道题用到了dijkstra&dfs&回溯，关键点是如何记录**多条**最短路径，并逐条分析需要带回或者送出的自行车数量。**多条最短路的记录，在DFS中体现，有点难理解**，其实就是对递归算法的理解，画图，一定要画图帮助理解！**另外**，这里的零结点是不存储书记的，所以在添加权重的时候一定要从1开始循环。就说到这，上代码！
```c++
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
#define inf 99999999
#define M 501
vector<int> weigh(M), dis(M), preMark[M], pathTemp, path;
vector<bool> visit(M);
vector<vector<int>> edge(M, vector<int>(M, inf));
int minIn = inf, minOut = inf;
void dfs(int sp){
	if (sp == 0){
		pathTemp.push_back(sp);
		int needOut = 0, takeIn = 0;
		for (int i = pathTemp.size() - 1; i >= 0; i--)
		{
			int id = pathTemp[i];
			if (weigh[id] > 0){
				takeIn += weigh[id];
			}
			else{
				if (takeIn > (0 - weigh[id])){
					takeIn += weigh[id];
				}
				else{
					needOut += ((0 - weigh[id]) - takeIn);
					takeIn = 0;
				}
			}
		}
		if (needOut < minOut){
			minOut = needOut;
			minIn = takeIn;//this point is important
			path = pathTemp;
		}
		else if (needOut == minOut && takeIn<minIn){
			minIn = takeIn;
			path = pathTemp;
		}
		pathTemp.pop_back();
		return;
	}
	/*excellent method should be undstood deeply*/
	pathTemp.push_back(sp);
	for (int i = 0; i < preMark[sp].size(); i++)
	{
		dfs(preMark[sp][i]);
	}
	pathTemp.pop_back();
}
int main(){
	/*data input*/
	int cmax, n, sp, m;
	cin >> cmax >> n >> sp >> m;
	/*How many things are needed for each point.*/
	for (int i = 1; i <= n; i++)//i begins from 1!!!!!!!!!!!!
	{
		cin >> weigh[i];
		weigh[i] = weigh[i] - cmax / 2;
	}
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		edge[a][b] = c;
		edge[b][a] = c;
	}
	/*dijkstra begin*/
	fill(visit.begin(), visit.end(), false);
	fill(dis.begin(), dis.end(), inf);
	dis[0] = 0;
	for (int i = 0; i <= n; i++)
	{
		int u = -1, min = inf;
		/*find the min dis_loc*/
		for (int j = 0; j <= n; j++)
		{
			if (visit[j] == false && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		/*do not find point*/
		if (u == -1){
			break;
		}
		visit[u] = true;
		for (int v = 0; v <= n; v++)
		{
			if (edge[u][v] != inf && visit[v] == false){
				if (dis[v] > dis[u] + edge[u][v]){
					dis[v] = dis[u] + edge[u][v];
					preMark[v].clear();
					preMark[v].push_back(u);
				}
				else if (dis[v] == dis[u] + edge[u][v]){
					preMark[v].push_back(u);
				}
			}
		}
	}
	/*dijkstra end*/
	/*dfs begin*/
	dfs(sp);
	/*final reault is stored in the path*/
	printf("%d ",minOut);
	printf("0");
	for (int i = path.size()-2; i >=0; i--)
	{
		printf("->%d",path[i]);
	}
	printf(" %d", minIn);
	return 0;
}
```

### [1022. Digital Library (30)](https://www.patest.cn/contests/pat-a-practise/1022)

　　这道题我想法还是很巧妙的，需要把每一个相关的query和ID关联起来，所以只需要把输入的每个属性作为map的key即可。**另外，很重要的一点是，如果以后用到函数应用，参数一定要用引用类型，否则容易超时**
```c++
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
map<string, set<int>> title, author, keyword, publisher, year;
//这里一定要用引用类型，否则超时，学到了！！
void query(map<string, set<int>> &mp, string &str){
	set<int>::iterator it;
	if (mp.find(str) != mp.end()){
		for (it = mp[str].begin(); it != mp[str].end(); it++)
		{
			printf("%07d\n",*it);
		}
	}
	else{
		printf("Not Found\n");
	}
}
int main(){
	int n, id;
	string inTitle, inAuthor, inKeyword, inPublisher, inYear;
	char c;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> id;
		getchar();
		getline(cin, inTitle);
		title[inTitle].insert(id);
		getline(cin, inAuthor);
		author[inAuthor].insert(id);
		while (cin >> inKeyword){
			keyword[inKeyword].insert(id);
			c = getchar();
			if (c == '\n') break;
		}
		getline(cin, inPublisher);
		publisher[inPublisher].insert(id);
		getline(cin, inYear);
		year[inYear].insert(id);
	}
	int m, num;
	string str;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d: ", &num);
		getline(cin, str);
		printf("%d: %s\n", num, str.c_str());
		switch (num)
		{
		case 1:
			query(title, str); break;
		case 2:
			query(author, str); break;
		case 3:
			query(keyword, str); break;
		case 4:
			query(publisher, str); break;
		case 5:
			query(year, str); break;
		}
	}

	return 0;
}
```
### [1026. Table Tennis (30)](https://www.patest.cn/contests/pat-a-practise/1026)
　　贼难，模拟题真的不适合我这种想象能力弱的人。太难了，细节很多，题目的坑也很多，21:00（含）就不营业了，这里是第一个测试点，debug好累。
```c++
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define inf 9999999999
using namespace std;
struct person{
	int	arrivTime, startTime, p;
	bool isVip = false;
};
struct tableInfo{
	int num = 0, endTime = 8 * 3600;
	bool tbVip = false;
};
bool cmp1(person &a, person &b){
	return a.arrivTime < b.arrivTime;
}
bool cmp2(person &a, person &b){
	return a.startTime < b.startTime;
}
vector<person> player;
vector<tableInfo> table;
void arrange(int i, int index){
	if (player[i].arrivTime <= table[index].endTime){
		player[i].startTime = table[index].endTime;
	}
	else{
		player[i].startTime = player[i].arrivTime;
	}
	table[index].num++;
	table[index].endTime = player[i].startTime + player[i].p;
};

int findVip(int vipIndex){
	vipIndex++;
	while (vipIndex < player.size() && player[vipIndex].isVip == false){
		vipIndex++;
	}
	return vipIndex;
}

int main(){
	int n, k, m;
	cin >> n;
	int hh, mm, ss, ptime, vipTemp;
	person personTemp;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d:%d:%d %d %d", &hh, &mm, &ss, &ptime, &vipTemp);
		personTemp.arrivTime = hh * 3600 + mm * 60 + ss;
		personTemp.startTime = 21 * 3600;
		if (personTemp.arrivTime >= 21 * 3600)
			continue;
		personTemp.p = ptime <= 120 ? ptime * 60 : 7200;//errorable
		personTemp.isVip = ((vipTemp == 1) ? true : false);

		player.push_back(personTemp);
	}
	cin >> k >> m;
	table.resize(k + 1);
	int tableNum;
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d", &tableNum);
		table[tableNum].tbVip = true;
	}
	sort(player.begin(), player.end(), cmp1);
	/*begin queuing*/
	int i = 0, vipIndex = -1;
	/*find the foremost vipIndex*/
	vipIndex = findVip(vipIndex);
	while (i < player.size()){
		int index = -1, minEndTime = inf;
		for (int j = 1; j <= k; j++)
		{
			//find the earlist table
			if (table[j].endTime < minEndTime){
				minEndTime = table[j].endTime;
				index = j;
			}
		}
		/*the club is ended*/
		if (table[index].endTime >= 21 * 3600)//errorable
			break;
		/*skip the vip who has entered the club*/
		if (player[i].isVip == true && i < vipIndex){
			i++;
			continue;

		}
		/*begin queuing by different situations*/
		if (table[index].tbVip == true){
			if (player[i].isVip == true){
				arrange(i, index);
				if (i == vipIndex){
					vipIndex = findVip(vipIndex);
				}
				i++;
			}
			else{
				if (vipIndex < player.size() && player[vipIndex].arrivTime <= table[index].endTime){
					arrange(vipIndex, index);
					vipIndex = findVip(vipIndex);
				}
				else{
					arrange(i, index);
					i++;
				}
			}
		}
		else{
			if (player[i].isVip == false){
				arrange(i, index);
				i++;
			}
			/*person is vip*/
			else{
				int vipTableIndex = -1, minVipEndTime = inf;
				for (int j = 1; j <= k; j++)
				{
					if (table[j].tbVip == true && table[j].endTime < minVipEndTime){
						minVipEndTime = table[j].endTime;
						vipTableIndex = j;
					}
				}

				if (vipTableIndex != -1 && player[i].arrivTime >= table[vipTableIndex].endTime){
					arrange(i, vipTableIndex);
					if (i == vipIndex){
						vipIndex = findVip(vipIndex);
					}
					i++;
				}
				else{
					arrange(i, index);
					if (i == vipIndex){
						vipIndex = findVip(vipIndex);
					}
					i++;
				}

			}

		}

	}
	sort(player.begin(), player.end(), cmp2);
	for (int i = 0; i < player.size() && player[i].startTime < 21 * 3600; i++)
	{
		printf("%02d:%02d:%02d ", player[i].arrivTime / 3600, player[i].arrivTime % 3600 / 60, player[i].arrivTime % 60);
		printf("%02d:%02d:%02d ", player[i].startTime / 3600, player[i].startTime % 3600 / 60, player[i].startTime % 60);
		printf("%.0f\n", round((player[i].startTime - player[i].arrivTime) / 60.0));
	}
	for (int i = 1; i <= k; i++) {
		if (i != 1)
			printf(" ");
		printf("%d", table[i].num);
	}

	return 0;
}
```
### [1030. Travel Plan (30)](https://www.patest.cn/contests/pat-a-practise/1030)
　　这道题几乎和1018一模一样，详细参考github中的代码，或者1018中的思路。考察的点在DFS&最短路&多条最短路的记录。

### [1033. To Fill or Not to Fill (25)](https://www.patest.cn/contests/pat-a-practise/1033)
　　贪心算法的应用，贪心算法不一定能达到全局最优，所以每一步都要求是最“贪婪的”。代码参考自[liuchuo](https://www.liuchuo.net/archives/2461)，我将它的代码做一个注释！
　　/*贪心思想：0.寻找比自己距离远的，到能够到达的最大距离之间的加油站，看他们的油价。如果找到了更低价格的油价，就加油到刚好能到达那个加油站的距离的油，然后去那个更低价格的加油站（有更低的我一分都不想多花在别的距离上，只加到刚好满足更低价格的加油站的距离就行，那样以后的路程我就可以以更低的价格行驶啦）
　　1.如果找不到更低的，就找尽可能低的油价的加油站，在当前加油站加满油之后过去。因为想要让路程上使用的尽可能是低价的油，既然没有比当前更低价格的了，就让油箱加到最大值，这样能保证利益最大化，保证最大的距离使用的是便宜的油。*/
```c++
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define inf 999999
using namespace std;
struct data{
	double price, dis;
};
vector<data> v;
bool cmp(data &a, data &b){
	return a.dis < b.dis;
}
int main(){
	/*data input & sort*/
	int cmax, d, davg, n;
	cin >> cmax >> d >> davg >> n;
	v.resize(n + 1);
	v[0].dis = d;
	v[0].price = 0.0;
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%lf %lf", &v[i].price, &v[i].dis);
	}
	sort(v.begin(), v.end(), cmp);
	/*begin greedy algorithm*/
	if (v[0].dis != 0){
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	else{
		double totalPrice = 0.0, nowPrice = v[0].price, nowDis = 0.0, leftDis = 0.0, maxDis = 0.0;
		while (nowDis < d){
			double minDis = 0, minPrice = inf;
			int flag = 0;//erroeable place
			maxDis = nowDis + cmax * davg;
			for (int i = 1; i <= n && v[i].dis <= maxDis; i++)
			{
				if (nowDis >= v[i].dis)continue;
				if (v[i].price < nowPrice){
					totalPrice += nowPrice * (v[i].dis - nowDis - leftDis) / davg;
					leftDis = 0.0;//fogetable
					nowDis = v[i].dis;
					nowPrice = v[i].price;
					flag = 1;
					break;
				}
				/*find the cheapest gas station*/
				if (v[i].price < minPrice){
					minPrice = v[i].price;
					minDis = v[i].dis;
				}
			}
			/*there is no station in front of nowStation*/
			if (flag == 0 && minPrice == inf){
				/*there is no need totalPrice*/
				maxDis = nowDis + cmax * davg;
				printf("The maximum travel distance = %.2lf",maxDis);
				return 0;
			}
			if (flag == 0 && minPrice != inf){
				totalPrice += (cmax - leftDis / davg)*nowPrice;
				leftDis = nowDis + cmax * davg - minDis;
				nowPrice = minPrice;
				nowDis = minDis;
			}
		}
		printf("%.2lf",totalPrice);
	}

	return 0;
}
```
### [1034. Head of a Gang (30)](https://www.patest.cn/contests/pat-a-practise/1034)
　　这道题是第一次碰到“离散化的知识点”，对于一个现实中的图如何将它化成理性模型的图方法有很多种，本题解法思路比较巧妙。**另外**此题不需要计算连通图的个数，直接对完整图遍历即可。**值得注意的一点是**边的遍历和点的遍历有很大不同，遍历后的边要将其化成inf或者0以防止少便利或者循环回路死循环的发生。
```c++
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#define M 2005
using namespace std;
map<string, int> sti, ans;
map<int, string> its;
vector<vector<int>> edge(M, vector<int>(M));
vector<int> nodeWeigh(M);
vector<bool> visit;
int NodeNum = 0, head = 0, menberNum = 0, totalWeigh = 0;
int strToInt(string &s){
	if (sti[s] == 0){
		NodeNum++;
		sti[s] = NodeNum;
		its[NodeNum] = s;//errorable:make the its Correspondence
		return sti[s];
	}
	else{
		return sti[s];
	}
}
void dfs(int v, int &head, int &menberNum, int &totalWeigh){
	visit[v] = true;
	/*deal with all variables*/
	menberNum++;
	if (nodeWeigh[v] > nodeWeigh[head]){
		head = v;
	}
	for (int u = 1; u <= NodeNum; u++)
	{
		/*it is worthing noting that edge travesal is different from the node traversal*/
		if (edge[v][u] > 0){
			totalWeigh += edge[v][u];
			edge[u][v] = edge[v][u] = 0;
			if (visit[u] == false)
				dfs(u, head, menberNum, totalWeigh);
		}
	}
}
int main(){
	int n, k;
	cin >> n >> k;
	string s1, s2;
	int w, a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2 >> w;
		/*convert the name to id number*/
		a = strToInt(s1);
		b = strToInt(s2);
		/*add all edge weight to the node*/
		nodeWeigh[a] += w;
		nodeWeigh[b] += w;
		/*sum up two edges into one,then add up all weight*/
		edge[a][b] += w;
		edge[b][a] += w;
	}
	visit.resize(NodeNum + 1, false);
	/*compute every connected_graph's head&menberNum*/
	for (int i = 1; i <= NodeNum; i++)
	{
		head = 0, menberNum = 0, totalWeigh = 0;
		if (visit[i] == false){
			dfs(i, head, menberNum, totalWeigh);
		}
		if (menberNum > 2 && totalWeigh > k){
			ans[its[head]] = menberNum;//stored the result into the ans
		}
	}
	/*print the result*/
	cout << ans.size() << endl;
	for (map<string, int>::iterator it = ans.begin(); it != ans.end(); it++)
		cout << it->first << " " << it->second << endl;
	return 0;
}
```
### [1038. Recover the Smallest Number (30)](https://www.patest.cn/contests/pat-a-practise/1038)
　　大家都说这是很妙的一道题，嗯，我也这么认为！反正我没想出来。
```c++
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
bool cmp(string a, string b){
	return a + b < b + a;
}
int main(){
	int n;
	cin >> n;
	string temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(),cmp);
	string s="";
	for (int i = 0; i < v.size(); i++)
	{
		s += v[i];
	}
	while (s.length() != 0 && s[0] == '0'){
		s.erase(s.begin());
	}
	if (s.length() == 0){
		cout << 0;
	}
	else{
		cout << s;
	}

	return 0;
}

```
### [1040. Longest Symmetric String (25)](https://www.patest.cn/contests/pat-a-practise/1040)
　　分类讨论！
```c++
#include <iostream>  
#include <string.h>  
using namespace std;   
char s[1001];  
int main() {  
    int i, j, x ,y;  
    while(gets(s)) {  
        int max  = 0;  
        for(i=0; i<strlen(s); i++) {  
            for(j=0; i-j >= 0 && i+j < strlen(s); j++) { //奇数时  
                if(s[i-j] != s[i+j])  
                    break;  
                if(j * 2 + 1 > max) {  
                    max = j * 2 + 1;  
                }  
            }  
            for(j=0; i-j >= 0 && i+j+1 < strlen(s); j++) {//偶数时  
                if(s[i-j] != s[i+j+1])  
                    break;  
                if(j * 2 + 2 > max) {  
                    max = j * 2 + 2;  
                }  
            }  
        }  
        cout<<max<<endl;  
    }  
    return 0;  
}  
```
### [1043. Is It a Binary Search Tree (25)](https://www.patest.cn/contests/pat-a-practise/1043)
　　对于递归的先序后序中序后序的遍历，理解实在有点小困难，所以遇到这类题目首先想到的肯定不是建一棵树而是根据三者的关系进行推敲，特别是对于样例要进行对比理解。
```c++
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> post, pre;
bool isMirror = false;
void computePost(int root, int tail){
	if (root > tail)
		return;
	int i = root + 1, j = tail;
	if (!isMirror){
		for (; i <= tail && pre[i] < pre[root]; i++);
		for (; j > root && pre[j] >= pre[root]; j--);
	}
	else{
		for (; i <= tail && pre[i] >= pre[root]; i++);
		for (; j > root && pre[j] < pre[root]; j--);
	}
	if (i - j != 1)
		return;
	computePost(root + 1, j);
	computePost(i, tail);
	post.push_back(pre[root]);
}
int main(){
	int n;
	cin >> n;
	pre.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &pre[i]);
	}
	computePost(0, n - 1);
	if (post.size() != n){
		isMirror = true;
		post.clear();
		computePost(0, n - 1);
	}
	if (post.size() != n){
		printf("NO");
	}
	else{
		printf("YES\n");
		printf("%d", post[0]);
		for (int i = 1; i < n; i++)
		{
			printf(" %d", post[i]);
		}
	}
	return 0;
}
```
### [1044. Shopping in Mars (25)](https://www.patest.cn/contests/pat-a-practise/1044)
　　对于二分法查找数据的中心点mid更新问题，今天有了新的认识。以前都是将mid更新为left+1或者right+1，这当然没什么问题对于单纯的查找元素来说。但是，如果针对1044这道题来说，如果我们的情况是：只要求找到>=m的位置，那么mid在向右更新时需要将min更新为right而不是right+1，否则将可能出现找不到>=m的位置。
```c++
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v, result;
int mmin, m;
int findValue(int i, int &right){
	int left = i;
	while (left < right){
		int mid = (left + right) / 2;
		if (v[mid] - v[i - 1] >= m){
			right = mid;//errorable place, it's different from finding value
		}
		else{
			left = mid + 1;
		}
	}
	return v[right] - v[i - 1];
}
int main(){
	/*data input*/
	int n, temp, sum = 0;
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &temp);
		sum += temp;
		v[i] = sum;
	}
	/*algorithm begin*/
	int j, res = 0;
	mmin = v[n];//OR set the mmin's initial value >10^e8
	for (int i = 1; i <= n; i++)
	{
		j = n;
		res = findValue(i, j);//binary search
		if (res >= m){
			if (res > mmin)//remove the res that larger than mmin
				continue;
			if (res < mmin){
				mmin = res;
				result.clear();
			}
			result.push_back(i);
			result.push_back(j);
		}
	}
	/*print result*/
	for (int i = 1; i < result.size(); i += 2)
	{
		printf("%d-%d\n", result[i - 1], result[i]);
	}
	return 0;
}
```
### [1045. Favorite Color Stripe (30)](https://www.patest.cn/contests/pat-a-practise/1045)
　　这是一道动态规划的题目，今天下午（2017年9月1日）把动态规划典型的面试题也顺带学习了一下，不禁感叹动态规划实在太厉害了。本题是动态规划最为简单的一种形式（求最大递增子列长度）。所以思路也就显而易见了，只需要把颜色按照顺序重新编号，剔除给定序列中不包含想要序列中的颜色并且重新编号。然后按照顺序求最大子列长度。
```c++
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int color[201];
vector<int> v,dp;
int main(){
	int n, m, l;
	cin >> n >> m;
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
```
### [1049. Counting Ones (30)](https://www.patest.cn/contests/pat-a-practise/1049)
　　数1的题目在《编程之美》也有讲到。

　　根据上面的一些尝试，下面我们推导出一般情况下，从N得到f（N）的计算方法：

　　假设N=abcde，这里a、b、c、d、e分别是十进制数N的各个数位上的数字。如果要计算百位上出现1的次数，它将会受到三个因素的影响：百位上的数字，百位以下（低位）的数字，百位（更高位）以上的数字。

　　如果百位上的数字为0，则可以知道，百位上可能出现1的次数由更高位决定，比如12 013，则可以知道百位出现1的情况可能是100～199，1 100～1 199，2 100～2 199，…，11 100~11 199，一共有1 200个。也就是由更高位数字（12）决定，并且等于更高位数字（12）×当前位数（100）。

　　如果百位上的数字为1，则可以知道，百位上可能出现1的次数不仅受更高位影响，还受低位影响，也就是由更高位和低位共同决定。例如对于12 113，受更高位影响，百位出现1的情况是100～199，1 100～1 199，2 100～2 199，…，11 100~11 199，一共1 200个，和上面第一种情况一样，等于更高位数字（12）×当前位数（100）。但是它还受低位影响，百位出现1的情况是12 100～12 113，一共14个，等于低位数字（13）+1。

　　如果百位上数字大于1（即为2~9），则百位上可能出现1的次数也仅由更高位决定，比如12 213，则百位出现1的可能性为：100～199，1 100～1 199，2 100～2 199，…，11 100～11 199，12 100～12 199，一共有1 300个，并且等于更高位数字+1（12+1）×当前位数（100）。AC代码：
```c++
#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int right = 0, left = 0, cur, a = 1, ans = 0;
	while (n / a){
		left = n / (a * 10);
		right = n%a;
		cur = n / a % 10;
		if (cur == 0){
			ans += left*a;
		}
		else if (cur == 1){
			ans += left*a + right + 1;
		}
		else{
			ans += (left + 1)*a;
		}
		a *= 10;
	}
	cout << ans;
	return 0;
}
```
### [1053. Path of Equal Weight (30)](https://www.patest.cn/contests/pat-a-practise/1053)
　　方法类似1018和1030。
### [1058. A+B in Hogwarts (20)](https://www.patest.cn/contests/pat-a-practise/1058)
　　这道题涉及**树状数组**，相当厉害的一种数据结构。对于理解，一定要把图和测试用例结合起来理解。
　　分析：用排序查询的方法会超时！用树状数组，即求第k = (s.size() + 1) / 2大的数。查询小于等于x的数的个数是否等于k的时候用二分法更快~
```c++
#include <stdio.h>
#include <iostream>
#include <stack>
#define M 100001
#define lowbit(i) i&(-i)
using namespace std;
int c[M];
stack<int> s;
void update(int index, int v){
	for (int i = index; i < M; i += lowbit(i))
	{
		c[i] += v;
	}
}
int getSum(int index){
	int sum = 0;
	for (int i = index; i >0; i-=lowbit(i))
	{
		sum += c[i];
	}
	return sum;
}
void peek(){
	int left = 0, right = M, mid, k = (s.size() + 1) / 2;
	while (left<right){
		mid = (left + right) / 2;
		if (getSum(mid) >= k){
			right = mid;
		} else{
			left = mid + 1;
		}
	}
	printf("%d\n",left);
}

int main(){
	int n, value;
	char str[10];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%s", str, 10);
		/*if str == "pop","push","peekmedian"*/
		if (str[1] == 'u'){
			scanf_s("%d", &value);
			s.push(value);
			update(value, 1);
		}
		else if (str[1] == 'o'){
			if (!s.empty()){
				printf("%d\n", s.top());
				update(s.top(), -1);
				s.pop();
			}
			else{
				printf("Invalid\n");
			}
		}
		else{
			if (!s.empty()){
				peek();
			}
			else{
				printf("Invalid\n");
			}
		}
	}
	return 0;
}
```
