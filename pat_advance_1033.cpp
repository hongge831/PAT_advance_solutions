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