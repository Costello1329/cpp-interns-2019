#include <iostream>
#include <vector>

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
    const bool firstOneIsLonger = firstOne.digits.size() > secondOne.digits.size();
    const BigUint &longestOne = firstOneIsLonger ? firstOne : secondOne;
    const BigUint &shortestOne = firstOneIsLonger ? secondOne : firstOne;

    uint8_t carry = 0;
    vector<uint8_t> digits(longestOne.digits.size());

    for (size_t i = 0; i < longestOne.digits.size(); i ++) {
        uint8_t sum = longestOne.digits[i] + carry;

        if (i < shortestOne.digits.size())
            sum += shortestOne.digits[i];

        carry = sum / 10;
        sum %= 10;

        digits[i] = sum;
    }

    return BigUint(digits);
}

BigUint operator * (
    const BigUint &firstOne,
    const BigUint &secondOne
) {
    const bool firstOneIsLonger = firstOne.digits.size() > secondOne.digits.size();
    const BigUint &longestOne = firstOneIsLonger ? firstOne : secondOne;
    const BigUint &shortestOne = firstOneIsLonger ? secondOne : firstOne;

    uint8_t carry = 0;
    vector<uint8_t> digits(shortestOne.digits.size() + longestOne.digits.size());

    for (size_t i = 0; i < longestOne.digits.size(); i ++) {
        for (size_t j = 0; j < shortestOne.digits.size(); j ++) {
            uint8_t multiplication =
                longestOne.digits[i] * shortestOne.digits[j] +
                digits[i + j] +
                carry;

            carry = multiplication / 10;
            multiplication %= 10;

            digits[i + j] = multiplication;
        }

        if (carry != 0) {
            digits[i + shortestOne.digits.size()] = carry;
            carry = 0;
        }
    }

    for (size_t i = digits.size() - 1; i > 0; i --) {
        if (digits[i] != 0)
            break;

        else
            digits.pop_back();
    }

    if (digits.empty())
        digits.push_back(0);

    return BigUint(digits);
}
