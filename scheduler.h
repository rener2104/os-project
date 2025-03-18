#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Process.h"
#include <vector>

class Scheduler {
private:
    std::vector<int> completionTimes;
    std::vector<int> turnaroundTimes;
    std::vector<int> waitingTimes;
    double averageTurnaroundTime;
    double averageWaitingTime;

public:
    Scheduler();

    void FCFS(std::vector<Process>& processes);
    void SJF(std::vector<Process>& processes, bool preemptive);
    void PrintResults();
};

#endif //SCHEDULER_H
