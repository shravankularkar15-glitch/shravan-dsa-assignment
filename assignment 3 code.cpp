#include &lt;iostream&gt;
Using namespace std;

Struct node
{
Int data;
Node *next;
};
Class Linklist
{
Private:
Node *head; //starting node of the list

Public:
Linklist()
//constructor
{
Head=NULL;
}
Void createlist()
{
Int n, value;
Cout&lt;&lt;”\nenter no. of nodes “;
Cin&gt;&gt;n;
If(n&lt;=0)
{
Cout&lt;&lt;”list is empty”;

Return;
}
For (int i=1;i&lt;=n;i++)
{
Cout&lt;&lt;”enter value “&lt;&lt;i&lt;&lt;”:”;
Cin&gt;&gt;value;
Insert(value);
}
Cout&lt;&lt;”\nlinked list created.\n”;
}
Void insert(int value)
{
//create new node
Node *newnode=new node;
Newnode-&gt;data=value;
Newnode-&gt;next=NULL;
If(head==NULL)
{
Head=newnode;
Return;
}
//traversing head just create a temp node to traverse till last
Node *temp=head;
While(temp-&gt;next!=NULL)
{
Temp=temp-&gt;next;
}

//attach new node
Temp-&gt;next=newnode;
}
Void display()
{
If (head==NULL)
{
Cout&lt;&lt;”\nlinked list is empty.\n “;
Return;
}
Node *temp=head;
Cout&lt;&lt;”\nlinked list :”;
While(temp!=NULL)
{
Cout&lt;&lt;temp-&gt;data&lt;&lt;”-?”;
Temp=temp-&gt;next;
}
}
Void deleteNode(int value)
{
If(head==NULL)
{
Cout&lt;&lt;”\nList is Empty.\n”;
Return;
}

Node *temp=head;

Node *previous=NULL;

// Delete first node
If(head-&gt;data==value)
{
Head=head-&gt;next;
Delete temp;

Cout&lt;&lt;”\nNode Deleted.\n”;
Return;
}

// Search node
While(temp!=NULL &amp;&amp; temp-&gt;data!=value)
{
Previous=temp;
Temp=temp-&gt;next;
}

If(temp==NULL)
{
Cout&lt;&lt;”\nValue Not Found.\n”;
Return;
}

Previous-&gt;next=temp-&gt;next;
Delete temp;

Cout&lt;&lt;”\nNode Deleted Successfully.\n”;
}
};
//main function
Int main()
{
Linklist obj;
Int value;
Obj.createlist();
Cout&lt;&lt;”\nenter value to insert “;
Cin&gt;&gt;value;
Obj.insert(value);
Obj.display();
Cout&lt;&lt;”\nenter value to delete “;
Cin&gt;&gt;value;
Obj.deleteNode(value);
Cout&lt;&lt;”\nAfter deletion:”;
Obj.display();
Return 0;
}
