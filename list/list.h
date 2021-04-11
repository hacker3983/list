#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct list {
	int osize; // original size
	int size; // array index size
	int* arr; // array
	int malloced; // sets when memory is allocated
};
// sets the size of array
void set(struct list* list) {
	list->osize = 1;
	list->size = 0;
}
// allocates memory
void allocate(struct list* list) {
	list->arr = (int*)malloc(list->osize * sizeof(int));
	list->malloced = 1;
}
// appends an element
void append(struct list* list, int value) {
	if(list->size == 0) {
		allocate(list);
	}
	list->osize++;
	list->size++;
	list->arr = (int*)realloc(list->arr, list->osize*sizeof(int));
	list->arr[list->size-1] = value;
}
// removes element
void removel(struct list* list, int x) {
	struct list list2;
	int found = 0;
	set(&list2);
	for(int i=0;i<list->size;i++) {
		if(list->arr[i] == x) {
			if(found != 1) found++;
			else append(&list2, list->arr[i]);
		} else {
			append(&list2, list->arr[i]);
		}
	}
	free(list->arr);
	list->size = list2.size;
	list->osize = list2.osize;
	list->arr = list2.arr;
}

// prints out elements
void print(struct list list) {
	if(list.size == 0) {
		printf("Error: array is empty\n");
	} else {
		for(int i=0;i<list.size;i++) {
			printf("%d\n", list.arr[i]);
		}
	}
}

// returns the index position of a given element
int indexl(struct list list, int x) {
	for (int i=0;i<list.size;i++) {
		if(list.arr[i] == x) {
			return i;
		}
	}
	return -1;
}
// counts the amount of time a given element is in the list
int count(struct list list, int x) {
	int amount = 0;
	for (int i=0;i<list.size;i++) {
		if(list.arr[i] == x) amount++;
	}
	return amount;
}
// reverses the list
void reverse(struct list* list) {
	struct list list2;
	set(&list2);
	for(int i=list->size-1;i>=0;i--) {
		append(&list2, list->arr[i]);
	}
	free(list->arr);
	list->size = list2.size;
	list->osize = list2.osize;
	list->arr = list2.arr;
}
// frees memory and resets everything
void release(struct list* list) {
	list->osize = 0;
	list->size = 0;
	if(list->malloced == 1) {
		list->malloced = 0;
		free(list->arr);
	}
}
