# Map
Map allows you to perform a function on every single character in the string. The function that you pass to map must take a char parameter and return a char.

In order to pass a function to map, you will ned to either pass the memory address of the function or create a function pointer and pass that to the map method.

```
int main() {
  // two functions we will be passing
  char ascii_inc(char t) { return ++t };
  char ascii_dec(char t) { return --t };
  
  // how to create a function pointer
  char (*fnptr)(char) = &ascii_inc
  
  // declare the String
  String* str = new_String("Hello, world!\n");
  
  // map the functions to the string
  printf("%s\n", str->map(str, fnptr)->value); // result: Ifmmp-!Xpsme"
  printf("%s", str->map(str, &ascii_dec)->value);
  
  return 0;
}
```
