#ifndef VIRTUAL_MEMORY_H
#define VIRTUAL_MEMORY_H

#include <vector>
#include <queue>


struct PageTableEntry {
    bool valid;
    int frameNumber;
    bool dirty;

    PageTableEntry() : valid(false), frameNumber(-1), dirty(false) {}
};

class VirtualMemory {
public:
    static const int PAGE_SIZE = 4096; // 4KB
    static const int VIRTUAL_MEMORY_SIZE = 64 * 1024; // 64KB
    static const int PHYSICAL_MEMORY_SIZE = 16 * 1024; // 16KB
    static const int NUM_PAGES = VIRTUAL_MEMORY_SIZE / PAGE_SIZE;
    static const int NUM_FRAMES = PHYSICAL_MEMORY_SIZE / PAGE_SIZE;

    static int allocateFrame();

    static std::vector<bool> frameUsage;
    static int nextFreeFrame;

    // FIFO
    static std::queue<int> loadedPages;
    static void freeFrame(int frameNumber);
    static void replacePage(int& frameNumber);
};

#endif