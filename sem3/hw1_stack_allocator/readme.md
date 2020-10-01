# H/w 1: stack_allocator

### Task itself
Implement a template class StackAllocator<typename T>. Interface must be the same as the C++11 [std::allocator](https://en.cppreference.com/w/cpp/memory/allocator). Stack Allocator must allocate (with the new[]) big chunk of memory only once and provide small blocks of memory from this chuck of data consequently. If the big chuck is not enough for user and it is not able to provide enough memory – you need to allocate new big chunck of the data, etc. Deallocation queries must not cause any actual deallocations (with the operator delete[]). You should deallocate the big chucks of data inside the destructor instead. So, the actual memory is getting freed only after the instance of the allocator is getting deleted. This type of allocation strategy is optimal for big data structures.

Class StackAllocator must be STL-compatible (it must be able to be passed as an allocator for standart containers such as std::vector, std::list etc.). You need to implement:
+ default constructor
+ copy constructor
+ destructor
+ allocate (same interface as std::allocator)
+ deallocate (same interface as std::allocator)
+ rebind (same interface as std::allocator)

##### Test yourself
Write the test function that creates std::list<int> and makes some random pushes and pops. If you've done everything right – your solution with std::list<int, StackAllocator<int>> probably may be working faster compared to std::list<int, std::allocator<int>>.

#### Cost
task costs 15 points

#### Deadline
Oct 14 2020, 23:59:59.
