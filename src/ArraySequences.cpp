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

int * find_sequences(int *arr, int len)
{
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	int *result, pointer = 0, index, counter, gp = 1, ap = 2, ap_ind = 0;
	result = (int *)malloc(sizeof(int) * 6);
	if (arr == NULL || len < 0)
		return NULL;
	for (counter = 0; counter < len - 1; counter++)
	{
		index = counter>ap_ind ? counter : ap_ind;
		if (arr[index + 2] - arr[index + 1] == arr[index + 1] - arr[index] && ap)
		{
			result[pointer++] = index;
			while (arr[index + 2] - arr[index + 1] == arr[index + 1] - arr[index])
				index++;
			result[pointer++] = index + 1;
			ap_ind = index + 1;
			ap--;
		}
		index = counter;
		if (arr[index + 2] / arr[index + 1] == arr[index + 1] / arr[index] && arr[index + 1] % arr[index] == 0 && gp)
		{
			result[4] = index;
			while (arr[index + 2] / arr[index + 1] == arr[index + 1] / arr[index] && arr[index + 1] % arr[index] == 0)
				index++;
			result[5] = index + 1;
			gp--;
		}
	}
	return result;
}