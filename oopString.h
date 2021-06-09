typedef struct _STRING_STRUCT String; 

struct _STRING_STRUCT {
  char* value;
  unsigned int length;
  char (*charAt)(struct _STRING_STRUCT*, int);
  void (*cat)(struct _STRING_STRUCT*, struct _STRING_STRUCT*);
  int (*includes)(struct _STRING_STRUCT*, char*);
  unsigned int (*indexOf)(struct _STRING_STRUCT*, char);
  unsigned int (*lastIndexOf)(struct _STRING_STRUCT*, char);
};

String* new_string(char* value);
char _STRING_charat(String* self, int index);
void _STRING_concat(String* self, String* other);
int _STRING_includes(String* self, char val);
unsigned int _STRING_indexof(String* self, char val);
unsigned int _STRING_lastindexof(String* self, char val);
