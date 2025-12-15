#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        printf("Queue overflow\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    queue[rear] = value;
}

void delete()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
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
