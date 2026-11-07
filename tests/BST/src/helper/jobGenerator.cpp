#include "../../include/jobGenerator.h"

std::vector<Job> generate(size_t numberOfJobs, bool randomVruntimes)
{
    std::vector<Job> jobs;
    unsigned int jobId = 1;
    std::mt19937_64 engine(1);

    std::uniform_int_distribution<size_t> randomNumber(0, numberOfJobs - 1);

    unsigned int vruntime = 0;

    for (size_t i = 0; i < numberOfJobs; ++i)
    {
        Job job('X', 100);

        if (randomVruntimes)
        {
            vruntime = randomNumber(engine);
        }

        job.updateVRuntime(vruntime);
        job.setId(jobId++);
        jobs.push_back(job);
    }

    std::shuffle(jobs.begin(), jobs.end(), engine);
    return jobs;
}