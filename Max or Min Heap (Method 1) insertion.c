#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct Node {
    int data;
    struct Node* next;
};

int heap[MAX];
int size = 0;


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertMinHeap(int data) {
    if (size >= MAX) {
        printf("Heap is full!\n");
        return;
    }

    int i = size;
    heap[size++] = data;

    
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) //For Max heap: heap[(i-1)/2] < heap[i]
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void printHeap() {
    printf("Min Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void printList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert Element\n");
        printf("2. Display Linked List\n");
        printf("3. Display Min Heap\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            append(&head, value);
            insertMinHeap(value);
            break;
        case 2:
            printList(head);
            break;
        case 3:
            printHeap();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}
