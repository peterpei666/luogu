#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int data;
    struct node* next;
} node;

node* hash_table[1000000]={NULL};

int hash_func(int n,int id)
{
    return 10*(n-1)+id%10;
}

node* create(int id,int data)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->id=id;
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insert(int n,int id,int data)
{
    int m=hash_func(n,id);
    node* newnode=create(id,data);
    node* temp=hash_table[m];
    if(hash_table[m]==NULL)
    {
        hash_table[m]=newnode;
    }
    else
    {
        while(temp->next&&temp->id!=id)
        {
            temp=(node*)temp->next;
        }
        if(temp->id==id)
        {
            temp->data=data;
        }
        else
        {
            temp->next=(struct node*)newnode;
        }
    }
}

int search(int n,int id)
{
    node* temp=hash_table[hash_func(n,id)];
    if(!temp)
    {
        return -1;
    }
    while(temp->next&&temp->id!=id)
    {
        temp=(node*)temp->next;
    }
    if(temp->id==id)
    {
        return temp->data;
    }
    else
    {
        return -1;
    }
}

void free_list(void)
{
    int i;
    node* temp;
    node* m;
    for(i=0;i<1000000;i++)
    {
        if(hash_table[i]==NULL)
        {
            continue;
        }
        else
        {
            temp=hash_table[i];
            while(temp->next)
            {
                m=temp;
                temp=(node*)temp->next;
                free(m);
            }
            free(temp);
        }
    }
}

int main(void)
{
    int number,m,n,id,data,type,ans;
    scanf("%d%d",&number,&m);
    while(m)
    {
        scanf("%d",&type);
        switch(type)
        {
            case 1:
                scanf("%d%d%d",&n,&id,&data);
                insert(n,id,data);
                break;
            case 2:
                scanf("%d%d",&n,&id);
                ans=search(n,id);
                if(ans==-1)
                {
                    printf("Position Not Found!\n");
                }
                else
                {
                    printf("%d\n",ans);
                }
                break;
            default:
                printf("Invalid Command\n");
                break;
        }
        m--;
    }
    free_list();
    return 0;
}
