#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
using namespace std;
map<int, set<int>> mp;
int getid(char *name) {
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = 26 * id + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}
int main(){
	int n, k;
	//cin >> n >> k;
	scanf_s("%d %d", &n, &k);
	//string name;
	char name[5];
	int index, num, id;
	for (int i = 0; i < k; i++)
	{
		//cin >> index >> num;
		scanf_s("%d %d", &index, &num);
		for (int i = 0; i < num; i++)
		{
			//cin >> name;
			scanf_s("%s", name);
			id = getid(name);
			mp[id].insert(index);
		}
	}
	for (int i = 0; i < n; i++)
	{
		//cin >> name;
		scanf_s("%s", name);
		id = getid(name);
		if (mp[id].size() == 0){
			printf("%s 0\n", name);
		}
		else{
			printf("%s %d", name, mp[id].size());
			for (set<int>::iterator it = mp[id].begin(); it != mp[id].end(); it++)
			{
				printf(" %d", *it);
			}printf("\n");
		}
	}


	return 0;
}