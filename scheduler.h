#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Process.h"

class Scheduler {

  public:
    void FCFS(std::vector<Process>& processes);
    void SJF(std::vector<Process>& processes, bool preemptive = false);
    void PrintResults();

  private:
    std::vector<int> completionTimes;
    std::vector<int> turnaroundTimes;
    std::vector<int> waitingTimes;
    double averageTurnaroundTime = 0.0;
    double averageWaitingTime = 0.0;
};

#endif //SCHEDULER_H
