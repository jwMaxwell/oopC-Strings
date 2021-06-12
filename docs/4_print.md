# Print
Print is a very simple method to use, however, it can easily be misused. In the first document, I talked about how you can create anonymous Strings. Anonymous Strings can be a bad idea since they will allocate memory but never free it. With the print method, it can be very easy and tempting to use anonymous String, however, this will eat up your memory over time.

```
String* str = new_String("Hello, world!\n");
str->print(str);

// try to avoid doing this unless you don't care (like me)
str->print(str->append(str, new_String("more lines haha\n\n\n"));
```

[Next document](./5_append.md)
