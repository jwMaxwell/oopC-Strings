typedef struct _STRING_STRUCT String; 

struct _STRING_STRUCT {
  char* value;
  unsigned int length;
  char (*charat)(struct _STRING_STRUCT*, int);
  String* (*cat)(struct _STRING_STRUCT*, struct _STRING_STRUCT*);
  int (*includes)(struct _STRING_STRUCT*, char*);
  int (*indexof)(struct _STRING_STRUCT*, char*);
  int (*lastindexof)(struct _STRING_STRUCT*, char*);
  void (*print)(struct _STRING_STRUCT*);
  String* (*substring)(struct _STRING_STRUCT*, unsigned, unsigned);
  String* (*toupper)(struct _STRING_STRUCT*);
  String* (*tolower)(struct _STRING_STRUCT*);
  String* (*append)(struct _STRING_STRUCT*, void*, char);
  String* (*reverse)(struct _STRING_STRUCT*);
  String* (*map)(struct _STRING_STRUCT*, char(char));
};

String* new_String(char* value);
char _STRING_charat(String* self, int index);
String* _STRING_concat(String* self, String* other);
int _STRING_indexof(String* self, char *other);
int _STRING_includes(String* self, char *other);
int _STRING_lastindexof(String* self, char *other);
void _STRING_print(String* self);
String* _STRING_substring(String* self, unsigned start, unsigned end);
String* _STRING_toupper(String* self);
String* _STRING_tolower(String* self);
String* _STRING_append(String* self, void* val, char type);
String* _STRING_reverse(String* self);
String* _STRING_map(String* self, char (*func)(char));
