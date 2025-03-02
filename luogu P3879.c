#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 100083
#define N 8009

typedef struct
{
    char word[20];
    int count;
    int list[1000];
    struct node* next;
} node;

node* hash_table[M]={NULL};

node* create(char* word)
{
    node* newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->word,word);
    newnode->count=0;
    newnode->next=NULL;
    return newnode;
}

int hash_func(char* word)
{
    int ans=0,i;
    for(i=0;i<strlen(word);i++)
    {
        ans=ans*31+*(word+i);
    }
    return (ans%M+M)%M;
}

int search(char* word,int book)
{
    node* temp=hash_table[hash_func(word)];
    while(temp)
    {
        if(strcmp(temp->word,word)==0&&temp->list[temp->count-1]==book)
        {
            return 1;
        }
        temp=(node*)temp->next;
    }
    return 0;
}

void insert(char* word,int book)
{
    int hash=hash_func(word);
    node* temp=hash_table[hash];
    node* prev=temp;
    while(temp)
    {
        prev=temp;
        if(strcmp(temp->word,word)==0)
        {
            break;
        }
        temp=(node*)temp->next;
    }
    if(prev==NULL)  //整个链表为空
    {
        node* newnode=create(word);
        newnode->list[0]=book;
        newnode->count++;
        hash_table[hash]=newnode;
    }
    else if(temp==NULL)  //遍历至结尾也没有这个词
    {
        node* newnode=create(word);
        newnode->list[0]=book;
        newnode->count++;
        prev->next=(struct node*)newnode;
    }
    else  //找到这个词
    {
        temp->list[temp->count]=book;
        temp->count++;
    }
}

void find(char* word)
{
    node* temp=hash_table[hash_func(word)];
    int i;
    while(temp)
    {
        if(strcmp(temp->word,word)==0)
        {
            for(i=0;i<temp->count;i++)
            {
                if(i>0)
                {
                    printf(" ");
                }
                printf("%d",temp->list[i]);
            }
            printf("\n");
            return;
        }
        temp=(node*)temp->next;
    }
}

int main(void)
{
    int n,m,q,i;
    char word[20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        while(m)
        {
            scanf("%s",word);
            if(search(word,i+1)==0)
            {
                insert(word,i+1);
            }
            m--;
        }
    }
    scanf("%d",&q);
    while(q)
    {
        q--;
        scanf("%s",word);
        find(word);
    }
    return 0;
}
