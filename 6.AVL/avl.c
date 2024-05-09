#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height;
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
    node->parent = NULL;
    node->height = -1;
    return node;
}

int max(int a, int b){
    return (a>=b) ? a : b;
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

// void insert(BST *bst, int value)
// {
//     Node *node = new_node(value);
//     if (bst->root == NULL) 
//     {
//         bst->root = node;
//         node->height = 0;
//         return;
//     }
//     Node *current = bst->root;
//     while (current != NULL) 
//     {
//         if (value < current->value) 
//         {
//             if (current->left == NULL) 
//             {
//                 current->left = node;
//                 node->parent = current;
//                 current->height = bstHeightrec(current);
//                 return;
//             }
//             current = current->left;
//         } 
//         else 
//         {
//             if (current->right == NULL) 
//             {
//                 current->right = node;
//                 node->parent = current;
//                 current->height = bstHeightrec(current);
//                 return;
//             }
//             current = current->right;
//         }
//     }
// }

int update_height(Node* node){
    if(node->left == NULL && node->right == NULL) return 0;
    if(node->left == NULL) return node->right->height;
    if(node->right == NULL) return node->left->height;

    return max(node->left->height, node->right->height) + 1;
}

void insert_node(Node *node, int value){
    if(value < node->value){
        if(node->left == NULL){
            Node* toInsert = new_node(value);
            node->left = toInsert;
            toInsert->parent = node;
            toInsert->height = 0;
            node->height = update_height(node);
            return;
        }
        else{
            insert_node(node->left, value);
            node->height = update_height(node);
        }        
    }
    else{
        if(node->right == NULL){
            Node* toInsert = new_node(value);
            node->right = toInsert;
            toInsert->parent = node;
            toInsert->height = 0;
            node->height = update_height(node);
            return;
        }
        else{
            insert_node(node->right, value);
            node->height = update_height(node);
        }
    }
}

void insert(BST* bst, int value){
    if(bst->root == NULL){
        Node* new = new_node(value);
        bst->root = new;
        new->height = 0;
        return;
    }
    insert_node(bst->root, value);
    bst->root->height = update_height(bst->root);
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

void upward_height_update(Node* node){
    int h;
    while(node != NULL){
        h = update_height(node);
        if(node->height == h) return;
        else{
            node->height = h;
            node = node->parent;
        }
    }
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
                upward_height_update(current);               
                break;
            }
            if (current->right == node)
            {
                current->right = NULL; 
                upward_height_update(current);               
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
            node->right->parent = NULL;
            bst->root->height = 0;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->right;
                node->right->parent = current;
                upward_height_update(current);
                break;
            }
            if (current->right == node)
            {
                current->right = node->right;
                node->right->parent = current;
                upward_height_update(current);
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
            bst->root->height = 0;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->left;
                node->left->parent = current;
                upward_height_update(current);
                break;
            }
            if (current->right == node)
            {
                current->right = node->left;
                node->left->parent = current;
                upward_height_update(current);
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


//avl tree implementation
struct node *rotate_left(struct node* x){
    struct node* y = x->right;
    y->parent = x->parent;
    x->parent = y;
    x->right = y->left;
    y->left->parent = x;
    y->left = x;

    x->height = update_height(x);
    upward_height_update(y);
    return y;
}

struct node *rotate_right(struct node* x){
    struct node* y = x->left;
    y->parent = x->parent;
    x->parent = y;
    x->left = y->right;
    y->right->parent = x;    
    y->right = x;
    x->height = update_height(x);
    upward_height_update(y);
    return y;
}

int balance_factor(Node* node){
    if(node->left == NULL && node->right == NULL) return 0;
    if(node->left == NULL) return -1*node->right->height;
    if(node->right == NULL) return node->left->height;

    return node->left->height - node->right->height;
}

int is_height_balanced(struct node* node){
    int bf = node->left->height - node->right->height;
    if(bf <=1 && bf >= -1){
        return bstHeightrec(node);
    }
    else return -1;
}

struct node *insertAVL(struct node* node, int value){
    if(node == NULL){
        node = new_node(value);
        node->height = 0;
    }
    else if(value < node->value){
        node->left = insertAVL(node->left, value);
        node->left->parent = node;
    }
    else{
        node->right = insertAVL(node->right, value);
        node->right->parent = node;
    }
    node->left->height = update_height(node->left);
    node->right->height = update_height(node->right);
    node->height = update_height(node);

    int balance = is_height_balanced(node);
    if(balance == -1){
        if(value < node->value){
            if(value < node->left->value){
                node = rotate_right(node);
            }
            else{
                node->left = rotate_left(node->left);
                node = rotate_right(node);
            }
        }
        else{
            if(value >= node->right->value){
                node = rotate_left(node);
            }
            else{
                node->right = rotate_right(node->right);
                node = rotate_left(node);
            }
        }
    }
    return node;
}

void traverse_bfs(Node* node){
    if(node == NULL) return;

    Node *queue[100];
    int front = 0;
    int back = 0;
    queue[back++] = node;
    while(front != back){
        Node *current = queue[front++];
        printf("%d ", current->value);
        if(current->left != NULL) queue[back++] = current->left;
        if(current->right != NULL) queue[back++] = current->right;
    }
}

Node* deleteAVL(Node *node, int value){
    if(node == NULL) return NULL;
    else if(value < node->value){
        node->left = deleteAVL(node->left,value);
        node->height = update_height(node);
    }
    else if(value > node->value){
        node->right = deleteAVL(node->right, value);
        node->height = update_height(node);
    }
    else{
        if(node->left == NULL && node->right == NULL){
            Node* parent = node->parent;
            free(node);
            
            node = NULL;            
        }
        else if(node->right == NULL){
            struct node* temp = node;
            node = node->left;
            free(temp);
            
        }
        else if(node->left == NULL){
            struct node *temp = node;
            node = node->right;
            free(temp);
            
        }
        else{
            struct node *temp = predecessor(node);
            node->value = temp->value;
            node->left = deleteAVL(node->left,temp->value);
            node->height = update_height(node);            
        }
    }

    int balance = balance_factor(node);
    if(balance > 1){
        if(balance_factor(node->left) >= 0){
            node = rotate_right(node);
        }
        else{
            node->left = rotate_left(node->left);
            node = rotate_right(node);
        }
    }
    else if(balance < -1){
        if(balance_factor(node->right) <= 0){
            node = rotate_left(node);
        }
        else{
            node->right = rotate_right(node->right);
            node = rotate_left(node);
        }
    }
    return node;
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
    
    BST *bst = constructBST(arr,1);
    traverse_in_order(bst->root);
    printf("\n");
    traverse_pre_order(bst->root);
    printf("\n");
    traverse_post_order(bst->root);
    printf("\n");  

    printf("Height of tree is: %d", bstHeight(bst));
    printf("Height of tree is: %d\n", bst->root->height);

  

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