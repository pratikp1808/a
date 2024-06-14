#include<stdio.h>
#include<stdlib.h>

int front = -1, rear = -1,v=0;
int n = 5;
int q[5];
int startTime[5] = {0};

void dis();

void enqueue(int c, int start)
 {
    int i, j;
    if (rear == n - 1) 
	{
        printf("\nQUEUE IS FULL!");
        return;
    }
    if (front == -1 && rear == -1) 
	{
        front = rear = 0;
        q[rear] = c;
        startTime[rear] = start;
    } 
	else 
	{
        rear++;
        q[rear] = c;
        startTime[rear] = start;
    }
    v++;
}
void dequeue() 
{
    if (front == -1 && rear == -1) 
	{
        printf("\nQUEUE IS EMPTY!");
    } 
	else if (front == rear) 
	{
        printf("\nThe Dequeued element is: %d", q[front]);
        front = rear = -1;
    } 
	else 
	{
        printf("\nThe Dequeued element is: %d ", q[front]);
        front++;
    }
    
}

void dis() 
{
    int wait = 0,j,sum,avg;
    if (front == -1 && rear == -1) 
    {
        printf("\nQUEUE IS EMPTY!");
    }
     else 
    {
        printf("\nprocess\t\tstart time\twait\n");
        printf("______________________________________\n\n");
        for ( j = front; j <= rear; j++) 
        {
            if (j == front) 
			{
                wait = 0;
            } 
			else 
			{
                wait = startTime[j] + wait;
                sum+=wait;
            }
            printf("[%d]\t\t%d\t\t%d\t\t\n", q[j], startTime[j], wait);
        }
        avg=sum/v;
        printf("\nTotal waiting time is:%d",sum);
        printf("\nAvg waiting time is:%d",avg);
    }
}
int main()
{
 int y, c, start = 0;
    while (y != 4) 
	{
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        printf("\nEnter the operation :");
        scanf("%d", &y);
        switch (y) 
		{
            case 1:
                printf("\nEnter the process: ");
                scanf("%d", &c);
                printf("\nEnter the start time: ");
                scanf("%d", &start);
                enqueue(c, start);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                dis();
                break;
            case 4:
                exit(0);
                break;
        }
    }
}
