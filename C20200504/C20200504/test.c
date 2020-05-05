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
// 越界非法 访问
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
	//realloc  自带释放free机制,不需要后期手动机制，如果给一个空指针，功能和malloc一样
	// malloc 申请空间失败返回NULL ，因此每次应用的时候都会去判断一下

	system("pause");
	return 0;
}

