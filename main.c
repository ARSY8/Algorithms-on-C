#include <stdio.h>
#include "insertion_sort.h"


int main(void) {

	int int_arr[] = { -5, 7, -2, 10, 5, -3, 9, 8 };
	float float_arr[] = { 3.14, -1.5, 0, 2.71, -8.25, 5.5 };
	char char_arr[] = "Hello World";

	char data_type = 'f';

	int (*compare[])(void*, void*) = { compare_int, compare_float, compare_char };

	if (data_type == 'i') {
		size_t size_in_bytes = sizeof(int);
		int len = sizeof(int_arr) / sizeof(int_arr[0]);
		insertion_sort(int_arr, len, size_in_bytes, compare[1]);
		for (int i = 0; i < len; ++i) {
			printf("%d ", int_arr[i]);
		}
	}
	else if (data_type == 'f') {
		size_t size_in_bytes = sizeof(float);
		int len = sizeof(float_arr) / sizeof(float_arr[0]);
		insertion_sort(float_arr, len, size_in_bytes, compare[2]);
		for (int i = 0; i < len; ++i) {
			printf("%.2f ", float_arr[i]);
		}
	}
	else if (data_type == 'c') {
		size_t size_in_bytes = sizeof(char);
		int len = sizeof(char_arr) / sizeof(char_arr[0]);
		insertion_sort(char_arr, len, size_in_bytes, compare[3]);
		for (int i = 0; i < len; ++i) {
			printf("%c ", char_arr[i]);
		}
	}
	return 0;
}