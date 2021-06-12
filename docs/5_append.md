# Append
In the 3rd document, I showed how to use the *cat* method. Cat will only work with two strings, which is limiting. Append will allow you to append almost any other datatype to your String (excluding Strings and C strings).

The structure of the append method is
```
String* append(String* self, void* val, char type);
```
This means that you will need to pass in itself (like always), pass a pointer or address of the value you want to append, and then you must identify the datatype that is being appended.
- Character = 'c'
- Integer = 'i'
- Unsigned = 'u'
- Floating point = 'f'

```
String* str = new_String("Hello, world!");

char c = 'a';
int i = -123;
unsigned u = 25;
double f = 123.321;
String* result1 = str->append(str, &c, 'c');   // Hello, world!a
String* result2 = str->append(str, &i, 'i');   // Hello, world!-123
String* result3 = str->append(str, &u, 'u');   // Hello, world!25
String* result4 = str->append(str, &f, 'f');   // Hello, world!123.321000
```

[Next document](./6_map.md)
