# list
A list library for c, dynamically allocated array.
# Examples:
```c
/*
appending elements to the list
*/
#include <stdio.h>
#include <list/list.h>

int main() {
  struct list list;
  set(&list);
  for(int i=10;i<0;i++) {
    append(&list, i);
  }
  release();
}
```
