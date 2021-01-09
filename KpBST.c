#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* left; 
    struct node* right;
} node;


struct node* new_node(int value)
{
    struct node *node_new;
    node_new = malloc(sizeof(struct node));
    node_new->value = value;
    node_new->left = NULL;
    node_new->right= NULL;

    return node_new;
}

node* insert(int value, node *tnode)
{
  /* add your code here */
    if(tnode == NULL){
        return new_node(value);     
    }
    
    if(value<tnode->value){
       tnode->left = insert(value, tnode->left);
    }
    else{
        tnode->right = insert(value,tnode->right);
    }  
    
    return tnode;       
}

void display(node* tnode)
{
   if(tnode==NULL)
   {
       return;
   }
   display(tnode->left);
   printf("%d ", tnode->value);
   display(tnode->right);
}

int main() {
    int i, num, value;
    node *root = NULL;
    scanf("%d", &num);
    for (i = 0; i < num; i++){
        scanf("%d",&value);
        root = insert(value, root);
    }
    display(root);
    return 0;
}