#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int m,k,capacity=1,temp=1,i=0,j,flag=1;
	scanf("%d%d",&m,&k);
	m%=(int)pow(10,k);
    int* list=(int*)malloc(capacity*sizeof(int));
	while(flag)
	{
		temp*=m;
		temp%=(int)pow(10,k);
		if(i==capacity)
		{
            capacity++;
            list=(int*)realloc(list,sizeof(int)*capacity);
		}
        list[i]=temp;
        for(j=0;j<i;j++)
        {
            if(list[j]==temp)
            {
                printf("period: %d\n",i-j);
                flag=0;
                break;
            }
        }
        i++;
	}
    return 0;
}
