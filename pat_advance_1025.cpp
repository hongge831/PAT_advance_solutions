#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct data{
	long long id;
	int score, fRank, lRank, loc;
};
vector<data> vtemp, vfinal;
bool cmp(data &a, data &b){
	return a.score != b.score ? a.score > b.score : a.id < b.id;
}
int main(){
	int n;
	cin >> n;
	int numLocal, sum = 0;
	data temp;
	for (int i = 1; i <= n; i++)
	{
		cin >> numLocal;
		sum += numLocal;//the number of students
		for (int j = 1; j <= numLocal; j++)
		{
			cin >> temp.id >> temp.score;
			temp.loc = i;
			vtemp.push_back(temp);
		}
		/*sort every loc scores*/
		sort(vtemp.begin(), vtemp.end(), cmp);
		vtemp[0].lRank = 1;
		vfinal.push_back(vtemp[0]);
		for (int k = 1; k < vtemp.size(); k++)
		{
			if (vtemp[k].score == vtemp[k - 1].score){
				vtemp[k].lRank = vtemp[k - 1].lRank;
			}
			else{
				vtemp[k].lRank = k + 1;
			}
			vfinal.push_back(vtemp[k]);
		}vtemp.clear();
	}
	/*sort total students*/
	sort(vfinal.begin(), vfinal.end(), cmp);
	vfinal[0].fRank = 1;
	for (int k = 1; k < vfinal.size(); k++)
	{
		if (vfinal[k].score == vfinal[k - 1].score){
			vfinal[k].fRank = vfinal[k - 1].fRank;
		}
		else{
			vfinal[k].fRank = k + 1;
		}
	}cout << sum << endl;
	/*print the result*/
	for (int i = 0; i < sum; i++)
	{
		printf("%013lld %d %d %d\n", vfinal[i].id, vfinal[i].fRank, vfinal[i].loc, vfinal[i].lRank);
	}
	return 0;
}