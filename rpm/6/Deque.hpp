#pragma once

#include <iostream>
#include <vector>
#include <string>

template <typename T>
class Deque {
public:
    Deque(){}

    ~Deque(){}

    T front();
    T back();

    void pushFront(T elem);
    void pushBack(T elem);

    void popFront();
    void popBack();
private:
    std::vector <T> arr;
};

template<typename T>
T Deque<T>::front() {
    try {
        if (arr.empty()) throw "front() err: Deque is empty";
        return arr.front();
    } catch (const char *str) {
        std::cout << str << std::endl;
    }
}

template<typename T>
T Deque<T>::back(){
    try {
        if (arr.empty()) throw "back() err: Deque is empty";
        return arr.back();
    } catch (const char *str) {
        std::cout << str << std::endl;
    }
}

template<typename T>
void Deque<T>::pushBack(T elem) {
    arr.push_back(elem);
}

template<typename T>
void Deque<T>::pushFront(T elem) {
    arr.insert(arr.begin(), elem);
}

template<typename T>
void Deque<T>::popBack() {
    try {
        if (arr.empty()) throw "popBack err: Deque is empty";
        arr.pop_back();
    } catch(const char *str) {
        std::cout << str << std::endl;
    }
    
}

template<typename T>
void Deque<T>::popFront() {
    try {
        if (arr.empty()) throw "popFront() err: Deque is empty";
        arr.erase(arr.begin());
    } catch(const char *str) {
        std::cout << str << std::endl;
    }
}