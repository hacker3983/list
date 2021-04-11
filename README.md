# list
A list library for c, dynamically allocated array.
# Whats new
* Fixed memory leaks
* Now works for C++
* int count(struct list list, int x) - counts the occurence of a given element
* void reversel(struct list* list) - reverses the list
* int indexl(struct list, int x) - finds the index of a given element
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
![Appending Elements](https://cdn.discordapp.com/attachments/709031059593101413/824836009665101834/unknown.png)

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
![Removing Element](https://cdn.discordapp.com/attachments/709031059593101413/824833948084731924/unknown.png)
* counting the occurence of an element
```c
// counting elements
#include <stdio.h>
#include "list/list.h"

int main() {
	struct list list;
	for(int i=2;i<10;i+=2) {
		append(&list, i);
		append(&list, 4);
	}
	print(list);
	printf("4 is in the list %d times\n", count(list, 4)); // amount of times 4 is in the list
	release(&list);
	return 0;
}
```
![Counting elements](https://cdn.discordapp.com/attachments/795649348364926986/830837631490457621/unknown.png)
* reverses the list
```c
// reverse list
#include <stdio.h>
#include "list/list.h"

int main() {
	struct list list;
	set(&list);
	for(int i=0;i<10;i++) { append(&list, i+i+1+1); }
	reverse(&list); // reverse the list
	print(list);
	release(&list);
	return 0;
}
```
![Reversing list](https://cdn.discordapp.com/attachments/795649348364926986/830837984801718291/unknown.png)
* finds the index of an element
```c
// finds the index of a given element
#include <stdio.h>
#include "list/list.h"

int main() {
	struct list list;
	set(&list);
	for(int i=1;i<10;i++) { append(&list, i); }
	// returns index of element if not found -1 is returned
	printf("Index of element 5 is %d\n", indexl(list, 5));
	release(&list);
	return 0;
}
```
![Indexing element](https://cdn.discordapp.com/attachments/795649348364926986/830836876964790332/unknown.png)
