#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int a, b, c, j;
	j = 1;
	string sum;
	stack<char> s;
	cin >> a >> b;
	c = (a + b) > 0 ? a + b : -a - b;
	while (c != 0){
		if (j % 3 != 0 || c / 10 == 0){
			s.push(c % 10 + '0');
			c /= 10;
		}
		else{
			s.push(c % 10 + '0');
			s.push(',');
			c /= 10;
			j = 0;
		}
		j += 1;
	}
	if (a + b < 0){
		s.push('-');
	}
	if (a + b == 0){
		s.push('0');
	}
	while (!s.empty()){
		cout << s.top();
		s.pop();
	}
	return 0;
}

