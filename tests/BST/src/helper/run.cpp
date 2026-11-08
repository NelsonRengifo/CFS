#include "../../include/run.h"

/*
    Refactor the run logic... you can do better
*/

// Add new tests here
std::unordered_map<std::string, Test> Runner::tests = {
    {"testInsertAllNodesWithIdenticalVruntimes", {"testInsertAllNodesWithIdenticalVruntimes", testInsertAllNodesWithIdenticalVruntimes}},
    {"testRightLeftRotation", {"testRightLeftRotation", testRightLeftRotation}},
    {"testRootRightLeftRotation", {"testRootRightLeftRotation", testRootRightLeftRotation}},
    {"testLeftRightRotation", {"testLeftRightRotation", testLeftRightRotation}},
    {"testRootLeftRightRotation", {"testRootLeftRightRotation", testRootLeftRightRotation}},
    {"testRightRightRotation", {"testRightRightRotation", testRightRightRotation}},
    {"testRootRightRightRotation", {"testRootRightRightRotation", testRootRightRightRotation}},
    {"testRootLeftLeftRotation", {"testRootLeftLeftRotation", testRootLeftLeftRotation}},
    {"testNodeParentPointerTraversal", {"testNodeParentPointerTraversal", testNodeParentPointerTraversal}},
    {"testLeftLeftRotation", {"testLeftLeftRotation", testLeftLeftRotation}},
    {"testInsertingSingleNode", {"testInsertingSingleNode", testInsertingSingleNode}},
    {"testInsertMultipleNodesAscending", {"testInsertMultipleNodesAscending", testInsertMultipleNodesAscending}},
    {"testInsertMultipleNodesDescending", {"testInsertMultipleNodesDescending", testInsertMultipleNodesDescending}},
    {"testInsertMultipleNodesBranching", {"testInsertMultipleNodesBranching", testInsertMultipleNodesBranching}},
    {"testInsertMultipleNodesVruntimeAscending", {"testInsertMultipleNodesVruntimeAscending", testInsertMultipleNodesVruntimeAscending}},
    {"testInsertMultipleNodesVruntimeDescending", {"testInsertMultipleNodesVruntimeDescending", testInsertMultipleNodesVruntimeDescending}},
    {"testInsertMultipleNodesVruntimeBranching", {"testInsertMultipleNodesVruntimeBranching", testInsertMultipleNodesVruntimeBranching}},
    {"testRemoveEmptyTree", {"testRemoveEmptyTree", testRemoveEmptyTree}},
    {"testRemoveRootNode", {"testRemoveRootNode", testRemoveRootNode}},
    {"testRemoveRootNodeWithChildren", {"testRemoveRootNodeWithChildren", testRemoveRootNodeWithChildren}},
    {"testRemoveRootNodeWithRightChild", {"testRemoveRootNodeWithRightChild", testRemoveRootNodeWithRightChild}},
    {"testRemoveRootNodeWithLeftChild", {"testRemoveRootNodeWithLeftChild", testRemoveRootNodeWithLeftChild}},
    {"testRemoveRootNodeWithSuccessorNoChild", {"testRemoveRootNodeWithSuccessorNoChild", testRemoveRootNodeWithSuccessorNoChild}},
    {"testRemoveRootNodeWithSuccessorImmediateRight", {"testRemoveRootNodeWithSuccessorImmediateRight", testRemoveRootNodeWithSuccessorImmediateRight}},
    {"testRemoveRootNodeWithSuccessorHasRightChild", {"testRemoveRootNodeWithSuccessorHasRightChild", testRemoveRootNodeWithSuccessorHasRightChild}},
    {"testRemoveNodeWithNoChildrenRight", {"testRemoveNodeWithNoChildrenRight", testRemoveNodeWithNoChildrenRight}},
    {"testRemoveNodeWithNoChildrenLeft", {"testRemoveNodeWithNoChildrenLeft", testRemoveNodeWithNoChildrenLeft}},
    {"testRemoveNodeWithLeftChild", {"testRemoveNodeWithLeftChild", testRemoveNodeWithLeftChild}},
    {"testRemoveNodeWithRightChild", {"testRemoveNodeWithRightChild", testRemoveNodeWithRightChild}},
    {"testRemoveNodeWithTwoChildren", {"testRemoveNodeWithTwoChildren", testRemoveNodeWithTwoChildren}},
    {"testRemoveDeepNodeNoChildren", {"testRemoveDeepNodeNoChildren", testRemoveDeepNodeNoChildren}},
    {"testRemoveDeepNodeTwoChildren", {"testRemoveDeepNodeTwoChildren", testRemoveDeepNodeTwoChildren}},
    {"testSequentialDeletionUntilEmpty", {"testSequentialDeletionUntilEmpty", testSequentialDeletionUntilEmpty}},
    {"testRemoveNoneExistingNode", {"testRemoveNoneExistingNode", testRemoveNoneExistingNode}},
    {"testRemoveSameNodeTwice", {"testRemoveSameNodeTwice", testRemoveSameNodeTwice}},
    {"testRemoveNodesWithIdenticalVRuntime", {"testRemoveNodesWithIdenticalVRuntime", testRemoveNodesWithIdenticalVRuntime}},
    {"testDeleteRootThenDeleteSuccessor", {"testDeleteRootThenDeleteSuccessor", testDeleteRootThenDeleteSuccessor}},
    {"testDeleteNodesInRandomOrder", {"testDeleteNodesInRandomOrder", testDeleteNodesInRandomOrder}},
    {"testDeleteAllNodesInReverseInsertionOrder", {"testDeleteAllNodesInReverseInsertionOrder", testDeleteAllNodesInReverseInsertionOrder}}};

void Runner::run()
{
    for (auto &[key, test] : Runner::tests)
    {
        if (test.function())
        {
            Runner::passed++;
            test.passed = true;
            test.ran = true;
        }

        else
        {
            Runner::failed++;
        }
    }

    Runner::statistics();
};

void Runner::run(int argc, char *argv[])
{
    for (size_t i = 1; i < argc; ++i)
    {
        std::string argument = argv[i];

        if (Runner::tests.contains(argument))
        {
            Test &test = tests[argument];

            if (test.function())
            {
                Runner::passed++;
                test.passed = true;
            }

            else
            {
                Runner::failed++;
            }

            test.ran = true;
        }
    }

    Runner::statistics();
}

void Runner::statistics()
{
    for (auto &[key, test] : Runner::tests)
    {
        if (test.ran)
        {
            if (test.passed)
            {
                std::cout << "[PASSED] " << test.name << "\n";
            }

            else
            {
                std::cout << "[FAILED] " << test.name << "\n";
            }
        }
    }

    unsigned int total = Runner::passed + Runner::failed;

    std::cout << "\nPassed: " << Runner::passed << "\n"
              << "Failed: " << Runner::failed << "\n"
              << "Total: " << total << "\n";
}