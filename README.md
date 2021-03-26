# list
A list library for c, dynamically allocated array.
# Examples:
```c
// appending elements to the list and printing
#include <stdio.h>
#include <list/list.h>

int main() {
  struct list list;
  set(&list); // sets the startup options for the list
  for(int i=10;i<0;i++) {
    append(&list, i);
  }
  print(list); // prints the list
  release(); // frees the memory that has been used
}
```
```c
// removing elements from the list
#include <stdio.h>
#include <list/list.h>

int main() {
  struct list list;
  set(&list);
  for(int i=0;i<10;i++) {
    append(&list, (i)+1);
  }
  printf("List before element has been removed:\n");
  print(list);
  printf("List after element has been removed:\n");
  removel(&list, 4); // removes the element 4
  print(list);
  release(&list);
  return 0;
}
```
