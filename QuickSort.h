//
// Created by Jason Wang on 2019-07-05.
//

#ifndef SORT_QUICKSORT_H
#define SORT_QUICKSORT_H
#include <iostream>

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

template <typename T>
int __partition2(T arr[], int l, int r){

    swap(arr[l],arr[rand()%(r-l+1)+l]);

    T p = arr[l];
    int i = l + 1;
    int j = r;
    while(true){
        while(arr[i]<p && i<=r)
            i++;
        while(arr[j]>p && j>=l+1)
            j--;
        if(i>j) break;
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    swap(arr[l], arr[j]);

    return j;
}

template <typename T>
void __quickSort2(T arr[], int l, int r){

    if(r - l <= 15){
        //optimization 2
        insertSort(arr, l, r);
        return;
    }

    int p = __partition2(arr, l, r);
    __quickSort2(arr, l, p-1);
    __quickSort2(arr, p+1, r);
}

template <typename T>
void quickSort2(T arr[], int n){

    srand(time(NULL));
    __quickSort2(arr, 0, n-1);
}

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
#endif //SORT_QUICKSORT_H
