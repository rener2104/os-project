#include "VirtualMemory.h"
#include <stdexcept>
#include <iostream>

std::vector<bool> VirtualMemory::frameUsage(VirtualMemory::NUM_FRAMES, false);
int VirtualMemory::nextFreeFrame = 0;
std::queue<int> VirtualMemory::loadedPages;

int VirtualMemory::allocateFrame() {
    for (int i = 0; i < NUM_FRAMES; ++i) {
        if (!frameUsage[i]) {
            frameUsage[i] = true;
            loadedPages.push(i);
            return i;
        }
    }

    // FIFO
    int victim = loadedPages.front();
    loadedPages.pop();
    std::cout << "[Replacement] Evicting frame " << victim << std::endl;
    loadedPages.push(victim);
    return victim;
}

void VirtualMemory::freeFrame(int frameNumber) {
    if (frameNumber >= 0 && frameNumber < NUM_FRAMES) {
        frameUsage[frameNumber] = false;
    }
}