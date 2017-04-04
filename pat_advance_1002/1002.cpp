#include <stdio.h>
#include <iostream>
#include <list>
#include<iomanip>
using namespace std;
typedef struct _polynomial{
	float coefficient;
	int conponent;
} pol;
pol tempIn;

list<pol> init(int k){
	list<pol> input;
	for (int i = 0; i < k; i++)
	{
		cin >> setprecision(2) >> tempIn.conponent;
		cin >> setprecision(2) >> tempIn.coefficient;
		input.push_back(tempIn);
	}
	return input;
}

int main(){
	list<pol> in1, in2, out;
	int k1, k2;
	cin >> k1;
	in1 = init(k1);
	cin >> k2;
	in2 = init(k2);

	list<pol>::iterator iter1, iter2, outer;
	iter1 = in1.begin();
	iter2 = in2.begin();
	while (iter1 != in1.end() && iter2 != in2.end()){
		if (iter2->conponent > iter1->conponent){
			out.push_back(*iter2);
			iter2++;
		}
		else if (iter2->conponent == iter1->conponent){
			iter2->coefficient = iter2->coefficient + iter1->coefficient;
			if (iter2->coefficient != 0){
				out.push_back(*iter2);
			}
			iter1++;
			iter2++;
		}
		else{
			out.push_back(*iter1);
			iter1++;
		}
	}
	outer = out.end();
	//注释的部分是将多余的部分遍历push到out中
	/*while (iter1 != in1.end()){
	out.push_back(*iter1);
	iter1++;
	}
	while (iter2 != in2.end()){
	out.push_back(*iter2);
	iter2++;
	*/
	//链表的拼接
	if (iter1 != in1.end()){
		out.splice(outer, in1, iter1, in1.end());
	}
	if (iter2 != in2.end()){
		out.splice(outer, in2, iter2, in2.end());
	}

	if (out.size() == 0){
		cout << out.size();
	}
	else{
		cout << out.size() << " ";
		outer = out.begin();
		int f = 1;
		while (f++ != out.size()){
			cout << setprecision(1) << fixed << outer->conponent << " " << setprecision(1) << fixed << outer->coefficient << " ";
			outer++;
		}
		cout << setprecision(1) << fixed << outer->conponent << " " << setprecision(1) << fixed << outer->coefficient;
	}
	return 0;
}