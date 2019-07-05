//
// Created by Jason Wang on 2019-07-05.
//

#ifndef SORT_MERGESORT_H
#define SORT_MERGESORT_H

template <typename T>
void __merge(T arr[], int l, int mid, int r){

    T aux[r-l+1];
    for(int i = l; i <= r; i++)
        aux[i-l] = arr[i];

    int i = l, j = mid + 1;
    for(int k = l; k <= r; k++){

        if(i > mid){
            arr[k] = aux[j-l];
            j++;
        }
        else if(j > r){
            arr[k] = aux[i-l];
            i++;
        }
        else if(aux[i-l] < aux[j-l]){
            arr[k] = aux[i-l];
            i++;
        }
        else{
            arr[k] = aux[j-l];
            j++;
        }
    }
}

//arr[l,r)
template <typename T>
void __mergeSort(T arr[], int l, int r){
    if(r - l <= 15){
        //optimization 2
        insertSort(arr, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    //optimization 1
    if(arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T arr[], int n){

    __mergeSort(arr, 0, n-1);
}

template <typename T>
void mergeSortBU(T arr[], int n){

    for(int size = 1; size <= n; size +=size)
        for(int i = 0; i + size < n; i += size + size)
            __merge(arr, i, i + size - 1, min(i + size +size -1, n - 1));
}
#endif //SORT_MERGESORT_H
