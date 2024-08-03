#include<stdio.h>
int main()
{
	int num,i,temp=0;
	printf("enter num:");
	scanf("%d",&num);
	for(i=2;i<=num/2;i++){
		if(num%i==0){
			temp++;
			break;
		}
	}
	if(temp==0 && num!=1){
		printf("prime number");
	}
	else{
		printf("not prime number");
	}
}
