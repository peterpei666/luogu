#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char arr1[70];
    char arr2[70];
    char arr3[71];
    char temp;
    int m=0,n=0,i,f=0;
    while((arr1[m]=getchar())!='\n')
    {
        m++;
    }
    arr1[m]='\0';
    while((arr2[n]=getchar())!='\n')
    {
        n++;
    }
    arr2[n]='\0';
    while(1)
    {
        if(m>n)
        {
            for(i=n-1;i>=0;i--)
            {
                arr2[i+1]=arr2[i];
            }
            arr2[0]='0';
            n++;
        }
        else if(m<n)
        {
            for(i=m-1;i>=0;i--)
            {
                arr1[i+1]=arr1[i];
            }
            arr1[0]='0';
            m++;
        }
        else
        {
            break;
        }
    }
    for(i=m-1;i>=0;i--)
    {
        temp=arr1[i]-'0'+arr2[i];
        if(f)
        {
            temp++;
            f=0;
        }
        if(temp>'9')
        {
            temp-=10;
            f=1;
        }
        arr3[i]=temp;
    }
    arr3[m]='\0';
    if(f)
    {
        printf("1%s\n",arr3);
    }
    else
    {
        printf("%s\n",arr3);
    }
    return 0;
}
