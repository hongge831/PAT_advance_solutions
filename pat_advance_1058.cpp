#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int g1, s1, k1, g2, s2, k2, g, s, k;
	int q = 0, p = 0;
	scanf_s("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	k = (k1 + k2) % 29;
	q = (k1 + k2) / 29;
	s = (s1 + s2 + q) % 17;
	p = (s1 + s2 + q) / 17;
	g = g1 + g2 + p;
	printf("%d.%d.%d",g,s,k);
	return 0;
}