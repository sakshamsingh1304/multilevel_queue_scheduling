#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    string name;
    int priority;
    int burstTime;
};

bool sortByPriority(const Process &a, const Process &b) {
    return a.priority < b.priority;
}

int main() {
    int x, y, z; 
    cout << "Enter the number of processes for Queue 1: ";
    cin >> x;
    cout << "Enter the number of processes for Queue 2: ";
    cin >> y;
    cout << "Enter the number of processes for Queue 3: ";
    cin >> z;

    int priority1, priority2, priority3;
    cout << "Enter the priority for Queue 1: ";
    cin >> priority1;
    cout << "Enter the priority for Queue 2: ";
    cin >> priority2;
    cout << "Enter the priority for Queue 3: ";
    cin >> priority3;

    queue<Process> queue1;
    queue<Process> queue2;
    queue<Process> queue3;

    for (int i = 1; i <= x; i++) {
        Process process;
        process.name = "1" + to_string(i);
        process.priority = priority1;

        if (priority1 == 1) {
            cout << "Enter burst time for " << process.name << ": ";
            cin >> process.burstTime;
        } else {
            process.burstTime = 0; 
        }

        queue1.push(process);
    }
    for (int i = 1; i <= y; i++) {
        Process process;
        process.name = "2" + to_string(i);

        if (priority2 == 2) {
            cout << "Enter priority for " << process.name << ": ";
            cin >> process.priority;
        } else {
            process.priority = priority2;
        }
        queue2.push(process);
    }
    for (int i = 1; i <= z; i++) {
        Process process;
        cout << "Enter the name for process A" << i << ": ";
        cin >> process.name;
        queue3.push(process);
    }

    cout << "Processes in Queue 1: ";
    queue<Process> tempQueue1 = queue1;
    while (!tempQueue1.empty()) {
        cout << tempQueue1.front().name << " ";
        tempQueue1.pop();
    }
    cout << endl;

    cout << "Processes in Queue 2: ";
    queue<Process> tempQueue2 = queue2;
    while (!tempQueue2.empty()) {
        cout << tempQueue2.front().name << " ";
        tempQueue2.pop();
    }
    cout << endl;
    cout << "Processes in Queue 3: ";
    queue<Process> tempQueue3 = queue3;
    while (!tempQueue3.empty()) {
        cout << tempQueue3.front().name << " ";
        tempQueue3.pop();
    }
    cout << endl;
    int quantum = 4;
    if (priority1 == 1) {
        queue<Process> roundRobinQueue1 = queue1;
        cout << "Round Robin Output for Queue 1: ";

        while (!roundRobinQueue1.empty()) {
            Process currentProcess = roundRobinQueue1.front();
            roundRobinQueue1.pop();

            cout << currentProcess.name << " ";

            if (currentProcess.burstTime > quantum) {
                currentProcess.burstTime -= quantum;
                roundRobinQueue1.push(currentProcess);
            }
        }
        cout << endl;
    }

    if (priority2 == 2) {
        vector<Process> sortedProcesses2;
        while (!queue2.empty()) {
            sortedProcesses2.push_back(queue2.front());
            queue2.pop();
        }
        sort(sortedProcesses2.begin(), sortedProcesses2.end(), sortByPriority);

        cout << "Processes in Queue 2 based on priority (Low Number Highest Priority): ";
        for (const Process &process : sortedProcesses2) {
            cout << process.name << " ";
        }
        cout << endl;
    }
    if(priority3 == 3){
        cout << "Processes in Queue 3: ";
        queue<Process> tempQueue3 = queue3;
    while (!tempQueue3.empty()) {
        cout << tempQueue3.front().name << " ";
        tempQueue3.pop();
    }
    cout << endl;

    }
    return 0;
}
