import java.util.NoSuchElementException;

public class Stack {
    private static final int STARTING_CAPACITY = 16;
    public static final int MAXIMUM_CAPACITY = 1024;

    private String[] elements;
    private int size;
    private int capacity;

    public Stack() {
        this.elements = new String[STARTING_CAPACITY];
        this.size = 0;
        this.capacity = STARTING_CAPACITY;
    }

    public void push(String item) {
        if (size == capacity) {
            expandStack();
        }
        elements[size] = item;
        size++;
    }

    private void expandStack() {
        int newCapacity = capacity * 2;
        
        if (newCapacity > MAXIMUM_CAPACITY) {
            throw new IllegalStateException("Stack is full");
        }
        String[] newElements = new String[newCapacity];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        elements = newElements;
        capacity = newCapacity;
    }

    public String pop() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }
        String lastItem = elements[size - 1];
        elements[size - 1] = null;
        size--;
        return lastItem;
    }

    public String peek() {
        if (isEmpty()) {
            throw new NoSuchElementException();
        }
        return elements[size - 1];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public boolean isFull() {
        return size == MAXIMUM_CAPACITY;
    }


}
