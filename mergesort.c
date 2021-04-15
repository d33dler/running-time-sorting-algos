//
// Created by radubereja on 14-04-21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

int *dynamicSize(int cnt) {

    int *array = malloc(cnt* sizeof(int));
    if (!array) {
        printf("error");
        exit(EXIT_FAILURE);
    }
    return array;
}

int *copysArr(int lef, int rig, int arr[]) {

    int i;
    int *copy = dynamicSize((rig - lef) * sizeof(int));
    for (i = lef; i < rig; i++) {
        copy[i - lef] = arr[i];
    }
    return copy;
}

void mergeSort(int len, int arr[]) {

    int l, r, mid, idx, *lef, *rig;
    /*base case */
    if (len <= 1) {
        return;
    }
    /*recursive case: length >= 2 implies 0<length/2 < length */
    mid = len / 2;
    /*make copies of subarrays and sort them (recursion) */
    lef = copysArr(0, mid, arr);
    rig = copysArr(mid, len, arr);
    mergeSort(mid, lef);
    mergeSort(len - mid, rig);
    /*merge sorted subarrays */
    idx = 0;
    l = r = 0;
    while ((l < mid) && (r < len - mid)) {
        if (lef[l] < rig[r]) {
            arr[idx] = lef[l];
            l++;
        } else {
            arr[idx] = rig[r];
            r++;
        }
        idx++;
    }
    /*process trailing elements: either l < mid or r < length − mid */
    while (l < mid) {
        arr[idx] = lef[l];
        idx++;
        l++;
    }
    while (r < len - mid) {
        arr[idx] = rig[r];
        idx++;
        r++;
    }
    /*deallocating memory */
    free(lef);
    free(rig);
}