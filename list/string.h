#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct _string {
	struct list* list; // list
	int size; // size of the list
	int osize; // full sizeof the list
	int isinit; // used for checking if list is initialized
} string_t;
// initialize the list
void string_init(string_t* string) {
	string->osize = 1;
	string->size = 0;
	string->list = malloc(1*sizeof(struct list));
	set(&string->list[string->size]);
	string->isinit = 1;
}
void string_pushchar(string_t* string, char c) {
	if(string->isinit == 1) {
		if(string->size == 0) {
			append(&string->list[string->size], c);
			string->size++;
			string->osize++;
			string->list = realloc(string->list, string->osize*sizeof(struct list));
		} else {
			append(&string->list[string->size-1], c);
		}
	}
}
// appends a string to the list
void string_pushback(string_t* string, char* buff) {
	if(string->isinit == 1) {
		string->size++;
		string->osize++;
		for(int i=0;i<strlen(buff);i++) {
			append(&string->list[string->size-1], buff[i]);
		}
		string->list = realloc(string->list, string->osize*sizeof(struct list));
		set(&string->list[string->osize-1]);
	}
}
void string_clear(string_t* string) {
	if(string->isinit == 1) {
		release(&string->list[string->size-1]);
	}
}
// compares a given string in the list
bool string_compare(string_t* string, char* buff) {
	if(string->isinit == 1) {
		int x=0, c, list_size, size = string->size;
		if(size == 0) {
			size = string->size;
			list_size = string->list[size].size;
		} else {
			size = string->size-1;
			list_size = string->list[size].size;
		}
		if(buff == NULL) {
			return false;
		}
		if(strlen(buff) != list_size) {
			return false;
		}
		for(int i=0;i<list_size;i++) {
			c = string->list[size].arr[i];
			if(buff[x] != c) {
				return false;
			}
			x++;
		}
		return true;
	}
	return false;
}

// finds the index position of a given string
int string_index(string_t string, char* buff) {
	if(string.isinit == 1) {
		for(int i=0;i<string.size;i++) {
			int idx = 0;
			if(strlen(buff) == string.list[i].size) {
				for(int x=0;x<string.list[i].size;x++) {
					if(buff[idx] != string.list[i].arr[x]) {
						break;
					}
					idx++;
				}
			}
			if(idx == string.list[i].size) {
				return i;
			}
		}
	}
	return -1;
}
// count the amount of time a given string is in the list
int string_count(string_t string, const char* str) {
	int amount = 0;
	if(string.isinit == 1) {
		for(int i=0;i<string.size;i++) {
			if(strlen(str) == string.list[i].size) {
				int l_size = string.list[i].size, failed=0, idx=0;
				for(int x=0;x<l_size;x++) {
					if(str[idx] != string.list[i].arr[x]) { failed = 1; break; }
					idx++;
				}
				if(failed == 0) amount++;
			}
		}
	}
	return amount;
}
// print the list
void string_print(string_t string) {
	if(string.isinit == 1) {
		printf("[");
		if(string.size == 0) {
			if(string.list[0].size != 0) printf("'");
			for(int i=0;i<string.list[0].size;i++) {
				printf("%c", string.list[0].arr[i]);
			}
			if(string.list[0].size != 0) printf("'");
		}
		for(int i=0;i<string.size;i++) {
			printf("'");
			for(int x=0;x<string.list[i].size;x++) {
				printf("%c", string.list[i].arr[x]);
			}
			printf("'");
			if(i != string.size-1) printf(", ");
		}
		printf("]\n");
	}
}
// free memory used by the list
void string_free(string_t* string) {
	if(string->isinit == 1) {
		string->isinit = 0;
		for(int i=0;i<string->size;i++) { release(&string->list[i]); }
		string->size = 0;
		string->osize = 0;
		if(string->size == 0) {
			release(&string->list[string->size]);
		}
		free(string->list);
	}
}
