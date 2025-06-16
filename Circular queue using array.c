#include <stdio.h>
#define SIZE 5  // define the size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to add an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

// Function to remove an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }

    int value = queue[front];

    if (front == rear) {
        // Queue has only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return value;
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Driver code
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); // should say "Queue is full" because one space is always kept free in circular queue to distinguish full and empty

    display();

    printf("Deleted %d\n", dequeue());
    printf("Deleted %d\n", dequeue());

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}
