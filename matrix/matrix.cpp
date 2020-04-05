#include <array>
#include <iostream>

using std::array;
using std::cout;
using std::cin;
using std::endl;



class Matrix {
private:
    array<int, 9> elements;

public:
    /// Your code goes here.
};


int main () {
    /// Tests:

    Matrix a;
    const Matrix b;

    input(a);
    input(b);

    output(a);
    output(b);

    output(a + b);
    output(a - b);
    output(a * b);

    Matrix c(a);
    output(c);

    output(a = b);
    output(b); /// Should be the same to the previous output.

    cout << (a == b) << endl; /// Should be 1.

    output(a -= b);

    cout << (a == Matrix()) << endl; /// Should be 1.

    a.set(0, 0, 1);
    cout << a << endl;

    a += b;
    b.set(0, 0, b.get(0, 0) + 1);

    cout << (a != b) << endl; /// Should be 0.

    Matrix d;
    Matrix e;

    for (size_t i = 0; i < 9; i ++) {
        d.set(i / 3, i % 3, i + 1);
        e.set(i / 3, i % 3, 9 - i);
    }

    output(d * e);
    output(d *= e); /// Should be the same to the previous output.

    return 0;
}
