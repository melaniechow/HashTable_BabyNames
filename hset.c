#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hset.h"

unsigned long int good_hash(const char* s)
{
  fprintf(stderr,"todo: good_hash\n");
  exit(1);
}

unsigned long int bad_hash(const char* s)
{
  fprintf(stderr,"todo: bad_hash\n");
  exit(1);
}

hset* hset_new(unsigned long int(*hash_func)(const char*), size_t sz)
{
  fprintf(stderr,"todo: hset_new\n");
  exit(1);
}

size_t hset_size(hset* hs)
{
  fprintf(stderr,"todo: hset_size\n");
  exit(1);
}

double hset_load_factor(hset* hs)
{
  fprintf(stderr,"todo: hset_load_factor\n");
  exit(1);
}

size_t hset_max_bucket(hset* hs)
{
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
