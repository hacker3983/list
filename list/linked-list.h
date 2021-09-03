#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
	int data;
	struct linked_list* next;
} linked_t;

linked_t* linked_create(int val);
size_t linked_getlen(linked_t* list);
size_t linked_count(linked_t* list, int x);
void linked_push(linked_t** list, int x);
void linked_append(linked_t** list, int x);
void linked_reverse(linked_t** list);
void linked_merge(linked_t** list1, linked_t* list2);
void linked_remove(linked_t** list, int x);
void linked_print(linked_t* list);
void linked_free(linked_t* list);
// creates a new node at the start of the linked list
linked_t* linked_create(int val) {
	linked_t* new_list = (linked_t*)malloc(sizeof(linked_t));
	new_list->data = val;
	new_list->next = NULL;
	return new_list;
}
// inserts a new node at the front of the linked list
void linked_push(linked_t** list, int x) {
	linked_t* new_node = linked_create(0);
	new_node->data = x;
	if(*list == NULL) {
		*list = new_node;
		return;
	}
	new_node->next = *list;
	*list = new_node;
}
// appends a new node at the end of the linked list
void linked_append(linked_t** list, int x) {
	linked_t* new_node = linked_create(x), *last = *list;
	if(*list == NULL) {
		*list = new_node;
		return;
	}
	while(last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
}
// reverses the linked list
void linked_reverse(linked_t** list) {
	linked_t* new_list = NULL, *last = *list;
	while(last != NULL) {
		linked_push(&new_list, last->data);
		last = last->next;
	}
	linked_free(*list);
	*list = new_list;
}
// merges two linked lists
void linked_merge(linked_t** list1, linked_t* list2) {
	while(list2 != NULL) {
		linked_append(list1, list2->data);
		list2 = list2->next;
	}
}
// counts the amount of time a given integer occurs
size_t linked_count(linked_t* list, int x) {
	size_t count = 0;
	while(list != NULL) {
		if(list->data == x) count++;
		list = list->next;
	}
	return count;
}
// gets the length of the linked list
size_t linked_getlen(linked_t* list) {
	size_t size = 0;
	while(list != NULL) {
		size++;
		list = list->next;
	}
	return size;
}
// removes or deletes a given node in the linked list
void linked_remove(linked_t** list, int x) {
	linked_t* new_list = NULL, *last = *list;
	int found = 0;
	while(last != NULL) {
		if(last->data == x && !found) {
			found = 1; last = last->next; continue;
		}
		linked_append(&new_list, last->data);
		last = last->next;
	}
	linked_free(*list);
	*list = new_list;
}

// prints out the linked list
void linked_print(linked_t* list) {
	while(list != NULL) {
		printf("%d\n", list->data);
		list = list->next;
	}
}
// frees memory allocated by the linked list
void linked_free(linked_t* list) {
	while(list != NULL) {
		linked_t* temp = list->next;
		free(list);
		list = temp;
	}
}
#endif
