#include <stdio.h>
#include <string.h>
#include "linked-list.h"

typedef struct hash_table {
	char* key;
	linked_t* value;
	struct hash_table* next;
} hash_t;
hash_t* hash_create(char* key, int value);
void hash_update(hash_t** hash, char* key, int value);
linked_t* hash_query(hash_t* hash, char* key);
void hash_print(hash_t* hash);
void hash_destroy(hash_t* hash);

hash_t* hash_create(char* key, int value) {
	hash_t* hash = malloc(sizeof(hash_t));
	hash->key = key;
	hash->value = linked_create(value);
	hash->next = NULL;
	return hash;
}

void hash_update(hash_t** hash, char* key, int value) {
	hash_t *last = *hash;
	if(*hash == NULL) {
		*hash = hash_create(key, value);
		return;
	}
	while(last->next != NULL) {
		if(strcmp(last->key, key) == 0) {
			linked_append(&last->value, value);
			return;
		}
		last = last->next;
	}
	if(strcmp(last->key, key) == 0) {
		linked_append(&last->value, value);
		return;
	}
	last->next = hash_create(key, value);
}

linked_t* hash_query(hash_t* hash, char* key) {
	while(hash != NULL) {
		if(strcmp(hash->key, key) == 0) {
			return hash->value;
		}
		hash = hash->next;
	}
	linked_t* value = NULL;
	return value;
}

void hash_print(hash_t* hash) {
	while(hash != NULL) {
		printf("%s:", hash->key);
		linked_t* value = hash->value;
		while(value != NULL) {
			printf("%d", value->data);
			if(value->next != NULL)  printf(", ");
			value = value->next;
		}
		printf("\n");
		hash = hash->next;
	}
}

void hash_destroy(hash_t* hash) {
	while(hash != NULL) {
		hash_t* temp = hash->next;
		linked_free(hash->value);
		free(hash);
		hash = temp;
	}
}
