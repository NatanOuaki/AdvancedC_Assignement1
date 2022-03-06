#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexi(char str1, char str2);
void main()
{
	char str1[] = "abad";
	char str2[] = "aaad";

	printf("first str: %s\nsecond str: %s\nthe answer is: ###  %d  ###",str1,str2 ,lexi(str1, str2));

}
int lexi(char str1[], char str2[]){
	if (str1[0] == '\0' && str2[0] == '\0')
		return 0; 
		
	if (str1[0] == '\0' && str2[0] != '\0' || str1[0] < str2[0])
		return -1;
	
	if (str1[0] != '\0' && str2[0] == '\0' || str1[0] > str2[0])
		return 1;
	
	if (str1[0] == str2[0]) 
		lexi(str1 + 1, str2 + 1);
}
