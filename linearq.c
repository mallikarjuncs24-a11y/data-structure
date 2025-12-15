#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int value;
    if (rear == MAX - 1)
    {
        printf("Queue overflow\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    queue[++rear] = value;
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front++]);

    // Optional reset when queue becomes empty
    if (front > rear)
        front = rear = -1;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert  2. Delete  3. Display  4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}

