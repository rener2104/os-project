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

    std::string pid;
    int arrivalTime;
    int burstTime;
    std::string state;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
    int memoryRequired;
    int priority = 0;
    char* ioOperations = {};

    // Constructor
    Process(std::string pid, int arrivalTime, int burstTime,
            std::string state, int remainingTime, int waitingTime,
            int turnaroundTime, int memoryRequired, int priority = 0, char* ioOperations = {});

    // Method that moves between the valid StatusIDs
    void UpdateState(int statusID);

    // Method to decrement remaining execution time when process is scheduled
    int ReduceExecutionTime();

public:
    // getters
    std::string GetPID();
    int GetArrivalTime();
    int GetBurstTime();
    std::string GetState();
    int GetRemainingTime();
    int GetWaitingTime();
    int GetTurnaroundTime();
    int GetMemoryRequired();
    int GetPriority();
    char* GetIoOperations();

    // setters
    void SetPriority(int priority);
    void SetIoOperations(char* ioOperations);
};



#endif //PROCESS_H
