#include <stdio.h>
#include <math.h>

int main(void)
{
	double t1,t2,H,S1,V,L,K,min,max;
	int n,count=0,i;
	scanf("%lf%lf%lf%lf%lf%d",&H,&S1,&V,&L,&K,&n);
	t1=sqrt(2.0*(H-K)/10);
	t2=sqrt(2.0*(H)/10);
	min=S1-V*t2;
	max=S1-V*t1+L;
	for(i=0;i<n;i++)
	{
		if(i>=min&&i<=max)
		{
			count++;
		}
	}
	printf("number: %d",count);
	return 0;
}