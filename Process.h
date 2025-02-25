//
// Created by Andy De Luna on 2/24/25.
//

#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>

class Process {
private:
    enum statusIDs {
        READY,
        RUNNING,
        WAITING,
        TERMINATED
    };

    int pid;
    int arrivalTime;
    int burstTime;
    std::string state;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
    int memoryRequired;
    int priority;
    std::string ioOperations;

    // Private Constructor
    Process(int pid, int arrivalTime, int burstTime, int memoryRequired, int priority, const std::string& ioOperations);

public:
    // Public Constructor
    static Process CreateProcess(int pid, int arrivalTime, int burstTime, int memoryRequired, int priority = 0, const std::string& ioOperations = "");

    // Getters
    int GetPID() const;
    int GetArrivalTime() const;
    int GetBurstTime() const;
    std::string GetState() const;
    int GetRemainingTime() const;
    int GetWaitingTime() const;
    int GetTurnaroundTime() const;
    int GetMemoryRequired() const;
    int GetPriority() const;
    std::string GetIoOperations() const;

    // Setters
    void SetPriority(int priority);
    void SetIoOperations(const std::string& ioOperations);

    // Method to update the state based on the provided statusID
    void UpdateState(int statusID);

    // Method to reduce remaining execution time when the process is scheduled
    void ReduceExecutionTime(int time);

    // Method to update waiting time
    void UpdateWaitingTime(int timeElapsed);

    // Method to update turnaround time
    void UpdateTurnaroundTime(int burstTime);
};

#endif //PROCESS_H
