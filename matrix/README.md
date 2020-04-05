# The task itself
## You need to implement Matrix class and next methods/functions:

+ Default constructor
+ Copy constructor
+ Destructor
+ Constructor from array<int, 9>
+ Operator =
+ Compound assignment operators: +=, -=, *=
+ Binary arithmetic operators: +, -, * (matrix multiplication, not a scalar one!)
+ Unary arithmetic operators + and -
+ Getter and Setter for elements of matrix
+ Comparison operators: ==, !=
+ Output and Input functions (out-of-class!)

## Examples and signatures:

+ `const Matrix a({1, 2, 3, 4, 5, 6, 7, 8, 9}); output(a);` should print: \
`1 2 3`\
`4 5 6`\
`7 8 9`

+ Getter signature can be figured out from the example of usage: \
`cout << a.get(0, 1)` should print: `2`.

+ Same for the setter. Lets use a copy constructor in order to make
non-const Matrix, and after that we can call setter on it: \
`Matrix b(a); b.set(2, 1, 0); output(b);` should print: \
`1 2 3`\
`4 5 6`\
`7 0 9`

## Pay attention to:

+ Consts and references. Try to write optimized code. Don't make unnecessary
 copies! Use const every time when you don't need to change the object.
+ Test your code before sending it to me!
+ Codestyle!
+ Deadline :-) 