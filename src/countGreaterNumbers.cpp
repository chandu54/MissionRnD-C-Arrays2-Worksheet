/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
struct dates
{
	int dd, mm, yyyy;
};
struct dates function(char* strdate)
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
	//printf("%d %d %d\n ",intdate.dd,intdate.mm,intdate.yyyy);
	return intdate;
}
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i, count = 0;
	struct dates intdate[5];
	struct dates givendate;
	givendate = function(date);
	//printf("\n %d %d %d\n ",givendate.dd,givendate.mm,givendate.yyyy);
	for (i = 0; i<len; i++)
		intdate[i] = function(Arr[i].date);
	for (i = 0; i<len; i++)
		//printf("\n %d %d %d",intdate[i].dd,intdate[i].mm,intdate[i].yyyy);
		for (i = 0; i<len; i++)
		{
			if (intdate[i].yyyy>givendate.yyyy)
				count++;
			else if (intdate[i].yyyy == givendate.yyyy)
			{
				if (intdate[i].mm>givendate.mm)
					count++;
				else if (intdate[i].mm == givendate.mm)
				{
					if (intdate[i].dd>givendate.dd)
						count++;
				}
			}
		}
	return count;
}
