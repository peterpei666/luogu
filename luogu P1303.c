#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char arr1[3000];
    char arr2[3000];
    int m=0,n=0,i,j,t;
    scanf("%s%s",arr1,arr2);
    m=(int)strlen(arr1);
    n=(int)strlen(arr2);
    int* mult=(int*)calloc(m+n,sizeof(int));
    for(i=m-1;i>=0;i--)
    {
        for(j=n-1;j>=0;j--)
        {
            t=(arr1[i]-'0')*(arr2[j]-'0');
            mult[i+j+1]+=t;
        }
    }
    for(i=m+n-1;i>0;i--)
    {
        mult[i-1]+=mult[i]/10;
        mult[i]%=10;
    }
    for(i=0;i<m+n;i++)
    {
        if(mult[i]>0)
        {
            break;
        }
    }
    if(i==m+n)
    {
        printf("0\n");
    }
    else
    {
        while(i<m+n)
        {
            printf("%d",mult[i]);
            i++;
        }
        printf("\n");
    }
    free(mult);
    return 0;
}
