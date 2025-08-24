#include <iostream>
#include <climits>
using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int at[], int wt[]) {
    int rt[n]; // Remaining time
    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0;
    bool check = false;  

    while (complete != n) {
        // Find process with minimum remaining time among arrived processes
        for (int j = 0; j < n; j++) {
            if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (!check) {
            t++;
            continue;
        }

        // Reduce remaining time
        rt[shortest]--;
        minm = rt[shortest];

        if (minm == 0)
            minm = INT_MAX;

        // If process is completed
        if (rt[shortest] == 0) {
            complete++;
            check = false;

            int finish_time = t + 1;
            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int at[], int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, at, wt);
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
    // Example 1
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);
    int arrival_time[] = {0, 1, 2, 3};
    int burst_time[] = {8, 4, 2, 1};

    findAverageTime(processes, n, arrival_time, burst_time);

    return 0;
}
