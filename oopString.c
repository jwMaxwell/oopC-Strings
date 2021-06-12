#include <string.h>
#include "oopString.h"
#include <stdlib.h>
#include <stdio.h>

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
  
  return new_String(temp);
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

int _STRING_includes(String *self, char *other) {
  if (self->indexof(self, other) == -1)
    return 0;
  return 1;
}

void _STRING_print(String* self) {
  printf("%s", self->value);
}

String* _STRING_substring(String *self, unsigned start, unsigned end) {
  char* buffer = malloc(sizeof(char) * (end - start));
  unsigned i;
  unsigned j;
  for (i = start, j = 0; i < end; ++i, ++j) {
    buffer[j] = self->value[i];
  }
  buffer[j] = '\0';

  return new_String(buffer);
}

String* _STRING_toupper(String* self) {
  char* buffer = malloc(sizeof(char) * self->length);
  for (unsigned i = 0; i < self->length; ++i) {
    buffer[i] = self->value[i];
    if (buffer[i] >= 'a' && buffer[i] <= 'z')
      buffer[i] -= 32;
  }
  return new_String(buffer);
}

String* _STRING_tolower(String* self) {
  char* buffer = malloc(sizeof(char) * self->length);
  for (unsigned i = 0; i < self->length; ++i) {
    buffer[i] = self->value[i];
    if (buffer[i] >= 'A' && buffer[i] <= 'Z')
      buffer[i] += 32;
  }
  return new_String(buffer);
}

String* _STRING_append(String* self, void* val, char type) {

  if (type == 'c') { // see if integer method works on characters as well
    char* result = malloc(sizeof(char) * (self->length + 1));
    result[self->length] = '\0';
    
     unsigned i;
     for (i = 0; i < self->length; ++i)
       result[i] = self->value[i];
     result[i] = *((char*) val);
    
    return new_String(result);

    // snprintf(result, sizeof(char) * (self->length + 1), "%s%c", self->value, *((char*) val));
    return new_String(result);
  }
  else if (type == 'i') {
    char* result = malloc(sizeof(char) * (self->length + 10));
    snprintf(result, sizeof(char) * (self->length + 10), "%s%d", self->value, *((int*) val));
    return new_String(result);
  }
  else if (type == 'u') {
    char* result = malloc(sizeof(char) * (self->length + 10));
    snprintf(result, sizeof(char) * (self->length + 10), "%s%u", self->value, *((unsigned*) val));
    return new_String(result);
  }
  else if (type == 'f') {
    char* result = malloc(sizeof(char) * (self->length + 326));
    snprintf(result, sizeof(char) * (self->length + 326), "%s%f", self->value, *((double*) val));
    return new_String(result);
  }
  return self;
}

String* _STRING_reverse(String* self) {
  char* result = malloc(sizeof(char) * self->length);
  unsigned i, j;
  for (i = 0, j = self->length - 1; i < self->length; ++i, --j)
    result[i] = self->value[j];
  
  return new_String(result);
}

String* new_String(char* value)
{
  String* self = calloc(1, sizeof(struct _STRING_STRUCT));
  
  self->value       = value;
  self->length      = strlen(value);
  self->charat      = &_STRING_charat;
  self->indexof     = &_STRING_indexof;
  self->cat         = &_STRING_concat;
  self->lastindexof = &_STRING_lastindexof;
  self->includes    = &_STRING_includes;
  self->print       = &_STRING_print;
  self->substring   = &_STRING_substring;
  self->toupper     = &_STRING_toupper;
  self->tolower     = &_STRING_tolower;
  self->append      = &_STRING_append;
  self->reverse     = &_STRING_reverse;
  
  return self;
}
