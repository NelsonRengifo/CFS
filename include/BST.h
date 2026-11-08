#pragma once

#include "job.h"
#include <vector>
#include <memory>

// CFS determines the weight; the tree accounts for the weights of the runnable set.

class Node
{
private:
    Job *job;
    unsigned int vruntime;
    unsigned int weight;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    Node *parent;

public:
    Node(Job *job, unsigned int weight);
    std::unique_ptr<Node> &getLeftOwner();
    std::unique_ptr<Node> &getRightOwner();
    Node *getLeft();
    Node *getRight();
    Node *getParent();
    void setParent(Node *parent);
    void setLeft(std::unique_ptr<Node> node);
    void setRight(std::unique_ptr<Node> node);
    unsigned int getWeight();
    unsigned int getvruntime();
    unsigned int getJobId();
    Job *getJob();
};

enum class Direction
{
    LEFT,
    RIGHT
};

enum class Rotation
{
    LL,
    LR,
    RR,
    RL
};

class BST
{
private:
    std::unique_ptr<Node> root;
    unsigned int totalWeight;
    std::size_t size;

    void DFS(std::vector<std::pair<unsigned int, unsigned int>> &vruntimes, Node *node);
    Direction compare(Job *job, Node *currNode);
    Rotation rotation(Node *node, int factor);
    void rightRotation(Node *node, const Rotation &type);
    void leftRotation(Node *node, const Rotation &type);
    std::pair<Node *, Node *> findSuccessor(Node *target);
    int height(Node *node);
    int balanceFactor(Node *node);

public:
    BST();
    Node *getRoot();
    void insert(Job *job, unsigned int weight);
    bool remove(Job *job);
    Node *find(Job *job);
    Job *min();
    std::size_t treeSize();
    unsigned int getTotalWeight();
    std::vector<std::pair<unsigned int, unsigned int>> inOrder();
};