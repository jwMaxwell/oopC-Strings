# Initializing Strings
Just like in regular Object Oriented Languages, to initialize an object, you must first call it's constructor. This must be done for each String, otherwise, the String methods will not be initialized.

```
String* str = new_String("Hello, world!\n");
```

You can also create anonymous Strings. This, however, is strongly discouraged as it will lead to memory being dynamically allocated and never freed. For some users, this will not be a big issue and I personally don't mind it so I thought I would share how this works.

```
String* str = new_String("Hello, ");

str->print(
    str->append(
      str, new_String("world!\n")
    )
);
```

[Next document](./2_accessing_data.md)
