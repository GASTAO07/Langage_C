# Langage_C

```
# Stack and Queue Implementations in C

This repository provides simple implementations of the stack and queue data structures in the C programming language. These data structures can be used to organize and manipulate data in a Last-In-First-Out (LIFO) or First-In-First-Out (FIFO) manner, respectively.

## Stack

The stack implementation (`stack.c`) consists of the following functions:

- `initStack`: Initializes the stack.
- `isStackEmpty`: Checks if the stack is empty.
- `isStackFull`: Checks if the stack is full.
- `push`: Adds an element to the top of the stack.
- `pop`: Removes and returns the top element from the stack.

To use the stack implementation, include `stack.c` in your project and call the appropriate functions to perform stack operations.

## Queue

The queue implementation (`queue.c`) includes the following functions:

- `initQueue`: Initializes the queue.
- `isQueueEmpty`: Checks if the queue is empty.
- `isQueueFull`: Checks if the queue is full.
- `enqueue`: Adds an element to the rear of the queue.
- `dequeue`: Removes and returns the front element from the queue.

To use the queue implementation, include `queue.c` in your project and use the provided functions to perform queue operations.

## Usage

1. Clone the repository:

```
git clone https://github.com/example/stack-and-queue-c.git
```

2. Include the respective implementation file (`stack.c` or `queue.c`) in your C project.

3. Call the appropriate functions to perform stack or queue operations based on your requirements.

## Example

Here's an example usage of the stack and queue implementations:

```c
#include <stdio.h>
#include "stack.c"
#include "queue.c"

int main() {
    // Stack example
    initStack();
    push(10);
    push(20);
    push(30);
    
    int stackValue = pop();
    printf("Stack value: %d\n", stackValue);  // Output: 30
    
    // Queue example
    initQueue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    int queueValue = dequeue();
    printf("Queue value: %d\n", queueValue);  // Output: 10
    
    return 0;
}
```

This example demonstrates how to initialize, perform operations, and retrieve values from both the stack and the queue.

## Contributing

If you'd like to contribute to this project by improving the code or adding new features, you're welcome to submit a pull request. Please ensure that your code follows the established coding style and includes appropriate tests.

## License

This project is licensed under the [MIT License](LICENSE).
```
