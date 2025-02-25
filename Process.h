//
// Created by Andy De Luna on 2/24/25.
//

#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>

/**
 * @brief Process Class
 * 
 * This class represents a process in an operating system simulator. It manages process
 * attributes and state transitions throughout the process lifecycle.
 * 
 * States:
 * - READY: Process is waiting to be executed
 * - RUNNING: Process is currently being executed
 * - WAITING: Process is waiting for I/O or other resources
 * - TERMINATED: Process has completed execution
 */
class Process {
private:
    /**
     * @brief Process states enumeration
     * Represents the possible states a process can be in during its lifecycle
     */
    enum statusIDs {
        READY,      ///< Process is ready to be executed
        RUNNING,    ///< Process is currently executing
        WAITING,    ///< Process is waiting for resources
        TERMINATED  ///< Process has finished execution
    };

    int pid;                ///< Unique identifier for the process
    int arrivalTime;        ///< Time at which process enters the system
    int burstTime;          ///< Total CPU time required for execution
    std::string state;      ///< Current state of the process
    int remainingTime;      ///< Remaining CPU time needed for completion
    int waitingTime;        ///< Total time spent in ready queue
    int turnaroundTime;     ///< Total time from arrival to completion
    int memoryRequired;     ///< Memory required by the process
    int priority;           ///< Priority level of the process
    std::string ioOperations; ///< List of I/O operations required

    /**
     * @brief Private constructor for Process class
     * @param pid Process ID
     * @param arrivalTime Time when process enters system
     * @param burstTime Total CPU time required
     * @param memoryRequired Memory needed by process
     * @param priority Process priority level
     * @param ioOperations I/O operations needed
     */
    Process(int pid, int arrivalTime, int burstTime, int memoryRequired, 
            int priority, const std::string& ioOperations);

public:
    /**
     * @brief Factory method to create a new process
     * @param pid Process ID
     * @param arrivalTime Time when process enters system
     * @param burstTime Total CPU time required
     * @param memoryRequired Memory needed by process
     * @param priority Process priority level (default: 0)
     * @param ioOperations I/O operations needed (default: empty)
     * @return Process New process instance
     */
    static Process CreateProcess(int pid, int arrivalTime, int burstTime, 
                               int memoryRequired, int priority = 0, 
                               const std::string& ioOperations = "");

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

    /**
     * @brief Updates the state of the process based on statusID
     * @param statusID New state to transition to
     * @throws std::invalid_argument if statusID is invalid
     */
    void UpdateState(int statusID);

    /**
     * @brief Reduces the remaining execution time when the process is scheduled
     * @param time Amount of time to reduce
     */
    void ReduceExecutionTime(int time);

    /**
     * @brief Updates the waiting time of the process
     * @param timeElapsed Time spent waiting
     */
    void UpdateWaitingTime(int timeElapsed);

    /**
     * @brief Updates the turnaround time
     * @param burstTime Total CPU time taken
     */
    void UpdateTurnaroundTime(int burstTime);
};

#endif //PROCESS_H
