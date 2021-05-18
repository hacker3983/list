#include <stdlib.h>
#include <string.h>

typedef struct _easy_string_ {
	char** list;
	int osize;
	int size;
	int init;
} string_t;

void string_init(string_t* str) {
	str->osize = 1;
	str->size = 0;
	str->list = malloc(1*sizeof(char*));
	str->list[str->size] = malloc(1*sizeof(char));
	str->init = 1;
}

void string_pushchar(string_t* str, char c) {
	if(str->init == 1) {
		int idx, size = 0;
		if(str->size == 0) {
			str->size++;
		}
		idx = str->size-1;
		size = strlen(str->list[idx])+1;
		str->list[idx] = realloc(str->list[idx], size*sizeof(char));
		str->list[idx][size-1] = c;
	}
}
void string_pushback(string_t* str, const char* buff) {
	if(str->init == 1) {
		str->osize++;
		str->size++;
		int size = str->size-1;
		str->list[size] = realloc(str->list[size], strlen(buff)*sizeof(char));
		strcpy(str->list[size], buff);
		str->list = realloc(str->list, str->osize*sizeof(char*));
	}
}

void string_print(string_t str) {
	printf("[");
	for(int i=0;i<str.size;i++) {
		printf("'%s'", str.list[i]);
		if(i != str.size-1) printf(", ");
	}
	printf("]\n");
}

void string_free(string_t* str) {
	if(str->init == 1) {
		for(int i=0;i<str->osize;i++) {
			free(str->list[i]);
		}
		str->size = 0;
		str->osize = 0;
		free(str->list);
	}
}
