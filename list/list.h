#ifndef _LIST_H
#define _LIST_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct list {
	size_t size; // array index size
	int* arr; // array
};
// sets the size of array
void set(struct list* list) {
	list->size = 0;
	list->arr = (int*)malloc((list->size + 1) * sizeof(int));
}

// appends an element
void append(struct list* list, int value) {
	list->arr[list->size++] = value;
	list->arr = (int*)realloc(list->arr, (list->size + 1) * sizeof(int));
}

// removes element
void removel(struct list* list, int x) {
	struct list list2;
	int found = false;
	set(&list2);
	for(size_t i=0;i<list->size;i++) {
		if(list->arr[i] == x && !found) {
			found = true;
			i++;
			continue;
		}
		append(&list2, list->arr[i]);
	}
	free(list->arr);
	list->size = list2.size;
	list->arr = list2.arr;
}

// prints out elements
void print(struct list list) {
	if(list.size == 0) {
		printf("Error: array is empty\n");
	} else {
		for(size_t i=0;i<list.size;i++) {
			printf("%d\n", list.arr[i]);
		}
	}
}

// returns the index position of a given element
size_t indexl(struct list list, int x) {
	for (size_t i=0;i<list.size;i++) {
		if(list.arr[i] == x) {
			return i;
		}
	}
	return 0;
}
// counts the amount of time a given element is in the list
size_t count(struct list list, int x) {
	size_t amount = 0;
	for (size_t i=0;i<list.size;i++) {
		if(list.arr[i] == x) amount++;
	}
	return amount;
}
// reverses the list
void reverse(struct list* list) {
	struct list list2;
	set(&list2);
	for(size_t i=list->size-1;i>0;i--) {
		append(&list2, list->arr[i]);
	}
	append(&list2, list->arr[0]);
	free(list->arr);
	list->size = list2.size;
	list->arr = list2.arr;
}
// frees memory and resets everything
void release(struct list* list) {
	list->size = 0;
	free(list->arr);
}
#endif
