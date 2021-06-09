typedef struct _STRING_STRUCT String; 

struct _STRING_STRUCT {
  char* value;
  unsigned int length;
  char (*charat)(struct _STRING_STRUCT*, int);
  String* (*cat)(struct _STRING_STRUCT*, struct _STRING_STRUCT*);
  int (*includes)(struct _STRING_STRUCT*, char*);
  int (*indexof)(struct _STRING_STRUCT*, char*);
  int (*lastindexof)(struct _STRING_STRUCT*, char*);
};

String* new_string(char* value);
char _STRING_charat(String* self, int index);
String* _STRING_concat(String* self, String* other);
int _STRING_indexof(String* self, char *other);
int _STRING_lastindexof(String* self, char *other);
