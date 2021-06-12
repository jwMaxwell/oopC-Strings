#include "stdio.h"
#include "stdlib.h"
#include "oopString.h"

int main() {
  String* s = new_String("Hello, world!\n");
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

  // test toupper
  printf("toupper: %s", s->toupper(s)->value);

  // test tolower
  printf("tolower: %s", s->tolower(s)->value);

  // test append
  char c = 'a';
  void *ptr = &c;
  printf("append c: %s\n", temp->append(temp, ptr, 'c')->value);
  
  int i = 123;
  ptr = &i;
  printf("append i: %s\n", temp->append(temp, ptr, 'i')->value);

  unsigned u = 123;
  ptr = &u;
  printf("append u: %s\n", temp->append(temp, ptr, 'u')->value);

  double f = 321.123;
  ptr = &f;
  printf("append f: %s\n", temp->append(temp, ptr, 'f')->value);

  // test reverse
  printf("reverse: %s\n", s->reverse(s)->value);

  // test map
  char ascii_inc(char t) { return ++t; };
  char (*fnptr)(char) = &ascii_inc;
  printf("map: %s\n", s->map(s, fnptr)->value);
  
  free(temp);
  free(s);
  return 0;
}
