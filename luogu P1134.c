#include <stdio.h>

int main(void)
{
	int last=1,n,i,temp;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		temp=i%10;
		if(temp)
		{
			last*=temp;
			if(last%10==0)
			{
				last/=10;
			}
			last%=10;
		}
	}
	printf("%d\n",last);
	return 0;
}