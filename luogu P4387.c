#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    
    int top,q,m,i,j;
    scanf("%d",&q);
    while(q)
    {
        scanf("%d",&m);
        int* list1=(int*)malloc(m*sizeof(int));
        int* list2=(int*)malloc(m*sizeof(int));
        int* stack=(int*)malloc(m*sizeof(int));
        for(i=0;i<m;i++)
        {
            scanf("%d",&list1[i]);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&list2[i]);
        }
        j=0;
        top=-1;
        for(i=0;i<m;i++)
        {
            top++;
            stack[top]=list1[i];
            while(stack[top]==list2[j]&&top>=0&&j<m)
            {
                top--;
                j++;
            }
        }
        if(top==-1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        free(list1);
        free(list2);
        free(stack);
        q--;
    }
    return 0;
}
