# Lists

## Task 1: Double-linked list.

+ Watch the [video](https://www.youtube.com/watch?v=DMqlCXrFY0k).
+ Create a template (!) class List, that will be acting similar to the std::list class. \
You should create project, that will consist of two files: .h and .cpp.
Provide the definitions and the declarations inside the .h file, and implementations inside the .cpp file.
+ You don't need to implement the iterator class for your list.

## Rules
+ Don't use std containers (std::vector, std::list, etc...)
+ Use new and delete to allocate and deallocate the memory.
+ Split your code into three parts:
library-code definitions, library-code implementation, main file
+ Provide some tests of your code inside the int main () function.
+ Put some comments to explain what is happening inside your code.

### Implement inside the class List:
+ The inner template class ListNode<T> (declare it only inside
the private scope of the class List. In this case users won't be able to see
that Node class is defined). This class should store two pointers to the left
and right elements of the linked list and the value of the the actual element (node), that
it will represent.
+ default constructor
+ copy constructor
+ destructor
+ operator =
+ size() method
+ push_back() method
+ pop_back() method
+ push_front() method
+ pop_front() method
+ operator[] (get i-th element of the list)
+ exists() method, that will return true if the element exists inside the list, otherwise false. 
+ insert_before(index, value) - insert value before the i-th position inside the list.
+ insert_after(index, value)
+ erase(index) - delete i-th element from the list.
+ bool empty() - return true if the list is empty
+ clear method
+ front() method (returns value of the first element)
+ back() method (returns value of the last element)
+ Create your own exceptions for the most trivial errors (access to non-existing index etc).


#### Note: maybe later I'll post some tests.

### Deadline
+ FIRST: One week starting from now (25.04 23:59), so the deadline will be May 2-th 23:59.
Before that time you should send me at least the first version of the code.
+ SECOND: Two weeks starting from now (25.04 23:59), so the deadline will be May 9-th 23:59.



## Task 2 (bonus): XOR list.

+ Read the [article](https://en.wikipedia.org/wiki/XOR_linked_list).
+ Implement the XOR-list (the requirments are the same as for the task 1).
+ WARNING: if you will do (and pass the h/w check of course) this task, you will NOT need to do the first one (instantly full points for the first task).