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
	/*data input & sort*/
	int n, k, m;
	cin >> n;
	int hh, mm, ss, ptime, vipTemp;
	person personTemp;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d:%d:%d %d %d", &hh, &mm, &ss, &ptime, &vipTemp);
		personTemp.arrivTime = hh * 3600 + mm * 60 + ss;
		if (personTemp.arrivTime >= 21 * 3600)
			continue;
		personTemp.startTime = 21 * 3600;
		personTemp.p = ptime <= 120 ? ptime * 60 : 7200;//errorable:the unit of time is minutes
		personTemp.isVip = ((vipTemp == 1) ? true : false);
		player.push_back(personTemp);
	}
	cin >> k >> m;
	table.resize(k + 1);
	int tableNum;//the total number of table
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
			//find the earlist endtime table
			if (table[j].endTime < minEndTime){
				minEndTime = table[j].endTime;
				index = j;
			}
		}
		/*the club is ended*/
		if (table[index].endTime >= 21 * 3600)//errorable:endtime can not exceed 21:00
			break;
		/*skip the vip who has entered the club*/
		if (player[i].isVip == true){
			if (i < vipIndex){
				i++;
				continue;
			}
			else if (i == vipIndex){
				vipIndex = findVip(vipIndex);
			}
		}
		/*begin queuing by different situations*/
		if (table[index].tbVip == true){
			if (player[i].isVip == true){
				arrange(i, index);
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
			/*if the person is vip, he only choose the vip table, when there is a vip table*/
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
					i++;
				}
				else{
					arrange(i, index);					
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