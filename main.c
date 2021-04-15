//
// Created by radubereja on 14-04-21.
//

#include "main.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include <stdio.h>
#include <stdlib.h> /* malloc, free */
#include <assert.h> /* assert */
#include <string.h>
#include <time.h>
#include <unistd.h>
#define BILLION  1000000000.0
#define CPU 1
#if CPU
#endif


void populateArr(int arrsort[],int len) {
    srand(clock());
    for (int i = 0; i < len; i++) {
        arrsort[i] = rand() ;
    }
}

void runMS( int arrsort[],int len) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    mergeSort(len,arrsort);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("MERGE-SORT ::  N = %d ; Running time = %f\n", len, cpu_time_used);
}

void runQS( int arrsort[],int len) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    quickSort(len,arrsort);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("QUICK-SORT ::  N = %d ; Running time = %f\n", len, cpu_time_used);
}

void runIS( int arrsort[],int len) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    insertionSort(len,arrsort);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("INSERT-SORT ::  N = %d ; Running time = %f\n", len, cpu_time_used);
}
void cloneArr(int arr[], int clone[], int len)  {
    for (int i=0; i<len; i++) {
        clone[i] = arr[i];
    }
}

int main(int argc, char *argv[]) {
    int arrn[8] = {10000,20000,30000,90000,120000,200000,250000,500000};

    for (int i = 0; i < 7; i++) {
        int arrsort[arrn[i]];
        int clone1[arrn[i]];
        int clone2[arrn[i]];
        populateArr(arrsort, arrn[i]);
        cloneArr(arrsort, clone1, arrn[i]);
        cloneArr(arrsort, clone2, arrn[i]);
        //runIS(arrsort, arrn[i]);
        runMS(clone1, arrn[i]);
        runQS(clone2, arrn[i]);
    }
    return 0;
}