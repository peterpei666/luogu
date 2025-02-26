#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    struct node* next;
    struct node* prev;
} node;

node* create(int id)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->id=id;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
void insert(int id,node** root)
{
    node* newnode=create(id);
    node* temp=*root;
    if(*root==NULL)
    {
        *root=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=(node*)temp->next;
        }
        temp->next=(struct node*)newnode;
        newnode->prev=(struct node*)temp;
    }
}

void ring(node** root)
{
    node* temp=*root;
    while(temp->next)
    {
        temp=(node*)temp->next;
    }
    temp->next=(struct node*)(*root);
    (*root)->prev=(struct node*)temp;
}

node* cut(int m,int num,node* start)
{
    int i;
    node* temp=start;
    node* next;
    node* prev;
    if(m%num)
    {
        m=m%num-1;
    }
    else
    {
        m=num-1;
    }
    for(i=0;i<m;i++)
    {
        temp=(node*)temp->next;
    }
    printf("%d ",temp->id);
    next=(node*)temp->next;
    prev=(node*)temp->prev;
    next->prev=(struct node*)prev;
    prev->next=(struct node*)next;
    free(temp);
    return next;
}

int main(void)
{
    int n,m,i;
    node* root=NULL;
    node* current;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        insert(i+1,&root);
    }
    ring(&root);
    current=root;
    for(i=0;i<n;i++)
    {
        current=cut(m,n-i,current);
    }
    printf("\n");
    return 0;
}
