#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char id;
    struct node* left;
    struct node* right;
} node;

node *root;

char preorder[30],inorder[30];

void initialize(unsigned long sp,unsigned long ep,unsigned long so,unsigned long eo,node **p)
{
    if (sp>ep||so>eo)
    {
        return;
    }
    unsigned long i,j;
    for (i = sp, j = so; i <= ep; i++,j++)
    {
        if (inorder[j]==preorder[sp]) break;
    }
    *p=(node *)malloc(sizeof(node));
    (*p)->left=NULL;
    (*p)->right=NULL;
    (*p)->id=preorder[sp];
    initialize(sp + 1, sp + (j - so), so, j - 1, &((*p)->left));
    initialize(sp + (j - so) + 1, ep, j + 1, eo, &((*p)->right));
}

void print(node *p)
{
    
    if (p == NULL)
    {
        return;
    }
    print(p->left);
    print(p->right);
    printf("%c",p->id);
}

int main(void)
{
    scanf("%s%s",inorder,preorder);
    initialize(0,strlen(preorder)-1, 0, strlen(inorder) - 1, &root);
    print(root);
    printf("\n");
    return 0;
}

