#include<stdio.h>
#include<stack>
using namespace::std;
unsigned int m, n, k, tmp, cur;
bool flag;
stack<int> s;
int _main()
{
	scanf_s("%d %d %d", &m, &n, &k);
	while (k--) {
		flag = true;
		cur = 1;
		s.push(1);
		for (int i = 0; i != n; ++i) {
			scanf_s("%d", &tmp);
			if (tmp > cur) {
				for (int j = cur + 1; j <= tmp; ++j)
					s.push(j);
				if (s.size() > m) flag = false;
				cur = tmp;
			}
			else {
				if (s.top() != tmp)
					flag = false;
			}
			s.pop();
		}

		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}