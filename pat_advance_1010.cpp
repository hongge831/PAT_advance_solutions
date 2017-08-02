#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int map[200];
int findLargestNum(string str){
	int re = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (re < map[str[i]]){
			re = map[str[i]];
		}
	}return re + 1;
}
long long convertToDecimal(string str, long long radix){
	long long d = 1, re = 0;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		re += map[str[i]] * d;
		d *= radix;
	}
	return re;
}

long long binarySearch(long long low, long long high, string n2, long long t){
	long long mid, res = -1;
	while (low <= high){
		mid = (low + high) / 2;
		long long num2 = convertToDecimal(n2, mid);
		if (num2 < 0 || num2 > t){
			mid -= 1;
			high = mid;
		}
		else if (num2 < t){
			mid += 1;
			low = mid;
		}
		else if (num2 == t){
			return mid;//there doesn't exit any more 'mid' when num2==t, there is only one,so return the re directly
		}
	}
	return res;

}

int main(){
	/*read in the input data*/
	long long tag, radix;
	string n1, n2;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2)swap(n1, n2);
	/*initialize the arr map[]*/
	for (char c = '0'; c <= 'z'; c++)
	{
		if (c <= '9'&&c >= '0'){
			map[c] = c - '0';
		}
		else if (c <= 'z'&&c >= 'a'){
			map[c] = c - 'a' + 10;
		}
	}
	/*compute the lowest radix of n2*/
	long long low;
	low = findLargestNum(n2);
	/*convert the n1 to decimal number*/
	long long t, high;//n1's decimal number is the highest radix of n2 when n2 is a two digit number
	t = convertToDecimal(n1, radix);
	high = max(t, low) + 1;//
	/*binary search for the matched radix for n2*/
	long long result;
	result = binarySearch(low, high, n2, t);

	/*print the result*/
	if (result == -1){
		printf("Impossible\n");
	}
	else{
		printf("%ld\n", result);
	}
	return 0;
}