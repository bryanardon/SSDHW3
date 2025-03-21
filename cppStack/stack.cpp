#include <stdexcept>
#include <string>
#include "stack.h"


Stack::Stack() {
    currentCapacity = STARTING_CAPACITY;
    numElements = 0;
    values = std::make_unique<std::string[]>(STARTING_CAPACITY);
}

Stack::~Stack() {
    values.reset();
    currentCapacity = 0;
    numElements = 0;
}

void Stack::expand() {
    unsigned int new_capacity = currentCapacity * 2;
    
    if (new_capacity > MAXIMUM_SIZE) {
        throw std::overflow_error("Exceeded permitted amount of elements in the stack.");
    }
    std::unique_ptr<std::string[]> new_data = std::make_unique<std::string[]>(new_capacity);

    for (unsigned int i = 0; i < numElements; i++) {
        new_data[i] = std::move(values[i]);
    }
    // For clarity
    this->values = std::move(new_data);
    this->currentCapacity = new_capacity;
}

void Stack::push(const std::string value) {
    if (numElements == currentCapacity) {
        expand();  // Expand the stack if it's full
    }
    values[numElements] = value;  // Add the new value
    numElements++;  // Increment the numElements
}

// Pops a value from the stack
std::string Stack::pop() {
    if (numElements == 0) {
        throw std::underflow_error("Can't pop empty stack");
    }

    numElements--;  // Decrease the numElements
    std::string popped_value = std::move(values[numElements]);  // Get the popped value
    return popped_value;
}

// Returns the top element of the stack without removing it
std::string Stack::peek() {
    if (numElements == 0) {
        throw std::underflow_error("Can't peek empty stack.");
    }
    return values[numElements - 1];  // Return the string at the top
}

// Returns true if the stack is empty
bool Stack::isEmpty(){
    return numElements == 0;
}

// Returns the current number of elements in the stack
unsigned int Stack::size(){
    return numElements;
}

// Returns the current currentCapacity of the stack
unsigned int Stack::current_capacity() {
    return currentCapacity;
}

