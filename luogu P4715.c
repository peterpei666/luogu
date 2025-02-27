#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int id;
    int lv;
} country;

int main(void)
{
    int n,i;
    scanf("%d",&n);
    n=pow(2,n);
    country* list=(country*)malloc(2*n*sizeof(country));
    for(i=0;i<n;i++)
    {
        scanf("%d",&list[n+i-1].lv);
        list[n+i-1].id=i+1;
    }
    for(i=n-2;i>=0;i--)
    {
        if(list[2*i+1].lv>list[2*i+2].lv)
        {
            list[i].id=list[2*i+1].id;
            list[i].lv=list[2*i+1].lv;
        }
        else
        {
            list[i].id=list[2*i+2].id;
            list[i].lv=list[2*i+2].lv;
        }
    }
    if(list[0].id==list[1].id)
    {
        printf("%d\n",list[2].id);
    }
    else
    {
        printf("%d\n",list[1].id);
    }
    free(list);
    return 0;
}

