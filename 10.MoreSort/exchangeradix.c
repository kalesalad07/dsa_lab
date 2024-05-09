#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void display(int* arr, int start, int end) {
    printf("arr: ");
    for (int i = start; i < end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void radixExchangeSort(int *arr, int start, int end, int bit, int first, int last) {
    // printf("18: %d %d %d %d\n", bit, first, last, end);
    // display(arr, first, last+1);
    // printf("\n");
    if (bit < 0 || start >= end) {
        return;
    }
    int startMSB, endMSB, temp;
    while (start < end) {
        startMSB = (((arr[start] & (int) pow(2, bit)) == 0) ? 0:1);
        endMSB = (((arr[end] & (int) pow(2, bit)) == 0) ? 0:1);
        if (startMSB > endMSB) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
        startMSB = (((arr[start] & (int) pow(2, bit)) == 0) ? 0:1);
        endMSB = (((arr[end] & (int) pow(2, bit)) == 0) ? 0:1);
        if (startMSB == 0) start++;
        if (endMSB == 1) end--;
    }

    end = first;
    while (((arr[end] >> bit) & 1) == 0 && end < last) {
        end++;
    }
    end--;
    // printf("50: %d %d %d %d\n", bit, first, last, end);
    // display(arr, first, end+1);
    // display(arr, 0, 6);
    // printf("\n");
    radixExchangeSort(arr, first, end, bit-1, first, end);

    end = last;
    while (((arr[end] >> bit) & 1) == 1 && end > first) {
        end--;
    }
    end++;
    // printf("61: %d %d %d %d\n", bit, first, last, end);
    // display(arr, end, last+1);
    // display(arr, 0, 6);
    // printf("\n");
    radixExchangeSort(arr, end, last, bit-1, end, last);
}

int main() {
    int arr[] = {6, 9, 8, 5, 7, 4, 1, 2, 3, 0};
    int length = 10;
    int max = arr[0];
    for (int i = 0; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    display(arr, 0, length);
    radixExchangeSort(arr, 0, length-1, floor(log2(max)), 0, length-1);
    display(arr, 0, length);
}