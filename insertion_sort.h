#include <stddef.h>

int compare_int(void* a, void* b);
int compare_float(void* a, void* b);
int compare_char(void* a, void* b);
void insertion_sort(void* arr, int len, size_t size_in_bytes, int (*compare)(void*, void*));
void swap(void* a, void* b, size_t size);