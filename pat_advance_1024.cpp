#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> vTemp;
vector<int> vCom;
bool isPalindromic(vector<int> &v){
	bool result;
	int i = 0, j = v.size() - 1;
	while (i <= j){
		if (v[i] != v[j])break;
		i++, j--;
	}
	i <= j ? result = false : result = true;
	return result;
}
int main(){
	string str;
	int k, step = 0;
	cin >> str >> k;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		vTemp.push_back(str[i] - '0');
	}
	if (isPalindromic(vTemp) == true){
		cout << str << endl;
		cout << '0';
	}
	else{
		vCom = vTemp;//when the k equal to 0 do not foget
		while (step < k){
			vCom.clear();
			step++;
			int j = vTemp.size() - 1;
			int ge = 0, shi = 0;
			//the add operation is not same as multi
			for (int i = 0; i < vTemp.size(); i++, j--)
			{
				ge = shi + (vTemp[i] + vTemp[j]) % 10;
				shi = ge / 10 + (vTemp[i] + vTemp[j]) / 10;
				vCom.push_back(ge % 10);
			}
			if (shi != 0){
				vCom.push_back(shi);
			}
			if (isPalindromic(vCom) == true){
				break;
			}
			vTemp = vCom;

		}
		for (int i = vCom.size() - 1; i >= 0; i--)
		{
			cout << vCom[i];
		}
		cout << endl << step;
	}
	return 0;
}