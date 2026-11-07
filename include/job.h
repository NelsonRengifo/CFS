#pragma once

/*
    The scheduler sets the job id.
    Remember to update vruntime and runtime as the job runs.
    REFACTOR enum to enum class.
*/

enum Status
{
    DONE = 0,
    RUNNING = 1,
    READY = 2,
    BLOCKED = 3
};

class Job
{
private:
    unsigned int id;
    Status status;
    char name;
    unsigned int jobLength;
    unsigned int vruntime;
    unsigned int runTime;
    int nice;

public:
    Job(char name, unsigned int jobLength, int niceness = 0);
    void setId(unsigned int id);
    unsigned int getId();
    void setStatus(Status status);
    Status getStatus();
    char getName();
    unsigned int getJobLength();
    void updateVRuntime(unsigned int time);
    unsigned int getvruntime();
    int getNice();
    unsigned int getRuntime();
    void updateRuntime(unsigned int time);
};