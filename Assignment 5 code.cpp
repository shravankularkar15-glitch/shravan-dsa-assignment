#include &lt;iostream&gt;
#include &lt;stack&gt;
Using namespace std;

Class Node
{
Public:
Int data;
Node* left;
Node* right;

Node(int value)
{
Data = value;
Left = NULL;
Right = NULL;
}
};

Class BST
{
Private:
Node* root;

Public:

BST()
{
Root = NULL;
}

// Non-recursive BST insertion
Void insert(int value)
{
Node* newNode = new Node(value);

If (root == NULL)
{
Root = newNode;
Return;
}

Node* current = root;
Node* parent = NULL;

While (current != NULL)
{
Parent = current;

If (value &lt; current-&gt;data)
{
Current = current-&gt;left;
}

Else if (value &gt; current-&gt;data)
{
Current = current-&gt;right;
}
Else
{
Cout &lt;&lt; “Duplicate value not inserted.\n”;
Delete newNode;
Return;
}
}

If (value &lt; parent-&gt;data)
{
Parent-&gt;left = newNode;
}
Else
{
Parent-&gt;right = newNode;
}
}

Void createBST()
{
Int n, value;

Cout &lt;&lt; “Enter number of nodes: “;

Cin &gt;&gt; n;

Cout &lt;&lt; “Enter node values:\n”;

For (int I = 0; I &lt; n; i++)
{
Cin &gt;&gt; value;
Insert(value);
}
}

// Non-recursive Inorder Traversal
Void inorderNonRecursive()
{
Stack&lt;Node*&gt; s;
Node* current = root;

Cout &lt;&lt; “Inorder Traversal: “;

While (current != NULL || !s.empty())
{
While (current != NULL)
{
s.push(current);
current = current-&gt;left;
}

Current = s.top();
s.pop();

cout &lt;&lt; current-&gt;data &lt;&lt; “ “;

current = current-&gt;right;
}

Cout &lt;&lt; endl;
}

// Non-recursive Preorder Traversal
Void preorderNonRecursive()
{
If (root == NULL)
{
Cout &lt;&lt; “Tree is empty.\n”;
Return;
}

Stack&lt;Node*&gt; s;
s.push(root);

cout &lt;&lt; “Preorder Traversal: “;

while (!s.empty())
{

Node* current = s.top();
s.pop();

cout &lt;&lt; current-&gt;data &lt;&lt; “ “;

// Push right first
If (current-&gt;right != NULL)
{
s.push(current-&gt;right);
}

// Push left second
If (current-&gt;left != NULL)
{
s.push(current-&gt;left);
}
}

Cout &lt;&lt; endl;
}
};

Int main()
{
BST tree;

Tree.createBST();

Tree.inorderNonRecursive();
Tree.preorderNonRecursive();

Return 0;
}
