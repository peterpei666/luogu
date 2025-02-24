#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a,b,n,m,t,atk,i;
    char type[6];
    scanf("%d%d",&n,&m);
    a=0x7fffffff;
    b=0;
    atk=0;
    while(n--)
    {
        scanf("%s%d",type,&t);
        switch(*type)
        {
            case 'A':
                a=a&t;
                b=b&t;
                break;
            case 'O':
                a=a|t;
                b=b|t;
                break;
            case 'X':
                a=a^t;
                b=b^t;
                break;
        }
    }
    for(i=30;i>=0;i--)
    {
        if(b&(1<<i))
        {
            atk+=(1<<i);
        }
        else
        {
            if(a&(1<<i)&&m>=(1<<i))
            {
                m-=(1<<i);
                atk+=(1<<i);
            }
        }
    }
    printf("%d\n",atk);
    return 0;
}
