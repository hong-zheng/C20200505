#include "seqList.h"


void test(){
	seqList sl;
	seqListInit(&sl);
	//seqListPushBack(&sl, 1);
	//seqListPushBack(&sl, 2);
	//seqListPushBack(&sl, 3);
	//seqListPushBack(&sl, 4);
	//seqListPushBack(&sl, 5);
	//seqListPrint(&sl);
	//seqListPopBack(&sl);
	//seqListPrint(&sl);
	//seqListPopBack(&sl);
	//seqListPrint(&sl);
	//seqListPopBack(&sl);
	//seqListPrint(&sl);
	//seqListPopBack(&sl);
	//seqListPrint(&sl);
	//seqListPopBack(&sl);
	//seqListPrint(&sl);
	//seqListPopBack(&sl);
	seqListPushFront(&sl, 1);
	seqListPushFront(&sl, 2);
	seqListPushFront(&sl, 3);
	seqListPushFront(&sl, 4);
// Խ��Ƿ� ����
	//seqListPushFront(&sl, 5);
	//seqListPushFront(&sl, 6);
	//seqListPushFront(&sl, 7);
	seqListPrint(&sl);
	int find = seqListFind(&sl, 4);
	printf("find = %d\n", find);
	seqListPopFront(&sl);
	seqListPrint(&sl);

	seqListPopFront(&sl);
	seqListPrint(&sl);

	seqListPopFront(&sl);
	seqListPrint(&sl);

	seqListPopFront(&sl);
	seqListPrint(&sl);
	seqListInsert(&sl, 4, 12);
	seqListPrint(&sl);
	seqListErase(&sl, 0);
	seqListPrint(&sl);

	
}
void testsort(){
	int arr[] = {21,6,4,8,9,0,31,0,3,58,617,0,85,1046,38,95,61};
	int len = sizeof(arr) / sizeof(arr[0]);
	bubblesortH(arr, len);
	printArr(arr, len);
}
int main(void){
	//testsort();
	test();

	//int* ret = (int*)malloc(2);
	//realloc  �Դ��ͷ�free����,����Ҫ�����ֶ����ƣ������һ����ָ�룬���ܺ�mallocһ��
	// malloc ����ռ�ʧ�ܷ���NULL �����ÿ��Ӧ�õ�ʱ�򶼻�ȥ�ж�һ��

	system("pause");
	return 0;
}

