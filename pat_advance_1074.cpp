/*
说明：本例没有对一些非法输入进行判断。
*/
#include <iostream>
#include <stdio.h>
#include <list>
#include <iomanip>
using namespace std;
typedef int ElementType;
//定义结构数组，用于构建链表；
struct Node {
	ElementType left;
	ElementType value;
	ElementType right;
};
//函数声明；
list<Node> init(int startPoint, int num, int k);//初始化链表，将给定的内存点中取出单链表；
list<Node> ReverseL(list<Node> L, int k, int size);//将单链表按照要求逆序；
void Print(list<Node> L);//打印链表；

int main(){
	list<Node> L, reverseL;
	int startPoint, num, k;
	cin >> startPoint >> num >> k;
	L = init(startPoint, num, k);//构建链表，并剔除无关内存结点
	int size = L.size();
	reverseL = ReverseL(L, k, size);//对构建好的链表进行排序
	Print(reverseL);
	return 0;
}

list<Node> init(int startPoint, int num, int k){
	list<Node> L, tempL;
	list<Node>::iterator iter;
	Node tempNode;
	for (int i = 0; i < num; i++)//采用两张表的形式对链表进行实现
	{
		cin >> tempNode.left;
		cin >> tempNode.value;
		cin >> tempNode.right;
		tempL.push_back(tempNode);
	}
	iter = tempL.begin();
	while (iter != tempL.end()){
		if (startPoint == iter->left){
			L.push_back(*iter);
			startPoint = iter->right;
			tempL.erase(iter);//测试点5对时间要求高，在原始链表中剔除已经找到的链表；
			iter = tempL.begin();
		}
		else{
			iter++;
		}
	}
	return L;
}

list<Node> ReverseL(list<Node> L, int k, int size){
	int shan = size / k;//需要几次倒序
	list<Node>::iterator iter1;
	list<Node> RL;
	iter1 = L.begin();
	for (int j = 0; j < shan; j++)
	{
		advance(iter1, k - 1);
		for (int i = 0; i < k; i++)
		{
			RL.push_back(*iter1);
			if (i < k - 1)iter1--;

		}
		advance(iter1, k);
	}
	//将剩余的部分不逆序加入链表中
	while (iter1 != L.end()){
		RL.push_back(*iter1);
		iter1++;
	}
	return RL;
}

void Print(list<Node> L){
	list<Node>::iterator iter1, temp;
	iter1 = L.begin();
	temp = L.end();
	advance(temp, -1);
	while (iter1 != temp){
		cout << setw(5) << setfill('0') << iter1->left << " " << iter1->value << " ";
		cout << setw(5) << setfill('0') << (++iter1)->left << endl;
	}
	cout << setw(5) << setfill('0') << iter1->left << " " << iter1->value << " " << -1 << endl;
}