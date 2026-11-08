#include "BST.h"

// WARNING: You must update a node's vruntime when the job's vruntime changes.

Node::Node(Job *job, unsigned int weight) : vruntime(job->getvruntime()), weight(weight), left(nullptr), right(nullptr), parent(nullptr)
{
    this->job = job;
}

void Node::setParent(Node *parent)
{
    this->parent = parent;
}

Node *Node::getParent()
{
    return this->parent;
}

void Node::setLeft(std::unique_ptr<Node> node)
{
    this->left = std::move(node);
}

Node *Node::getLeft()
{
    return left.get();
}

void Node::setRight(std::unique_ptr<Node> node)
{
    this->right = std::move(node);
}

Node *Node::getRight()
{
    return right.get();
}

unsigned int Node::getWeight()
{
    return weight;
}

unsigned int Node::getvruntime()
{
    return vruntime;
}

unsigned int Node::getJobId()
{
    return job->getId();
}

Job *Node::getJob()
{
    return job;
}

std::unique_ptr<Node> &Node::getLeftOwner()
{
    return left;
}

std::unique_ptr<Node> &Node::getRightOwner()
{
    return right;
}

// ----------------------------------------------------------------

BST::BST() : root(nullptr), totalWeight(0), size(0) {}

int BST::height(Node *node)
{
    if (!node)
    {
        return -1;
    }

    return 1 + std::max(height(node->getLeft()), height(node->getRight()));
}

int BST::balanceFactor(Node *node)
{
    return height(node->getLeft()) - height(node->getRight());
}

Direction BST::compare(Job *job, Node *currNode)
{
    if (job->getvruntime() < currNode->getvruntime())
    {
        return Direction::LEFT;
    }

    else if (job->getvruntime() > currNode->getvruntime())
    {
        return Direction::RIGHT;
    }

    else
    {
        if (job->getId() < currNode->getJobId())
        {
            return Direction::LEFT;
        }

        else
        {
            return Direction::RIGHT;
        }
    }
}

void BST::insert(Job *job, unsigned int weight)
{
    std::unique_ptr<Node> node = std::make_unique<Node>(job, weight);

    totalWeight += node->getWeight();
    ++size;

    if (!root)
    {
        root = std::move(node);
        return;
    }

    Node *curr = root.get();
    Node *parent = nullptr;

    while (curr != nullptr)
    {
        parent = curr;

        Direction direction = compare(node->getJob(), curr);

        if (direction == Direction::LEFT)
        {
            curr = curr->getLeft();
        }

        else
        {
            curr = curr->getRight();
        }
    }

    Direction direction = compare(node->getJob(), parent);

    // Use parent to obtain curr node again (currently nullptr)
    if (direction == Direction::LEFT)
    {
        parent->setLeft(std::move(node));
        curr = parent->getLeft();
        curr->setParent(parent);
    }

    else
    {
        parent->setRight(std::move(node));
        curr = parent->getRight();
        curr->setParent(parent);
    }

    while (curr != nullptr)
    {
        int factor = balanceFactor(curr);

        if (factor < -1 || factor > 1)
        {
            Rotation type = rotation(curr, factor);

            if (type == Rotation::LL || type == Rotation::LR)
            {
                rightRotation(curr, type);
            }

            if (type == Rotation::RR || type == Rotation::RL)
            {
                leftRotation(curr, type);
            }
        }

        curr = curr->getParent();
    }
}

// RR or RL rotation
void BST::leftRotation(Node *node, const Rotation &type)
{
    if (type == Rotation::RL)
    {
        // Suppose you inserted 10, 30, 20 (draw the tree)...

        // 1. Store 20 locally
        std::unique_ptr<Node> twenty = std::move(node->getRight()->getLeftOwner());

        // 2. Store 30 locally
        std::unique_ptr<Node> thirty = std::move(node->getRightOwner());

        // 3. Set 20's parent to 10 via 30
        twenty->setParent(thirty->getParent());

        // 4. Move 20 into 10's right (local 20 is no longer available)
        node->setRight(std::move(twenty));

        // 5. Set 30's parent to be 20 via 10 (use right child)
        thirty->setParent(node->getRight());

        // 6. Move 30 into 20's right via 10
        node->getRight()->setRight(std::move(thirty));

        // The subtree is ready for left rotation
    }

    // Rotation around root
    if (!node->getParent())
    {
        // 1. Save node locally into curr
        std::unique_ptr<Node> curr = std::move(root);

        // 2. Set curr parent to be the new root (it's right child)
        curr->setParent(curr->getRight());

        // 3. Set root by getting curr's right child and set the child's parent to nullptr (becomes new tree root)
        root = std::move(curr->getRightOwner());
        root->setParent(nullptr);

        // 4. Set the new root's left child to be curr (the old root)
        root->setLeft(std::move(curr));
    }

    // Rotation deep in tree
    else
    {
        if (node->getParent()->getLeft() == node)
        {
            // 1. Save curr node locally
            std::unique_ptr<Node> curr = std::move(node->getParent()->getLeftOwner());

            // 2. Set curr's child parent to be curr's parent and set curr's parent to own curr's child
            curr->getRight()->setParent(curr->getParent());
            curr->getParent()->setLeft(std::move(curr->getRightOwner()));

            // 3. Set curr as the left child of curr's right child
            curr->getParent()->getLeft()->setLeft(std::move(curr));
        }

        if (node->getParent()->getRight() == node)
        {
            // 1. Save curr node locally
            std::unique_ptr<Node> curr = std::move(node->getParent()->getRightOwner());

            // 2. Set curr's child parent to be curr's parent and set curr's parent to own curr's child
            curr->getRight()->setParent(curr->getParent());
            curr->getParent()->setRight(std::move(curr->getRightOwner()));

            // 3. Set curr as the right child of curr's right child
            curr->getParent()->getRight()->setLeft(std::move(curr));
        }
    }
}

// LL or LR rotation
void BST::rightRotation(Node *node, const Rotation &type)
{
    if (type == Rotation::LR)
    {
        // Suppose you inserted 30, 20, 25 (draw the tree)...

        // 1. Store 25 locally
        std::unique_ptr<Node> twentyFive = std::move(node->getLeft()->getRightOwner());

        // 2. Store 20 locally
        std::unique_ptr<Node> twenty = std::move(node->getLeftOwner());

        // 3. Set 25's parent to 30 via 20
        twentyFive->setParent(twenty->getParent());

        // 4. Move 25 into 30's left (local 25 is no longer available)
        node->setLeft(std::move(twentyFive));

        // 5. Set 20's parent to be 25 via 30 (use left child)
        twenty->setParent(node->getLeft());

        // 6. Move 20 into 25's left via 30
        node->getLeft()->setLeft(std::move(twenty));

        // The subtree is ready for right rotation
    }

    // Rotation around root
    if (!node->getParent())
    {
        // 1. Save node locally into curr
        std::unique_ptr<Node> curr = std::move(root);

        // 2. Set curr parent to be the new root (it's left child)
        curr->setParent(curr->getLeft());

        // 3. Set root by getting curr's left child and set the child's parent to nullptr (becomes new tree root)
        root = std::move(curr->getLeftOwner());
        root->setParent(nullptr);

        // 4. Set the new root's right child to be curr (the old root)
        root->setRight(std::move(curr));
    }

    // Rotation deep in tree
    else
    {
        // Determine if curr is to the right or left of its parent

        if (node->getParent()->getLeft() == node)
        {
            // 1. Save curr node locally
            std::unique_ptr<Node> curr = std::move(node->getParent()->getLeftOwner());

            // 2. Set curr's child parent to be curr's parent and set curr's parent to own curr's child
            curr->getLeft()->setParent(curr->getParent());
            curr->getParent()->setLeft(std::move(curr->getLeftOwner()));

            // 3. Set curr as the right child of curr's left child
            curr->getParent()->getLeft()->setRight(std::move(curr));
        }

        if (node->getParent()->getRight() == node)
        {
            // 1. Save curr node locally
            std::unique_ptr<Node> curr = std::move(node->getParent()->getRightOwner());

            // 2. Set curr's child parent to be curr's parent and set curr's parent to own curr's child
            curr->getLeft()->setParent(curr->getParent());
            curr->getParent()->setRight(std::move(curr->getLeftOwner()));

            // 3. Set curr as the right child of curr's left child
            curr->getParent()->getRight()->setRight(std::move(curr));
        }
    }
}

Rotation BST::rotation(Node *node, int factor)
{
    // left heavy
    if (factor > 1)
    {
        if (node->getLeft()->getLeft() == nullptr)
        {
            return Rotation::LR;
        }

        return Rotation::LL;
    }

    // right heavy
    else
    {
        if (node->getRight()->getRight() == nullptr)
        {
            return Rotation::RL;
        }

        return Rotation::RR;
    }
}

bool BST::remove(Job *job)
{
    // 3 CASES: LEAF NODE, ONE CHILD, TWO CHILDREN (SUCCESSOR)

    if (!root)
    {
        return false;
    }

    Node *curr = root.get();
    Node *parent = nullptr;

    while (curr && curr->getJob() != job)
    {
        parent = curr;

        Direction direction = compare(job, curr);

        if (direction == Direction::LEFT)
        {
            curr = curr->getLeft();
        }

        else
        {
            curr = curr->getRight();
        }
    }

    if (!curr) // JOB NOT FOUND
    {
        return false;
    }

    totalWeight -= curr->getWeight();
    --size;

    if (!parent) // DEL ROOT
    {
        // LEAF CASE

        if (!curr->getLeft() && !curr->getRight())
        {
            root.reset();
        }

        // ONE CHILD

        else if (curr->getLeft() && !curr->getRight())
        {
            root = (std::move(curr->getLeftOwner()));
        }

        else if (curr->getRight() && !curr->getLeft())
        {
            root = (std::move(curr->getRightOwner()));
        }

        // TWO CHILD CASE

        else
        {
            // IMMEDIATE RIGHT

            auto [successor, successorParent] = findSuccessor(curr);

            if (curr->getRight() == successor)
            {
                successor->setLeft(std::move(root->getLeftOwner()));
                root = std::move(root->getRightOwner());
            }

            // SUCCESSOR NO CHILDREN

            else if (!successor->getLeft() && !successor->getRight())
            {
                successor->setRight(std::move(root->getRightOwner()));
                successor->setLeft(std::move(root->getLeftOwner()));
                root = std::move(successorParent->getLeftOwner());
            }

            // SUCCESSOR HAS RIGHT CHILD

            else
            {
                std::unique_ptr<Node> successor = std::move(successorParent->getLeftOwner());
                successorParent->setLeft(std::move(successor->getRightOwner()));
                successor->setRight(std::move(root->getRightOwner()));
                successor->setLeft(std::move(root->getLeftOwner()));
                root = std::move(successor);
            }
        }
    }

    else // DEL DEEP IN TREE
    {
        // LEAF CASE

        if (!curr->getLeft() && !curr->getRight())
        {
            if (parent->getLeft() == curr)
            {
                parent->setLeft(nullptr);
            }

            else
            {
                parent->setRight(nullptr);
            }
        }

        // ONE CHILD CASE

        else if (curr->getLeft() && !curr->getRight())
        {
            if (parent->getLeft() == curr)
            {
                parent->setLeft(std::move(curr->getLeftOwner()));
            }

            else
            {
                parent->setRight(std::move(curr->getLeftOwner()));
            }
        }

        else if (!curr->getLeft() && curr->getRight())
        {
            if (parent->getLeft() == curr)
            {
                parent->setLeft(std::move(curr->getRightOwner()));
            }

            else
            {
                parent->setRight(std::move(curr->getRightOwner()));
            }
        }

        // TWO CHILD CASE

        else
        {
            auto [successor, successorParent] = findSuccessor(curr);

            // IMMEDIATE RIGHT

            if (curr->getRight() == successor)
            {
                successor->setLeft(std::move(curr->getLeftOwner()));

                if (parent->getRight() == curr)
                {
                    parent->setRight(std::move(curr->getRightOwner()));
                }

                else
                {
                    parent->setLeft(std::move(curr->getRightOwner()));
                }
            }

            // SUCCESSOR NO CHILDREN

            else if (!successor->getLeft() && !successor->getRight())
            {
                successor->setLeft(std::move(curr->getLeftOwner()));
                successor->setRight(std::move(curr->getRightOwner()));

                if (parent->getRight() == curr)
                {
                    parent->setRight(std::move(successorParent->getLeftOwner()));
                }

                else
                {
                    parent->setLeft(std::move(successorParent->getLeftOwner()));
                }
            }

            // SUCCESSOR HAS RIGHT CHILD

            else
            {
                std::unique_ptr<Node> successorChild = std::move(successor->getRightOwner());
                std::unique_ptr<Node> successor = std::move(successorParent->getLeftOwner());

                successor->setLeft(std::move(curr->getLeftOwner()));
                successor->setRight(std::move(curr->getRightOwner()));

                if (parent->getRight() == curr)
                {
                    parent->setRight(std::move(successor));
                }

                else
                {
                    parent->setLeft(std::move(successor));
                }

                successorParent->setLeft(std::move(successorChild));
            }
        }
    }

    return true;
}

Job *BST::min()
{
    Node *curr = getRoot();

    while (curr->getLeft())
    {
        curr = curr->getLeft();
    }

    return curr->getJob();
}

Node *BST::find(Job *job)
{
    Node *curr = root.get();

    while (curr && curr->getJob() != job)
    {
        Direction dir = compare(job, curr);

        if (dir == Direction::RIGHT)
        {
            curr = curr->getRight();
        }

        else
        {
            curr = curr->getLeft();
        }
    }

    return curr;
}

std::vector<std::pair<unsigned int, unsigned int>> BST::inOrder()
{
    std::vector<std::pair<unsigned int, unsigned int>> vruntimes;
    DFS(vruntimes, root.get());
    return vruntimes;
}

void BST::DFS(std::vector<std::pair<unsigned int, unsigned int>> &vruntimes, Node *node)
{
    // LEFT -> ROOT -> RIGHT

    if (!node)
    {
        return;
    }

    DFS(vruntimes, node->getLeft());
    vruntimes.push_back({node->getJobId(), node->getvruntime()});
    DFS(vruntimes, node->getRight());
}

unsigned int BST::getTotalWeight()
{
    return totalWeight;
}

std::pair<Node *, Node *> BST::findSuccessor(Node *target)
{
    Node *successorParent = target->getRight();
    Node *successor = successorParent;

    while (successor && successor->getLeft())
    {
        successorParent = successor;
        successor = successor->getLeft();
    }

    return std::make_pair(successor, successorParent);
}

Node *BST::getRoot()
{
    return root.get();
}

std::size_t BST::treeSize()
{
    return size;
}