#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hset.h"

unsigned long int good_hash(const char* s)
{
	unsigned long int ret=17;
	for (int i=0; i<strlen(s);i++){
		ret=ret*37 + s[i];
	}
	return ret;
}

unsigned long int bad_hash(const char* s)
{
	unsigned long int ret = strlen(s);
	return ret;
}

hset* hset_new(unsigned long int(*hash_func)(const char*), size_t sz)
{
	hset *hset_ret=malloc(sizeof (hset));
	hset_ret->hash_func = hash_func;
	bucket **new_buckets=malloc(sizeof(bucket*) * sz);
	//set each pointer in the array to an empty bucket, "NULL"
	for (int i=0; i<sz;i++){
		new_buckets[i]=NULL;
	}
	hset_ret->buckets=new_buckets;
	hset_ret->n_buckets=sz;
	return hset_ret;
}

size_t hset_size(hset* hs)
{
	size_t ret=0;
	for (int i=0; i<hs->n_buckets; i++){
		ret+=bucket_size(hs->buckets[i]);
	}
	return ret;
}

double hset_load_factor(hset* hs)
{
	double ret=(hset_size(hs)*1.0)/(hs->n_buckets);
	return ret;
}

size_t hset_max_bucket(hset* hs)
{
	size_t max=0;
	size_t compareVal;
	for (int i=0; i<hs->n_buckets; i++){
		compareVal=bucket_size(hs->buckets[i]);
		if (max < compareVal){
			max=compareVal;
		}
	}
	return max;
}

size_t hset_insert(const char* s, hset* hs)
{
	unsigned int long hash = hs->hash_func(s);
	int bucknum = hash%(hs->n_buckets);
	bucket *inserted_bucket=hs->buckets[bucknum];
	inserted_bucket=bucket_cons(s, hash, inserted_bucket);
	hs->buckets[bucknum]=inserted_bucket;
	return bucket_size(inserted_bucket);
}

int hset_contains(const char* s, hset* hs)
{
	unsigned int long hash=hs->hash_func(s);
	int bucknum=hash%(hs->n_buckets);
	return bucket_contains(s,hash,hs->buckets[bucknum]);
}

void hset_show(hset* hs)
{
	for (int i=0; i<hs->n_buckets ; i++){
		fprintf(stdout, "%d : ", i);
		bucket_show(hs->buckets[i]);
		fprintf(stdout, "\n");
	}
}

void hset_free(hset* hs)
{
	 if (hs==NULL){
		 fprintf(stderr,"todo: hset_free\n");
		 exit(1);
	}
	for (int i=0; i<hs->n_buckets ; i++){
		bucket_free(hs->buckets[i]);
	}
	free(hs->buckets);
	free(hs);
}
