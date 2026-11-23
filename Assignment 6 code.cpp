#include <iostream>
#include <queue>
using namespace std;

// Structure of BST Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{
private:
    Node *root;

    // Insert Employee ID
    Node* insertNode(Node *root, int value)
    {
        if (root == NULL)
        {
            Node *newnode = new Node;
            newnode->data = value;
            newnode->left = NULL;
            newnode->right = NULL;
            return newnode;
        }

        if (value < root->data)
            root->left = insertNode(root->left, value);

        else if (value > root->data)
            root->right = insertNode(root->right, value);

        else
            cout << "Duplicate Employee ID not allowed.\n";

        return root;
    }

    // Copy Original BST
    Node* copyTree(Node *root)
    {
        if (root == NULL)
            return NULL;

        Node *newnode = new Node;
        newnode->data = root->data;

        newnode->left = copyTree(root->left);
        newnode->right = copyTree(root->right);

        return newnode;
    }

    // Calculate Height
    int calculateHeight(Node *root)
    {
        if (root == NULL)
            return 0;

        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        return 1 + max(leftHeight, rightHeight);
    }

    // Print Leaf Nodes
    void printLeafNodes(Node *root)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            cout << root->data << " ";
            return;
        }

        printLeafNodes(root->left);
        printLeafNodes(root->right);
    }

    // Delete Tree
    void deleteTree(Node *root)
    {
        if (root == NULL)
            return;

        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

public:

    // Constructor
    BST()
    {
        root = NULL;
    }

    // Insert Employee ID
    void insert(int value)
    {
        root = insertNode(root, value);
    }

    // Level Order Traversal
    void levelOrder()
    {
        if (root == NULL)
        {
            cout << "BST is empty.\n";
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }

        cout << endl;
    }

    // Copy BST
    BST copyBST()
    {
        BST newTree;
        newTree.root = copyTree(root);
        return newTree;
    }

    // Find Height
    int height()
    {
        return calculateHeight(root);
    }

    // Display Leaf Nodes
    void displayLeafNodes()
    {
        if (root == NULL)
        {
            cout << "BST is empty.\n";
            return;
        }

        cout << "Leaf Nodes: ";
        printLeafNodes(root);
        cout << endl;
    }

    // Destructor
    ~BST()
    {
        deleteTree(root);
    }

    // Disable shallow copying
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

    // Move constructor
    BST(BST&& other) noexcept
    {
        root = other.root;
        other.root = NULL;
    }
};

// Main Function
int main()
{
    BST original, copied;
    int n, id;

    cout << "===== Employee Database Using BST =====\n";

    cout << "Enter number of employees: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "No employees to insert.\n";
        return 0;
    }

    // Insert Employee IDs
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Employee ID: ";
        cin >> id;
        original.insert(id);
    }

    // Display Original BST
    cout << "\nOriginal BST (Level Order): ";
    original.levelOrder();

    // Copy BST
    copied = original.copyBST();

    // Display Copied BST
    cout << "\nCopied BST (Level Order): ";
    copied.levelOrder();

    // Calculate Height
    cout << "\nHeight of BST: " << original.height() << endl;

    // Display Leaf Nodes
    original.displayLeafNodes();

    return 0;
}
