#include "stdio.h"
#include "stdlib.h"
#include "oopString.h"

int main() {
  String* s = new_string("Hello, World!\n");
  String* temp = new_string("World");
  printf("String: %s\nLength: %d\nChar at 0: %c\nIof world: %d\n",
      s->value, s->length, s->charat(s, 0), s->indexof(s, temp->value));

  printf("Concat: %s\n", s->cat(s, temp)->value);
  printf("Liof 'l': %d\n", s->lastindexof(s, "l"));
  
  free(temp);
  free(s);
  return 0;
}
