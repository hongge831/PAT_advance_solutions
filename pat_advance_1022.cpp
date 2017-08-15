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