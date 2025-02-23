#include <stdio.h>
#include <stdlib.h>

char string[500];
int p1,p2,p3;

void print(char a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%c",a);
    }
}

void replace(char* position)
{
    char temp;
    if(*(position+1)<='z'&&*(position+1)>='a'&&*(position-1)<='z'&&*(position-1)>='a'&&*(position+1)>*(position-1))
    {
        switch(p1)
        {
            case 1:
                if(p3==1)
                {
                    for(temp=*(position-1)+1;temp<*(position+1);temp++)
                    {
                        print(temp,p2);
                    }
                }
                else if(p3==2)
                {
                    for(temp=*(position+1)-1;temp>*(position-1);temp--)
                    {
                        print(temp,p2);
                    }
                }
                break;
            case 2:
                if(p3==1)
                {
                    for(temp=*(position-1)+1;temp<*(position+1);temp++)
                    {
                        print(temp+'A'-'a',p2);
                    }
                }
                else if(p3==2)
                {
                    for(temp=*(position+1)-1;temp>*(position-1);temp--)
                    {
                        print(temp+'A'-'a',p2);
                    }
                }
                break;
            case 3:
                for(temp=*(position-1)+1;temp<*(position+1);temp++)
                {
                    print('*',p2);
                }
                break;
        }
    }
    else if(*(position+1)<='9'&&*(position+1)>='0'&&*(position-1)<='9'&&*(position-1)>='0'&&*(position+1)>*(position-1))
    {
        switch(p1)
        {
            case 1:case 2:
                if(p3==1)
                {
                    for(temp=*(position-1)+1;temp<*(position+1);temp++)
                    {
                        print(temp,p2);
                    }
                }
                else if(p3==2)
                {
                    for(temp=*(position+1)-1;temp>*(position-1);temp--)
                    {
                        print(temp,p2);
                    }
                }
                break;
            case 3:
                for(temp=*(position-1)+1;temp<*(position+1);temp++)
                {
                    print('*',p2);
                }
                break;
        }
    }
    else
    {
        printf("-");
    }
}

int main(void)
{
    scanf("%d%d%d%s",&p1,&p2,&p3,string);
    char* current=string;
    while(*current!='\0')
    {
        if(*current!='-')
        {
            printf("%c",*current);
        }
        else
        {
            replace(current);
        }
        current++;
    }
    printf("\n");
    return 0;
}
