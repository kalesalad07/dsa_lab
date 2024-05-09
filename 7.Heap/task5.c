#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

struct heap {
	struct person *p;
	int size;
	int capacity;
	int depth;
};
typedef struct heap* Heap;

Heap heap_create(){
	Heap h = (Heap)malloc(sizeof(struct heap));
	h->p = malloc(sizeof(struct person));
	h->size = 0;
	h->capacity = 1;
	h->depth = 0;
	return h;
}

void add_to_tree(Heap h, struct person person){

	h->p[h->size] = person;
    // printf("%d,%s,%d,%d,%d\n",h->p[h->size].id, h->p[h->size].name, h->p[h->size].age, h->p[h->size].height, h->p[h->size].weight);

	if((h->size)==(pow(2,(h->depth))-1)){
		h->size++;
		h->depth++;
		// h->capacity = (pow(2,(h->depth))-1);
        h->capacity *=2;
        // int cap = h->capacity;
		h->p = realloc(h->p,sizeof(struct person)*h->capacity);
	}

	else{
		h->size++;
	}

}

int parent(Heap h, int node){
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
	
	if (left>0 && left < h->size && h->p[left].height > h->p[largest].height){ 
		largest = left;
	}
	
	if (right>0 && right < h->size && h->p[right].height > h->p[largest].height){
		largest = right;
	}
	
	if (largest != index){
	
		struct person temp = h->p[index];
		
		h->p[index] = h->p[largest];
		h->p[largest] = temp;
		
		max_heapify(h, largest);
	}
}

void build_max_heap(Heap h){    // * needed? No
	for(int i = ((h->size)/2)-1;i>=0;i--){
		max_heapify(h,i);
	}
}

int nodes_at_level(Heap h, int d){
	if(d == h->depth){
		int missing = h->capacity - h->size;
		return(pow(2,d-1) - missing);
	}
	else{
		return(pow(2,d-1));
	}
}

int main(){

	Heap h = heap_create();
    FILE *fptr;
    fptr = fopen("dat1000.csv", "r");
    printf("enter number ");
    int n;
    scanf("%d",&n);
    struct person arr[n];
    for(int i =0;i<n;i++){
        char temp[100];
        // scanf("%s",temp);
        fscanf(fptr, "%d,%[^,],%d,%d,%d\n",&arr[i].id, temp, &arr[i].age, &arr[i].height, &arr[i].weight);
        arr[i].name = (char*)malloc((strlen(temp)+1)*sizeof(char));
        strcpy(arr[i].name,temp);
        // printf("%d,%s,%d,%d,%d\n",arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
    }

    fclose(fptr);

    for(int i=0;i<n;i++){
        add_to_tree(h,arr[i]);
    }

	// for(int i = 0;i<7;i++){
	// 	printf("%d ",h->p[i].height);
	// }

	printf("\n");

	build_max_heap(h);

	// printf("%d \n",parent(h,4));
	// printf("%d \n",right_child(h,5));
	// printf("%d \n",left_child(h,1));

	for(int i = 0;i<n;i++){
		// printf("%d ",h->p[i].height);
        printf("%d,%s,%d,%d,%d\n",h->p[i].id, h->p[i].name, h->p[i].age, h->p[i].height, h->p[i].weight);
	}

    return 0;

}


