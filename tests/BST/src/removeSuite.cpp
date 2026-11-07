#include "../include/removeSuite.h"

bool testRemoveEmptyTree()
{
    // ARRANGE
    BST tree;
    Job job('A', 100);

    // ACT
    tree.remove(&job);

    // ASSERT
    return tree.find(&job) == nullptr && tree.treeSize() == 0 && tree.getRoot() == nullptr;
}

bool testRemoveRootNodeWithChildren()
{
    // ARRANGE
    BST tree;
    unsigned int jobId = 1;
    unsigned int expectedWeight = 2048;
    unsigned int expectedSize = 2;

    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);

    tree.remove(&A);

    auto vruntimes = tree.inOrder();
    Node *root = tree.getRoot();

    // ASSERT
    for (size_t i = 1; i < vruntimes.size(); ++i)
    {
        if (vruntimes[i - 1].second > vruntimes[i].second)
        {
            return false;
        }

        // std::cout << vruntimes[i - 1].second << " ";
    }

    // std::cout << vruntimes[vruntimes.size() - 1].second << "\n";

    return root->getJob() == &B &&
           root->getLeft()->getJob() == &C &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testRemoveRootNodeWithRightChild()
{
    // ARRANGE
    BST tree;
    unsigned int jobId = 1;
    unsigned int expectedWeight = 1024;
    unsigned int expectedSize = 1;

    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);

    tree.remove(&A);

    Node *root = tree.getRoot();

    // ASSERT
    return root->getJob() == &B &&
           root->getLeft() == nullptr &&
           root->getRight() == nullptr &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testRemoveRootNodeWithLeftChild()
{
    // ARRANGE
    BST tree;
    unsigned int jobId = 1;
    unsigned int expectedWeight = 1024;
    unsigned int expectedSize = 1;

    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(5);
    B.setId(jobId++);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);

    tree.remove(&A);

    Node *root = tree.getRoot();

    // ASSERT
    return root->getJob() == &B &&
           root->getLeft() == nullptr &&
           root->getRight() == nullptr &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testRemoveRootNodeWithSuccessorNoChild()
{
    // ARRANGE
    BST tree;
    unsigned int jobId = 1;
    unsigned int expectedWeight = 3072;
    unsigned int expectedSize = 3;

    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    Job D('D', 100);
    D.updateVRuntime(15);
    D.setId(jobId++);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);

    tree.remove(&A);

    Node *root = tree.getRoot();
    auto vruntimes = tree.inOrder();

    // ASSERT
    for (size_t i = 1; i < vruntimes.size(); ++i)
    {
        if (vruntimes[i - 1].second > vruntimes[i].second)
        {
            return false;
        }

        // std::cout << vruntimes[i - 1].second << " ";
    }

    // std::cout << vruntimes[vruntimes.size() - 1].second << "\n";

    return root->getJob() == &D &&
           root->getLeft()->getJob() == &C &&
           root->getRight()->getJob() == &B &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testRemoveRootNodeWithSuccessorImmediateRight()
{
    // ARRANGE
    BST tree;
    unsigned int jobId = 1;
    unsigned int expectedWeight = 3072;
    unsigned int expectedSize = 3;

    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    Job D('D', 100);
    D.updateVRuntime(25);
    D.setId(jobId++);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);

    tree.remove(&A);

    Node *root = tree.getRoot();
    auto vruntimes = tree.inOrder();

    // ASSERT
    for (size_t i = 1; i < vruntimes.size(); ++i)
    {
        if (vruntimes[i - 1].second > vruntimes[i].second)
        {
            return false;
        }

        // std::cout << vruntimes[i - 1].second << " ";
    }

    // std::cout << vruntimes[vruntimes.size() - 1].second << "\n";

    return root->getJob() == &B &&
           root->getLeft()->getJob() == &C &&
           root->getRight()->getJob() == &D &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testRemoveRootNodeWithSuccessorHasRightChild()
{
    // ARRANGE
    BST tree;
    unsigned int jobId = 1;
    unsigned int expectedWeight = 4096;
    unsigned int expectedSize = 4;

    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    Job D('D', 100);
    D.updateVRuntime(15);
    D.setId(jobId++);

    Job E('E', 100);
    E.updateVRuntime(17);
    E.setId(jobId++);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);
    tree.insert(&E, 1024);

    tree.remove(&A);

    Node *root = tree.getRoot();
    auto vruntimes = tree.inOrder();

    // ASSERT
    for (size_t i = 1; i < vruntimes.size(); ++i)
    {
        if (vruntimes[i - 1].second > vruntimes[i].second)
        {
            return false;
        }

        // std::cout << vruntimes[i - 1].second << " ";
    }

    // std::cout << vruntimes[vruntimes.size() - 1].second << "\n";

    return root->getJob() == &D &&
           root->getLeft()->getJob() == &C &&
           root->getRight()->getJob() == &B &&
           root->getRight()->getLeft()->getJob() == &E &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testRemoveRootNode()
{
    // ARRANGE
    BST tree;
    Job job('A', 100);

    // ACT
    tree.insert(&job, 1024);
    tree.remove(&job);

    // ASSERT
    return tree.find(&job) == nullptr && tree.treeSize() == 0 && tree.getRoot() == nullptr;
}

bool testDeleteAllNodesInReverseInsertionOrder()
{
    // ARRANGE
    unsigned int expectedWeight = 0;
    size_t numberOfJobs = 100;
    size_t numberOfDeletions = 100;
    size_t expectedSize = 0;
    size_t lower = 0;
    size_t upper = numberOfDeletions - 1;

    BST tree;

    // ACT
    auto jobs = generate(numberOfJobs);
    for (auto &job : jobs)
    {
        tree.insert(&job, 1024);
    }

    // Use int to avoid infinite loop (size_t cannot be negative!)
    for (int i = jobs.size() - 1; i >= 0; --i)
    {
        tree.remove(&jobs[i]);
    }

    return isValidTree(tree.inOrder()) &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testDeleteNodesInRandomOrder()
{
    // ARRANGE
    size_t numberOfJobs = 100;
    size_t numberOfDeletions = 50;
    size_t expectedSize = 50;
    size_t lower = 0;
    size_t upper = numberOfDeletions - 1;
    unsigned int expectedWeight = 1024 * expectedSize;

    BST tree;

    // ACT
    auto jobs = generate(numberOfJobs);
    for (auto &job : jobs)
    {
        tree.insert(&job, 1024);
    }

    std::vector<size_t> indices;
    for (size_t i = 0; i < numberOfDeletions; ++i)
    {
        indices.push_back(i);
    }

    shuffleContainer(indices, lower, upper);

    for (size_t i = 0; i < indices.size(); ++i)
    {
        tree.remove(&jobs[i]);
    }

    return isValidTree(tree.inOrder()) &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testDeleteRootThenDeleteSuccessor()
{
    // ARRANGE
    size_t expectedSize = 2;
    unsigned int expectedWeight = 2048;
    unsigned int jobId = 1;

    BST tree;

    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    Job D('D', 100);
    D.updateVRuntime(15);
    D.setId(jobId++);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);

    // DEL ROOT THEN SUCCESSOR
    tree.remove(&A);
    tree.remove(&D);

    return isValidTree(tree.inOrder()) &&
           tree.treeSize() == expectedSize &&
           tree.getTotalWeight() == expectedWeight &&
           tree.getRoot()->getJob() == &B &&
           tree.getRoot()->getLeft()->getJob() == &C &&
           tree.getRoot()->getRight() == nullptr;
}

bool testRemoveNodesWithIdenticalVRuntime()
{
    // ARRANGE
    BST tree;
    unsigned int expectedWeight = 4096;
    unsigned expectedSize = 4;
    unsigned int jobId = 1;

    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    Job D('D', 100);
    D.updateVRuntime(7);
    D.setId(jobId++);

    Job E('E', 100);
    E.updateVRuntime(7);
    E.setId(jobId++);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);
    tree.insert(&E, 1024);

    tree.remove(&D);

    // ASSERT
    return isValidTree(tree.inOrder()) &&
           tree.getTotalWeight() == expectedWeight &&
           tree.getRoot()->getJob() == &A &&
           tree.treeSize() == expectedSize &&
           tree.getRoot()->getLeft()->getRight()->getJob() == &E;
}

bool testRemoveSameNodeTwice()
{
    // ARRANGE
    BST tree;
    unsigned int expectedWeight = 2048;
    unsigned expectedSize = 2;
    unsigned int jobId = 1;

    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);

    tree.remove(&C);
    tree.remove(&C);

    // ASSERT
    return isValidTree(tree.inOrder()) &&
           tree.getTotalWeight() == expectedWeight &&
           tree.getRoot()->getJob() == &A &&
           tree.treeSize() == expectedSize;
}

bool testRemoveNoneExistingNode()
{
    // ARRANGE
    BST tree;
    unsigned int expectedWeight = 3072;
    unsigned expectedSize = 3;
    unsigned int jobId = 1;

    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    Job X('X', 100);
    X.updateVRuntime(30);
    X.setId(jobId++);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);

    tree.remove(&X);

    // ASSERT
    return isValidTree(tree.inOrder()) &&
           tree.getTotalWeight() == expectedWeight &&
           tree.getRoot()->getJob() == &A &&
           tree.treeSize() == expectedSize;
}

bool testSequentialDeletionUntilEmpty()
{
    // ARRANGE
    BST tree;
    size_t numberOfJobs = 100;
    unsigned int expectedWeight = 0;
    size_t expectedSize = 0;

    auto jobs = generate(numberOfJobs);

    // ACT
    for (auto job : jobs)
    {
        tree.insert(&job, 1024);
    }

    // ASSERT
    for (auto job : jobs)
    {
        tree.remove(&job);

        if (!isValidTree(tree.inOrder()))
        {
            return false;
        }
    }

    return tree.getRoot() == nullptr && tree.getTotalWeight() == expectedWeight && tree.treeSize() == expectedSize;
}

bool testRemoveNodeWithNoChildrenRight() // ROOT = PARENT
{
    // ARRANGE
    BST tree;
    unsigned int jobId = 1;
    size_t expectedSize = 2;
    unsigned int expectedWeight = 2048;

    // ACT
    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);

    tree.remove(&B);

    Node *root = tree.getRoot();
    auto vruntimes = tree.inOrder();

    // ASSERT
    for (size_t i = 1; i < vruntimes.size(); ++i)
    {
        if (vruntimes[i - 1].second > vruntimes[i].second)
        {
            return false;
        }

        // std::cout << vruntimes[i - 1].second << " ";
    }

    // std::cout << vruntimes[vruntimes.size() - 1].second << "\n";

    return root->getJob() == &A &&
           root->getLeft()->getJob() == &C &&
           root->getRight() == nullptr &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testRemoveNodeWithNoChildrenLeft() // ROOT = PARENT
{
    // ARRANGE
    BST tree;
    unsigned int jobId = 1;
    size_t expectedSize = 2;
    unsigned int expectedWeight = 2048;

    // ACT
    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);

    tree.remove(&C);

    Node *root = tree.getRoot();
    auto vruntimes = tree.inOrder();

    // ASSERT
    for (size_t i = 1; i < vruntimes.size(); ++i)
    {
        if (vruntimes[i - 1].second > vruntimes[i].second)
        {
            return false;
        }

        // std::cout << vruntimes[i - 1].second << " ";
    }

    // std::cout << vruntimes[vruntimes.size() - 1].second << "\n";

    return root->getJob() == &A &&
           root->getLeft() == nullptr &&
           root->getRight()->getJob() == &B &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testRemoveNodeWithLeftChild() // ROOT = PARENT
{
    // ARRANGE
    BST tree;
    unsigned int jobId = 1;
    size_t expectedSize = 3;
    unsigned int expectedWeight = 3072;

    // ACT
    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    Job D('D', 100);
    D.updateVRuntime(15);
    D.setId(jobId++);

    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);

    tree.remove(&B);

    auto vruntimes = tree.inOrder();
    Node *root = tree.getRoot();

    // ASSERT
    for (size_t i = 1; i < vruntimes.size(); ++i)
    {
        if (vruntimes[i - 1].second > vruntimes[i].second)
        {
            return false;
        }

        // std::cout << vruntimes[i - 1].second << " ";
    }

    // std::cout << vruntimes[vruntimes.size() - 1].second << "\n";

    return root->getJob() == &A &&
           root->getLeft()->getJob() == &C &&
           root->getRight()->getJob() == &D &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testRemoveNodeWithRightChild() // ROOT = PARENT
{
    // ARRANGE
    BST tree;
    unsigned int jobId = 1;
    size_t expectedSize = 3;
    unsigned int expectedWeight = 3072;

    // ACT
    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    Job D('D', 100);
    D.updateVRuntime(25);
    D.setId(jobId++);

    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);

    tree.remove(&B);

    auto vruntimes = tree.inOrder();
    Node *root = tree.getRoot();

    // ASSERT
    for (size_t i = 1; i < vruntimes.size(); ++i)
    {
        if (vruntimes[i - 1].second > vruntimes[i].second)
        {
            return false;
        }

        // std::cout << vruntimes[i - 1].second << " ";
    }

    // std::cout << vruntimes[vruntimes.size() - 1].second << "\n";

    return root->getJob() == &A &&
           root->getLeft()->getJob() == &C &&
           root->getRight()->getJob() == &D &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testRemoveNodeWithTwoChildren() // ROOT = PARENT
{
    // ARRANGE
    BST tree;
    unsigned int jobId = 1;
    size_t expectedSize = 4;
    unsigned int expectedWeight = 4096;

    // ACT
    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    Job D('D', 100);
    D.updateVRuntime(15);
    D.setId(jobId++);

    Job E('E', 100);
    E.updateVRuntime(25);
    E.setId(jobId++);

    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);
    tree.insert(&E, 1024);

    tree.remove(&B);

    auto vruntimes = tree.inOrder();
    Node *root = tree.getRoot();

    // ASSERT
    for (size_t i = 1; i < vruntimes.size(); ++i)
    {
        if (vruntimes[i - 1].second > vruntimes[i].second)
        {
            return false;
        }

        // std::cout << vruntimes[i - 1].second << " ";
    }

    // std::cout << vruntimes[vruntimes.size() - 1].second << "\n";

    return root->getJob() == &A &&
           root->getLeft()->getJob() == &C &&
           root->getRight()->getJob() == &E &&
           root->getRight()->getLeft()->getJob() == &D &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testRemoveDeepNodeNoChildren()
{
    // ARRANGE
    BST tree;
    unsigned int jobId = 1;
    size_t expectedSize = 7;
    unsigned int expectedWeight = 7168;

    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    Job D('D', 100);
    D.updateVRuntime(3);
    D.setId(jobId++);

    Job E('E', 100);
    E.updateVRuntime(4);
    E.setId(jobId++);

    Job F('F', 100);
    F.updateVRuntime(6);
    F.setId(jobId++);

    Job G('G', 100);
    G.updateVRuntime(15);
    G.setId(jobId++);

    Job H('H', 100);
    H.updateVRuntime(25);
    H.setId(jobId++);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);
    tree.insert(&E, 1024);
    tree.insert(&F, 1024);
    tree.insert(&G, 1024);
    tree.insert(&H, 1024);

    tree.remove(&E);

    Node *root = tree.getRoot();
    auto vruntimes = tree.inOrder();

    // ASSERT
    for (size_t i = 1; i < vruntimes.size(); ++i)
    {
        if (vruntimes[i - 1].second > vruntimes[i].second)
        {
            return false;
        }

        // std::cout << vruntimes[i - 1].second << " ";
    }

    // std::cout << vruntimes[vruntimes.size() - 1].second << "\n";

    return root->getJob() == &A &&
           root->getLeft()->getLeft()->getRight() == nullptr &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testRemoveDeepNodeTwoChildren()
{
    // ARRANGE
    BST tree;
    unsigned int jobId = 1;
    size_t expectedSize = 8;
    unsigned int expectedWeight = 8192;

    Job A('A', 100);
    A.updateVRuntime(10);
    A.setId(jobId++);

    Job B('B', 100);
    B.updateVRuntime(20);
    B.setId(jobId++);

    Job C('C', 100);
    C.updateVRuntime(5);
    C.setId(jobId++);

    Job D('D', 100);
    D.updateVRuntime(3);
    D.setId(jobId++);

    Job E('E', 100);
    E.updateVRuntime(4);
    E.setId(jobId++);

    Job F('F', 100);
    F.updateVRuntime(6);
    F.setId(jobId++);

    Job G('G', 100);
    G.updateVRuntime(15);
    G.setId(jobId++);

    Job H('H', 100);
    H.updateVRuntime(25);
    H.setId(jobId++);

    Job I('I', 100);
    I.updateVRuntime(2);
    I.setId(jobId++);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);
    tree.insert(&E, 1024);
    tree.insert(&F, 1024);
    tree.insert(&G, 1024);
    tree.insert(&H, 1024);
    tree.insert(&I, 1024);

    tree.remove(&D);

    Node *root = tree.getRoot();
    auto vruntimes = tree.inOrder();

    // ASSERT
    for (size_t i = 1; i < vruntimes.size(); ++i)
    {
        if (vruntimes[i - 1].second > vruntimes[i].second)
        {
            return false;
        }

        // std::cout << vruntimes[i - 1].second << " ";
    }

    // std::cout << vruntimes[vruntimes.size() - 1].second << "\n";

    return root->getJob() == &A &&
           root->getLeft()->getLeft()->getJob() == &E &&
           root->getLeft()->getLeft()->getLeft()->getJob() == &I &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}