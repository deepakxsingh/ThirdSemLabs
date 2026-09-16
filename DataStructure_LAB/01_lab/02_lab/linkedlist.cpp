#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student Node structure
typedef struct Node {
    int rollNumber;
    char name[50];
    struct Node* next;
} Node;

// Function to create a new node dynamically
Node* createNode(int roll, const char* studentName) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->rollNumber = roll;
    strcpy(newNode->name, studentName);
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("[Roll: %d, Name: %s] -> ", temp->rollNumber, temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

// a. Insert a new node at a specified position (1-based index)
Node* insertAtPosition(Node* head, int roll, const char* name, int position) {
    Node* newNode = createNode(roll, name);

    // If inserting at the beginning (position 1)
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    // Traverse to the node right before the target position
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If the position is out of bounds
    if (temp == NULL) {
        printf("Position out of bounds. Node not inserted.\n");
        free(newNode);
        return head;
    }

    // Insert the node
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// b. Delete a node with the specified roll number
Node* deleteByRollNumber(Node* head, int roll) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    // If the node to be deleted is the head node
    if (head->rollNumber == roll) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("Deleted student with Roll Number %d\n", roll);
        return head;
    }

    Node* current = head;
    Node* prev = NULL;

    // Search for the roll number
    while (current != NULL && current->rollNumber != roll) {
        prev = current;
        current = current->next;
    }

    // If the roll number was not found
    if (current == NULL) {
        printf("Student with Roll Number %d not found.\n", roll);
        return head;
    }

    // Unlink the node from the linked list
    prev->next = current->next;
    free(current);
    printf("Deleted student with Roll Number %d\n", roll);
    return head;
}

// c. Reversal of the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next; // Store the next node
        current->next = prev;     // Reverse the current node's pointer
        prev = current;           // Move prev one step forward
        current = nextNode;       // Move current one step forward
    }
    return prev; // New head of the reversed list
}

// Free memory allocation at the end of the program
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    printf("--- Initializing and Inserting Students ---\n");
    head = insertAtPosition(head, 101, "Alice", 1);
    head = insertAtPosition(head, 103, "Charlie", 2);
    head = insertAtPosition(head, 102, "Bob", 2); // Inserts between Alice and Charlie
    displayList(head);

    printf("\n--- b. Deleting Node with Roll Number 102 ---\n");
    head = deleteByRollNumber(head, 102);
    displayList(head);

    printf("\n--- c. Reversing the Linked List ---\n");
    head = reverseList(head);
    displayList(head);

    // Clean up memory
    freeList(head);

    return 0;
}
