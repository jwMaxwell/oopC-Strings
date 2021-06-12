# Accessing String Data
OopC-Strings have 2 important pieces of data: **value** and **length**. Value contains the raw char array that makes up the String. This may be important for some standard functions that only accept C strings. Length, is the length of the string. Both are pretty straight forward.

```
String* str = new_String("Hello, world!\n");
printf("My String: %s", str->value); // this will print "Hello, world!"

// this will increment the value of each char by one
for (unsigned i = 0; i < str->length; ++i) {
  str->value[i] += 1;
}
```

As you may have noticed, oopC-Strings use arrows rather than dots to access data. This is since each String must be a pointer (similar to FILE pointers).

[Next document](./3_capitalization.md)
