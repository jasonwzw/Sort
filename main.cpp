#include <iostream>
#include <cmath>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Heap.h"
#include "HeapSort.h"

using namespace std;

template <typename T>
void __shiftDown(T arr[], int n, int k){
    while(2*k+1<n){
        int j = 2*k+1;

        if(j+1<n && arr[j+1]>arr[j])
            j++;

        if(arr[k]>=arr[j])
            break;

        swap(arr[k],arr[j]);
        k=j;
    }
}

template <typename T>
void heapSort(T arr[], int n){

    for(int i=(n-1)/2;i>=0;i--)
        __shiftDown(arr,n,i);

    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        __shiftDown(arr,i,0);
    }
}

int main() {
    int n = 1000000;
    cout<<"Test for Random Array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1,n);
    int *arr3 = SortTestHelper::copyIntArray(arr1,n);
    int *arr4 = SortTestHelper::copyIntArray(arr1,n);
    int *arr5 = SortTestHelper::copyIntArray(arr1,n);
    int *arr6 = SortTestHelper::copyIntArray(arr1,n);
    //SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    //SortTestHelper::testSort("Insert Sort", insertSort, arr2, n);
    //SortTestHelper::testSort("Insert Sort2", insertSort2, arr3, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    //SortTestHelper::testSort("Merge SortBU", mergeSortBU, arr3, n);
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n);
    //SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort3", quickSort3, arr3, n);
    SortTestHelper::testSort("Heap Sort1", heapSort1, arr4, n);
    SortTestHelper::testSort("Heap Sort2", heapSort2, arr5, n);
    SortTestHelper::testSort("Heap Sort3", heapSort, arr6, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    int swapTimes=100;
    cout<<"Test for Random Nearly Ordered Array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    arr4 = SortTestHelper::copyIntArray(arr1,n);
    arr5 = SortTestHelper::copyIntArray(arr1,n);
    arr6 = SortTestHelper::copyIntArray(arr1,n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort3", quickSort3, arr3, n);
    SortTestHelper::testSort("Heap Sort1", heapSort1, arr4, n);
    SortTestHelper::testSort("Heap Sort2", heapSort2, arr5, n);
    SortTestHelper::testSort("Heap Sort3", heapSort, arr6, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;


    cout<<"Test for Random Array, size = "<<n<<", random range [0, 10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1,n);
    arr3 = SortTestHelper::copyIntArray(arr1,n);
    arr4 = SortTestHelper::copyIntArray(arr1,n);
    arr5 = SortTestHelper::copyIntArray(arr1,n);
    arr6 = SortTestHelper::copyIntArray(arr1,n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n);
    SortTestHelper::testSort("Quick Sort3", quickSort3, arr3, n);
    SortTestHelper::testSort("Heap Sort1", heapSort1, arr4, n);
    SortTestHelper::testSort("Heap Sort2", heapSort2, arr5, n);
    SortTestHelper::testSort("Heap Sort3", heapSort, arr6, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
//    MaxHeap<int> maxHeap = MaxHeap<int>(100);
//
//    srand(time(NULL));
//    for(int i=0;i<50;i++)
//        maxHeap.insert(rand()%100);
//
//    maxHeap.testPrint();
//
//    while(!maxHeap.isEmpty())
//        cout<<maxHeap.extractMax()<<" ";
//    cout<<endl;

    return 0;
}