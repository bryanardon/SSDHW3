import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

class StackTest {

    @Test
    void addition() {
        assertEquals(true, true);
    }

    @Test
    void check() {
        assertEquals(true, true);
    }
      @Test
    public void testPush() {
        Stack stack = new Stack();
        stack.push("first");
        stack.push("second");
        stack.push("third");
        assertEquals(3, stack.size());
    }

    @Test
    public void testPop() {
        Stack stack = new Stack();
        stack.push("first");
        stack.push("second");
        stack.push("third");
        assertEquals("third", stack.pop());
        assertEquals("second", stack.pop());
        assertEquals("first", stack.pop());
        assertThrows(RuntimeException.class, stack::pop);
    }

    @Test
    public void testPeek() {
        Stack stack = new Stack();
        stack.push("first");
        stack.push("second");
        assertEquals("second", stack.peek());
        stack.pop();
        assertEquals("first", stack.peek());
        stack.pop();
        assertThrows(RuntimeException.class, stack::peek);
    }

    @Test
    public void testIsEmpty() {
        Stack stack = new Stack();
        assertTrue(stack.isEmpty());
        stack.push("new element");
        assertFalse(stack.isEmpty());
        stack.pop();
        assertTrue(stack.isEmpty());
    }

    @Test
    public void testIsFull() {
        Stack stack = new Stack();
        for(int i = 0; i < Stack.MAXIMUM_CAPACITY; i++) {
            stack.push("test");
        }
        try {
            stack.push("test");
            assert(false);
        } catch (IllegalStateException e) {
            assertEquals("Stack is full", e.getMessage());
        }
    }
}
