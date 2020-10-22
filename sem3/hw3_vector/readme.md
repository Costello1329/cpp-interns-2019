# H/w 3: vector

### Task itself
Implement vector, the analogue for STL std::vector.

The interface must be almost the same as the std::vector.
##### Member types:
+ The same member types as in std::vector.
##### Member functions:
+ [constructor](https://en.cppreference.com/w/cpp/container/vector/vector): deault (1), copy (6), from allocator (2), normal ones (3)(4), from the iterated range (5), copy with allocator (7), copy move (8), copy move with different allocator (9)
+ [destructor](https://en.cppreference.com/w/cpp/container/vector/%7Evector)
+ [operator=](https://en.cppreference.com/w/cpp/container/vector/operator%3D): only (1) and (2).
+ [assign](https://en.cppreference.com/w/cpp/container/vector/assign):  only (1) and (2).
+ [get_allocator](https://en.cppreference.com/w/cpp/container/vector/get_allocator)
##### Iterators:
+ All iterators methods: for normal, const, reverse and const reverse iterators.
##### Element access:
+ [at](https://en.cppreference.com/w/cpp/container/vector/at)
+ [operator[]](https://en.cppreference.com/w/cpp/container/vector/operator_at)
+ [front](https://en.cppreference.com/w/cpp/container/vector/front)
+ [back](https://en.cppreference.com/w/cpp/container/vector/back)
+ [data](https://en.cppreference.com/w/cpp/container/vector/data)
##### Capacity:
+ [empty](https://en.cppreference.com/w/cpp/container/vector/empty)
+ [size](https://en.cppreference.com/w/cpp/container/vector/size)
+ [reserve](https://en.cppreference.com/w/cpp/container/vector/reserve)
+ [capacity](https://en.cppreference.com/w/cpp/container/vector/capacity)
+ [shrink_to_fit](https://en.cppreference.com/w/cpp/container/vector/shrink_to_fit)
##### Modifiers:
+ [clear](https://en.cppreference.com/w/cpp/container/vector/clear)
+ [insert](https://en.cppreference.com/w/cpp/container/vector/insert): only (1-4)
+ [emplace](https://en.cppreference.com/w/cpp/container/vector/emplace)
+ [erase](https://en.cppreference.com/w/cpp/container/vector/erase): (1-2)
+ [push_back](https://en.cppreference.com/w/cpp/container/vector/push_back): (1-2)
+ [emplace_back](https://en.cppreference.com/w/cpp/container/vector/emplace_back): (1-2)
+ [pop_back](https://en.cppreference.com/w/cpp/container/vector/pop_back)
+ [resize](https://en.cppreference.com/w/cpp/container/vector/resize): (1-2)
+ [swap](https://en.cppreference.com/w/cpp/container/vector/swap): (1-2)
##### Non-member functions:
+ [comparison](https://en.cppreference.com/w/cpp/container/vector/operator_cmp): without operator<=>
+ [std::swap](https://en.cppreference.com/w/cpp/container/vector/operator_cmp): you should provide a specialization of std::swap for your own vector-type



#### Cost
task costs 25 points

#### Deadline
Nov 25 2020, 23:59:59.
