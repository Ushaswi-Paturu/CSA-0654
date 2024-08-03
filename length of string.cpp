#include<stdio.h>
#include<string.h>
int main()
{
	int len;
	char str[100];
	printf("enter string:");
	scanf("%s",&str);
	len=strlen(str);
	printf("length =%d",len);
}
