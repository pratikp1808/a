#include<stdio.h>
#include <stdlib.h>
void display(int p[], int n, int allocated[]) {
    printf("Process No.\tProcess Size\tBlock no.\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t", i + 1, p[i]);
        if (allocated[i] != -1) {
            printf("%d", allocated[i] + 1);
        } else {
            printf("Not Allocated");
        }
        printf("\n");
    }
}
void reverse(int arr[], int n) {
    int temp;
    for (int i = 0; i < n/2; i++) {
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void firstfit(int p[], int b[], int m, int n)
{
    int allocation[n];
    for(int i = 0; i < n; i++) {
        allocation[i] = -1; 
        printf(" %d ",b[i]);
    }
    int y[n];
    for(int i = 0; i < n; i++) 
    {  
        y[i] = b[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(y[j] >= p[i]) {
                allocation[i] = j; 
                y[j]=-1;
                break;
            }
        }
    }
    printf("\nFirst Fit Allocation:\n");
    display(p, m, allocation);
}
void bestfit(int p[], int b[], int m, int n)
{
    int allocation[n];
    for(int i = 0; i < n; i++) 
    {
        allocation[i] = -1; 
    }
    int x[n];
    for(int i = 0; i < n; i++) 
    {
        x[i] = b[i];
    }
    bubbleSort(x,n);
    printf("\nBlocks are :\n");
    for(int i = 0; i < n; i++) 
    {
        printf("%d\n",x[i]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(x[j] >= p[i]) {
                allocation[i] = j; 
                x[j]=-1;
                break;
            }
        }
    }
    printf("\nBest Fit Allocation:\n");
    display(p, m, allocation);
}
void worstfit(int p[], int b[], int m, int n)
{
    int allocation[n];
    for(int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    int x[n];
    for(int i = 0; i < n; i++)
    {
        x[i] = b[i];
    }
    bubbleSort(x,n);
    reverse(x,n);
    printf("\nBlocks are :\n");
    for(int i = 0; i < n; i++){
        printf("%d\n",x[i]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if(x[j] >= p[i])
            {
                allocation[i] = j;
                x[j]=-1;
                break;
            }
        }
    }
    printf("\nWorst Fit Allocation:\n");
    display(p,m, allocation);
}
int main() {
    int n, m;
    printf("\nEnter the no. of blocks: ");
    scanf("%d", &n);
    printf("\nEnter the no. of processes: ");
    scanf("%d", &m);
    int blocksize[n];
    int process[m];
    printf("\nEnter the block sizes: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &blocksize[i]);
    }
    printf("\nEnter the process sizes: ");
    for(int i = 0; i < m; i++) {
        scanf("%d", &process[i]);
    }
    for(int i = 0; i < n; i++) {
        printf("%d", blocksize[i]);
    }
    int choice;
    while(choice!=4)
    {
        printf("\n1.First Fit Allocation\n2.Best Fit Allocation\n3.Worst Fit Allocation\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: firstfit(process, blocksize, m, n);
            break;
            case 2: bestfit(process, blocksize, m, n);
            break;
            case 3:worstfit(process, blocksize, m, n);
            break;
            case 4:return 0;
            default: printf("Invalid choice\n");    
        }
    }
    return 0;
}
