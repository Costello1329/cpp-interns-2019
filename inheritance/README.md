# Inheritance: some funny stuff with cars :) 
## The task itself:

In `fun_with_cars.cpp` you can see:
+ class Engine. It is getting constructed from horsePowers Value. This is
the max power that this engine can generate.\
There are two methods for increasing and decreasing current engine's power:
increasePower and decreasePower.

+ class Car. You need to implement this class from the scratch.
You should choose which inheritance modifier you should use in order
to hide all Engine's base class methods from the user
(all base class's methods should not be visible from the inside
of `int main`). 
You should declare:
    + protected (!) constructor from `int` and `std::string` - h/p and color.
    + public default constructor should be deleted by you (use `delete`).
    + empty destructor.
    + Two getters: `int getSpeed()` and
    `const std::string &getColor()`.
    + You should NOT store current speed inside a variable, but
     you can get it from using this formula: `currentPower / 2` (this is an
     example, so the formula is as easy as possible :-) ).
    + It's forbidden to you to modify currentPower "with your hands" inside
    Car class. Use methods, that you've inherited from the base class Car.
    + Two methods: `accelerate` and `decelerate`. You should call
     `increasePower()` and `decreasePower()` methods in them. Pay attention:
     this methods should be inherited from the base class Engine.
     
+ class BMW. Only implement a constructor from `std::string` color here.
You should initialize the base class too! In order to do it, use initializer
lists. Initialize the base class with `600` (h/ps) and `color`.

+ class Porsche:
    + Implement a constructor from `std::string` color and `std::string`
    type here (store type variable inside the private field type of
    the current class Porsche).
    You should initialize the base class too! In order to do it,
    use initializer lists. Initialize the base class with `800`
    (h/ps) and `color`.
    + Implement `const std::string getType () const {...}` method that
    will return type of a car (coupe, for example);
    
### PS:
This is a hard task. it will cost 50 (!!!) points. You are allowed to write
your code only where the comments say `/// Put your code here:`.
Pay attention to the codestyle. Do this h/w by yourself and (please!) look
at ALL the examples, that I've provided you with.
Understand each one of them deeply. You are allowed to ask some questions to
your groupmates, but writting-off is prohibited and will be banned
(-25 points both sides!).
