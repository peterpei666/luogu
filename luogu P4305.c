#include <stdio.h>
#include <stdlib.h>

#define M 100089

typedef struct node
{
    int data;
    struct node* next;
} node;

node* hash_table[M]={NULL};

int hash_func(int data)
{
    data=abs(data);
    return data%M;
}

node* create(int data)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insert(int data)
{
    node* newnode=create(data);
    int p=hash_func(data);
    if(hash_table[p]==NULL)
    {
        hash_table[p]=newnode;
    }
    else
    {
        node* temp=hash_table[p];
        newnode->next=hash_table[p];
        hash_table[p]=newnode;
    }
}

int search(int key)
{
    int p=hash_func(key);
    node* temp=hash_table[p];
    while(temp)
    {
        if(temp->data==key)
        {
            return 1;
        }
        temp=(node*)temp->next;
    }
    return 0;
}

void clear(void)
{
    int i;
    for(i=0;i<M;i++)
    {
        node* temp=hash_table[i];
        while(temp)
        {
            node* next=temp->next;
            free(temp);
            temp=next;
        }
        hash_table[i]=NULL;
    }
}

int main(void)
{
    int t,n,i,m;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        while(n)
        {
            n--;
            scanf("%d",&m);
            if(search(m)==0)
            {
                printf("%d ",m);
                insert(m);
            }
        }
        printf("\n");
        clear();
    }
    return 0;
}
