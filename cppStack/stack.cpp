#include <stdexcept>
#include <string>
#include "stack.h"

Stack::Stack() {
    currentCapacity = STARTING_CAPACITY;
    numElements = 0;
    values = new std::unique_ptr<std::string>[STARTING_CAPACITY];
}


Stack::~Stack() {
    delete[] values;
}

void Stack::expand() {
    unsigned int new_capacity = currentCapacity * 2;

    if (new_capacity > MAXIMUM_SIZE) {
        throw std::overflow_error("Exceeded permitted amount of elements in the stack.");
    }
    std::unique_ptr<std::string>* newValues = new std::unique_ptr<std::string>[new_capacity];

    for (unsigned int i = 0; i < numElements; i++) {
        newValues[i] = std::move(values[i]);
    }

    delete[] values;
    values = newValues;
    currentCapacity = new_capacity;
}

void Stack::push(const std::string value) {
    if (numElements == currentCapacity) {
        expand(); 
    }
    values[numElements] = std::make_unique<std::string>(value);  
    numElements++; 
}

std::string Stack::pop() {
    if (numElements == 0) {
        throw std::underflow_error("Can't pop from empty stack");
    }

    numElements--;  
    std::string popped_value = std::move(*values[numElements]);  
    values[numElements].reset();  
    return popped_value;
}

std::string Stack::peek() {
    if (numElements == 0) {
        throw std::underflow_error("Can't peek empty stack.");
    }
    return *values[numElements - 1]; 
}

bool Stack::isEmpty() {
    return numElements == 0;
}

unsigned int Stack::size() {
    return numElements;
}

unsigned int Stack::current_capacity() {
    return currentCapacity;
}
