#include <stdio.h>

int main(void)
{
    int a=0,b=0,i,j,t,x1=0,x2=0,y1=0,y2=0;
    char arr[10][10];
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            arr[i][j]=getchar();
            if(arr[i][j]=='F')
            {
                x1=i;
                y1=j;
            }
            else if(arr[i][j]=='C')
            {
                x2=i;
                y2=j;
            }
        }
        getchar();
    }
    for(t=0;t<1000000;t++)
    {
        switch(a)
        {
            case 0:
                if(x1>0&&arr[x1-1][y1]!='*')
                {
                    x1--;
                }
                else
                {
                    a++;
                    a%=4;
                }
                break;
            case 1:
                if(y1<9&&arr[x1][y1+1]!='*')
                {
                    y1++;
                }
                else
                {
                    a++;
                    a%=4;
                }
                break;
            case 2:
                if(x1<9&&arr[x1+1][y1]!='*')
                {
                    x1++;
                }
                else
                {
                    a++;
                    a%=4;
                }
                break;
            case 3:
                if(y1>0&&arr[x1][y1-1]!='*')
                {
                    y1--;
                }
                else
                {
                    a++;
                    a%=4;
                }
                break;
        }
        switch(b)
        {
            case 0:
                if(x2>0&&arr[x2-1][y2]!='*')
                {
                    x2--;
                }
                else
                {
                    b++;
                    b%=4;
                }
                break;
            case 1:
                if(y2<9&&arr[x2][y2+1]!='*')
                {
                    y2++;
                }
                else
                {
                    b++;
                    b%=4;
                }
                break;
            case 2:
                if(x2<9&&arr[x2+1][y2]!='*')
                {
                    x2++;
                }
                else
                {
                    b++;
                    b%=4;
                }
                break;
            case 3:
                if(y2>0&&arr[x2][y2-1]!='*')
                {
                    y2--;
                }
                else
                {
                    b++;
                    b%=4;
                }
                break;
        }
       if(x1==x2&&y1==y2)
       {
           break;
       }
    }
    if(t==1000000)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n",t+1);
    }
    return 0;
}
