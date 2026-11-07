#include "CFS.h"
#include <iostream>

CFS::CFS() : schedLatency(48), minGranularity(6), jobId(1), clock(0), tree(BST()) {}

unsigned int CFS::getWeight(int nice)
{
    double weight = std::round(defaultWeight * std::pow(factor, nice));
    return static_cast<unsigned int>(weight);
}

void CFS::addJob(std::unique_ptr<Job> job)
{
    job->setId(jobId++);
    unsigned int jobWeight = getWeight(job->getNice());
    tree.insert(job.get(), jobWeight);
    queue.push(std::move(job));
}

unsigned int CFS::getTimeSlice(Job *job)
{
    unsigned int jobWeight = getWeight(job->getNice());
    unsigned int totalWeight = tree.getTotalWeight();
    double timeSlice = std::round((jobWeight / totalWeight) * schedLatency);
    return std::max(static_cast<unsigned int>(timeSlice), minGranularity);
}

unsigned int CFS::getVRuntime(Job *job)
{
    unsigned int jobWeight = getWeight(job->getNice());
    unsigned int jobRuntime = job->getRuntime();
    unsigned int vRuntime = std::round((defaultWeight / jobWeight) * jobRuntime);
    job->updateVRuntime(static_cast<unsigned int>(vRuntime));
    return static_cast<unsigned int>(vRuntime);
}

Job *CFS::getNextJob()
{
    return tree.min();
}