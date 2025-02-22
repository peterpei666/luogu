#include <stdio.h>

int main(void)
{
    int n,t1,t2,i,a=0,b=0;
    scanf("%d%d%d",&n,&t1,&t2);
    int arr1[t1],arr2[t2];
    for(i=0;i<t1;i++)
    {
        scanf("%d",&arr1[i]);
    }
    for(i=0;i<t2;i++)
    {
        scanf("%d",&arr2[i]);
    }
    for(i=0;i<n;i++)
    {
        switch(arr1[i%t1])
        {
            case 0:
                if(arr2[i%t2]==1)
                {
                    b++;
                }
                else if(arr2[i%t2]==2)
                {
                    a++;
                }
                else if(arr2[i%t2]==3)
                {
                    a++;
                }
                else if(arr2[i%t2]==4)
                {
                    b++;
                }
                break;
            case 1:
                if(arr2[i%t2]==0)
                {
                    a++;
                }
                else if(arr2[i%t2]==2)
                {
                    b++;
                }
                else if(arr2[i%t2]==3)
                {
                    a++;
                }
                else if(arr2[i%t2]==4)
                {
                    b++;
                }
                break;
            case 2:
                if(arr2[i%t2]==0)
                {
                    b++;
                }
                else if(arr2[i%t2]==1)
                {
                    a++;
                }
                else if(arr2[i%t2]==3)
                {
                    b++;
                }
                else if(arr2[i%t2]==4)
                {
                    a++;
                }
                break;
            case 3:
                if(arr2[i%t2]==0)
                {
                    b++;
                }
                else if(arr2[i%t2]==1)
                {
                    b++;
                }
                else if(arr2[i%t2]==2)
                {
                    a++;
                }
                else if(arr2[i%t2]==4)
                {
                    a++;
                }
                break;
            case 4:
                if(arr2[i%t2]==0)
                {
                    a++;
                }
                else if(arr2[i%t2]==1)
                {
                    a++;
                }
                else if(arr2[i%t2]==2)
                {
                    b++;
                }
                else if(arr2[i%t2]==3)
                {
                    b++;
                }
                break;
        }
    }
    printf("%d %d\n",a,b);
    return 0;
}
