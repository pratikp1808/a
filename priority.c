#include <stdio.h>

typedef struct {
    int process_no;
    int priority;
    int burst;
    int wait;
    int tat;
} process;

void bubbleSort(process arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].priority > arr[j + 1].priority) {
                process temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    process p[n];

    printf("\nEnter the processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].process_no);
    }

    printf("\nEnter the burst times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].burst);
    }

    printf("\nEnter the priority: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].priority);
    }

    bubbleSort(p, n);

    p[0].wait = 0;
    int total_waiting_time = 0;
    for (int i = 1; i < n; i++) {
        p[i].wait = p[i - 1].wait + p[i - 1].burst;
        total_waiting_time += p[i].wait;
    }

    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].wait + p[i].burst;
    }

    printf("\n");
    printf("Processes\tPriority\tBurstTime\tWaitTime\tTurnaroundTime\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].process_no, p[i].priority, p[i].burst, p[i].wait, p[i].tat);
    }

    float avg_wait = (float)total_waiting_time / n;
    printf("\nThe average waiting time is: %f\n", avg_wait);

    return 0;
}
