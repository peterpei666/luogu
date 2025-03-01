#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func(char* string)
{
    return (*string-'A')*26+(*(string+1)-'A');
}

int main(void)
{
    int list[703][703]={0};
    int n,i,j,count=0;
    char city[20],state[4];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s %s",city,state);
        list[func(city)][func(state)]++;
    }
    for(i=0;i<703;i++)
    {
        for(j=0;j<703;j++)
        {
            if(i==j)
            {
                continue;
            }
            else
            {
                count+=list[i][j]*list[j][i];
            }
        }
    }
    printf("%d",count/2);
    return 0;
}


