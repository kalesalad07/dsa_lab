#include <stdio.h>
#include <stdlib.h>

typedef struct node* NODE;
	struct node{
	float value;
	NODE next;
	};

typedef struct linked_list* LIST;
struct linked_list{
	int count;
	NODE head;
	};

LIST createNewList(){
	LIST myList;
	myList = (LIST) malloc(sizeof(struct linked_list));
	myList->count=0;
	myList->head=NULL;
	return myList;
}

NODE createNewNode(float value){
	NODE myNode;
	myNode = (NODE) malloc(sizeof(struct node));
	myNode->value = value;
	myNode->next=NULL;
	return myNode;
}

void insertFirst(NODE n1, LIST l1){
    if(l1->count == 0) {
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    }

    else{
        n1->next = l1->head;
		l1->head = n1;
        l1->count++;
    }

}

void plsSort(LIST l1){

	NODE sorted = NULL; 

	void sortedInsert(NODE newnode) 
	{ 
		/* Special case for the head end */
		if (sorted == NULL || (sorted)->value >= newnode->value) { 
			newnode->next = sorted; 
			sorted = newnode; 
			// printf("%f \n", sorted->value);
		} 
		else { 
			NODE current = sorted; 
			/* Locate the node before the point of insertion 
			*/
			while (current->next != NULL && current->next->value < newnode->value) { 
				current = current->next; 
			} 
			newnode->next = current->next; 
			current->next = newnode; 
		} 
	} 

	// function to sort a singly linked list 
	// using insertion sort 
	void insertionSort() 
	{ 
		
		NODE current = l1->head; 

		if(current==NULL){
			return;
		}
		// Traverse the given linked list and insert every 
		// node to sorted 
		while (current != NULL) { 
			
			// Store next for next iteration		
			NODE next = current->next;
			// insert current in sorted linked list 
			sortedInsert(current); 		
			// Update current 
			current = next; 
			
		} 
		// Update head to point to sorted linked list 
		l1->head = sorted; 
		
	}
	insertionSort(l1->head); 
}

void intervalSort(float arr[], int n)
{
    int i, j;
    // Create n empty buckets
    LIST b[n];
    for(i=0; i<n; i++)
    {
        b[i] = createNewList();
    }
	
    // Put array elements in different buckets
    for(i=0; i<n; i++)
    {
        insertFirst(createNewNode(arr[i]),b[(int)(n*arr[i])]);
    }

	
    // Sort individual buckets
    for(int i=0; i<n; i++)
    {
        plsSort(b[i]); // sortList() function has to be implemented
    }
	
    // // Concatenate all buckets (in sequence) into arr[]

	for(i=0, j=0; i<n; i++)
	{
		NODE temp = b[i]->head;
		while(temp != NULL)
		{
			arr[j++] = temp->value;
			temp = temp->next;
		}
	}

    
}

int main(){

    float arr[] = { 0.48, 0.52, 0.83, 0.91, 0.35, 0.12, 0.09, 0.43, 0.29, 0.35 };

    intervalSort(arr, 10);

    for (int i = 0; i < 10; i++){
        printf("%f ", arr[i]);
    }


    return 0;
}


