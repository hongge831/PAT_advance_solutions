#include <stdio.h>
#include <iostream>
#include <string>
#define M 61
using namespace std;
string s1, s2, s3, s4;
string day[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
int main(){
	cin >> s1 >> s2 >> s3 >> s4;
	int cnt = 0, i = 0;
	bool flag = true;
	while (cnt < 2){
		if (flag){
			if (s1[i] == s2[i] && s1[i] <= 'G' && s1[i] >= 'A'){
				cnt++; flag = false;
				printf("%s ", day[s1[i] - 'A'].c_str());
			}
		}
		else{
			if (s1[i] == s2[i] && (s1[i] <= 'N' && s1[i] >= 'A' || s1[i] <= '9' && s1[i] >= '0')){
				cnt++;
				if (s1[i] <= '9'){
					printf("%02d:",s1[i]-'0');
				}
				else{
					printf("%02d:",s1[i]-'A'+10);
				}
			}
		}i++;
	}
	for (int i = 0; i < s3.length(); i++)
	{
		if (s3[i] == s4[i] && (s3[i] <= 'Z' && s3[i] >= 'A' || s3[i] <= 'z' && s3[i] >= 'a')){
			printf("%02d", i); break;
		}
	}
	return 0;
}