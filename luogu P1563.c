#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char na[15];
} name;

int main(void)
{
    int n,q,i,current=0,a,b;
    scanf("%d%d",&n,&q);
    int direction[n];
    name list[n];
    for(i=0;i<n;i++)
    {
        scanf("%d %s",&direction[i],list[i].na);
    }
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&a,&b);
        if(a!=direction[current])
        {
            current+=b;
            current%=n;
        }
        else
        {
            current-=b;
            while(current<0)
            {
                current+=n;
            }
        }
    }
    printf("%s\n",list[current].na);
    return 0;
}
