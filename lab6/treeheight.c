#include<stdio.h>
#include<stdlib.h>
/*----defining the structure for Avl tree node----*/
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node_t;
/*---defining structure for AVL tree--*/
typedef struct BinaryTree{
    node_t* root;
}Tree;

/* creating a new Avl node*/
node_t* NewNode(int data){

    node_t* temp = (node_t*)malloc(sizeof(node_t));
    if(temp==NULL){
        printf("memory is not allocated\n");
        exit(1);
    }

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
/*------------Creating a Tree------------------*/
Tree* initTree(){
    Tree* t;
    t=(Tree*)malloc(sizeof(Tree));
    if(t==NULL){
     printf("Memory is not allocated\n");
     exit(1);
 }
    t->root=NULL;
    
    return t;
}


/* calculating maximum of 2 numbers*/
int max(int a,int b){

     if(a>b)
         return a;
 else return b;
}

/* finding the height of the tree*/
int height(node_t* node){
    if (node ==  NULL) {
        return -1;
    }
    int lheight = height(node->left);
    int rheight = height(node->right);
    return max(lheight, rheight) + 1;
       
}

/* finding the balance factor of the node*/
int Balance(node_t* node){
    if (node ==  NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

/*---------------- function to display the preorder traversal of tree------------*/
void preorder(node_t *temp){
    
    
    if(temp!=NULL)
    {
    printf("%d\n",temp->data);
    preorder(temp->left);
    preorder(temp->right);
      
    }
}
/*---free the tree nodes----*/
void freenode(node_t *p){

    if(p!=NULL)
    {
        freenode(p->left);
        freenode(p->right);
        free(p);
    }
}

/*------------------main program-------------------------------*/
    int main()
{
 Tree* T=initTree();
    int n,x,i;
    /*      10
            /\
           1  4
          /    \
         2      5
                 \
                  6
                  */
    T->root=NewNode(10);
    T->root->left=NewNode(1);
    T->root->left->left=NewNode(2);
    T->root->right=NewNode(4);
    T->root->right->right=NewNode(5);
    T->root->right->right->right=NewNode(6);
    int treeheight=height(T->root);
    int bfactor=Balance(T->root);
    printf("The tree height is:%d\n",treeheight);
    printf("The balance factor is:%d\n",bfactor);
    preorder(T->root);
    freenode(T->root);
    free(T);
    return 0;
}
