#include<stdio.h>
int main()
{
	int n,i,arr[100];
	printf("enter the n range of array:");
	scanf("%d",&n);
	printf("enter the numbers in the array:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=1;i<n;i++){
		if(arr[0]<arr[i]){
			arr[0]=arr[i];
		}
	}
			printf("largest number=%d",arr[0]);
}
