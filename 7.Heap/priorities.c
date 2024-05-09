#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct heap {
    int *data;
    int size;
    int capacity;
    int depth;
};

typedef struct heap* Heap;

Heap heap_create(){
	Heap h = (Heap)malloc(sizeof(struct heap));
	h->data = malloc(sizeof(int));
	h->size = 0;
	h->capacity = 1;
	h->depth = 0;
	return h;
}

void add_to_tree(Heap h, int num){

	h->data[h->size] = num;

	if((h->size)==(pow(2,(h->depth))-1)){
		h->size++;
		h->depth++;
		// h->capacity = (pow(2,(h->depth))-1);
		h->capacity*=2;
		h->data = realloc(h->data,sizeof(int)*h->capacity);
	}

	else{
		h->size++;
	}

	}

int parent(Heap h, int node){
    if(node<0){
        return -1;
    }

	if(node%2==0){
		return((node-2)/2);
	}

	else{
		return((node-1)/2);
	}
}

int left_child(Heap h, int node){
	// return(h->data[2*node + 1]); i thought we eturn value not index
	if((2*node + 1)>h->size){
		return -1;
	}
	else{
		return 2*node + 1;
	}
}

int right_child(Heap h, int node){
	// return(h->data[2*node + 2]); same as above
	if((2*node + 2)>h->size){
		return -1;
	}
	else{
		return 2*node + 2;
	}
}

void max_heapify(Heap h, int index){
	int left = left_child(h, index);
	int right = right_child(h, index);
	int largest = index;
	
	if (left>0 && left < h->size && h->data[left] > h->data[largest]){ 
		largest = left;
	}
	
	if (right>0 && right < h->size && h->data[right] > h->data[largest]){
		largest = right;
	}
	
	if (largest != index){
	
		int temp = h->data[index];
		
		h->data[index] = h->data[largest];
		h->data[largest] = temp;
		
		max_heapify(h, largest);
	}
}

void build_max_heap(Heap h){    // * needed? No
	for(int i = ((h->size)/2)-1;i>=0;i--){
		max_heapify(h,i);
	}
}

void insert(Heap h, int value)
{
    add_to_tree(h, value);
    int index = h->size;
    while(parent(h,index)!= -1){
        max_heapify(h,index);
        index = parent(h,index);
    }
	max_heapify(h,index);
    return;
}

int maximum(Heap h)
{
    if (h->size == 0)
        return -1;    // -1 denotes that the heap is empty
    else
        return h->data[0];
}

int extract_maximum(Heap h)
{
    int max = maximum(h);
    // Complete the function here
    h->data[0] = h->data[h->size-1];
    h->size--;
    max_heapify(h,0);
    return max;
}

void increase_key(Heap h, int x, int k)
{
    h->data[x] = k;
    // Complete the function here
    while(parent(h,x)!= -1){
        max_heapify(h,x);
        x = parent(h,x);       
    }
	max_heapify(h,x);
    return;
}

int main(){
    Heap h = heap_create();

	add_to_tree(h,29);
	add_to_tree(h,15);
	add_to_tree(h,46);
	add_to_tree(h,54);
	add_to_tree(h,68);
	add_to_tree(h,62);
	add_to_tree(h,49);

	build_max_heap(h);

    int max = maximum(h);
    printf("%d \n",max);

    max= extract_maximum(h);
    printf("%d \n",max);

    for(int i = 0;i<6;i++){
		printf("%d ",h->data[i]);
	}

    printf("\n");

    max= extract_maximum(h);
    printf("%d \n",max);

    for(int i = 0;i<5;i++){
		printf("%d ",h->data[i]);
	}

    printf("\n");

    insert(h,64);
    for(int i = 0;i<6;i++){
		printf("%d ",h->data[i]);
	}

    printf("\n");

    increase_key(h, 4,98);
    for(int i = 0;i<6;i++){
		printf("%d ",h->data[i]);
	}

    printf("\n");

    max = maximum(h);
    printf("%d \n",max);    

    return 0;
}