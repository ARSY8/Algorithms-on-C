#include <stdio.h>


typedef enum {
	type_int,
	type_float,
	type_char,
} data_type;

void insertion_sort(void* arr, int len, size_t size_in_bytes, data_type type);
void swap(void* a, void* b, size_t size);
int compare_value(void* a, void* b, data_type type);

int main(void) {

	int int_arr[] = { -5, 7, -2, 10, 5, -3, 9, 8 };
	float float_arr[] = { 3.14, -1.5, 0.0, 2.71, -8.25, 5.5 };
	char char_arr[] = { "Hello World" };

	size_t size_data_type = sizeof(char_arr[0]);

	int len = sizeof(char_arr) / size_data_type;
	insertion_sort(char_arr, len, size_data_type, type_char);
	
	for (int i = 0; i < len; ++i) {
		printf("%c", char_arr[i]);
	}
	return 0;
}

void insertion_sort(void* arr, int len, size_t size_in_bytes, data_type type){

	for (int i = 1; i < len; i++) {
		for (int j = i; j > 0; --j) {
			void* current = (char*)arr + j * size_in_bytes;
			void* previous = (char*)arr + (j - 1) * size_in_bytes;

			if (compare_value(current, previous, type) == -1) {
				swap(current, previous, size_in_bytes);
			}
			else {
				break;
			}
		}
	}
}

int compare_value(void* a, void* b, data_type type) {
	switch (type) {
	case type_int:
		return *(int*)a < *(int*)b ? -1 : 0;
	case type_float:
		return *(float*)a < *(float*)b ? -1 : 0;
	case type_char:
		return *(char*)a < *(char*)b ? -1 : 0;
	default:
		return 0;
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