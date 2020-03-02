#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;


class BigUint {
private:
    vector<uint8_t> digits;

    BigUint (const vector<uint8_t> &digits)
        : digits(digits)
    {}

    void readFromString (const string &str) {
        digits.clear();

        for (ssize_t i = str.size() - 1; i >= 0; i --) {
            digits.push_back(str[i] - '0');
        }
    }

public:
    BigUint (const BigUint &anotherUint) {
        this->digits = anotherUint.digits;
    }

    BigUint (const string &str) {
        readFromString(str);
    }

    string toString () const {
        string str;

        for (ssize_t i = digits.size() - 1; i >= 0; i --) {
            str += (digits[i] + '0');
        }

        return str;
    }

    friend BigUint operator + (
        const BigUint &firstOne,
        const BigUint &secondOne
    );

    friend BigUint operator * (
        const BigUint &firstOne,
        const BigUint &secondOne
    );
};

BigUint operator + (
    const BigUint &firstOne,
    const BigUint &secondOne
) {
    // Write your code here:
}

BigUint operator * (
    const BigUint &firstOne,
    const BigUint &secondOne
) {
    // Write your code here:
}
