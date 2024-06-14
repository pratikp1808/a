#include <stdio.h>
#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

struct Process {
    int id;
    int burst;
    int remaining_time;
    int wait;
    int tat;
};

void waittime(struct Process processes[], int n) {
    int remaining_burst[MAX_PROCESSES];
    int i;
    for (i = 0; i < n; i++) {
        remaining_burst[i] = processes[i].burst;
    }
    int currentTime = 0;
    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                done = 0;
                if (remaining_burst[i] > TIME_QUANTUM) {
                    printf("Process %d executed for %d units.\n", processes[i].id, TIME_QUANTUM);
                    currentTime += TIME_QUANTUM;
                    remaining_burst[i] -= TIME_QUANTUM;
                } else {
                    printf("Process %d executed for %d units.\n", processes[i].id, remaining_burst[i]);
                    currentTime += remaining_burst[i];
                    processes[i].wait = currentTime - processes[i].burst;
                    remaining_burst[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
}

void tat(struct Process processes[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        processes[i].tat = processes[i].burst + processes[i].wait;
    }
}

void AverageTime(struct Process processes[], int n) {
    int totalwait = 0, total_tat = 0;
    waittime(processes, n);
    tat(processes, n);
    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time\n");
    int i;
    for (i = 0; i < n; i++) {
        totalwait += processes[i].wait;
        total_tat += processes[i].tat;
        printf("%d\t %d\t\t %d\t\t %d\n", processes[i].id, processes[i].burst, processes[i].wait, processes[i].tat);
    }
    printf("\nAverage waiting time: %.2f", (float)totalwait / n);
    printf("\nAverage turnaround time: %.2f\n", (float)total_tat / n);
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    if (n > MAX_PROCESSES) {
        printf("Number of processes exceeds maximum limit. Please try again.");
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst);
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst;
    }
    AverageTime(processes, n);
    return 0;
}
