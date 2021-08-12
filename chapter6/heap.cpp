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

}

int MAX_HEAP_EXTRACT(int *A) {
	return A[0];
}

void MAX_HEAP_INCREASE_KEY(int *A, int i) {

}

int MAX_HEAP_GET_MAXIMUM(int *A) {
	
	return A[0];
}

void PRINT_A(int *A, int size) {
	printf("+++++++++++++ PRINT_A ++++++++++++++\n");
	for (int i = 0; i < size; i++) {
		printf(" %d", A[i]);
	}
	printf("\n-------------------------------\n");
}
int main(int agrc, char **argv) {
	int A[ARRAY_SIZE] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7, 0, };
	HEAP_SIZE = 10;
	
	PRINT_A(A, ARRAY_SIZE);
	
	HEAP_SORT(A);
	
	PRINT_A(A,ARRAY_SIZE);
	return 0;
} 
