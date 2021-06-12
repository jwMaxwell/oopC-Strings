# Common and Simple String Methods

### charat
Calling charat will return the char at a given index.
```
String* str = new_String("Hello, world!\n");

// traditional way
printf("%c\n", str->value[2]);

// charat
printf("%c\n", str->charat(str, 2));
```

### cat
Concatinating C strings can sometimes be a pain, however, with the cat method, the process is made easy.
```
String* str = new_String("Hello, world!\n");
String* new_str = str->cat(str, new_String("Goodbye, world!\n"));

// the value of new_str is now equal to:
// Hello, world!
// Goodbye, world!
```

### indexof
This method will find the index of the first occurence of a substring. If the given substring doesn't exist, indexof will return -1.
```
String* str = new_String("Hello, world!\n");
printf("%u\n", str->indexof(str, "world")); // prints "7"
```

### lastindexof
Similar to indexof, this method will also find the index of a given substring. The biggest difference between the two is that lastindexof will return the last occurence of the substring.
```
String* str = new_String("Hello, world!\n");
printf("%u", str->lastindexof(str, "l")); // prints "10"
```

### includes
While you could just use indexof to see if a given substring exists within the String, this method makes it simple for conditional statements. If the substring exists, it will return 1, otherwise it will return 0.
```
String* str = new_String("Hello, world!\n");
if (str->includes(str, "Hello")) {
  printf("Nice!\n");
}
```

### substring
Often we just want to have part of a given string rather than the whole thing. With this method, it is as easy to do as in Javascript!
```
String* str = new_String("Hello, world!\n");
printf("%s", str->substring(str, 3, 8)->value); // prints "lo, w"
```

### toupper
Sometimes its just easier to deal will uppercase letters only
```
String* str = new_String("Hello, world!\n");
printf("%s", str->toupper(str)->value); // prints "HELLO, WORLD!"
```

### tolower
Other times its just easier to deal will lowercase letters only
```
String* str = new_String("Hello, world!\n");
printf("%s", str->tolower(str)->value); // prints "hello, world!"
```

### reverse
What would you do if your String was backwards? I don't know about you but I would just use this handy reverse method!
```
String* str = new_String("Hello, world!");
printf("%s", str->reverse(str)->value) // prints "!dlrow ,olleH"
```

[Next document](./4_print.md)













