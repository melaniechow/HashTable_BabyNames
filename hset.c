#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hset.h"

unsigned long int good_hash(const char* s)
{
	unsigned long int ret=17;
	for (int i=0; i<strlen(s);i++){
		ret=ret*37 + atoi(s[i]);
	}
	return ret;
	fprintf(stderr,"todo: good_hash\n");
	exit(1);
}

unsigned long int bad_hash(const char* s)
{
	unsigned long int ret = strlen(s);
	return ret;
	fprintf(stderr,"todo: bad_hash\n");
	exit(1);
}

hset* hset_new(unsigned long int(*hash_func)(const char*), size_t sz)
{
	hset *hset_ret=malloc(sizeof hset);
	hset_ret->hash_func = hash_func;
	bucket **new_buckets= (bucket **)malloc(sizeof (bucket*)*sz);
	hset_ret->buckets=new_buckets;
	hset_ret->n_buckets=sz;
	return hset_ret;
	fprintf(stderr,"todo: hset_new\n");
	exit(1);
}

size_t hset_size(hset* hs)
{
	size_t ret=0;
	for (int i=0; i<hs->sz; i++){
		ret+=bucket_size(hs->buckets[i]);
	}
	return ret;
	fprintf(stderr,"todo: hset_size\n");
	exit(1);
}

double hset_load_factor(hset* hs)
{
	
	fprintf(stderr,"todo: hset_load_factor\n");
	return (hset_size(hs)/(hs->sz))
	exit(1);
}

size_t hset_max_bucket(hset* hs)
{
	size_t max=0;
	size_t compareVal;
	for (int i=0; i<hs->sz; i++){
		compareVal=bucket_size(hs->buckets[i]);
		if (max < compareVal){
			max=compareVal;
		}	
	}
	return max;
	fprintf(stderr,"todo: hset_max_bucket\n");
	exit(1);
}

size_t hset_insert(const char* s, hset* hs)
{
	
	fprintf(stderr,"todo: hset_insert\n");
	exit(1);
}

int hset_contains(const char* s, hset* hs)
{
  fprintf(stderr,"todo: hset_contains\n");
  exit(1);
}

void hset_show(hset* hs)
{
  fprintf(stderr,"todo: hset_show\n");
  exit(1);
}

void hset_free(hset* hs)
{
  fprintf(stderr,"todo: hset_free\n");
  exit(1);
}
