#include <stdio.h>
#include <stdlib.h>

#define MAX 8

typedef struct pqueue {
    int pri;
    int data;
} priq;

priq queue[MAX];
int rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return rear == -1;
}

void insert(int priority, int data) {
    if (isFull()) {
        printf("Queue is full, cannot insert!\n\n");
        return;
    }

    rear++;
    queue[rear].data = data;
    queue[rear].pri = priority;

    for (int i = rear; i > 0; i--) {
        if (queue[i].pri < queue[i - 1].pri) {
            priq temp = queue[i];
            queue[i] = queue[i - 1];
            queue[i - 1] = temp;
        }
    }

    printf("Inserted %d with priority %d\n\n", data, priority);
}

void deleteElement() {
    if (isEmpty()) {
        printf("Queue is empty, cannot delete!\n\n");
        return;
    }

    printf("Deleted: %d with priority %d\n\n", queue[0].data, queue[0].pri);

    for (int i = 0; i < rear; i++) {
        queue[i] = queue[i + 1];
    }

    rear--;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty, nothing to display.\n\n");
        return;
    }

    printf("Priority Queue Elements:\n");
    for (int i = 0; i <= rear; i++) {
        printf("Data: %d, Priority: %d\n", queue[i].data, queue[i].pri);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("Choices:\n\t1. Enqueue\n\t2. Dequeue\n\t3. Display\n\t4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1: {
                int ele, prio;
                printf("Enter element and its priority: ");
                scanf("%d %d", &ele, &prio);
                insert(prio, ele);
                break;
            }
            case 2: {
                char ch;
                printf("It deletes only the beginning (highest priority) element!\n");
                printf("Do you want to proceed? (y/n): ");
                scanf(" %c", &ch);
                (ch == 'y' || ch == 'Y') ? deleteElement() : printf("Cancelled.\n\n");
                break;
            }
            case 3:
                display();
                break;
            case 4:
                printf("Exited...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n\n");
        }
    }

    return 0;
}
