#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
int getLeftNum(int n);
void readArr(int *arr, int n);
int compare(const void *a, const void*b);//qsort�ȽϺ������
void mainSolution(int *arr, int *resArr, int n, int loc);
int main(){
	int n, loc;
	cin >> n;
	loc = 0;
	int *arr = (int *)malloc(n*sizeof(int));
	int *resArr = (int *)malloc(n*sizeof(int));
	readArr(arr, n);
	qsort(arr, n, sizeof(int), compare);//�������������
	mainSolution(arr, resArr, n, loc);
	for (int i = 0; i < n - 1; i++)
	{
		cout << resArr[i] << " ";
	}cout << resArr[n - 1];
	return 0;
}

void readArr(int *arr, int n){
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
int getLeftNum(int n){
	int result;
	int levelN = floor(log2(n));
	int maxLeft = pow(2, levelN - 1);
	int normalLeft = n - pow(2, levelN) + 1;
	int subLeft = maxLeft > normalLeft ? normalLeft : maxLeft;
	result = pow(2, levelN - 1) - 1 + subLeft;
	return result;
}
int compare(const void *a, const void*b){
	return *(int*)a - *(int*)b;
}

void mainSolution(int *arr, int *resArr, int n, int loc){
	int L = getLeftNum(n);//������ڵ��Ԫ�ظ�����
	if (n == 0)return;
	if (n == 1){
		resArr[loc] = arr[L];
		return;
	}//�ݹ��������
	resArr[loc] = arr[L];
	mainSolution(arr, resArr, L, 2 * loc + 1);
	mainSolution(arr + L + 1, resArr, n - L - 1, 2 * (loc+1));
	return;
}