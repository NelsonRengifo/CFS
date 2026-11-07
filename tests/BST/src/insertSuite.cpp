#include "../include/insertSuite.h"

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
    BST tree;
    unsigned int jobId = 1;

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
    size_t expectedSize = 100;
    size_t numberOfJobs = 100;
    size_t expectedWeight = 1024 * numberOfJobs;

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
    Job testJob('A', 100);
    Job *job = &testJob;
    BST tree = BST();

    // ACT
    tree.insert(job, 1024);
    Node *node = tree.find(job);

    // ASSERT
    return node != nullptr &&
           node->getJob() == job &&
           tree.getRoot()->getJob() == job &&
           tree.getTotalWeight() == 1024 &&
           tree.treeSize() == 1;
}

bool testInsertMultipleNodesVruntimeDescending()
{
    // ARRANGE
    int expectedTreeSize = 5;
    int expectedTotalWeight = expectedTreeSize * 1024;
    unsigned jobId = 1;

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

    auto result = tree.inOrder();

    // ASSERT
    for (std::size_t i = 1; i < result.size(); ++i)
    {
        // std::cout << result[i - 1].first << ": " << result[i - 1].second << "\n";
        // {JobId, Vruntime}
        if (result[i - 1].second > result[i].second)
        {
            return false;
        }
    }

    // std::cout << result[result.size() - 1].first << ": " << result[result.size() - 1].second;

    return tree.getTotalWeight() == expectedTotalWeight && tree.treeSize() == expectedTreeSize;
}

bool testInsertMultipleNodesVruntimeBranching()
{
    // ARRANGE
    BST tree;
    const size_t numberOfJobs = 50;
    unsigned int jobId = 1;
    int expectedTotalWeight = 1024 * numberOfJobs;
    int expectedTreeSize = numberOfJobs;
    std::mt19937_64 engine(1);
    std::uniform_int_distribution<unsigned int> distro(10, 100);

    std::array<char, 26> letters = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
        'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'K',
        'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};

    std::vector<std::vector<Job>> jobs(numberOfJobs);

    for (std::size_t i = 0; i < numberOfJobs; ++i)
    {
        std::size_t index = i % 26;
        char letter = letters[index];
        Job job(letter, 100);

        job.setId(jobId++);
        job.updateVRuntime(distro(engine));

        jobs[i].push_back(job);
    }

    std::vector<Job *> pointers;
    for (std::size_t i = 0; i < numberOfJobs; ++i)
    {
        auto &job = jobs[i][0];
        Job *ptr = &job;
        // std::cout << job.getId() << " ";
        pointers.push_back(ptr);
    }

    // ACT
    for (auto &ptr : pointers)
    {
        tree.insert(ptr, 1024);
    }

    auto result = tree.inOrder();

    // ASSERT
    for (std::size_t i = 1; i < result.size(); ++i)
    {
        // std::cout << "ID " << result[i - 1].first << ": " << result[i - 1].second << " vruntime" << "\n";

        // {JobId, Vruntime}
        if (result[i - 1].second > result[i].second)
        {
            return false;
        }
    }

    // std::cout << "ID " << result[result.size() - 1].first << ": " << result[result.size() - 1].second << " vruntime" << "\n";

    return tree.getTotalWeight() == expectedTotalWeight && tree.treeSize() == expectedTreeSize;
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
    for (std::size_t i = 1; i < result.size(); ++i)
    {
        // std::cout << result[i - 1].first << ": " << result[i - 1].second << "\n";
        // {JobId, Vruntime}
        if (result[i - 1].second > result[i].second)
        {
            return false;
        }
    }

    // std::cout << result[result.size() - 1].first << ": " << result[result.size() - 1].second;

    return tree.getTotalWeight() == expectedTotalWeight && tree.treeSize() == expectedTreeSize;
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

bool testInsertMultipleNodesBranching()
{
    // ARRANGE
    const size_t numberOfJobs = 50;
    unsigned int jobId = 1;
    unsigned int expectedTotalWeight = 1024 * numberOfJobs;
    unsigned int expectedTreeSize = numberOfJobs;

    BST tree;

    std::array<char, 26> letters = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
        'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'K',
        'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};

    std::vector<std::vector<Job>> jobs(numberOfJobs);

    for (std::size_t i = 0; i < numberOfJobs; ++i)
    {
        std::size_t index = i % 26;
        char letter = letters[index];
        Job job(letter, 100);
        job.setId(jobId++);

        jobs[i].push_back(job);
    }

    std::mt19937_64 engine(1);
    std::uniform_int_distribution<int>(0, numberOfJobs - 1);
    std::shuffle(jobs.begin(), jobs.end(), engine);

    std::vector<Job *> pointers;
    for (std::size_t i = 0; i < numberOfJobs; ++i)
    {
        auto &job = jobs[i][0];
        Job *ptr = &job;
        // std::cout << job.getId() << " ";
        pointers.push_back(ptr);
    }

    // ACT
    for (auto &ptr : pointers)
    {
        tree.insert(ptr, 1024);
    }

    auto result = tree.inOrder();

    // ASSERT
    for (std::size_t i = 1; i < result.size(); ++i)
    {
        // std::cout << result[i - 1].first << " ";

        // {JobId, Vruntime}
        if (result[i - 1].first > result[i].first)
        {
            return false;
        }
    }

    // std::cout << result[result.size() - 1].first << ": " << result[result.size() - 1].second;

    return tree.getTotalWeight() == expectedTotalWeight && tree.treeSize() == expectedTreeSize;
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