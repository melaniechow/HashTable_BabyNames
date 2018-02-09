#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hset.h"

bucket* bucket_cons(const char* s, unsigned long int hash, bucket* prev_head)
{
	bucket *add_bucket = malloc(sizeof (bucket));
	add_bucket->string = strdup(s);
	add_bucket->hash = hash;
	add_bucket->next = prev_head;
	return add_bucket;
}

size_t bucket_size(bucket* b)
{
	size_t num=0;
	while (b != NULL){
		num++;
		b=b->next;
	}
	return num;
}

int bucket_contains(const char* s, unsigned long int hash, bucket* b)
{
	while (b != NULL){
		if (b->hash == hash){
			if (strcmp (s, b->string) == 0){
				return 1;
			}
		}
		b=b->next;
	}
	return 0;
}

void bucket_show(bucket* b)
{
	while (b != NULL){
		fprintf(stdout, "(%s, %lu)", b->string, b->hash);
		b=b->next;
	}
}

void bucket_free(bucket* b)
{
	bucket *to_free;
	while (b != NULL){
		to_free=b;
		b=b->next;

		//char *str = (char *)malloc(sizeof(char));
		//str=strdup(to_free->string);
		free(to_free->string);
		free(to_free->next);
		free(to_free);
	}
	free(b);
}
