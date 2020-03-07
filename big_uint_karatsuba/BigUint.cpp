#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::min;


class BigUint {
private:
    vector<uint8_t> digits;

    explicit BigUint (const vector<uint8_t> &digits) {
        this->digits = digits;
        trimZeros(this->digits);
    }

    static void trimZeros (vector<uint8_t> &digits) {
        for (size_t i = digits.size() - 1; i > 0; i --) {
            if (digits[i] != 0)
                break;

            else
                digits.pop_back();
        }
    }

    static void pushFrontSomeZeros (vector<uint8_t> &vec, const size_t &count) {
        reverse(vec.begin(), vec.end());

        for (size_t i = 0; i < count; i ++)
            vec.push_back(0);

        reverse(vec.begin(), vec.end());
    }

    static BigUint trivialMultiplication (
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

        trimZeros(digits);
        return BigUint(digits);
    }

public:
    BigUint () {
        this->digits.resize(0);
    }

    BigUint (const BigUint &anotherUint) {
        this->digits = anotherUint.digits;
    }

    BigUint (const string &str) {
        digits.clear();

        for (ssize_t i = str.size() - 1; i >= 0; i --)
            digits.push_back(str[i] - '0');

        trimZeros(this->digits);
    }

    string toString () const {
        string str;

        for (ssize_t i = digits.size() - 1; i >= 0; i --)
            str += (digits[i] + '0');

        return str;
    }

    friend BigUint operator + (
        const BigUint &firstOne,
        const BigUint &secondOne
    );

    friend BigUint operator - (
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
    const bool firstOneIsLonger =
        firstOne.digits.size() > secondOne.digits.size();

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

    if (carry)
        digits.push_back(carry);

    return BigUint(digits);
}

BigUint operator - (
    const BigUint &firstOne,
    const BigUint &secondOne
) {
    // Paste your code here:
}

BigUint operator * (
    const BigUint &firstOne,
    const BigUint &secondOne
) {
    /**
     * Here we have the base of our recursion.
     * If one of the numbers has a length of 1,
     * we count product using trivial algorithm:
     */

    if (min(firstOne.digits.size(), secondOne.digits.size()) == 1)
        return BigUint::trivialMultiplication(firstOne, secondOne);

    /**
     * Otherwise, we use Karatsuba's algorithm to count product.
     * To use this algorithm, we need our numbers to have the
     * same length!
     * In order to comply this requirements, we need to push
     * front some zeros to the shortest number.
     * Example:
     * 10000 * 10 ---> 10000 * 00010
     */

    const bool firstOneIsLonger =
        firstOne.digits.size() > secondOne.digits.size();

    const BigUint &longestOne = firstOneIsLonger ? firstOne : secondOne;
    const BigUint &shortestOne = firstOneIsLonger ? secondOne : firstOne;

    /**
     * Here we prepare n/2 - length numbers a, b, c, d
     * that we'll need for main Karatsuba's algorithm's step.
     */

    const size_t n = longestOne.digits.size();
    const size_t m = n / 2;

    vector<uint8_t> a(n - m);
    vector<uint8_t> b(m);
    vector<uint8_t> c(n - m);
    vector<uint8_t> d(m);

    for (size_t i = m; i < n; i ++) {
        a[i - b.size()] = longestOne.digits[i];

        if (i < shortestOne.digits.size())
            c[i - b.size()] = shortestOne.digits[i];
    }

    for (size_t i = 0; i < m; i ++) {
        b[i] = longestOne.digits[i];

        if (i < shortestOne.digits.size())
            d[i] = shortestOne.digits[i];
    }

    if (c.empty())
        c.push_back(0);

    const BigUint aNum(a);
    const BigUint bNum(b);
    const BigUint cNum(c);
    const BigUint dNum(d);

    /**
     * Here we have the main step of Karatsuba's algorithm:
     * At first, we create alpha, beta, and gamma variables.
     * We count these three products using the same
     * algorithm (recursively)
     */

    BigUint alpha, beta, gamma;

    // Paste your code here:

    /** After that, we need to 'multiply' alpha by 10 ^ (2 * m)
     * and 'multiply' gamma by 10 ^ (m).
     * But, actually, we don't need to use multiplication algorithms
     * to do it!
     * We can just use some 'push_front's. Example:
     * 1234 * 10^2 = ?;
     * 1234 is presented in digits vector like 4321.
     * To multiply it by 100, we need to push front 2 zeros: 004321.
     * Now, if we will call .toString() method, we will get: "123400".
     * Profit.
     */

    BigUint::pushFrontSomeZeros(alpha.digits, 2 * m);
    BigUint::pushFrontSomeZeros(gamma.digits, m);

    /**
     * Now we only need to return the sum of alpha, beta and gamma:
     */

    return alpha + gamma + beta;
}
