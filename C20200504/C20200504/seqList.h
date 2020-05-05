#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1046
#define LEN 17
// 动态数据表
typedef int DataType;
typedef struct seqList{
	DataType* _array;
	size_t _size; // 无符号整形
	unsigned int _capacity;
}seqList;

void seqListInit(seqList* sl);

void seqListPushBack(seqList* sl, DataType value);
void seqListPopBack(seqList* sl);

void seqListPushFront(seqList* sl, DataType value);
void seqListPopFront(seqList* sl);
// 在pos位置前面插入一个数据
void seqListInsert(seqList* sl, size_t pos, DataType value);

// 删除pos位置的数据
void seqListErase(seqList* sl, size_t pos);

int seqListFind(seqList* sl, DataType value);
void seqListPrint(seqList* sl);



// 测排序
void printArr(int* ,int);
// 插入排序
void insertsort(int arr[], int len);
// shell
void shellsort(int arr[], int len);
// heap
void swap(int*, int, int);
void heapify(int arr[], int len, int parent);
void buildHeap(int arr[], int len);
void heapsort(int arr[], int len);

// quicksort
int partion(int arr[], int begin, int end);
void quicksort(int arr[], int len);
void QSORT(int *, int);

// 基数排序
void radix(int* arr, int len);

// 桶排序
void bucketsort(int arr[], int len);
// 选择排序
void selectsort(int arr[], int len);

// 冒泡排序
void bubblesort(int arr[], int len);
// 冒泡排序升级版
void bubblesortH(int arr[], int len);


#endif //__SEQLIST_H__