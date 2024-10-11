# Queue-implementation-using-array


# Queue Implementations in C++

## Overview

This project contains two implementations of a **queue** in C++:
1. Using the **C++ Standard Library (STL)** `queue` container.
2. A **custom queue** implementation using dynamic arrays with basic operations.

Both versions support basic queue operations like:
- **Enqueue** (push): Add an element to the end of the queue.
- **Dequeue** (pop): Remove the front element from the queue.
- **Peek** (front): View the front element without removing it.

---

## Queue Implementation using C++ STL `queue`

### Code Explanation:

This implementation leverages the `queue` container from the C++ Standard Template Library (STL), which provides a built-in, efficient way to handle queue operations.

### Operations:

1. **push(int)**: Adds an element to the end of the queue.
2. **pop()**: Removes the front element of the queue.
3. **front()**: Returns the front element of the queue.

### Example Code:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Adding elements to the queue
    q.push(30);
    q.push(20);
    q.push(10);

    // Print the front element of the queue
    cout << "Front element before pop: " << q.front() << endl;

    // Remove the front element from the queue
    q.pop();

    // Print the front element after pop
    cout << "Front element after pop: " << q.front() << endl;

    return 0;
}
```

### How to Run:
1. Copy the above code into a file (e.g., `queue_stl.cpp`).
2. Compile using a C++ compiler:
   ```
   g++ -o queue_stl queue_stl.cpp
   ```
3. Run the executable:
   ```
   ./queue_stl
   ```

---

## Custom Queue Implementation using Dynamic Array

### Code Explanation:

This version of the queue is implemented using a dynamic array. It handles manual memory allocation and provides the basic queue operations.

### Operations:

1. **push(int element)**: Adds an element to the queue if there is space (enqueue).
2. **pop()**: Removes the front element from the queue (dequeue).
3. **peek()**: Returns the front element of the queue without removing it.

### Class Structure:

- **Attributes**:
  - `int capacity`: The maximum size of the queue.
  - `int front`: The index of the front element in the queue.
  - `int rear`: The index of the rear element in the queue.
  - `int* arr`: Pointer to the dynamically allocated array used for storing queue elements.
  
- **Methods**:
  - `push(int element)`: Adds an element to the end of the queue.
  - `pop()`: Removes the front element of the queue.
  - `peek()`: Retrieves the front element without removing it.
  - **Destructor**: Cleans up dynamically allocated memory.

### Example Code:

```cpp
#include <iostream>
using namespace std;

class Queue {
public:
    int capacity;
    int front;
    int rear;
    int* arr;

    // Constructor to initialize the queue
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Enqueue: Add an element to the queue
    void push(int element) {
        if (rear + 1 < capacity) {
            if (front == -1) {
                front = 0;
            }
            rear++;
            arr[rear] = element;
        } else {
            cout << "Queue Overflow" << endl;
        }
    }

    // Dequeue: Remove an element from the queue
    void pop() {
        if (front >= 0) {
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        } else {
            cout << "Queue Underflow" << endl;
        }
    }

    // Peek: Get the front element of the queue
    int peek() {
        if (front >= 0) {
            return arr[front];
        } else {
            return -1;
        }
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5); // Initialize queue with a capacity of 5
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl; // Should print 10

    q.pop(); // Remove 10
    cout << "Front element after pop: " << q.peek() << endl; // Should print 20

    return 0;
}
```

### How to Run:
1. Copy the above code into a file (e.g., `queue_custom.cpp`).
2. Compile using a C++ compiler:
   ```
   g++ -o queue_custom queue_custom.cpp
   ```
3. Run the executable:
   ```
   ./queue_custom
   ```

---

## Key Differences between STL Queue and Custom Queue

- **STL Queue**: Provides an out-of-the-box solution with built-in memory management. Easier to use but less customizable.
- **Custom Queue**: Offers more control over memory management and allows deeper understanding of queue operations, but requires manual handling of memory and potential edge cases.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---
