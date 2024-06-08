#include <stdio.h>
#include <stdlib.h>

#define max 6
int front = -1, rear = -1;
int QUEUE[max];

void insertq();
void deleteq();
void display();
int count();

int main()
{

    int choice;

    printf("initially the queue was empty\n");
    printf("front = %d and rear = %d", front, rear);

    while (1)
    {
        printf("\n\npress 1 to insert\n");
        printf("press 2 to delete\n");
        printf("press 3 to display\n");
        printf("press 4 to count\n");
        printf("press 5 to exit\n");

        printf("\n enter your choice 1 to 5\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertq();
            break;
        case 2:
            deleteq();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("no of element in the queue = %d", count());
            break;

        case 5:
            exit(0);

        default:
            printf("Wrong choice");
        }
    }
    return 0;
}

void insertq()
{
    int data;
    if (rear == max - 1)
    {
        printf("\n queue is full. overflow. insertion not possible");
    }
    else
    {
        printf("\nEnter the element to be inserted\n");
        scanf("%d", &data);
        rear++;
        if (front == -1)
        {
            front++;
        }
        QUEUE[rear] = data;
        printf("Insertion secessful.\n");
        printf("front = %d, rear = %d", front, rear);
    }
}

void deleteq()
{
    int temp;
    if (front == -1)
    {
        printf("\nthe queue is empty.underflow. delete not possible\n");
    }
    else
    {
        temp = QUEUE[front];
        QUEUE[front] = NULL;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        printf("\nDeletion oparation sucessfull");
        printf("\nFront = %d , rear = %d", front, rear);
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("\nThe Queue is Empty. Nothing to display");
    }
    else
    {
        printf("\nElements in the queue are :\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", QUEUE[i]);
        }
    }
}
int count()
{
    if (front == -1)
    {
        return (0);
    }
    else
    {
        return (rear - front + 1);
    }
}