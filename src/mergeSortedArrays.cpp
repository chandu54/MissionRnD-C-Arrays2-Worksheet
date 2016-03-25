/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<malloc.h>
#include<string.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
struct dates
{
	int dd, mm, yyyy;
};
struct dates conversion(char* strdate)
{
	struct dates intdate;
	intdate.dd = 0;
	intdate.mm = 0;
	intdate.yyyy = 0;
	int index = 0;
	if (strdate[2] == '-'&&strdate[5] == '-')
	{
		for (index = 0; index<2; index++)
			intdate.dd = ((intdate.dd) * 10) + (strdate[index] - '0');
		for (index = 3; index<5; index++)
			intdate.mm = ((intdate.mm) * 10) + (strdate[index] - '0');
		for (index = 6; index<10; index++)
			intdate.yyyy = ((intdate.yyyy) * 10) + (strdate[index] - '0');
	}
	return intdate;
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	int i, j, k=0,tlen;
	tlen = ALen + BLen;
	struct transaction * result;
	struct dates *Adate, *Bdate;
	Adate = (struct dates*)malloc(sizeof(struct dates)*ALen);
	Bdate = (struct dates*)malloc(sizeof(struct dates)*BLen);
	result = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	for (i = 0; i < ALen; i++)
		Adate[i] = conversion(A[i].date);
	for (i = 0; i < BLen; i++)
		Bdate[i] = conversion(B[i].date);
	i = j = k = 0;
	while (i <= ALen - 1 && j <= BLen-1)
	{
		if (Adate[i].yyyy < Bdate[j].yyyy)
		{
			result[k].amount = A[i].amount;
			strcpy(result[k].date, A[i].date);
			strcpy(result[k].description, A[i].description);
			i++;
		}
		else if (Bdate[j].yyyy < Adate[i].yyyy)
		{
			result[k].amount = B[j].amount;
			strcpy(result[k].date, B[j].date);
			strcpy(result[k].description, B[j].description);
			j++;
		}
		else if (Adate[i].mm < Bdate[j].mm)
		{
			result[k].amount = A[i].amount;
			strcpy(result[k].date, A[i].date);
			strcpy(result[k].description, A[i].description);
			i++;
		}
		else if (Bdate[j].mm < Adate[i].mm)
		{
			result[k].amount = B[j].amount;
			strcpy(result[k].date, B[j].date);
			strcpy(result[k].description, B[j].description);
			j++;
		}
		else if (Adate[i].dd < Bdate[j].dd)
		{
			result[k].amount = A[i].amount;
			strcpy(result[k].date, A[i].date);
			strcpy(result[k].description, A[i].description);
			i++;
		}
		else if (Bdate[j].dd<=Adate[i].dd)
		{
			result[k].amount = B[j].amount;
			strcpy(result[k].date, B[j].date);
			strcpy(result[k].description, B[j].description);
			j++;
		}
		k++;
	}
	while (i <= ALen - 1)
	{
		result[k].amount = A[i].amount;
		strcpy(result[k].date, A[i].date);
		strcpy(result[k].description, A[i].description);
		i++;
		k++;
	}
	while (j <= BLen - 1)
	{
		result[k].amount = B[j].amount;
		strcpy(result[k].date, B[j].date);
		strcpy(result[k].description, B[j].description);
		j++;
		k++;
		
	}
	return result;
}