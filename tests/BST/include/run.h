#pragma once

#include "removeSuite.h"
#include "insertSuite.h"
#include <unordered_map>

struct Test
{
    std::string name;
    bool (*function)();
    bool passed = false;
    bool ran = false;
};

class Runner
{
private:
    static std::unordered_map<std::string, Test> tests;
    static void statistics();
    inline static unsigned int passed = 0;
    inline static unsigned int failed = 0;

public:
    static void run(int argc, char *argv[]);
    static void run();
};
