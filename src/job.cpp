#include "job.h"

Job::Job(char name, unsigned int jobLength, int nice) : name(name), jobLength(jobLength), id(0), status(Status::READY), vruntime(0), runTime(0)
{
    this->nice = nice;
}

void Job::setId(unsigned int id)
{
    this->id = id;
}

unsigned int Job::getId()
{
    return id;
}

void Job::setStatus(Status status)
{
    this->status = status;
}

Status Job::getStatus()
{
    return status;
}

char Job::getName()
{
    return name;
}

unsigned int Job::getJobLength()
{
    return jobLength;
}

void Job::updateVRuntime(unsigned int time)
{
    this->vruntime += time;
}

unsigned int Job::getvruntime()
{
    return vruntime;
}

int Job::getNice()
{
    return nice;
}

unsigned int Job::getRuntime()
{
    return runTime;
}

void Job::updateRuntime(unsigned int time)
{
    this->runTime += time;
}