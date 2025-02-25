//
// Created by Andy De Luna on 2/24/25.
//

#include "Process.h"
#include <iostream>
#include <stdexcept>

// Private Constructor
Process::Process(int pid, int arrivalTime, int burstTime, int memoryRequired, int priority, const std::string& ioOperations)
    : pid(pid), arrivalTime(arrivalTime), burstTime(burstTime), remainingTime(burstTime),
      waitingTime(0), turnaroundTime(0), memoryRequired(memoryRequired), priority(priority), ioOperations(ioOperations) {
    state = "READY";
}

// Public Constructor
Process Process::CreateProcess(int pid, int arrivalTime, int burstTime, int memoryRequired,
                                int priority, const std::string& ioOperations) {
    return Process(pid, arrivalTime, burstTime, memoryRequired, priority, ioOperations);
}

// Getters
int Process::GetPID() const {
    return pid;
}

int Process::GetArrivalTime() const {
    return arrivalTime;
}

int Process::GetBurstTime() const {
    return burstTime;
}

std::string Process::GetState() const {
    return state;
}

int Process::GetRemainingTime() const {
    return remainingTime;
}

int Process::GetWaitingTime() const {
    return waitingTime;
}

int Process::GetTurnaroundTime() const {
    return turnaroundTime;
}

int Process::GetMemoryRequired() const {
    return memoryRequired;
}

int Process::GetPriority() const {
    return priority;
}

std::string Process::GetIoOperations() const {
    return ioOperations;
}

// Setters
void Process::SetPriority(int priority) {
    this->priority = priority;
}

void Process::SetIoOperations(const std::string& ioOperations) {
    this->ioOperations = ioOperations;
}

// Method to update the state of the process
void Process::UpdateState(int statusID) {
    switch (statusID) {
        case READY:
            state = "READY";
            break;
        case RUNNING:
            state = "RUNNING";
            break;
        case WAITING:
            state = "WAITING";
            break;
        case TERMINATED:
            state = "TERMINATED";
            break;
        default:
            throw std::invalid_argument("Invalid status ID");
    }
}

// Method to reduce the remaining execution time when the process is scheduled
void Process::ReduceExecutionTime(int time) {
    if (remainingTime > 0) {
        remainingTime -= time;
        if (remainingTime < 0) {
            remainingTime = 0;
        }
    } else {
        remainingTime = 0;
    }
}

// Method to update waiting time
void Process::UpdateWaitingTime(int timeElapsed) {
    waitingTime += timeElapsed;
}

// Method to update turnaround time
void Process::UpdateTurnaroundTime(int burstTime) {
    turnaroundTime = waitingTime + burstTime;
}

