#include "BST/include/run.h"

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        Runner::run(argc, argv);
    }

    else
    {
        Runner::run();
    }

    return 0;
}