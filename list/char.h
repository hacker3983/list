#ifndef _CHAR_H
#define _CHAR_H
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct char_s {
	char* buff;
	size_t size;
	int length;
	int init;
} char_t;

// initialize char_t structure
void char_init(char_t* mychar) {
	mychar->buff = calloc(1, sizeof(char*));
	mychar->size = 1;
	mychar->length = 0;
	mychar->init = 1;
}
// push a character to the structure
bool char_push(char_t* mychar, char c) {
	if(mychar->init == 1) {
		mychar->buff[mychar->length] = c;
		mychar->size++;
		mychar->length++;
		char* ptr = mychar->buff;
		mychar->buff = calloc(mychar->size, sizeof(char*));
		strcpy(mychar->buff, ptr);
		free(ptr);
		return true;
	}
	return false;
}
// push a char pointer to the structure
bool char_pushptr(char_t* mychar, char* buff) {
	if(buff != NULL && mychar->init) {
		mychar->size += strlen(buff);
		char* ptr = mychar->buff;
		mychar->buff = calloc(mychar->size, sizeof(char*));
		strcpy(mychar->buff, ptr);
		strcat(mychar->buff, buff);
		mychar->length += strlen(buff);
		free(ptr);
		return true;
	}
	return false;
}
void char_reverse(char_t* mychar) {
	char_t list;
	char_init(&list);
	for(int i=mychar->length-1;i>=0;i--) {
		char_push(&list, mychar->buff[i]);
	}
	free(mychar->buff);
	mychar->size = list.size;
	mychar->length = list.length;
	mychar->buff = list.buff;
}
// frees memory and resets everything
void char_free(char_t* mychar) {
	if(mychar->init == 1) {
		free(mychar->buff);
		mychar->size = 0;
		mychar->length = 0;
		mychar->init = 0;
	}
}
#endif
