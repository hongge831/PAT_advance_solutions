#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct info{
	string name, id;
	char gender;
	int score;
};
vector<info> v;
int main(){
	int n, femalMax = -1, maleMin = 101, fNum = 0, mNum = 0;
	cin >> n;
	bool f = true;
	info temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp.name >> temp.gender >> temp.id >> temp.score;
		if (temp.gender == 'M'){
			if (temp.score < maleMin){
				maleMin = temp.score;
				mNum = i;
			}
		}
		else{
			if (temp.score > femalMax){
				femalMax = temp.score;
				fNum = i;
			}

		}
		v.push_back(temp);
	}

	if (femalMax != -1){
		cout << v[fNum].name <<' '<< v[fNum].id << endl;
	}
	else{
		cout << "Absent"<<endl;
		f = false;
	}

	if (maleMin != 101){
		cout << v[mNum].name <<' '<< v[mNum].id << endl;
	}
	else{
		cout << "Absent" << endl;
		f = false;
	}
	if (f)
		cout << v[fNum].score - v[mNum].score;
	else
		cout << "NA";
	return 0;
}
