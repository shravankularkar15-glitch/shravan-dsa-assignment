#include <iostream>
Using namespace std;

Struct node
{
Int data;
Node *left;
Node *right;
};
Class binary
{
Private:
Node *root; //starting node of the list

Public:
Binary()
//constructor
{
Root=NULL;
}
Node* create()
{
Int value;
Cout<<”\nenter node value (-1) for no. node “;
Cin>>value;

If(value == -1)
Return NULL;
Node *newnode = new node;
Newnode->data = value;

Cout<<”enter left child of “<< value;
Newnode->left = create();
Cout<<”enter right child of “<< value;
Newnode->right = create();
Return newnode;
}
Void build()
{
Cout<<”\ncreate binary tree\n”;
Root = create();
}
Void inorder(node *temp)
{
If (temp == NULL)
Return;
Inorder (temp->left);
Cout << temp->data << “ “;
Inorder(temp->right);
}
Void inorderdisplay()
{

Cout << “\ninorder traversal :”;
Inorder(root);
}
Void preorder(node *temp)
{
If (temp == NULL)
Return;

Cout << temp->data << “ “;
Preorder(temp->left);
Preorder(temp->right);
}
Void preorderdisplay()
{
Cout << “\nPreorder traversal : “;
Preorder(root);
}
Void postorder(node *temp)
{
If (temp == NULL)
Return;

Postorder(temp->left);
Postorder(temp->right);
Cout << temp->data << “ “;
}

Void postorderdisplay()
{
Cout << “\nPostorder traversal : “;
Postorder(root);
}
};
Int main()
{
Binary tree;
Int choice;

Do
{
Cout << “\n\n1. Create Binary Tree”;
Cout << “\n2. Inorder Traversal”;
Cout << “\n3. Preorder Traversal”;
Cout << “\n4. Postorder Traversal”;
Cout << “\n5. Exit”;

Cout << “\nEnter your choice: “;
Cin >> choice;

Switch(choice)
{
Case 1:
Tree.build();

Break;

Case 2:
Tree.inorderdisplay();
Break;

Case 3:
Tree.preorderdisplay();
Break;

Case 4:
Tree.postorderdisplay();
Break;

Case 5:
Cout << “\nExit”;
Break;

Default:
Cout << “\nInvalid choice”;
}

} while(choice != 5);

Return 0;
}
