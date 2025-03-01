#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char string[1600];
    struct node* next;
} node;

int hash_func(char* string)
{
    int i,ret=0;
    for(i=0;i<strlen(string)&&i<100;i++)
    {
        ret+=(int)*string;
        string++;
    }
    return ret%10000;
}

node* hash_table[10000]={NULL};

node* create(char* string)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->next=NULL;
    strcpy(newnode->string,string);
    return newnode;
}

void insert(char* string)
{
    node* newnode=create(string);
    int hash=hash_func(string);
    if(hash_table[hash]==NULL)
    {
        hash_table[hash]=newnode;
    }
    else
    {
        node* temp=hash_table[hash];
        while(temp->next!=NULL&&strcmp(string,temp->string)!=0)
        {
            temp=(node*)temp->next;
        }
        if(strcmp(string,temp->string)==0)
        {
            return;
        }
        else
        {
            temp->next=(struct node*)newnode;
        }
    }
}

int count(void)
{
    int i,ans=0;
    node* temp;
    for(i=0;i<10000;i++)
    {
        if(hash_table[i]==NULL)
        {
            continue;
        }
        else
        {
            temp=hash_table[i];
            ans++;
            while(temp->next!=NULL)
            {
                ans++;
                temp=(node*)temp->next;
            }
        }
    }
    return ans;
}

int main(void)
{
    int n,i,number;
    char string[1600];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",string);
        insert(string);
    }
    number=count();
    printf("%d\n",number);
    return 0;
}
