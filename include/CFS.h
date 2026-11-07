#pragma once
#include <queue>
#include <memory>
#include <array>
#include <cmath>
#include "job.h"
#include "BST.h"

/*
    Be careful when deleting job objects. Tree and Node would end up with dangling pointers.
*/

class CFS
{
private:
    std::queue<std::unique_ptr<Job>> queue;
    BST tree;
    const unsigned int defaultWeight = 1024;
    const float factor = 1.25;
    unsigned int jobId;
    unsigned int schedLatency;
    unsigned int minGranularity;
    unsigned int clock;
    unsigned int timeSlice;
    unsigned int getWeight(int nice);
    unsigned int getTimeSlice(Job *job);
    unsigned int getVRuntime(Job *job);
    Job *getNextJob();

public:
    CFS();
    void addJob(std::unique_ptr<Job> job);
};