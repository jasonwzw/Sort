#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

template <typename T>
void __quickSort3(T arr[], int l, int r){

    if(r - l <= 15){
        //optimization 2
        insertSort(arr, l, r);
        return;
    }

    swap(arr[l],arr[rand()%(r-l+1)+l]);

    T p = arr[l];
    int lt = l;
    int gt = r+1;
    int i = l+1;
    while(i<gt){
        if(arr[i] < p){
            swap(arr[i],arr[lt+1]);
            lt++;
            i++;
        }
        else if(arr[i] > p){
            swap(arr[i],arr[gt-1]);
            gt--;
        }
        else{
            i++;
        }
    }
    swap(arr[l],arr[lt]);
    __quickSort3(arr, l, lt-1);
    __quickSort3(arr, gt, r);
}

template <typename T>
void quickSort3(T arr[], int n){

    srand(time(NULL));
    __quickSort3(arr, 0, n-1);
}

int main() {
    int n = 1000000;
    int *arr = SortTestHelper::generateRandomArray(n,0,10);
    int *arr2 = SortTestHelper::copyIntArray(arr,n);
    int *arr3 = SortTestHelper::copyIntArray(arr,n);
    int *arr4 = SortTestHelper::copyIntArray(arr,n);
    //SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    //SortTestHelper::testSort("Insert Sort", insertSort, arr2, n);
    //SortTestHelper::testSort("Insert Sort2", insertSort2, arr3, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr4, n);
    //SortTestHelper::testSort("Merge SortBU", mergeSortBU, arr3, n);
    //SortTestHelper::testSort("Quick Sort", quickSort, arr, n);
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort3", quickSort3, arr3, n);


    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    return 0;
}