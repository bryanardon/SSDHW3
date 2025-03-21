#include "stack.h"
#include <stdlib.h>
#include <string.h>

typedef struct S {
    char** values;
    int size;
    int currentCapacity;
} S;

StackResponse createStack() {
    Stack s = malloc(sizeof(S));
    if (s == NULL) {
        return (StackResponse){NULL, out_of_memory};
    }
    s->size = 0;
    s->currentCapacity = STARTING_CAPACITY;
    s->values = malloc(sizeof(char*) * s->currentCapacity);
    if (s->values == NULL) {
        free(s);
        return (StackResponse){NULL, out_of_memory};
    }
    return (StackResponse){s, success};
}

void destroyStack(Stack s) {
    for (int i = 0; i < s->size; i++) {
        free(s->values[i]);
    }
    free(s->values);
    free(s);
}

response_code push(Stack s, char* str){
    if (isFull(s)){
        return stack_full;
    }
    if (valuesFull(s)){
        if(expandStack(s) != success){
            return out_of_memory;
        };
    }

    s->values[s->size] = strdup(str);
    s->size++;
    return success;

}

StringResponse pop(Stack s){
    if (isEmpty(s)){
        return (StringResponse){NULL, stack_empty};
    }
    int current_size = s->size;
    char* current_top_value = s->values[current_size - 1];
    // Disconnect the top value from the stack so we can move it
    s->values[current_size - 1] = NULL;
    s->size--;
    // It is safe to MOVE
    return (StringResponse){current_top_value, success};

}
StringResponse peek(Stack s){
    if (isEmpty(s)){
        return (StringResponse){NULL, stack_empty};
    }
    // Copy string for security, because strings are mutable in C
    // If mutable make a copy!
    return (StringResponse){strdup(s->values[s->size - 1]), success};

}
_Bool isEmpty(Stack s){
    return s->size == 0;

}
_Bool isFull(Stack s){
    return s->size == MAXIMUM_CAPACITY;
}

_Bool valuesFull(Stack s){
    return s->size == s->currentCapacity;
}

int size(Stack s){
    return s->size;
}

response_code expandStack(Stack s) {
    int newCapacity = s->currentCapacity * 2;
    if (newCapacity > MAXIMUM_CAPACITY) {
        return stack_full;
    }

    char** newValues = malloc(sizeof(char*) * newCapacity);
    if (newValues == NULL) {
        return out_of_memory;
    }

    for (int i = 0; i < s->size; i++) {
        newValues[i] = s->values[i];
    }

    //  free old array of pointers!!
    free(s->values);

    //  Same stack but point to new array and capacity
    s->values = newValues;
    s->currentCapacity = newCapacity;
    return success;
}