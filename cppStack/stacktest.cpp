#include <iostream>
#include <cassert>
#include <stdexcept>
#include "stack.h" 

void createStack() {
    Stack stack;

    assert(stack.size() == 0);
    assert(stack.current_capacity() == STARTING_CAPACITY);
    assert(stack.isEmpty());
}

void testPushAndPop() {
    Stack stack;

    stack.push("one");
    stack.push("two");
    stack.push("three");

    assert(stack.size() == 3);
    assert(stack.pop() == "three");
    assert(stack.pop() == "two");
    assert(stack.pop() == "one");
    assert(stack.isEmpty());

    std::cout << "testPushAndPop passed\n";
}

void testPeek() {
    Stack stack;

    stack.push("1");
    stack.push("2");

    assert(stack.peek() == "2");
    assert(stack.pop() == "2");
    assert(stack.peek() == "1");

    std::cout << "testPeek passed\n";
}

void testExpandStack(){
    Stack stack;
    int arbitrary_pushes = 1000;
    for (int i = 0; i < arbitrary_pushes; i++) {
        stack.push("test");
    }

    assert(stack.size() == arbitrary_pushes);
    // Should be at last possible capacity
    assert(stack.current_capacity() == MAXIMUM_SIZE);

    std::cout << "testExpandStack passed\n";
}

void testOverflowExpandStack(){
    Stack stack;
    for (int i = 0; i < 1024; i++) {
        stack.push("test");
    }
    try {
        stack.push("overflow");
        assert(false);
    } catch (const std::overflow_error&) {
        std::cout << "testOverflowExpandStack passed\n";
    
    }
}

void testIsEmpty() {
    Stack stack;
    assert(stack.isEmpty());
    stack.push("not empty");
    assert(!stack.isEmpty());
    stack.pop();
    assert(stack.isEmpty());
    std::cout << "testIsEmpty passed\n";

}

void testPopEmpty() {
    Stack stack;
    try {
        stack.pop();
        assert(false);
    } catch (const std::underflow_error&) {
        std::cout << "testPopEmpty passed\n";
    
    }
}

void testPeekEmpty() {
    Stack stack;
    try {
        stack.peek();
        assert(false);
    } catch (const std::underflow_error&) {
        std::cout << "testPeekEmpty passed\n";
    
    }
}

int main() {
    createStack();
    testPushAndPop();
    testExpandStack();
    testOverflowExpandStack();
    testPeek();
    testIsEmpty();
    testPopEmpty();
    testPeekEmpty();
    std::cout << "All tests passed!\n";
    return 0;
}
