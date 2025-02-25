#include <iostream>
#include <unistd.h>
#include "auth.h"
#include "Process.h"

using namespace std;

int main() {
    cout << "OS is booting up..." << endl;
    sleep(1);
    cout << "..." << endl;
    sleep(1);
    cout << "..." << endl;

    authenticateUser();

    // Process creation
    cout << "\nProcess Creation Tests:" << endl;
    Process proc1 = Process::CreateProcess(1, 0, 10, 100, 3, "Disk, Network");
    cout << "Test 1:" << endl;
    cout << "PID: " << proc1.GetPID() << ", Arrival Time: " << proc1.GetArrivalTime()
              << ", Burst Time: " << proc1.GetBurstTime() << ", Memory Required: " << proc1.GetMemoryRequired()
              << ", Priority: " << proc1.GetPriority() << ", IO Operations: " << proc1.GetIoOperations() << endl;

    Process proc2 = Process::CreateProcess(2, 1, 8, 200);
    cout << "\nTest 2:" << endl;
    cout << "PID: " << proc2.GetPID() << ", Arrival Time: " << proc2.GetArrivalTime()
              << ", Burst Time: " << proc2.GetBurstTime() << ", Memory Required: " << proc2.GetMemoryRequired()
              << ", Priority: " << proc2.GetPriority() << ", IO Operations: " << proc2.GetIoOperations() << endl;

    Process proc3 = Process::CreateProcess(3, 2, 5, 50, 5);
    cout << "\nTest 3:" << endl;
    cout << "PID: " << proc3.GetPID() << ", Arrival Time: " << proc3.GetArrivalTime()
              << ", Burst Time: " << proc3.GetBurstTime() << ", Memory Required: " << proc3.GetMemoryRequired()
              << ", Priority: " << proc3.GetPriority() << ", IO Operations: " << proc3.GetIoOperations() << endl;

    Process proc4 = Process::CreateProcess(4, 3, 12, 150, 0, "Disk, Network, Keyboard");
    cout << "\nTest 4:" << endl;
    cout << "PID: " << proc4.GetPID() << ", Arrival Time: " << proc4.GetArrivalTime()
              << ", Burst Time: " << proc4.GetBurstTime() << ", Memory Required: " << proc4.GetMemoryRequired()
              << ", Priority: " << proc4.GetPriority() << ", IO Operations: " << proc4.GetIoOperations() << endl;

    Process proc5 = Process::CreateProcess(5, 4, 6, 75);
    cout << "\nTest 5:" << endl;
    cout << "PID: " << proc5.GetPID() << ", Arrival Time: " << proc5.GetArrivalTime()
              << ", Burst Time: " << proc5.GetBurstTime() << ", Memory Required: " << proc5.GetMemoryRequired()
              << ", Priority: " << proc5.GetPriority() << ", IO Operations: " << proc5.GetIoOperations() << endl;

    return 0;
}
