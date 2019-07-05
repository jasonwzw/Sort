#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertSort.h"
#include "MergeSort.h"

using namespace std;

template <typename T>
int __partition(T arr[], int l, int r){

    swap(arr[l],arr[rand()%(r-l+1)+l]);

    int p = arr[l];
    int v = l;
    for(int i = l+1; i <= r; i++){
        if(arr[i] < p){
            swap(arr[i], arr[v+1]);
            v++;
        }
    }
    swap(arr[l], arr[v]);

    return v;
}

template <typename T>
void __quickSort(T arr[], int l, int r){

    if(r - l <= 15){
        //optimization 2
        insertSort(arr, l, r);
        return;
    }

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n){

    srand(time(NULL));
    __quickSort(arr, 0, n-1);
}

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n,10);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);
    int *arr3 = SortTestHelper::copyIntArray(arr,n);
    int *arr4 = SortTestHelper::copyIntArray(arr,n);
    //SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    //SortTestHelper::testSort("Insert Sort", insertSort, arr2, n);
    //SortTestHelper::testSort("Insert Sort2", insertSort2, arr3, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr4, n);
    SortTestHelper::testSort("Merge SortBU", mergeSortBU, arr3, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    return 0;
}