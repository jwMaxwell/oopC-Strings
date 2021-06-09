#include "stdio.h"
#include "stdlib.h"
#include "oopString.h"

int main() {
  String* s = new_string("Hello, World!\n");
  //(String*) malloc(sizeof(String));
  
  //  s = strinit(s, "Hello, world!");
  printf("%s", s->value);

  free(s);
  return 0;
}
