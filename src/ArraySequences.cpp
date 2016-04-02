/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int * isGp(int*arr, int len, int start);
int * isAp(int*arr, int len, int start);

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (len <= 0)
		return NULL;
	if (arr){
		int flag = 0;
		int finalArr[6];
		int gp[2];
		int *temp;
		int k = 0;
		for (int i = 0; i<len - 2; i++){
			temp = isAp(arr, len, i);
			if (temp[0] != temp[1]){
				finalArr[k++] = temp[0];
				finalArr[k++] = temp[1];
				i = temp[1];
			}
			if (flag == 0){
				temp = isGp(arr, len, i);
				if (temp[0] != temp[1]){
					gp[0] = temp[0];
					gp[1] = temp[1];
					i += 1;
					flag = 1;
				}
			}
		}
		finalArr[4] = gp[0];
		finalArr[5] = gp[1];
		return finalArr;
	}
	return NULL;
}
int * isGp(int*arr, int len,int start){
	float diff = arr[start + 1] / arr[start];
	int count = 0;
	int res[2];
	for (int i = start; i < len-1; i++){
		if (arr[i + 1] / arr[i] == diff){
			count++;
		}
		else{
			break;
		}
	}
	if (count >= 2){
		res[0] = start;
		res[1] = start + count;	
	}
	return res;
}
int * isAp(int*arr, int len, int start){
	float diff = arr[start + 1] - arr[start];
	int count = 0;
	int res[2] = { 0 };
	for (int i = start; i < len - 1; i++){
		if (arr[i + 1] - arr[i] == diff){
			count++;
		}
		else{
			break;
		}
	}
	if (count >= 2){
		res[0] = start;
		res[1] = start + count;
	}
	return res;
}
