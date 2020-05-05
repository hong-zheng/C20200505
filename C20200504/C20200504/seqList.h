#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1046
#define LEN 17
// ��̬���ݱ�
typedef int DataType;
typedef struct seqList{
	DataType* _array;
	size_t _size; // �޷�������
	unsigned int _capacity;
}seqList;

void seqListInit(seqList* sl);

void seqListPushBack(seqList* sl, DataType value);
void seqListPopBack(seqList* sl);

void seqListPushFront(seqList* sl, DataType value);
void seqListPopFront(seqList* sl);
// ��posλ��ǰ�����һ������
void seqListInsert(seqList* sl, size_t pos, DataType value);

// ɾ��posλ�õ�����
void seqListErase(seqList* sl, size_t pos);

int seqListFind(seqList* sl, DataType value);
void seqListPrint(seqList* sl);



// ������
void printArr(int* ,int);
// ��������
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

// ��������
void radix(int* arr, int len);

// Ͱ����
void bucketsort(int arr[], int len);
// ѡ������
void selectsort(int arr[], int len);

// ð������
void bubblesort(int arr[], int len);
// ð������������
void bubblesortH(int arr[], int len);


#endif //__SEQLIST_H__