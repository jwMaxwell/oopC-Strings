# oopC-Strings

Many claim that C is a procedural programming language and that creating classes in C is not possible. This project shows that C is object oriented and its classes function similarly to javascript (with some syntax differences of course).

This idea came to me when I learned about function pointers in C and decided to create a project where I could both use regular object strings and annoy strangers on the internet with pedantic semantics.

## Features
oopC-Strings have quite a number of modern features such as
1. Length data
2. String concatination
3. includes()
4. indexof()
5. lastindexof()
6. substring()
7. print()
8. A contructor "method"

## How to use oopC-Strings
Since the C programming language was not made to be an object oriented language, some of the syntax and use cases may be a little unintuitive. Each string object that is made must be a pointer, similar to a FILE pointer. 

```
String *s = new_String("Hello, world!");
```

To ease the process of switching to C objects, I tried to make the naming scheme as similar as possible to OOP langauges such as C++ and Java. Because there is no operator overloading in C, oopC-Strings rely on a traditional constructor, as shown above.

Because Strings are pointers, you will need to use arrow operators to access methods and data. To add to the differences, you will also need to include the object you want to act on in every method call, since the objects are ignorant of themselves

```
String *s = new_String("Hello, world!";
char c = s->charat(s, 3);
```

In order to get the value or length of a String, you can simply access their data as follows:

```
printf("%s - %d", s->value, s->length);
```

### Bonus Tip

For ease of printing a string (or multiple), I've added a print method in the class as well
```
String *s = new_String("This is ");
s->print(s->cat(s, new_String("a String\n")));
// prints: 
// This is a String 
```

## To-do
1. IO oopC library
2. Add method to append any datatype
3. Add replace()
4. Add replaceAll()
5. Add reverse()
6. Add toUpperCase()
7. Add toLowerCase()
8. Add padStart()
9. Add padEnd()
