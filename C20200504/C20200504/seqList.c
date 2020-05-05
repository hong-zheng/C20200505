#include "seqList.h"

void seqListInit(seqList* sl){
	// ��ʼ������
	sl->_capacity = 4;
	sl->_array = (int*)malloc(sizeof(DataType)*sl->_capacity);
	sl->_size = 0;
}
void checkCapacity(seqList* sl){
	// ����
	if (sl->_size == sl->_capacity){
		sl->_capacity *= 2;
		DataType* newArray = (DataType*)malloc(sizeof(DataType)*sl->_capacity);
		// ����
		memcpy(newArray, sl->_array, sl->_size*sizeof(DataType));
		// �ͷſռ�
		free(sl->_array);
		sl->_array = newArray;

		//sl->_array = (DataType*)realloc(sl->_array, sizeof(DataType)*sl->_capacity);
	}
}
void seqListPushBack(seqList* sl, DataType value){
	checkCapacity(sl);
	sl->_array[sl->_size++] = value;
}
// βɾ
void seqListPopBack(seqList* sl){
	// ɾ�����һ����ЧԪ��
	// ����Ҫ�ͷſռ�
	if (sl->_size) // 0Ҳ��Ԫ�أ�����_size����>0 �ű�ʾ��Ԫ��
		sl->_size--;
}
void seqListPushFront(seqList* sl, DataType value){
	checkCapacity(sl);
	// Ԫ���ƶ���ֻ�ܴӺ���ǰ�ƶ�����ֹԪ�ظ���
	size_t end = sl->_size; // size_t �޷������Σ�ע��ʹ��������ڽ���ʱ������Ϊ����0�����ķ�Χû��С��0
	while (end){
		sl->_array[end] = sl->_array[end - 1];
		--end;
	}
	sl->_array[0] = value;
	sl->_size++;
}
// ͷɾ
void seqListPopFront(seqList* sl){
	//if (sl->_size){
	//	for (int i = 0; i < sl->_size-1; i++)
	//		sl->_array[i] = sl->_array[i + 1];
	//	--sl->_size;
	//}
	// ע��Ԫ�ظ�������
	// �ƶ� �� ��ǰ����ƶ�
	// ��Ȼ��Ҫ�ж��Ƿ���Ԫ��
	if (sl->_size){
		size_t start = 1;
		while (start < sl->_size){
			sl->_array[start - 1] = sl->_array[start];
			++start;
		}
		// ������жϣ�ɾ�����һ��Ԫ��ʱ������Խ��
		sl->_size--;
	}
}
// ��posλ��ǰ�����һ������
void seqListInsert(seqList* sl, size_t pos, DataType value){
	// �ж�λ���Ƿ�Ϸ�
	if (pos <= sl->_size){
		checkCapacity(sl);
		// λ�úϷ�
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
		// �����λ�ò��ڷ�Χ��ֱ��ʵ��һ��β��
		seqListPushBack(sl, value);
		//checkCapacity(&sl);
		//sl->_array[sl->_size++] = value;
	}
}
// ɾ��posλ�õ�����
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





// ��������
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

// ��������
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

// Ͱ����
void bucketsort(int arr[], int len){
	// 1�����ƽ���Ͱ����
	for (int k = 1; k < MAX; k *= 10){
		// ��Ͱ
		int tmp[10][LEN];
		memset(tmp, -1, sizeof(int)*LEN * 10);
		for (int j = 0; j < len; j++){
			// 161
			int m = arr[j] / k % 10;
			tmp[m][j] = arr[j];
		}
		// ��Ͱ
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

// ѡ������
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

// ð������
void bubblesort(int arr[], int len){
	for (int i = 0; i < len; i++){
		for (int j = 0; j < len - i - 1; j++){
			if (arr[j + 1] < arr[j]){
				swap(arr, j, j + 1);
			}
		}
	}
}

// ð������������
void bubblesortH(int arr[], int len){
	for (int i = 0; i < len; i++){
		// ��ǵ�ǰ���Ƿ��н���˳���
		// ���һ��˳��û������˵���Ѿ����򣬲���Ҫ������һ��ð��
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