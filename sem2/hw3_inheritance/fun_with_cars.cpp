#include <algorithm>
#include <iostream>

using std::min;
using std::max;
using std::cin;
using std::cout;
using std::endl;



class Engine {
private:
    int horsePowers;

protected:
    int currentPower;

private:
    /// Function that sets h/p between min and max values:
    static int trimPowers (
        const int &horsePowers,
        const int &minVal = 100,
        const int &maxVal = 1000
    ) {
        return min<int>(max<int>(abs(horsePowers), minVal), maxVal);
    }

public:
    explicit Engine (const int &horsePowers) {
        this->horsePowers = trimPowers(horsePowers);
        currentPower = 0;
    }

    void increasePower () {
        this->currentPower =
            trimPowers(currentPower + horsePowers / 10, 0, horsePowers);
    }

    void decreasePower () {
        this->currentPower =
            trimPowers(currentPower - horsePowers / 10, 0, horsePowers);
    }
};


class Car : /** your code goes here **/ Engine {
    /** your code goes here **/
};


class BMW : /** your code goes here **/ Car {
    /** your code goes here **/
};


class Porsche : /** your code goes here **/ Car {
    /** your code goes here **/
};


int main () {
    /// Car car; /// Should not work, because you should delete public default constructor.

    BMW bmw( "red");
    Porsche porsche("green", "coupe");

    /// bmw.increasePower(); /// Should not work, because user should only be provided
    /// to interact with the car, but not with the engine.
    /// porsche.decreasePower(); /// Same.

    cout << "BMW" << endl;

    cout << "Acceleration test:" << endl;

    while (bmw.getSpeed() != 300) {
        bmw.accelerate();
        cout << bmw.getSpeed() << endl;
    }

    cout << "Deceleration test:" << endl;

    while (bmw.getSpeed() != 0) {
        bmw.decelerate();
        cout << bmw.getSpeed() << endl;
    }

    cout << "Porsche" << endl;

    cout << "Acceleration test:" << endl;

    while (porsche.getSpeed() != 400) {
        porsche.accelerate();
        cout << porsche.getSpeed() << endl;
    }

    cout << "Deceleration test:" << endl;

    while (porsche.getSpeed() != 0) {
        porsche.decelerate();
        cout << porsche.getSpeed() << endl;
    }

    cout << "BMW color: " << bmw.getColor() << endl;
    cout << "Porsche color: " << porsche.getColor() << endl;
    /// cout << "BMW type: " << bmw.getType() << endl; /// Should NOT work!
    cout << "Porsche type: " << porsche.getType() << endl;

    return 0;
}
