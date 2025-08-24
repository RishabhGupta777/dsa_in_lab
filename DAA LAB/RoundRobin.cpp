#include <iostream>
#include <queue>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[], int tq) {
    int rt[n];  // Remaining burst times
    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    int t = 0; // Current time
    queue<int> q;
    bool inQueue[n] = {false};

    int completed = 0;
    while (completed < n) { 
        // Add processes that have arrived
        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0 && !inQueue[i]) {
                q.push(i);
                inQueue[i] = true;  
            }
        }

        if (q.empty()) {
            t++;
            continue;
        }

        int i = q.front();
        q.pop();

        int execTime = min(tq, rt[i]);
        rt[i] -= execTime;
        t += execTime;

        // Add new arrivals during execution
        for (int j = 0; j < n; j++) {
            if (at[j] <= t && rt[j] > 0 && !inQueue[j]) {
                q.push(j);
                inQueue[j] = true;
            }
        }

        if (rt[i] > 0) {
            q.push(i); // Re-add unfinished process
        } else {
            wt[i] = t - at[i] - bt[i];
            completed++;
        }
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int at[], int bt[], int tq) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, at, wt, tq);
    findTurnAroundTime(processes, n, bt, wt, tat);

    cout << "Process\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "P" << processes[i] << "\t" << at[i] << "\t" << bt[i] << "\t"
             << wt[i] << "\t" << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << (float)total_wt / n;
    cout << "\nAverage Turnaround Time = " << (float)total_tat / n << endl;
}

int main() {
    // Example
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);
    int arrival_time[] = {0, 1, 2, 3};
    int burst_time[] = {5, 4, 2, 1};
    int time_quantum = 2;

    cout << "Round Robin Scheduling (Time Quantum = " << time_quantum << "):\n";
    findAverageTime(processes, n, arrival_time, burst_time, time_quantum);

    return 0;
}
