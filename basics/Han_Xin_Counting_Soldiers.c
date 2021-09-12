/*
Han Xin (韓信) (died 196 BC) was a military general who served Liu Bang during the Chu–Han Contention and contributed greatly to the founding of the Han dynasty.

In one of his many battles, he brought 1500 soldiers with him. 
It was a tough battle, about a little more than four hundred soldiers were killed. 
When they returned to their headquarters, general Han needed to know how many soldiers survived.

However, most of them could hardly count past ten.
Then he ordered the soldiers to line up 3 in a row, and the last row remains 2 soldiers.
Then he ordered them to line up 5 in a row, and the last row remains 4 soldiers.
Then he ordered them to line up 7 in a row, and the last row remains 6 soldiers.
Knowing those numbers, he quickly calculated how many soldiers he still had.

*/ 

#include<stdio.h>
int main()
{
	int n;
	for(n=1;;n++)
	{
		if(n%3==2 && n%5==3 && n%7==2)
		{
			printf("%d",n);
			break;
		}
	}
 } 
