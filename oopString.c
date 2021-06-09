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

String* new_string(/*String* self, */char* value)
{
  String* self = calloc(1, sizeof(struct _STRING_STRUCT));
  
  self->value = value;
  self->length = strlen(value);

  return self;
}
