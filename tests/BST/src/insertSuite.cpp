#include "../include/insertSuite.h"

bool testRightLeftRotation()
{
    // ARRANGE
    unsigned int expectedSize = 6;
    unsigned int expectedWeight = expectedSize * 1024;
    unsigned int jobId = 1;

    BST tree;

    // 10, 5, 30, 7, 35, 32

    Job A('A', 100);
    A.setId(jobId++);
    A.updateVRuntime(10);

    Job B('B', 100);
    B.setId(jobId++);
    B.updateVRuntime(5);

    Job C('C', 100);
    C.setId(jobId++);
    C.updateVRuntime(30);

    Job D('D', 100);
    D.setId(jobId++);
    D.updateVRuntime(7);

    Job E('E', 100);
    E.setId(jobId++);
    E.updateVRuntime(35);

    Job F('F', 100);
    F.setId(jobId++);
    F.updateVRuntime(32);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);
    tree.insert(&E, 1024);
    tree.insert(&F, 1024);

    Node *root = tree.getRoot();

    // ASSERT
    return root->getJob() == &A &&
           root->getLeft()->getJob() == &B &&
           root->getRight()->getJob() == &F &&
           root->getRight()->getLeft()->getJob() == &C &&
           root->getRight()->getRight()->getJob() == &E &&
           root->getLeft()->getRight()->getJob() == &D &&
           tree.treeSize() == expectedSize &&
           tree.getTotalWeight() == expectedWeight &&
           isValidTree(tree.inOrder());
}

bool testRootRightLeftRotation()
{
    // ARRANGE
    unsigned int expectedSize = 3;
    unsigned int expectedWeight = expectedSize * 1024;
    unsigned int jobId = 1;

    BST tree;

    // 10, 30, 20

    Job A('A', 100);
    A.setId(jobId++);
    A.updateVRuntime(10);

    Job B('B', 100);
    B.setId(jobId++);
    B.updateVRuntime(30);

    Job C('C', 100);
    C.setId(jobId++);
    C.updateVRuntime(20);

    // ACT

    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);

    Node *root = tree.getRoot();

    // ASSERT
    return root->getJob() == &C &&
           root->getLeft()->getJob() == &A &&
           root->getRight()->getJob() == &B &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize &&
           isValidTree(tree.inOrder());
}

bool testLeftRightRotation()
{
    // ARRANGE
    unsigned int jobId = 1;
    unsigned int expectedSize = 9;
    unsigned int expectedWeight = expectedSize * 1024;

    BST tree;

    // 50, 30, 70, 20, 40, 60, 80, 35, 38

    Job A('A', 100);
    A.setId(jobId++);
    A.updateVRuntime(50);

    Job B('B', 100);
    B.setId(jobId++);
    B.updateVRuntime(30);

    Job C('C', 100);
    C.setId(jobId++);
    C.updateVRuntime(70);

    Job D('D', 100);
    D.setId(jobId++);
    D.updateVRuntime(20);

    Job E('E', 100);
    E.setId(jobId++);
    E.updateVRuntime(40);

    Job F('F', 100);
    F.setId(jobId++);
    F.updateVRuntime(60);

    Job G('G', 100);
    G.setId(jobId++);
    G.updateVRuntime(80);

    Job H('H', 100);
    H.setId(jobId++);
    H.updateVRuntime(35);

    Job I('I', 100);
    I.setId(jobId++);
    I.updateVRuntime(38);

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

    Node *root = tree.getRoot();

    // ASSERT
    return root->getJob() == &A &&
           root->getLeft()->getJob() == &B &&
           root->getRight()->getJob() == &C &&
           root->getLeft()->getLeft()->getJob() == &D &&
           root->getLeft()->getRight()->getJob() == &I &&
           root->getLeft()->getRight()->getLeft()->getJob() == &H &&
           root->getLeft()->getRight()->getRight()->getJob() == &E &&
           root->getRight()->getLeft()->getJob() == &F &&
           root->getRight()->getRight()->getJob() == &G &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize &&
           isValidTree(tree.inOrder());
}

bool testRootLeftRightRotation()
{
    // ARRANGE
    unsigned int jobId = 1;
    unsigned int expectedSize = 3;
    unsigned int expectedWeight = expectedSize * 1024;

    BST tree;

    Job A('A', 100);
    A.setId(jobId++);
    A.updateVRuntime(30);

    Job B('B', 100);
    B.setId(jobId++);
    B.updateVRuntime(20);

    Job C('C', 100);
    C.setId(jobId++);
    C.updateVRuntime(25);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);

    Node *root = tree.getRoot();

    // ASSERT
    return root->getJob() == &C &&
           root->getLeft()->getJob() == &B &&
           root->getRight()->getJob() == &A &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize &&
           isValidTree(tree.inOrder());
}

bool testRightRightRotation()
{
    // ARRANGE
    unsigned int expectedSize = 5;
    unsigned int expectedWeight = expectedSize * 1024;
    unsigned int jobId = 1;
    BST tree;

    Job A('A', 100);
    A.setId(jobId++);
    A.updateVRuntime(10);

    Job B('B', 100);
    B.setId(jobId++);
    B.updateVRuntime(20);

    Job C('C', 100);
    C.setId(jobId++);
    C.updateVRuntime(5);

    Job D('D', 100);
    D.setId(jobId++);
    D.updateVRuntime(30);

    Job E('E', 100);
    E.setId(jobId++);
    E.updateVRuntime(40);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);
    tree.insert(&E, 1024);

    Node *root = tree.getRoot();

    // 40 triggers the rotation

    // ASSERT
    return isValidTree(tree.inOrder()) &&
           root->getJob() == &A &&
           root->getRight()->getJob() == &D &&
           root->getLeft()->getJob() == &C &&
           root->getRight()->getLeft()->getJob() == &B &&
           root->getRight()->getRight()->getJob() == &E &&
           tree.treeSize() == expectedSize &&
           tree.getTotalWeight() == expectedWeight;
}

bool testRootRightRightRotation()
{
    // ARRANGE
    unsigned int expectedSize = 3;
    unsigned int expectedWeight = expectedSize * 1024;
    unsigned int jobId = 1;
    BST tree;

    Job A('A', 100);
    A.setId(jobId++);
    A.updateVRuntime(10);

    Job B('B', 100);
    B.setId(jobId++);
    B.updateVRuntime(20);

    Job C('C', 100);
    C.setId(jobId++);
    C.updateVRuntime(30);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);

    Node *root = tree.getRoot();

    // ASSERT
    return isValidTree(tree.inOrder()) &&
           root->getJob() == &B &&
           root->getLeft()->getJob() == &A &&
           root->getRight()->getJob() == &C &&
           tree.treeSize() == expectedSize &&
           tree.getTotalWeight() == expectedWeight;
}

bool testLeftLeftRotation()
{
    // ARRANGE
    unsigned int expectedSize = 5;
    unsigned int expectedWeight = expectedSize * 1024;
    unsigned int jobId = 1;
    BST tree;

    Job A('A', 100);
    A.setId(jobId++);
    A.updateVRuntime(30);

    Job B('B', 100);
    B.setId(jobId++);
    B.updateVRuntime(10);

    Job C('C', 100);
    C.setId(jobId++);
    C.updateVRuntime(40);

    Job D('D', 100);
    D.setId(jobId++);
    D.updateVRuntime(8);

    Job E('E', 100);
    E.setId(jobId++);
    E.updateVRuntime(7);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);
    tree.insert(&E, 1024);

    // 30, 10, 40, 8, 7 (7 triggers a rotation)
    Node *root = tree.getRoot();

    // ASSERT
    return root->getJob() == &A &&
           root->getLeft()->getJob() == &D &&
           root->getRight()->getJob() == &C &&
           root->getLeft()->getRight()->getJob() == &B &&
           root->getLeft()->getLeft()->getJob() == &E &&
           isValidTree(tree.inOrder());
}

bool testRootLeftLeftRotation()
{
    // ARRANGE
    unsigned int expectedSize = 3;
    unsigned int expectedWeight = expectedSize * 1024;
    unsigned int jobId = 1;

    BST tree;

    Job A('A', 100);
    A.setId(jobId++);
    A.updateVRuntime(30);

    Job B('B', 100);
    B.setId(jobId++);
    B.updateVRuntime(20);

    Job C('C', 100);
    C.setId(jobId++);
    C.updateVRuntime(10);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);

    Node *root = tree.getRoot();

    // ASSERT
    return isValidTree(tree.inOrder()) &&
           root->getJob() == &B &&
           root->getLeft()->getJob() == &C &&
           root->getRight()->getJob() == &A &&
           tree.treeSize() == expectedSize &&
           tree.getTotalWeight() == expectedWeight;
}

bool testNodeParentPointerTraversal()
{
    // ARRANGE
    unsigned int expectedSize = 3;
    unsigned int expectedWeight = expectedSize * 1024;
    unsigned int jobId = 1;

    BST tree;

    Job A('A', 100);
    A.setId(jobId++);
    A.updateVRuntime(30);

    Job B('B', 100);
    B.setId(jobId++);
    B.updateVRuntime(20);

    Job C('C', 100);
    C.setId(jobId++);
    C.updateVRuntime(10);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);

    Node *root = tree.getRoot();

    // Get C's node
    Node *c = root->getLeft();

    // Get A's node
    Node *a = root->getRight();

    // ASSERT
    return c->getParent()->getJob() == &B &&
           a->getParent()->getJob() == &B &&
           isValidTree(tree.inOrder()) &&
           root->getJob() == &B &&
           root->getParent() == nullptr &&
           root->getLeft()->getJob() == &C &&
           root->getRight()->getJob() == &A &&
           tree.treeSize() == expectedSize &&
           tree.getTotalWeight() == expectedWeight;
}

bool testInsertAllNodesWithIdenticalVruntimes()
{
    // ARRANGE
    unsigned int expectedSize = 100;
    unsigned int numberOfJobs = 100;
    unsigned int expectedWeight = 1024 * numberOfJobs;

    BST tree;
    auto jobs = generate(numberOfJobs, false);

    // ACT
    for (auto &job : jobs)
    {
        tree.insert(&job, 1024);
    }

    // ASSERT
    return isValidTree(tree.inOrder()) &&
           tree.getTotalWeight() == expectedWeight &&
           tree.treeSize() == expectedSize;
}

bool testInsertingSingleNode()
{
    // ARRANGE
    Job A('A', 100);
    BST tree;

    // ACT
    tree.insert(&A, 1024);
    Node *node = tree.find(&A);

    // ASSERT
    return node != nullptr &&
           node->getJob() == &A &&
           tree.getRoot()->getJob() == &A &&
           tree.getTotalWeight() == 1024 &&
           tree.treeSize() == 1;
}

bool testInsertMultipleNodesVruntimeDescending()
{
    // ARRANGE
    unsigned int expectedTreeSize = 5;
    unsigned int expectedTotalWeight = expectedTreeSize * 1024;
    unsigned int jobId = 1;

    BST tree;

    Job A('A', 100);
    A.setId(jobId++);
    A.updateVRuntime(55);

    Job B('B', 100);
    B.setId(jobId++);
    B.updateVRuntime(45);

    Job C('C', 100);
    C.setId(jobId++);
    C.updateVRuntime(35);

    Job D('D', 100);
    D.setId(jobId++);
    D.updateVRuntime(25);

    Job E('E', 100);
    E.setId(jobId++);
    E.updateVRuntime(15);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);
    tree.insert(&E, 1024);

    // ASSERT
    return tree.getTotalWeight() == expectedTotalWeight &&
           tree.treeSize() == expectedTreeSize &&
           isValidTree(tree.inOrder());
}

bool testInsertMultipleNodesVruntimeBranching()
{
    // ARRANGE
    unsigned int numberOfJobs = 50;
    unsigned int expectedTotalWeight = 1024 * numberOfJobs;
    unsigned int expectedTreeSize = numberOfJobs;

    BST tree;

    auto jobs = generate(numberOfJobs);

    // ACT
    for (auto &job : jobs)
    {
        tree.insert(&job, 1024);
    }

    // ASSERT
    return tree.getTotalWeight() == expectedTotalWeight &&
           tree.treeSize() == expectedTreeSize &&
           isValidTree(tree.inOrder());
}

bool testInsertMultipleNodesVruntimeAscending()
{
    // ARRANGE
    int expectedTreeSize = 5;
    int expectedTotalWeight = expectedTreeSize * 1024;
    unsigned int jobId = 1;

    BST tree;

    Job A('A', 100);
    A.setId(jobId++);
    A.updateVRuntime(15);

    Job B('B', 100);
    B.setId(jobId++);
    B.updateVRuntime(25);

    Job C('C', 100);
    C.setId(jobId++);
    C.updateVRuntime(35);

    Job D('D', 100);
    D.setId(jobId++);
    D.updateVRuntime(45);

    Job E('E', 100);
    E.setId(jobId++);
    E.updateVRuntime(55);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);
    tree.insert(&E, 1024);

    auto result = tree.inOrder();

    // ASSERT

    return tree.getTotalWeight() == expectedTotalWeight &&
           tree.treeSize() == expectedTreeSize &&
           isValidTree(tree.inOrder());
}

bool testInsertMultipleNodesDescending()
{
    // ARRANGE
    int expectedTreeSize = 5;
    int expectedTotalWeight = expectedTreeSize * 1024;
    unsigned jobId = 1;

    BST tree;

    Job A('A', 100);
    A.setId(jobId++);

    Job B('B', 100);
    B.setId(jobId++);

    Job C('C', 100);
    C.setId(jobId++);

    Job D('D', 100);
    D.setId(jobId++);

    Job E('E', 100);
    E.setId(jobId++);

    // ACT
    tree.insert(&E, 1024);
    tree.insert(&D, 1024);
    tree.insert(&C, 1024);
    tree.insert(&B, 1024);
    tree.insert(&A, 1024);

    auto result = tree.inOrder();

    // ASSERT

    return tree.getTotalWeight() == expectedTotalWeight &&
           tree.treeSize() == expectedTreeSize &&
           isValidTree(tree.inOrder());
}

bool testInsertMultipleNodesBranching()
{
    // ARRANGE
    const size_t numberOfJobs = 100;
    unsigned int expectedTotalWeight = 1024 * numberOfJobs;
    unsigned int expectedTreeSize = numberOfJobs;

    BST tree;

    auto jobs = generate(numberOfJobs);

    // ACT
    for (auto &job : jobs)
    {
        tree.insert(&job, 1024);
    }

    // ASSERT
    return tree.getTotalWeight() == expectedTotalWeight &&
           tree.treeSize() == expectedTreeSize &&
           isValidTree(tree.inOrder());
}

bool testInsertMultipleNodesAscending()
{
    // ARRANGE
    int expectedTreeSize = 5;
    int expectedTotalWeight = expectedTreeSize * 1024;
    unsigned int jobId = 1;

    BST tree;

    Job A('A', 100);
    A.setId(jobId++);

    Job B('B', 100);
    B.setId(jobId++);

    Job C('C', 100);
    C.setId(jobId++);

    Job D('D', 100);
    D.setId(jobId++);

    Job E('E', 100);
    E.setId(jobId++);

    // ACT
    tree.insert(&A, 1024);
    tree.insert(&B, 1024);
    tree.insert(&C, 1024);
    tree.insert(&D, 1024);
    tree.insert(&E, 1024);

    auto result = tree.inOrder();

    // ASSERT
    for (std::size_t i = 1; i < result.size(); ++i)
    {
        // {JobId, Vruntime}
        if (result[i - 1].first > result[i].first)
        {
            return false;
        }
    }

    return tree.getTotalWeight() == expectedTotalWeight && tree.treeSize() == expectedTreeSize;
}