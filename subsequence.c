#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int *arr;
void findans(int index,int n,int temparr[])
{
	if(index==n)
	{
		for(int i=0;temparr[i]!=0;i++)
			printf("%d ",temparr[i]);
		printf("\n");
		return;
	}
	int i=0;
	while(temparr[i]!=0)
		i++;
	temparr[i]=arr[index];
	findans(index+1,n,temparr);
	temparr[i]=0;
	findans(index+1,n,temparr);
}

int main()
{
	int n;
	scanf("%d",&n);
	arr=(int *)calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int temparr[100];
	for(int i=0;i<100;i++)
		temparr[i]=0;
	findans(0,n,temparr);
	return 0;
}
