# H/w 2: smart_pointers

### Task itself
Implement 2 template classes, the analogues for STL smart pointers: UniquePtr (std::unique_ptr) and SharedPtr (std::shared_ptr).

##### UniquePtr. Implement:
+ Constructor from the raw pointer
+ move copy constructor
+ move assignment operator
+ destructor
+ Operator *
+ Operator ->
+ You also should delete the copy constructor and operator = that compile generates by default (see =delete topic)

##### SharedPtr. Implement:
+ Constructor from the raw pointer
+ copy constructor
+ assignment operator
+ move copy constructor
+ move assignment operator
+ destructor
+ Operator *
+ Operator ->
+ Method use_count(), that returns the count of pointers that are pointing to the same object.


##### Test yourself
Create a class Logger, that prints something when constructed and destructed. Try to create some instances and play with them. Make sure that your objects (resources) are getting constructed and destructed properly.

#### PS:
This is an easy task. If you'll watch the recording of the seminar – you'll get the main idea and base code, so implementation of some unimplemented methods won't be a problem for you at all.

#### Cost
task costs 15 points

#### Deadline
Oct 28 2020, 23:59:59.
