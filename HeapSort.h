//
// Created by jasonwzw on 7/12/19.
//

#ifndef SORT_HEAPSORT_H
#define SORT_HEAPSORT_H

#include "Heap.h"

template <typename T>
void heapSort1(T arr[], int n){

    MaxHeap<T> maxHeap = MaxHeap<T>(n);

    for(int i=0;i<n;i++)
        maxHeap.insert(arr[i]);

    for(int i=n-1;i>=0;i--)
        arr[i]=maxHeap.extractMax();
}

template <typename T>
void  heapSort2(T arr[], int n){

    MaxHeap<T> maxHeap = MaxHeap<T>(arr,n);
    for(int i=n-1;i>=0;i--)
        arr[i]=maxHeap.extractMax();
}
#endif //SORT_HEAPSORT_H
