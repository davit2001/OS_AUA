
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
    int start_time;
    int completion_time;
    int completed;
} Process;

void reset_processes(Process dest[], const Process src[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
        dest[i].waiting_time = 0;
        dest[i].turnaround_time = 0;
        dest[i].response_time = 0;
        dest[i].start_time = -1;
        dest[i].completion_time = -1;
        dest[i].completed = 0;
    }
}

void calculate_metrics(Process processes[], int index, int start) {
    processes[index].start_time = start;
    processes[index].completion_time = start + processes[index].burst_time;
    processes[index].turnaround_time =
        processes[index].completion_time - processes[index].arrival_time;
    processes[index].waiting_time =
        processes[index].turnaround_time - processes[index].burst_time;
    processes[index].response_time =
        processes[index].start_time - processes[index].arrival_time;
    processes[index].completed = 1;
}

void display_results(
    const char *name, Process p[], int order[],
    int starts[], int n
) {
    double total_wait = 0;
    double total_turnaround = 0;
    double total_response = 0;

    printf("\n=== %s ===\n", name);
    printf("Gantt Chart: ");

    for (int i = 0; i < n; i++) {
        int previous_end = 0;

        if (i > 0) {
            previous_end = p[order[i - 1]].completion_time;
        }

        if (starts[i] > previous_end) {
            printf("| Idle ");
        }

        printf("| P%d ", p[order[i]].pid);
    }

    printf("|\n");

    printf("Timeline: ");
    for (int i = 0; i < n; i++) {
        printf("[%d-%d: P%d] ",
           starts[i],
           p[order[i]].completion_time,
           p[order[i]].pid
        );
    }

    printf("\n");
    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");

    for (int i = 0; i < n; i++) {
        int index = order[i];

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
           p[index].pid,
           p[index].arrival_time,
           p[index].burst_time,
           p[index].waiting_time,
           p[index].turnaround_time,
           p[index].response_time
        );

        total_wait += p[index].waiting_time;
        total_turnaround += p[index].turnaround_time;
        total_response += p[index].response_time;
    }

    printf("Average Waiting Time: %.2f\n", total_wait / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround / n);
    printf("Average Response Time: %.2f\n", total_response / n);
}

void fcfs(const Process input[], int n) {
    Process *p = malloc(n * sizeof(Process));
    int *order = malloc(n * sizeof(int));
    int *starts = malloc(n * sizeof(int));

    if (p == NULL || order == NULL || starts == NULL) {
        printf("Memory allocation failed\n");
        free(p);
        free(order);
        free(starts);
        
        return;
    }

    reset_processes(p, input, n);

    for (int i = 0; i < n; i++) {
        order[i] = i;
    }

    for (int i = 1; i < n; i++) {
        int key = order[i];
        int j = i - 1;

        while (j >= 0 && p[order[j]].arrival_time > p[key].arrival_time) {
            order[j + 1] = order[j];
            j--;
        }

        order[j + 1] = key;
    }

    int time = 0;

    for (int i = 0; i < n; i++) {
        int index = order[i];
        if (time < p[index].arrival_time) {
            time = p[index].arrival_time;
        }

        starts[i] = time;
        calculate_metrics(p, index, time);
        time = p[index].completion_time;
    }

    display_results("First Come First Served (FCFS)", p, order, starts, n);
    
    free(p);
    free(order);
    free(starts);
}

void sjf(const Process input[], int n) {
    Process *p = malloc(n * sizeof(Process));
    int *order = malloc(n * sizeof(int));
    int *starts = malloc(n * sizeof(int));

    if (p == NULL || order == NULL || starts == NULL) {
        printf("Memory allocation failed\n");
        free(p);
        free(order);
        free(starts);
        return;
    }

    reset_processes(p, input, n);

    int time = 0;

    for (int done = 0; done < n; done++) {
        int best = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].completed == 1 ||
                p[i].arrival_time > time) {
                continue;
            }

            if (best == -1 ||
                p[i].burst_time < p[best].burst_time ||
                (p[i].burst_time == p[best].burst_time &&
                 p[i].arrival_time < p[best].arrival_time) ||
                (p[i].burst_time == p[best].burst_time &&
                 p[i].arrival_time == p[best].arrival_time &&
                 p[i].pid < p[best].pid)) {
                best = i;
            }
        }

        if (best == -1) {
            int earliest = INT_MAX;

            for (int i = 0; i < n; i++) {
                if (p[i].completed == 0 &&
                    p[i].arrival_time < earliest) {
                    earliest = p[i].arrival_time;
                }
            }

            time = earliest;
            done--;
            continue;
        }

        order[done] = best;
        starts[done] = time;

        calculate_metrics(p, best, time);
        time = p[best].completion_time;
    }

    display_results("Shortest Job First (SJF, Non-preemptive)",
                    p, order, starts, n);

    free(p);
    free(order);
    free(starts);
}

int main(void) {
    int n;

    printf("Enter the number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 10000) {
        printf("Invalid number of processes\n");
        return 1;
    }

    Process *processes = calloc(n, sizeof(Process));

    if (processes == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for process %d: ",
               i + 1);

        if (scanf("%d %d",
            &processes[i].arrival_time, 
            &processes[i].burst_time) != 2 ||
            processes[i].arrival_time < 0 ||
            processes[i].burst_time <= 0
        ) {
            printf("Invalid input\n");
            free(processes);
            return 1;
        }

        processes[i].pid = i + 1;
    }

    fcfs(processes, n);
    sjf(processes, n);

    free(processes);

    return 0;
}
