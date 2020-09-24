#include <iostream>
#include <list>
/// Here we need to include our implemented defined list.
#include "list.h"




void wrapTestStart (const std::string &testName, const std::string &testDescription) {
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << "Test name: " << testName << std::endl;
    std:: cout << "Test description: " << testDescription << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
}

void wrapTestEnd () {
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << std::endl << std::endl;
}


int main () {
    /**
     * Test one:
     * push_back(), pop_back(), and back() simple test
     */

    wrapTestStart(
        "Test one",
        "push_back(), pop_back(), and back() simple test."
    );

    {
        std::cout << "Std list prints: " << std::endl;
        std::list<int> stdList;
        stdList.push_back(123);
        stdList.push_back(321);
        stdList.push_back(333);

        /// Here we have {123, 321, 333} in list
        std::cout << stdList.back() << ", "; /// 333
        stdList.pop_back();
        /// Here we have {123, 321} in list
        std::cout << stdList.back() << ", "; /// 321
        stdList.pop_back();
        /// Here we have {123} in list
        std::cout << stdList.back() << std::endl; /// 123

        ///------------------------------------------------------------///

        std::cout << "Our list prints: " << std::endl;
        List<int> ourList;
        ourList.push_back(123);
        ourList.push_back(321);
        ourList.push_back(333);

        /// Here we have {123, 321, 333} in list
        std::cout << ourList.back() << ", "; /// 333
        ourList.pop_back();
        /// Here we have {123, 321} in list
        std::cout << ourList.back() << ", "; /// 321
        ourList.pop_back();
        /// Here we have {123} in list
        std::cout << ourList.back() << std::endl; /// 123
    }

    wrapTestEnd();


    /**
     * Test two:
     * push_front(), pop_front(), and front() simple test
     */

    wrapTestStart(
            "Test two",
            "push_front(), pop_front(), and front() simple test."
    );

    {
        std::cout << "Std list prints: " << std::endl;
        std::list<int> stdList;
        stdList.push_front(123);
        stdList.push_front(321);
        stdList.push_front(333);

        /// Here we have {333, 321, 123} in list
        std::cout << stdList.front() << ", "; /// 333
        stdList.pop_front();
        /// Here we have {333, 321} in list
        std::cout << stdList.front() << ", "; /// 321
        stdList.pop_front();
        /// Here we have {333} in list
        std::cout << stdList.front() << std::endl; /// 123

        ///------------------------------------------------------------///

        std::cout << "Our list prints: " << std::endl;
        List<int> ourList;
        ourList.push_front(123);
        ourList.push_front(321);
        ourList.push_front(333);

        /// Here we have {123, 321, 333} in list
        std::cout << ourList.front() << ", "; /// 333
        ourList.pop_front();
        /// Here we have {123, 321} in list
        std::cout << ourList.front() << ", "; /// 321
        ourList.pop_front();
        /// Here we have {123} in list
        std::cout << ourList.front() << std::endl; /// 123
    }

    wrapTestEnd();


    /**
     * Test three:
     * push, pop, front, back combined test.
     */

    wrapTestStart(
            "Test three",
            "push, pop, front, back combined test."
    );

    {
        std::cout << "Std list prints: " << std::endl;
        std::list<int> stdList;

        for (size_t i = 0; i < 25; i ++) {
            if (i % 2)
                stdList.push_back(i);

            else
                stdList.push_front(i);
        }

        std::cout << "{ ";

        for (size_t i = 0; i < 25; i ++) {
            if (i % 2) {
                std::cout << stdList.back() << " ";
                stdList.pop_back();
            }

            else {
                std::cout << stdList.front() << " ";
                stdList.pop_front();
            }
        }

        std::cout << "}" << std::endl;

        ///------------------------------------------------------------///

        std::cout << "Our list prints: " << std::endl;
        List<int> ourList;

        for (size_t i = 0; i < 25; i ++) {
            if (i % 2)
                ourList.push_back(i);

            else
                ourList.push_front(i);
        }

        std::cout << "{ ";

        for (size_t i = 0; i < 25; i ++) {
            if (i % 2) {
                std::cout << ourList.back() << " ";
                ourList.pop_back();
            }

            else {
                std::cout << ourList.front() << " ";
                ourList.pop_front();
            }
        }

        std::cout << "}" << std::endl;
    }

    wrapTestEnd();


    /**
     * Test four:
     * push, pop, front, back, clear, size, empty combined test.
     */

    wrapTestStart(
            "Test four",
            "push, pop, front, back, size, empty combined test."
    );

    {
        std::cout << "Std list prints: " << std::endl;
        std::list<int> stdList;

        for (size_t i = 0; i < 25; i ++) {
            if (i % 2)
                stdList.push_back(i);

            else
                stdList.push_front(i);
        }

        std::cout << stdList.size() << std::endl;

        std::cout << "{ ";

        while (!stdList.empty()) {
            std::cout << stdList.back() << " ";
            stdList.pop_back();
        }

        std::cout << "}" << std::endl;

        std::cout << stdList.size() << std::endl;

        ///------------------------------------------------------------///

        std::cout << "Our list prints: " << std::endl;
        List<int> ourList;

        for (size_t i = 0; i < 25; i ++) {
            if (i % 2)
                ourList.push_back(i);

            else
                ourList.push_front(i);
        }

        std::cout << ourList.size() << std::endl;

        std::cout << "{ ";

        while (!ourList.empty()) {
            std::cout << ourList.back() << " ";
            ourList.pop_back();
        }

        std::cout << "}" << std::endl;

        std::cout << ourList.size() << std::endl;
    }

    wrapTestEnd();


    /**
     * Test five:
     * copy constructor, operator equals, clear() test.
     */

    wrapTestStart(
            "Test five",
            "copy constructor, operator equals, clear() test."
    );

    {
        std::cout << "Std list prints: " << std::endl;
        std::list<int> stdListFirst;

        for (size_t i = 0; i < 25; i ++)
            stdListFirst.push_back(i);

        std::cout << stdListFirst.size() << std::endl;

        std::list<int> stdListSecond(stdListFirst);
        std::list<int> stdListThird;
        stdListThird = stdListSecond;

        stdListFirst.clear();
        std::cout <<
            stdListFirst.size() << ", " <<
            stdListSecond.size() << ", " <<
            stdListThird.size() << std::endl;

        std::cout << "{ ";

        while (!stdListSecond.empty()) {
            std::cout << stdListSecond.back() << " ";
            stdListSecond.pop_back();
        }

        std::cout << "}" << std::endl;

        stdListFirst.clear();
        std::cout <<
                  stdListFirst.size() << ", " <<
                  stdListSecond.size() << ", " <<
                  stdListThird.size() << std::endl;

        stdListThird.clear();

        std::cout <<
                  stdListFirst.empty() << ", " <<
                  stdListSecond.empty() << ", " <<
                  stdListThird.empty() << std::endl;

        ///------------------------------------------------------------///

        std::cout << "Our list prints: " << std::endl;
        List<int> ourListFirst;

        for (size_t i = 0; i < 25; i ++)
            ourListFirst.push_back(i);

        std::cout << ourListFirst.size() << std::endl;

        List<int> ourListSecond(ourListFirst);
        List<int> ourListThird;
        ourListThird = ourListSecond;

        ourListFirst.clear();
        std::cout <<
                  ourListFirst.size() << ", " <<
                  ourListSecond.size() << ", " <<
                  ourListThird.size() << std::endl;

        std::cout << "{ ";

        while (!ourListSecond.empty()) {
            std::cout << ourListSecond.back() << " ";
            ourListSecond.pop_back();
        }

        std::cout << "}" << std::endl;

        ourListFirst.clear();
        std::cout <<
                  ourListFirst.size() << ", " <<
                  ourListSecond.size() << ", " <<
                  ourListThird.size() << std::endl;

        ourListThird.clear();

        std::cout <<
                  ourListFirst.empty() << ", " <<
                  ourListSecond.empty() << ", " <<
                  ourListThird.empty() << std::endl;
    }

    wrapTestEnd();


    /**
     * Test six:
     * merge test.
     */

    wrapTestStart(
            "Test six",
            "merge test."
    );

    {
        std::cout << "Std list prints: " << std::endl;
        std::list<int> stdListFirst;
        stdListFirst.push_back(1);
        stdListFirst.push_back(2);
        stdListFirst.push_back(3);
        std::list<int> stdListSecond;
        stdListSecond.push_back(4);
        stdListSecond.push_back(5);
        stdListSecond.push_back(6);

        stdListFirst.merge(stdListSecond);

        std::cout << "{ ";

        while (!stdListFirst.empty()) {
            std::cout << stdListFirst.front() << " ";
            stdListFirst.pop_front();
        }

        std::cout << "}" << std::endl;

        std::cout << "{ ";

        while (!stdListSecond.empty()) {
            std::cout << stdListSecond.front() << " ";
            stdListSecond.pop_front();
        }

        std::cout << "}" << std::endl;

        ///------------------------------------------------------------///

        std::cout << "Our list prints: " << std::endl;
        List<int> ourListFirst;
        ourListFirst.push_back(1);
        ourListFirst.push_back(2);
        ourListFirst.push_back(3);
        List<int> ourListSecond;
        ourListSecond.push_back(4);
        ourListSecond.push_back(5);
        ourListSecond.push_back(6);

        ourListFirst.merge(ourListSecond);

        std::cout << "{ ";

        while (!ourListFirst.empty()) {
            std::cout << ourListFirst.front() << " ";
            ourListFirst.pop_front();
        }

        std::cout << "}" << std::endl;

        std::cout << "{ ";

        while (!ourListSecond.empty()) {
            std::cout << ourListSecond.front() << " ";
            ourListSecond.pop_front();
        }

        std::cout << "}" << std::endl;
    }

    wrapTestEnd();


    /**
     * Test seven:
     * simple iterators.
     */

    wrapTestStart(
            "Test seven",
            "simple iterators."
    );

    {
        std::cout << "Std list prints: " << std::endl;
        std::list<int> stdList;

        for (size_t i = 0; i < 10; i ++)
            stdList.push_back(i + 1);

        std::cout << "{ ";

        for (std::list<int>::iterator i = stdList.begin(); i != stdList.end(); ++ i)
            std::cout << *i << " ";

        std::cout << "}" << std::endl;

        std::cout << "{ ";

        std::list<int>::iterator i = stdList.end();

        do {
            std::cout << *(-- i) << " ";
        } while (i != stdList.begin());

        std::cout << "}" << std::endl;

        ///------------------------------------------------------------///

        std::cout << "Our list prints: " << std::endl;
        List<int> ourList;

        for (size_t i = 0; i < 10; i ++)
            ourList.push_back(i + 1);

        std::cout << "{ ";

        for (List<int>::iterator i = ourList.begin(); i != ourList.end(); ++ i)
            std::cout << *i << " ";

        std::cout << "}" << std::endl;

        std::cout << "{ ";

        List<int>::iterator j = ourList.end();

        do {
            std::cout << *(-- j) << " ";
        } while (j != ourList.begin());

        std::cout << "}" << std::endl;
    }

    wrapTestEnd();


    /**
     * Test eight:
     * simple iterators.
     */

    wrapTestStart(
            "Test eight",
            "insert, erase."
    );

    {
        std::cout << "Std list prints: " << std::endl;
        std::list<int> stdList;

        for (size_t i = 0; i < 5; i ++)
            stdList.push_back(2*i + 1);

        std::list<int>::iterator iter = stdList.begin();

        std::cout << "{ ";

        for (std::list<int>::iterator i = stdList.begin(); i != stdList.end(); ++ i)
            std::cout << *i << " ";

        std::cout << "}" << std::endl;

        for (size_t i = 0; i < 5; i ++)
            stdList.insert(++ iter, 2 * (i + 1));

        std::cout << "{ ";

        for (std::list<int>::iterator i = stdList.begin(); i != stdList.end(); ++ i)
            std::cout << *i << " ";

        std::cout << "}" << std::endl;

        for (size_t i = 0; i < 5; i ++)
            stdList.erase(----iter);

        std::cout << "{ ";

        for (std::list<int>::iterator i = stdList.begin(); i != stdList.end(); ++ i)
            std::cout << *i << " ";

        std::cout << "}" << std::endl;

        ///------------------------------------------------------------///

        std::cout << "Our list prints: " << std::endl;
        List<int> ourList;

        for (size_t i = 0; i < 5; i ++)
            ourList.push_back(2*i + 1);

        List<int>::iterator ourIter = ourList.begin();

        std::cout << "{ ";

        for (List<int>::iterator i = ourList.begin(); i != ourList.end(); ++ i)
            std::cout << *i << " ";

        std::cout << "}" << std::endl;

        for (size_t i = 0; i < 5; i ++)
            ourList.insert(++ ourIter, 2 * (i + 1));

        std::cout << "{ ";

        for (List<int>::iterator i = ourList.begin(); i != ourList.end(); ++ i)
            std::cout << *i << " ";

        std::cout << "}" << std::endl;

        for (size_t i = 0; i < 5; i ++)
            ourList.erase(----ourIter);

        std::cout << "{ ";

        for (List<int>::iterator i = ourList.begin(); i != ourList.end(); ++ i)
            std::cout << *i << " ";

        std::cout << "}" << std::endl;
    }

    wrapTestEnd();


    return 0;
}
