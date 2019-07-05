//
// Created by Jason Wang on 2019-07-04.
//

#ifndef SORT_INSERTSORT_H
#define SORT_INSERTSORT_H

template <typename T>
void insertSort(T arr[], int n){

    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0; --j) {
            if(arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
            else
                break;
        }
    }
}

template <typename T>
void insertSort2(T arr[], int n){

    for (int i = 1; i < n; ++i) {
        //optimization replace swap with assignment
        T temp = arr[i];
        int j;
        for (j = i; j > 0; --j) {
            if(arr[j - 1] > temp)
                arr[j] = arr[j - 1];
            else
                break;
        }
        arr[j] = temp;
    }
}

template <typename T>
void insertSort(T arr[], int l, int r){
    for(int i = l + 1; i <= r; i++){
        T temp = arr[i];
        int j;
        for(j = i; j > l; j--){
            if(arr[j-1] > temp)
                arr[j] = arr[j-1];
            else
                break;
        }
        arr[j] = temp;
    }
}

#endif //SORT_INSERTSORT_H
