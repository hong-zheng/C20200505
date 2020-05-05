#include "seqList.h"

void seqListInit(seqList* sl){
	// 初始化数组
	sl->_capacity = 4;
	sl->_array = (int*)malloc(sizeof(DataType)*sl->_capacity);
	sl->_size = 0;
}
void checkCapacity(seqList* sl){
	// 增容
	if (sl->_size == sl->_capacity){
		sl->_capacity *= 2;
		DataType* newArray = (DataType*)malloc(sizeof(DataType)*sl->_capacity);
		// 拷贝
		memcpy(newArray, sl->_array, sl->_size*sizeof(DataType));
		// 释放空间
		free(sl->_array);
		sl->_array = newArray;

		//sl->_array = (DataType*)realloc(sl->_array, sizeof(DataType)*sl->_capacity);
	}
}
void seqListPushBack(seqList* sl, DataType value){
	checkCapacity(sl);
	sl->_array[sl->_size++] = value;
}
// 尾删
void seqListPopBack(seqList* sl){
	// 删除最后一个有效元素
	// 不需要释放空间
	if (sl->_size) // 0也存元素，但是_size必须>0 才表示有元素
		sl->_size--;
}
void seqListPushFront(seqList* sl, DataType value){
	checkCapacity(sl);
	// 元素移动，只能从后向前移动，防止元素覆盖
	size_t end = sl->_size; // size_t 无符号整形，注意使用情况，在结束时条件不为等于0，它的范围没有小于0
	while (end){
		sl->_array[end] = sl->_array[end - 1];
		--end;
	}
	sl->_array[0] = value;
	sl->_size++;
}
// 头删
void seqListPopFront(seqList* sl){
	//if (sl->_size){
	//	for (int i = 0; i < sl->_size-1; i++)
	//		sl->_array[i] = sl->_array[i + 1];
	//	--sl->_size;
	//}
	// 注意元素覆盖问题
	// 移动 ： 从前向后移动
	// 任然需要判断是否有元素
	if (sl->_size){
		size_t start = 1;
		while (start < sl->_size){
			sl->_array[start - 1] = sl->_array[start];
			++start;
		}
		// 如果不判断，删除最后一个元素时则会出现越界
		sl->_size--;
	}
}
// 在pos位置前面插入一个数据
void seqListInsert(seqList* sl, size_t pos, DataType value){
	// 判断位置是否合法
	if (pos <= sl->_size){
		checkCapacity(sl);
		// 位置合法
		// pos - size -1
		size_t end = sl->_size;
		while (end > pos){
			sl->_array[end] = sl->_array[end - 1];
			--end;
		}
		sl->_array[pos] = value;
		++sl->_size;
	}
	else{
		// 如果该位置不在范围内直接实现一个尾插
		seqListPushBack(sl, value);
		//checkCapacity(&sl);
		//sl->_array[sl->_size++] = value;
	}
}
// 删除pos位置的数据
void seqListErase(seqList* sl, size_t pos){
	if (pos < sl->_size){
		size_t start = pos + 1;
		while (start < sl->_size){
			sl->_array[start - 1] = sl->_array[start];
			++start;
		}
		--sl->_size;
	}
	//if (pos < sl->_size){
	//	size_t start = pos+1;
	//	while (start < sl->_size){
	//		sl->_array[start-1] = sl->_array[start];
	//		start++;
	//	}
	//	sl->_size--;
	//}
}
int seqListFind(seqList* sl, DataType value){
	//if (sl->_size){
	//	size_t start = sl->_size-1;
	//	while (start >= 0){
	//		if (sl->_array[start] == value){
	//			return sl->_array[start];
	//		}
	//		--start;
	//	}
	//}

	for (int i = 0; i < sl->_size; i++){
		if (sl->_array[i] == value)
			return sl->_array[i];
	}
	return -1;
}
void seqListPrint(seqList* sl){
	for (int i = 0; i < sl->_size; i++){
		printf("%d ", sl->_array[i]);
	}
	printf("\n");
}





// 插入排序
void insertsort(int arr[], int len){
	for (int i = 1; i < len; i++){
		if (arr[i] < arr[i - 1]){
			int  j = 0;
			int cur = arr[i];
			for (j = i - 1; j >= 0 && cur < arr[j]; j--){
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = cur;
		}
	}
}

// shell
void shellsort(int arr[], int len){
	int step = len / 2;
	while (step >= 1){
		for (int i = step; i < len; i++){
			if (arr[i] < arr[i - 1]){
				int j = 0;
				int cur = arr[i];
				for (j = i - step; j >= 0 && arr[j] > cur; j -= step){
					arr[j + step] = arr[j];
				}
				arr[j + step] = cur;
			}
		}
		step /= 2;
	}
}

// heap
void swap(int* arr, int i , int j ){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
void heapify(int arr[], int len, int parent){
	if (parent >= len)
		return;
	int c1 = 2 * parent + 1;
	int c2 = 2 * parent + 2;
	int max = parent;
	if (c1<len && arr[c1] > arr[parent]) max = c1;
	if (c2<len && arr[c2] > arr[max]) max = c2;
	if (max != parent){
		swap(arr, max, parent);
		heapify(arr, len, max);
	} 
}
void buildHeap(int arr[], int len){
	for (int i = (len - 2) / 2; i >= 0; i--){
		heapify(arr, len, i);
	}
}
void heapsort(int arr[], int len){
	buildHeap(arr, len);
	for (int i = len - 1; i >= 0; i--){
		swap(arr, i, 0);
		heapify(arr, i, 0);
	}
}
void printArr(int* arr, int len){
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// quicksort
int partion(int arr[], int begin, int end){
	int cen = arr[begin];
	while (begin < end){
		while (begin < end && arr[end] >= cen)
			end--;
		arr[begin] = arr[end];
		while (begin < end && arr[begin] < cen)
			begin++;
		arr[end] = arr[begin];
	}
	arr[begin] = cen;
	return begin;
}
void quicksort(int arr[], int begin , int end){
	if (begin < end){
		int cen = partion(arr, begin, end);
		quicksort(arr, begin, cen - 1);
		quicksort(arr, cen + 1, end);
	}
}
void QSORT(int * arr, int len){
	quicksort(arr, 0, len - 1);
}

// 基数排序
void radix(int* arr, int len){
	int tmp[MAX+1];
	memset(tmp, 0, sizeof(int)*(MAX + 1));

	for (int i = 0; i < len; i++){
		tmp[arr[i]]++;
	}
	for (int i = 0; i < MAX + 1; i++){
		while (tmp[i]--){
			printf("%d ", i);
		}
	}
	printf("\n");
}

// 桶排序
void bucketsort(int arr[], int len){
	// 1、控制进出桶次数
	for (int k = 1; k < MAX; k *= 10){
		// 建桶
		int tmp[10][LEN];
		memset(tmp, -1, sizeof(int)*LEN * 10);
		for (int j = 0; j < len; j++){
			// 161
			int m = arr[j] / k % 10;
			tmp[m][j] = arr[j];
		}
		// 出桶
		int kk = 0;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < len; j++){
				if (tmp[i][j] != -1){
					arr[kk++] = tmp[i][j];
				}
			}
		}
	}	
}

// 选择排序
void selectsort(int arr[], int len){
	for (int i = 0; i < len; i++){
		int min = i;
		for (int j = i + 1; j < len; j++){
			if (arr[j] < arr[min]){
				min = j;
			}
		}
		if (i != min){
			swap(arr, i, min);
		}
	}
}

// 冒泡排序
void bubblesort(int arr[], int len){
	for (int i = 0; i < len; i++){
		for (int j = 0; j < len - i - 1; j++){
			if (arr[j + 1] < arr[j]){
				swap(arr, j, j + 1);
			}
		}
	}
}

// 冒泡排序升级版
void bubblesortH(int arr[], int len){
	for (int i = 0; i < len; i++){
		// 标记当前轮是否有交换顺序的
		// 如果一次顺序都没交换，说明已经有序，不需要再做下一轮冒泡
		int flag = 1;
		for (int j = 0; j < len - i - 1; j++){
			if (arr[j + 1] < arr[j]){
				swap(arr, j, j + 1);
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}