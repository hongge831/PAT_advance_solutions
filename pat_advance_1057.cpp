#include <stdio.h>
#include <iostream>
#include <stack>
#define M 100001
#define lowbit(i) i&(-i)
using namespace std;
int c[M];
stack<int> s;
void update(int index, int v){
	for (int i = index; i < M; i += lowbit(i))
	{
		c[i] += v;
	}
}
int getSum(int index){
	int sum = 0;
	for (int i = index; i >0; i-=lowbit(i))
	{
		sum += c[i];
	}
	return sum;
}
void peek(){
	int left = 0, right = M, mid, k = (s.size() + 1) / 2;
	while (left<right){
		mid = (left + right) / 2;
		if (getSum(mid) >= k){
			right = mid;
		} else{
			left = mid + 1;
		}
	}
	printf("%d\n",left);
}

int main(){
	int n, value;
	char str[10];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%s", str, 10);
		/*if str == "pop","push","peekmedian"*/
		if (str[1] == 'u'){
			scanf_s("%d", &value);
			s.push(value);
			update(value, 1);
		}
		else if (str[1] == 'o'){
			if (!s.empty()){
				printf("%d\n", s.top());
				update(s.top(), -1);
				s.pop();
			}
			else{
				printf("Invalid\n");
			}
		}
		else{
			if (!s.empty()){
				peek();
			}
			else{
				printf("Invalid\n");
			}
		}
	}
	return 0;
}