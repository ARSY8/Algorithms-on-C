#include "insertion_sort.h"


int compare_char(void* a, void* b) {
	return *(char*)a < *(char*)b ? -1 : 0;
}

int compare_int(void* a, void* b) {
	return *(int*)a < *(int*)b ? -1 : 0;
}

int compare_float(void* a, void* b) {
	return *(float*)a < *(float*)b ? -1 : 0;
}

void insertion_sort(void* arr, int len, size_t size_in_bytes, int (*compare)(void*, void*)) {
	for (int i = 1; i < len; i++) {
		for (int j = i; j > 0; --j) {
			void* current = (char*)arr + j * size_in_bytes;
			void* previous = (char*)arr + (j - 1) * size_in_bytes;

			if (compare(current, previous) == -1) {
				swap(current, previous, size_in_bytes);
			}
			else {
				break;
			}
		}
	}
}

void swap(void* a, void* b, size_t size) {
	char temp;
	size_t i;
	for (i = 0; i < size; i++) {
		temp = *((char*)b + i);
		*((char*)b + i) = *((char*)a + i);
		*((char*)a + i) = temp;
	}
}