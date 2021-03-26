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
	list->osize = 10;
	list->size = 0;
}
// allocates memory
void allocate(struct list* list) {
	list->arr = malloc(list->osize * sizeof(int));
	list->malloced = 1;
}
// appends an element
void append(struct list* list, int value) {
	if(list->size == 0) {
		allocate(list);
	}
	list->osize += 10;
	list->size++;
	list->arr = realloc(list->arr, list->osize*sizeof(int));
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
	list->arr = malloc(list2.osize*sizeof(int));
	set(list);
	for(int i=0;i<list2.size;i++)
		append(list, list2.arr[i]);
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

void release(struct list* list) {
	list->osize = 0;
	list->size = 0;
	if(list->malloced == 1) {
		list->malloced = 0;
		free(list->arr);
	}
}
