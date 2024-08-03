#include<stdio.h>
int main()
{
	int i,j,temp=0,arr[100],n;
	printf("enter n:");
	scanf("%d",&n);
	printf("enter numbers in the array:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	printf("sorted array:");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	
}
