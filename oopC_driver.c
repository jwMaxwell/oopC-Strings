#include "stdio.h"
#include "stdlib.h"
#include "oopString.h"

int main() {
  String* s = new_String("Hello, World!\n");
  String* temp = new_String("World");
  
  // test string value
  printf("s value: %s\n", s->value);

  // test length
  printf("s length: %d\n", s->length);

  // test charat
  printf("charat 1: %c\n", s->charat(s, 1));

  // test concatination
  printf("s + temp: %s\n", s->cat(s, temp)->value);

  // test includes
  printf("includes 'world': %s\n", s->includes(s, "world") ? "true" : "false");
  printf("includes 'python': %s\n", s->includes(s, "python") ? "true" : "false");

  // test indexof
  printf("index of 'world': %d\n", s->indexof(s, "world"));

  // test lastindexof
  printf("lio 'l': %d\n", s->lastindexof(s, "l"));

  // test print
  printf("print: ");
  s->print(s->cat(s, new_String("testing\n")));

  // test substring
  printf("substring(3, 8): %s\n", s->substring(s, 3, 8)->value);
  
  free(temp);
  free(s);
  return 0;
}
