#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int divider(int num, int digit);
void main()
{
	int num = 685484;
	int digit = 4;
	printf("there is %d digits that %d divide without rest.", divider(num, digit),digit);
}
int divider(int num, int digit)
{
	static int counter = 0;
	if (num == 0) //halting condition.
		return counter;

	if ((num % 10) % digit != 0) //if the number isn't divided by the digit (dont change counter).
		divider(num / 10, digit);

	if ((num % 10) % digit == 0){ //if the number is divided by the digit (counter grows).
		divider(num / 10, digit);
		counter++;
	}

}

