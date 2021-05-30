#include <stdlib.h>
#include <string.h>

typedef struct char_s {
	char* buff;
	size_t size;
	int idx;
	int init;
} char_t;

// initialize char_t structure
void char_init(char_t* mychar) {
	mychar->buff = calloc(1, sizeof(char*));
	mychar->size = 1;
	mychar->idx = 0;
	mychar->init = 1;
}
// push a character to the structure
bool char_push(char_t* mychar, char c) {
	if(mychar->init == 1) {
		mychar->buff[mychar->idx] = c;
		mychar->size++;
		mychar->idx++;
		mychar->buff = realloc(mychar->buff, mychar->size*sizeof(char*));
		return true;
	}
	return false;
}
// push a char pointer to the structure
bool char_pushptr(char_t* mychar, char* buff) {
	if(buff != NULL && mychar->init) {
		mychar->size += strlen(buff);
		mychar->buff = realloc(mychar->buff, mychar->size*sizeof(char*));
		strcat(mychar->buff, buff);
		mychar->idx += mychar->size-1;
		return true;
	}
	return false;
}
// frees memory and resets everything
void char_free(char_t* mychar) {
	if(mychar->init == 1) {
		free(mychar->buff);
		mychar->size = 0;
		mychar->idx = 0;
		mychar->init = 0;
	}
}
