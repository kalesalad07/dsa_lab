#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

typedef struct bst {
    Node *root;
} BST;

BST *new_bst() 
{
    BST *bst = malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

Node *new_node(int value) 
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void traverse_in_order(Node *node)
{
    if (node == NULL)
    {
        //printf("null ");
        return;
    }
    traverse_in_order(node->left);
    printf("%d ", node->value);
    traverse_in_order(node->right);
}

void traverse_pre_order(Node *node){
    if(node == NULL){
        //printf("null ");
        return;
    }
    printf("%d ", node->value);
    traverse_pre_order(node->left);
    traverse_pre_order(node->right);
}

void traverse_post_order(Node *node){
    if(node == NULL){
        //printf("null ");
        return;
    }
    traverse_post_order(node->left);
    traverse_post_order(node->right);
    printf("%d ", node->value);
    
}

void insert(BST *bst, int value)
{
    Node *node = new_node(value);
    if (bst->root == NULL) 
    {
        bst->root = node;
        return;
    }
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (value < current->value) 
        {
            if (current->left == NULL) 
            {
                current->left = node;
                return;
            }
            current = current->left;
        } 
        else 
        {
            if (current->right == NULL) 
            {
                current->right = node;
                return;
            }
            current = current->right;
        }
    }
}

int search(BST *bst, int key)
{
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (key == current->value) 
        {
            return 1;
        } 
        else if (key < current->value) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }
    return 0;
}

int find_min(BST *bst)
{
    Node *current = bst->root;
    while (current->left != NULL) 
    {
        current = current->left;
    }
    return current->value;
}

int find_max(BST *bst)
{
    Node *current = bst->root;
    while (current->right != NULL) 
    {
        current = current->right;
    }
    return current->value;
}

Node *predecessor(Node *node)
{
    if (node->left == NULL)
    {
        return NULL;
    }
    Node *current = node->left;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

Node *successor(Node *node)
{
    if (node->right == NULL)
    {
        return NULL;
    }
    Node *current = node->right;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

void delete(BST *bst, Node *node)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        // Node is a leaf
        Node* current = bst->root;
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = NULL;
                break;
            }
            if (current->right == node)
            {
                current->right = NULL;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }
    
    if (node->left == NULL)
    {
        // Node only has right child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->right;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->right;
                break;
            }
            if (current->right == node)
            {
                current->right = node->right;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    if (node->right == NULL)
    {
        // Node only has left child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->left;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->left;
                break;
            }
            if (current->right == node)
            {
                current->right = node->left;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    // Node has both children
    Node *temp = successor(node);
    node->value = temp->value;
    delete(bst, temp);
    return;
}

BST *constructBST(int *arr, int n){
    BST *bst = new_bst();
    for(int i = 0; i < n; i++){
        insert(bst,arr[i]);
    }
    return bst;
}

bool isBST(Node *node){
    if(node == NULL) return true;    
    bool left;
    bool right;

    if(node->left == NULL)left = true;
    else{
        if(predecessor(node)->value <= node->value){
            left = isBST(node->left);
        }
        else return false;
    }

    if(node->right == NULL)right = true;
    else{
        if(successor(node)->value >= node->value){
            right = isBST(node->right);
        }
        else return false;
    }

    return left && right;
}

int **createArrs(int no, int *sizes){
    FILE *fp = fopen("n_integers.txt","r");
    int **arr_p = (int **)malloc(no*sizeof(int *));
    int n;
    int *arr;
    for(int j = 0; j < no; j++){
        fscanf(fp,"%d",&n);
        sizes[j] = n;
        arr = (int *)malloc(n*sizeof(int));
        fscanf(fp, ",[");
        for(int i = 0; i < n; i++){
            fscanf(fp,"%d ",arr+i);
        }
        fscanf(fp,"]\n");
        arr_p[j] = arr;

    }
    return arr_p;
   
}

int max(int a, int b){
    return (a>=b) ? a : b;
}

int bstHeightrec(Node *n){
    if(n == NULL) return 0;
    if(n->left == NULL && n->right == NULL){
        return 1;
    }

    return 1 + max(bstHeightrec(n->left), bstHeightrec(n->right));
    
}

int bstHeight(BST *bst){
    return bstHeightrec(bst->root);
}



// Driver program to test the above functions (feel free to play around with this)
int main()
{
    // BST *bst = new_bst();
    // insert(bst, 2);
    // insert(bst, 1);
    // insert(bst, 3);
    // insert(bst, 4);
    // insert(bst, 5);
    // insert(bst, 6);
    // insert(bst, 7);
    // insert(bst, 8);
//task1 and 2
    int arr[10] = {5,3,7,2,4,1,6,9,8,10};
    BST *bst = constructBST(arr,10);
    traverse_in_order(bst->root);
    printf("\n");
    traverse_pre_order(bst->root);
    printf("\n");
    traverse_post_order(bst->root);
    printf("\n");  

    printf("Height of tree is: %d", bstHeight(bst));

//task 3 
    // int n = 5000;
    // int *sizes = (int *)malloc(n*sizeof(int));
    // int **arrs = createArrs(n,sizes);    
    
    // int flag = 0;
    // for(int i = 0; i < n; i++){
    //     BST *bst = constructBST(arrs[i],sizes[i]);
    //     if(isBST(bst->root))printf("is bst: %d\n", i);
    //     else flag++;

    //     free(bst);
    // }
    // printf("No of wrong answers: %d\n",flag);


    // printf("\n");
    // printf("Max = %d\n", find_max(bst));
    // printf("Min = %d\n", find_min(bst));
    // printf("Predecessor of root = %d\n", predecessor(bst->root)->value);
    // printf("Successor of root = %d\n", successor(bst->root)->value);
    // delete(bst, bst->root->left);
    // traverse_in_order(bst->root);
    // printf("\n");
    // delete(bst, bst->root->right);
    // traverse_in_order(bst->root);
    // printf("\n");
    // delete(bst, bst->root);
    // traverse_in_order(bst->root);
    // printf("\n");
    return 0;
}