#include <iostream>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;  // First process has no waiting time

    // Calculating waiting time for remaining processes
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Turnaround time is sum of burst time and waiting time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "P" << processes[i] << "\t\t"  << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << (float)total_wt / n;
    cout << "\nAverage Turnaround Time = " << (float)total_tat / n << endl;
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {6, 8, 7};  // Example burst times

    findAverageTime(processes, n, burst_time);

    return 0;
}
