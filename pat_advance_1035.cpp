#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct data{
	string id, pwd;
};
vector<data> v;
int main(){
	int n, sum = 0;
	bool flag = false;
	cin >> n;
	data dataTemp;
	for (int i = 0; i < n; i++)
	{
		cin >> dataTemp.id >> dataTemp.pwd;
		for (int i = 0; i < dataTemp.pwd.size(); i++)
		{
			switch (dataTemp.pwd[i])
			{
			case '1':dataTemp.pwd[i] = '@'; flag = true; break;
			case '0':dataTemp.pwd[i] = '%'; flag = true; break;
			case 'l':dataTemp.pwd[i] = 'L'; flag = true; break;
			case 'O':dataTemp.pwd[i] = 'o'; flag = true; break;
			}
		}
		if (flag == true){
			v.push_back(dataTemp);
			flag = false;
			sum++;
		}
	}
	if (sum == 0 && n == 1){
		printf("There is 1 account and no account is modified");
	}
	else if (sum == 0 && n > 1){
		printf("There are %d accounts and no account is modified", n);
	}
	else{
		printf("%d\n",sum);
		for (int i = 0; i < v.size(); i++)
		{
			printf("%s %s\n",v[i].id.c_str(),v[i].pwd.c_str());
		}
	}

	return 0;
}
