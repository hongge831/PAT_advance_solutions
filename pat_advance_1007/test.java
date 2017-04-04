package java01;

import java.util.Scanner;

public class test {
	public static int[] MaxsubqSum(int[] A, int N){
		int thisSum, maxSum, start1, start2, flag, end,sum1, sum2;
		thisSum = maxSum = start1 = start2 = flag = end = sum1 = sum2 = 0;
		int[] res = new int[3];
		for(int i=0; i<N; i++){
			if(A[i]<0){
				sum1++;
			}
			if(A[i]==0){
				sum2++;
			}
		}
		if(sum1 == N){
			maxSum = 0;
			start2 = 0;
			end = N-1;
		}else if(sum1+sum2==N){
			res[0] = 0;
			res[1] = 0;
			res[2] = 0;
			return res;
			
		}
		
		for(int i=0; i<N; i++){
			if(thisSum + A[i] < 0){
				thisSum = 0;
				start1 = i+1;
			}else{
				thisSum += A[i];
				if(thisSum > maxSum){
					maxSum = thisSum;
					end = i; 
					if(flag == 0){
						start2 = i;
						flag = 1;
					}
					if(end > start1){
						start2 = start1;
					}
					
				}
			}
		}
		res[0] = maxSum;
		res[1] = A[start2];
		res[2] = A[end];
		return res;
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn = new Scanner(System.in);
		int n = 0;
		n = scn.nextInt();
		int[] a = new int[n];
		for(int i=0; i<n; i++){
			a[i] = scn.nextInt();
		}
		int[] res = new int[3];
		res = MaxsubqSum(a, n);
		System.out.print(res[0] + " ");
		System.out.print(res[1] + " ");
		System.out.print(res[2]);
		scn.close();
	}

}
