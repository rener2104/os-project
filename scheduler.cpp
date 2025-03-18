#include "scheduler.h"
#include <iostream>
#include <queue>
#include <algorithm>

Scheduler::Scheduler() {
    averageTurnaroundTime = 0.0;
    averageWaitingTime = 0.0;
}

void Scheduler::FCFS(std::vector<Process>& processes) {
    int currentTime = 0;
    for (auto& process : processes) {
        if (process.GetArrivalTime() > currentTime) {
            currentTime = process.GetArrivalTime();
        }

        process.UpdateState(1);
        process.ReduceExecutionTime(process.GetBurstTime());
        currentTime += process.GetBurstTime();

        process.UpdateState(3);
        process.UpdateTurnaroundTime(currentTime - process.GetArrivalTime());
        process.UpdateWaitingTime(currentTime - process.GetArrivalTime() - process.GetBurstTime());

        completionTimes.push_back(currentTime);
        turnaroundTimes.push_back(process.GetTurnaroundTime());
        waitingTimes.push_back(process.GetWaitingTime());
    }
    PrintResults();
}

void Scheduler::SJF(std::vector<Process>& processes, bool preemptive) {
    int currentTime = 0;
    std::vector<Process> readyQueue = processes;

    if (preemptive) {
        auto compare = [](const Process& a, const Process& b) {
            return a.GetBurstTime() > b.GetBurstTime();
        };

        std::priority_queue<Process, std::vector<Process>, decltype(compare)> pq(compare);

        for (auto& process : readyQueue) {
            pq.push(process);
        }

        while (!pq.empty()) {
            Process currentProcess = pq.top();
            pq.pop();

            if (currentProcess.GetArrivalTime() > currentTime) {
                currentTime = currentProcess.GetArrivalTime();
            }

            currentProcess.UpdateState(1);
            currentProcess.ReduceExecutionTime(currentProcess.GetBurstTime());
            currentTime += currentProcess.GetBurstTime();

            currentProcess.UpdateState(3);
            currentProcess.UpdateTurnaroundTime(currentTime - currentProcess.GetArrivalTime());
            currentProcess.UpdateWaitingTime(currentTime - currentProcess.GetArrivalTime() - currentProcess.GetBurstTime());

            completionTimes.push_back(currentTime);
            turnaroundTimes.push_back(currentProcess.GetTurnaroundTime());
            waitingTimes.push_back(currentProcess.GetWaitingTime());
        }
    } else {
        std::sort(readyQueue.begin(), readyQueue.end(), [](const Process& a, const Process& b) {
            return a.GetBurstTime() < b.GetBurstTime();
        });

        for (auto& process : readyQueue) {
            if (process.GetArrivalTime() > currentTime) {
                currentTime = process.GetArrivalTime();
            }

            process.UpdateState(1);
            process.ReduceExecutionTime(process.GetBurstTime());
            currentTime += process.GetBurstTime();

            process.UpdateState(3);
            process.UpdateTurnaroundTime(currentTime - process.GetArrivalTime());
            process.UpdateWaitingTime(currentTime - process.GetArrivalTime() - process.GetBurstTime());

            completionTimes.push_back(currentTime);
            turnaroundTimes.push_back(process.GetTurnaroundTime());
            waitingTimes.push_back(process.GetWaitingTime());
        }
    }

    PrintResults();
}

void Scheduler::PrintResults() {
    double totalTurnaroundTime = 0.0;
    double totalWaitingTime = 0.0;
    int numProcesses = turnaroundTimes.size();

    for (int i = 0; i < numProcesses; ++i) {
        totalTurnaroundTime += turnaroundTimes[i];
        totalWaitingTime += waitingTimes[i];
    }

    averageTurnaroundTime = totalTurnaroundTime / numProcesses;
    averageWaitingTime = totalWaitingTime / numProcesses;

    std::cout << "Average Turnaround Time: " << averageTurnaroundTime << std::endl;
    std::cout << "Average Waiting Time: " << averageWaitingTime << std::endl;
}
