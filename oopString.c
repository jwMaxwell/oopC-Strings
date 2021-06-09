#include "string.h"
#include "oopString.h"
#include <stdlib.h>

//typedef struct STRING_STRUCT {
  //char* value;
  //unsigned int length;
  //char (*charAt)(struct STRING_STRUCT*, int);
  //void (*cat)(struct STRING_STRUCT*, struct STRING_STRUCT*);
  //int (*includes)(struct STRING_STRUCT*, char*);
  //unsigned int (*indexOf)(struct STRING_STRUCT*, char*);
  //  unsigned int (*lastIndexOf)(struct STRING_STRUCT*, char*);
  //} String;

char _STRING_charat(String *self, int index) {
  return self->value[index];
}

String *_STRING_concat(String* self, String* other) {
  const unsigned SIZE = self->length + other->length - 1;
  char* temp = malloc(sizeof(char) * SIZE);
  temp[SIZE] = '\0';
  
  unsigned i;
  for (i = 0; i < self->length; ++i)
    temp[i] = self->value[i];
  for (i; i < SIZE + 1; ++i)
    temp[i] = other->value[i - self->length];
  
  return new_string(temp);
}

int _STRING_indexof(String *self, char *other) {
  unsigned j = 0;
  for (unsigned i = 0; i < self->length; ++i) {
    if (other[j] == '\0')
      return i - j;
    else if (self->value[i] == other[j]) 
      ++j;
    else
      j = 0;
  }
  return -1;
}

int _STRING_lastindexof(String *self, char *other) {
  int j = strlen(other) - 1;
  for (unsigned i = self->length - 1; i >= 0; --i) {
    if (j == -1)
      return i + 1;
    else if (self->value[i] == other[j])
      --j;
    else
      j = strlen(other) - 1;
  }
  return -1;
}

String* new_string(/*String* self, */char* value)
{
  String* self = calloc(1, sizeof(struct _STRING_STRUCT));
  
  self->value       = value;
  self->length      = strlen(value);
  self->charat      = &_STRING_charat;
  self->indexof     = &_STRING_indexof;
  self->cat         = &_STRING_concat;
  self->lastindexof = &_STRING_lastindexof;
  return self;
}
