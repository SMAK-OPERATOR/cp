#include <iostream>
#include <string>

#include "Deque.hpp"

int main() {
    
    Deque<int> dequeInt;
    Deque<double> dequeDouble;
    Deque<std::string> dequeString;

    dequeInt.pushFront(1);
    dequeDouble.pushFront(1.11);
    dequeString.pushFront("dog");

    dequeInt.pushBack(2);
    dequeDouble.pushBack(2.23);
    dequeString.pushBack("cat");

    std::cout << dequeInt.front() << " " << dequeInt.back() << std::endl;
    std::cout << dequeDouble.front() << " " << dequeDouble.back() << std::endl;
    std::cout << dequeString.front() << " " << dequeString.back() << std::endl;

    dequeInt.popFront();
    dequeDouble.popFront();
    dequeString.popFront();

    std::cout << dequeInt.front() << " " << dequeInt.back() << std::endl;
    std::cout << dequeDouble.front() << " " << dequeDouble.back() << std::endl;
    std::cout << dequeString.front() << " " << dequeString.back() << std::endl;

    dequeInt.popBack();
    dequeDouble.popBack();
    dequeString.popBack();

    // std::cout << dequeInt.front() << " " << dequeInt.back() << std::endl;
    // std::cout << dequeDouble.front() << " " << dequeDouble.back() << std::endl;
    // std::cout << dequeString.front() << " " << dequeString.back() << std::endl;

    return 0;
}