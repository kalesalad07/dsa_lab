#include <stdio.h>


int min(int a, int b){
    return (a > b) ? b : a;
}

void insertionsort(int *arr, int n){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        int v = arr[i];
        while(j >= 0 && v < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;        
    }
}

void swap(int *arr, int a, int b){
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

int part(int Ls[], int lo, int hi, int pInd){
    swap(Ls, pInd, lo);
    int pivPos, lt, rt, pv;
    lt = lo+1;
    rt = hi;
    pv = Ls[lo];


    while(lt < rt){
        for(; lt <= hi && Ls[lt] <= pv; lt++);
        for(; Ls[rt] > pv; rt--);

        if(lt < rt){
            swap(Ls, lt, rt);
            lt++;
            rt--;
        }
    }
    if(Ls[lt] < pv && lt <= hi) pivPos = lt;
    else pivPos = lt -1;

    swap(Ls, lo, pivPos);

    return pivPos;
}

int lomutoPart(int Ls[], int lo, int hi, int pInd){
    swap(Ls, pInd, hi);
    int i, j, pv;
    pv = Ls[hi];
    i = lo;
    j = lo;

    while(j < hi){
        if(Ls[j] <= pv){
            swap(Ls,i,j);
            j++;
            i++;
        }
        else{
            j++;
        }
    }
    swap(Ls,i,hi);
    return i;
}

int threePart(int Ls[], int lo, int hi, int pInd){
    swap(Ls, pInd, hi);
    int pivPos, lt, rt, mid, pv;
    lt = lo;
    rt = hi-1;
    mid = lo;
    pv = Ls[hi];

    while(mid <= rt){
        if(Ls[mid] < pv){
            swap(Ls, lt, mid);
            lt++;
            mid++;
        }
        else if(Ls[mid] > pv){
            swap(Ls,mid,rt);
            rt--;
        }
        else{
            mid++;
        }
    }
    swap(Ls,mid,hi);
    return mid;
}

int select(int L[], int n, int k){    
    if(k == 0) return L[0];
    if(n <= 5){
        for(int i = 1; i < n; i++){
            for(int j = i-1; j >=0; j--){
                if(L[j] > L[j+1]){
                    swap(L,j,j+1);
                }
                else break;
            }
        }
        return L[k-1];
    }
    
    int numGroups;
    if(n%5 == 0) numGroups = n/5;
    else numGroups = n/5 + 1;

    int medians[numGroups];
    
    for(int i = 0; i < numGroups; i++){
        medians[i] = select(L + (i*5), min(5, n - 5*i), min(5,n - i*5)/2);
    }

    int M = select(medians, numGroups, (numGroups+1)/2);

    int mInd;
    for(int i = 0; i < n; i++){
        if(L[i] == M){
            mInd = i;
            break;
        }
    }
    
    int pInd = part(L,0,n-1,mInd);

    if(k <= pInd){
        return select(L, pInd, k);        
    }
    else if (k > pInd + 1){
        return select(L+pInd + 1, n - pInd -1, k - pInd - 1);
    }
    else{
        return L[pInd];
    }
}

int qselect(int L[], int n, int k){
    int pivot = 0;
    int lo = 0;
    int hi = n-1;
    int pInd = part(L,lo,hi,pivot);
    if(k <= pInd) return qselect(L,pInd,k);
    else if(k > pInd +1) return qselect(L + pInd + 1, n - pInd -1, k - pInd - 1);
    else return L[pInd];
}

int pivot(int Ls[], int lo, int hi){
    int ele = select(Ls+lo,(hi-lo+1), (hi-lo+1)/2);
    //int ele = qselect(Ls+lo,(hi-lo+1), (hi-lo+1)/2);

    for(int i = lo; i <= hi; i++){
        if(Ls[i] == ele) return i;
    }
    return lo;
}

int partition(int Ls[], int lo, int hi, int p){
    return part(Ls,lo,hi,p);
    // return lomutoPart(Ls,lo,hi,p);
    // return threePart(Ls,lo,hi,p);
}

void qs(int Ls[], int lo, int hi){
    if(lo < hi){
        int p = pivot(Ls,lo,hi);
        printf("(lo,hi)-(%d,%d), partition index: %d\n",lo,hi,p);

        p = partition(Ls,lo,hi,p);
        qs(Ls,lo,p-1);
        qs(Ls,p+1,hi);
    }
}

void qs_hybrid(int Ls[], int lo, int hi){
    if(hi - lo < 10){
        insertionsort(Ls+lo, hi-lo+1);
        return;
    }
    else if(lo < hi){
        int p = pivot(Ls,lo,hi);
        p = partition(Ls,lo,hi,p);
        qs_hybrid(Ls,lo,p-1);
        qs_hybrid(Ls,p+1,hi);
    }
}


int main(){
    int arr[] = {2,3,4,5,1,23,4,8,9,7};
    qs_hybrid(arr,0,9);
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}