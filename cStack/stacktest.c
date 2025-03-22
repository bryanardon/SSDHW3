#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

void testCreateStack() {
    StackResponse sr = createStack();
    assert(sr.code == success);
    assert(sr.stack != NULL);
    Stack s = sr.stack;
    assert(isEmpty(s));
    assert(!isFull(s));
    assert(size(s) == 0);
    destroyStack(s);
    printf("testCreateStack passed.\n");
}

void testPushPopPeek() {
    StackResponse sr = createStack();
    Stack s = sr.stack;
    
    assert(push(s, "one") == success);
    assert(push(s, "two") == success);
    assert(push(s, "three") == success);
    
    StringResponse peekRes = peek(s);
    assert(strcmp(peekRes.value, "three") == 0);
    
    StringResponse popRes = pop(s);
    assert(strcmp(popRes.value, "three") == 0);
    
    popRes = pop(s);
    assert(strcmp(popRes.value, "two") == 0);

    popRes = pop(s);
    assert(strcmp(popRes.value, "one") == 0);
    
    assert(pop(s).code == stack_empty);
    destroyStack(s);
    printf("testPushPopPeek passed.\n");
}

void testExpandStack() {
    StackResponse sr = createStack();
    Stack s = sr.stack;

    int pushes = STARTING_CAPACITY * 4;
    for (int i = 0; i < pushes; i++) {
        assert(push(s, "expand") == success);
    }
    assert(size(s) == pushes);
    destroyStack(s);
    printf("testExpandStack passed.\n");
}

void testMaxCapacity() {
    StackResponse sr = createStack();
    Stack s = sr.stack;
    
    for (int i = 0; i < MAXIMUM_CAPACITY; i++) {
        assert(push(s, "fill") == success);
    }
    assert(push(s, "too-much") == stack_full);
    destroyStack(s);
    printf("testMaxCapacity passed.\n");
}

int main() {
    testCreateStack();
    testPushPopPeek();
    testExpandStack();
    testMaxCapacity();
    
    printf("All stack tests passed!\n");
    return 0;
}
