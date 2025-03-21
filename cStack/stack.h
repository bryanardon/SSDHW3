// In class, this is a NONexandable stack of strings
// Even if you make exaandable stack of strings, you still need Maximum_capacity

#define MAXIMUM_CAPACITY 1024 // 2^10
#define STARTING_CAPACITY 4  // 2^2, easy for testing

typedef struct S* Stack; 

typedef enum {
    out_of_memory,
    stack_full,
    stack_empty,
    success
} response_code;

typedef struct {
    const char* value;
    response_code code;
} StringResponse;

typedef struct {
    Stack stack;
    response_code code;
} StackResponse;

StackResponse createStack();
void destroyStack(Stack s);
response_code push(Stack s, char* str);
StringResponse pop(Stack s);
StringResponse peek(Stack s);
_Bool isEmpty(Stack s);
_Bool isFull(Stack s);
_Bool valuesFull(Stack s);
response_code expandStack(Stack s);
int size(Stack s);