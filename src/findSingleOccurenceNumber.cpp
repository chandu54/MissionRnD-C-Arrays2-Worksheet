/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stddef.h>
int findSingleOccurenceNumber(int *A, int len)
{
	int i,number,c,d,t;
	if (A == NULL || len < 0)
		return -1;
	for (c = 1; c <= len - 1; c++) {
		d = c;
		while (d > 0 && A[d] < A[d - 1]) {
			t = A[d];
			A[d] = A[d - 1];
			A[d - 1] = t;
			d--;
		}
	}
	for (i = 0; i<len; i++)
	{
		if (A[i] == A[i + 1])
			i = i + 2;
		else
			number = A[i];
	}
	return number;
}