//
// Created by marvinle on 2018/12/12 5:07 PM.
//

// 快速排序

#include <cstdio>


void inline swap(int *a, int *b) {
    int temp  = *a;
    *a = *b;
    *b = temp;
}

int partion(int array[], int left, int right){
    // 目前采用第一个值作为分割
    int temp = array[left];
    int i = left, j = right;

    while(i < j){
        while(array[j] > temp && i < j){
            j--;
        }
        if(i < j) {
            array[i++] = array[j];

        }
        while(array[i] <= temp && i < j){
            i++;
        }
        if(i < j) {
            array[j--] = array[i];
        }
    }
    array[i] = temp;
    return i;
}


void _qsort(int array[], int left, int right) {
//    if(left >= right)
//        return;;
    if(left < right) {
        int mid = partion(array, left, right);
        _qsort(array, left, mid - 1);
        _qsort(array, mid + 1, right);
    }
}

void qsort(int array[], int len){
    _qsort(array, 0,len-1);
}

void test() {
    int array[] = {4,2,23,45,12,32};
    qsort(array, sizeof(array) / sizeof(int));

    for (int i = 0; i < sizeof(array) / sizeof(int); ++i) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int main() {
    test();
}