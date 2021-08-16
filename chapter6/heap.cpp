#include <stdio.h>
#include <iostream> 

void PRINT_A(int *, int);

int HEAP_SIZE; 
int ARRAY_SIZE = 16;

int PARENT(int i) {
	return i/2;
}

int LEFT(int i) {
	return 2*i + 1;
}

int RIGHT(int i) {
	return 2*i + 2;
}

void swap(int* A, int i, int j) {
	int tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}
/*
 * 	
*/
void MAX_HEAPIFY (int* A, int i) {
	int max; 
	int l = LEFT(i);
	int r = RIGHT(i);
	
	max = i;
	if (l < HEAP_SIZE && A[l] > A[i]) {
		max = l;
	}
	if (r < HEAP_SIZE && A[r] > A[max]) {
		max = r;
	}
	
	if (max != i) {
		swap(A, i, max);
		MAX_HEAPIFY (A, max);
	}

}

void BUILD_MAX_HEAP(int *A) {
	int i; 
	for (int i = HEAP_SIZE/2 + 1; i >=0; i--) {
		MAX_HEAPIFY(A, i);
	}
}

void HEAP_SORT(int *A) {
	// build the HEAP 
	BUILD_MAX_HEAP(A);
	// get max number (first element in array, root)
	int numloop = HEAP_SIZE;
	for (int i = 0; i < numloop; i++) {
		swap(A, 0, HEAP_SIZE - 1);
		HEAP_SIZE--;
		MAX_HEAPIFY(A, 0);
	}
}


/******* FUnctions for priority queue ******/
void MAX_HEAP_INSERT(int *A, int value) {
	if (HEAP_SIZE + 1 > ARRAY_SIZE) {
		printf("MAX_HEAP_INSERT: HEAP overflow\n");
		return;
	}
	
	int parent;
	int i = HEAP_SIZE;
	HEAP_SIZE++;

	A[HEAP_SIZE - 1] = value;
	
	parent = PARENT(i);
	while (parent != i) {
		if (A[parent] < A[i]) {
			swap(A, parent, i);
			i = parent;
			parent = PARENT(i);
		}
		else 
			break;
	}
}

int MAX_HEAP_EXTRACT(int *A) {
	swap(A, 0, HEAP_SIZE-1);
	HEAP_SIZE--;
	MAX_HEAPIFY(A, 0);
	return A[HEAP_SIZE];
}

void MAX_HEAP_INCREASE_KEY(int *A, int i, int k) {
	if (i < 0 || i >= HEAP_SIZE) 
		return;

	if (k <= A[i]) {
		printf("MAX_HEAP_INCREASE_KEY: new value must bigger than old one\n");
		return;
	}
	A[i] = k;
	
	int parent = PARENT(i);
	while (parent != i) { 
		if (A[parent] < A[i]) {
			swap(A, parent, i);
			i = parent;
			parent = PARENT(i);
		}
		else 
			break;
	}
	
}

int MAX_HEAP_GET_MAXIMUM(int *A) {
	return A[0];
}

void PRINT_A(int *A, int size) {
	printf("[PRINT_A]: ");
	for (int i = 0; i < size; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}

void test_heap_sort(int *A) {
	printf("+++++++++++   test_heap_sort     ++++++++++++++\n");
	printf(" 1. Init ..\n");

	PRINT_A(A, ARRAY_SIZE);
	printf(" 2. Run HEAP_SORT ..\n");
	HEAP_SORT(A);
	printf(" 3. HEAP_SORT done\n");
	PRINT_A(A, ARRAY_SIZE);
	printf("-----------   test_heap_sort     ---------------\n\n\n");
}

void test_priority_queue_extract(int *A) {
	printf("+++++++++++    test_priority_queue_extract [void] ++++++++++++++\n");
	PRINT_A(A, HEAP_SIZE);
	printf("  Extracting ....\n");
	int max = MAX_HEAP_EXTRACT(A); 
	printf("  Extract Result: MAX = %d\n", max);
	// print output 
	PRINT_A(A, HEAP_SIZE);
	printf("-------------   test_priority_queue_extract [void] -------------------\n\n\n");
}

void test_priority_queue_insert(int *A, int value) {
	printf("+++++++++++++  test_priority_queue_insert [%d] ++++++++++++++++++\n", value);
	PRINT_A(A, HEAP_SIZE);
	printf("  MAX_HEAP inserting value %d...\n", value);
	MAX_HEAP_INSERT(A, value);
	printf("  MAX_HEAP_INSERT: done\n");
	PRINT_A(A, HEAP_SIZE);
	printf("-------------  test_priority_queue_insert [%d] ------------------\n\n\n", value);
}

void test_priority_queue_increase(int *A, int i, int k) {
	printf("+++++++++++++  test_priority_queue_increase [pos=%d, value=%d] ++++++++++++++++++\n", i, k);
	PRINT_A(A, HEAP_SIZE);
	printf("  MAX_HEAP_INCREASE_KEY(%d, %d) running ...\n", i, k);
	MAX_HEAP_INCREASE_KEY(A, i , k);
	printf("  MAX_HEAP_INCREASE_KEY done\n");
	PRINT_A(A, HEAP_SIZE);
	printf("-------------  test_priority_queue_increase  ------------------\n\n\n");
}

int main(int agrc, char **argv) {
	int A1[ARRAY_SIZE] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7, 0, };
	int A2[ARRAY_SIZE] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7, 0, };
	
	// test HEAP_SORT using A1 array 
	HEAP_SIZE = 10;
	test_heap_sort(A1);

	// test priority queue using A2 array 
	HEAP_SIZE = 10;
	BUILD_MAX_HEAP(A2);
	
	PRINT_A(A2,ARRAY_SIZE);

	test_priority_queue_extract(A2);
	test_priority_queue_insert(A2, 16);
	test_priority_queue_increase(A2, 8, 15);

	return 0;
} 
