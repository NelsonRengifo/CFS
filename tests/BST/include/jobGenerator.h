#pragma once

#include "job.h"
#include <vector>
#include <algorithm>
#include <random>
#include <array>

std::vector<Job> generate(size_t numberOfJobs, bool randomVruntimes = true);