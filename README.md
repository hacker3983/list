# list
A list library for c, dynamically allocated array.
# Examples:
* appending elements and printing
```c
// appending elements to the list and printing
#include <stdio.h>
#include "list/list.h"

int main() {
  struct list list;
  set(&list); // sets the startup options for the list
  for(int i=10;i>-1;i--) {
    append(&list, i);
  }
  print(list); // prints the list
  release(&list); // frees the memory that has been used
}
```


* removing elements
```c
// removing elements from the list
#include <stdio.h>
#include "list/list.h"

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
![Removing Element](https://cdn.discordapp.com/attachments/709031059593101413/824833541551816724/unknown.png)
