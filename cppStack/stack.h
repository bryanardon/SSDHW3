#ifndef STACK_H
#define STACK_H

#include <string>
#include <memory>

#define MAXIMUM_SIZE 1024
#define STARTING_CAPACITY 4

class Stack {
private:
    unsigned int currentCapacity;
    unsigned int numElements;
    std::unique_ptr<std::string[]> values;
    void expand();

public:
    Stack();
    ~Stack();
    void push(const std::string value); 
    std::string pop(); 
    std::string peek(); 
    bool isEmpty();  
    unsigned int size();  
    unsigned int current_capacity();  
};

#endif