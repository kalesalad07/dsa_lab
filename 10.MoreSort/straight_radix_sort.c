#include <stdio.h>


int extract_place_digit(int num, int place){
    int index = num/place;
    index %= 10;
    return index;
}

void digit_counting_sort(int* A, int n, int place) 
{
    //place must contain 1,10,100....
    // Initialize array C with all 0s
    int k = 10; //0-9
    int B[n];
    int C[k];
    for (int i = 0; i < k; i++) 
    {
        C[i] = 0;
    }
    int index;
    // Count the number of times each element occurs in A and store it in C
    for (int j = 0; j < n; j++) 
    {
        index = extract_place_digit(A[j],place);
        C[index]++;
    }
    
    // Place the elements of A in B in the correct position
    for (int i = 1; i < k; i++) 
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--) 
    {
        index = extract_place_digit(A[j],place);
        B[C[index] - 1] = A[j];
        C[index]--;
    }
    for(int i = 0; i < n; i++){
        A[i] = B[i];
    }
    
}

int *radix_sort(int *A,int *B, int n){
    int max = A[0];
    for(int i = 0; i < n; i++){
        if( max < A[i]) max = A[i];
    }

    int b = 0;
    while(max > 0){
        b++;
        max = max/10;
    }
    int place = 1;
    
    for(int i = 0; i < b; i++){        
        digit_counting_sort(A, n, place);
        place = place*10;
    }
    return A;
}


int main() 
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &A[i]);
    }
    
    int B[n];
    int* sorted_array = radix_sort(A,B,n);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");
    return 0;
}