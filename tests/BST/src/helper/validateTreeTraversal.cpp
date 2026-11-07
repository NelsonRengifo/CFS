#include "../../include/validateTreeTraversal.h"

bool isValidTree(std::vector<std::pair<unsigned int, unsigned int>> nodes)
{
    for (size_t i = 1; i < nodes.size(); ++i)
    {
        if (nodes[i - 1].second != nodes[i].second)
        {
            if (nodes[i - 1].second > nodes[i].second)
            {
                return false;
            }
        }
    }

    return true;
}