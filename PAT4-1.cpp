/*
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.

    
    
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print ythe root of the resulting AVL tree in one line.

Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65
Sample Output 2:
88
*/

#include <iostream>

typedef struct AVLTreeNode *AVLTree;
typedef struct AVLTreeNode
{
	int Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};

int Max(int A, int B)
{
	return A >= B ? A:B;
}

int GetHeight(AVLTree A)
{
	if (A)
		return A->Height;	
	else 
		return -1;

}

AVLTree SingleLeftRotation(AVLTree A)//将A，B做左单旋，更新A，B高度，返回新的根节点B
{ 
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), GetHeight(B->Right)) + 1;

	return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), GetHeight(B->Right)) + 1;

	return B;

}

AVLTree DoubleLeftRightRotation(AVLTree A)//将A,B,C作两次单旋，返回新根节点C
{
	A->Left = SingleRightRotation(A->Left);

	return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A)
{
	A->Right = SingleLeftRotation(A->Right);

	return SingleRightRotation(A);
}

AVLTree AVL_Insertion(int X, AVLTree T)
{
	/*将X插入AVL树T中，并且返回调整后的AVL树*/
	if (!T)//若插入空树，则新建包含一个节点的树
	{
		 T = (AVLTree)malloc(sizeof(struct AVLTreeNode));
		 T->Data = X;
		 T->Height = 0;
		 T->Left = T->Right = NULL;
	}

	else if (X < T->Data)//插入T的左子树
	{
		T->Left = AVL_Insertion(X, T->Left);
		if (GetHeight(T->Left) - GetHeight(T->Right) >= 2)
		{
			if (X < T->Left->Data)
			    T = SingleLeftRotation(T);//左单旋
			else
				T = DoubleLeftRightRotation(T);//左右双旋
		}
	}

	else if (X > T->Data)//插入右子树
	{
		T->Right = AVL_Insertion(X, T->Right);
		if (GetHeight(T->Left) - GetHeight(T->Right) >= 2)
		{
			if (X > T->Right->Data)
				T = SingleRightRotation(T);//右单旋
			else
				T = DoubleRightLeftRotation(T);//右左双旋
		}
	}

	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;

	return T;
}

using namespace std;

int main(int argc, char const *argv[])
{
	int num = 0;
	cin>>num;
	AVLTree T = NULL;
	int X = 0;
	while(cin>>X)
		T = AVL_Insertion(X, T);
	
	cout<<T->Data;
	return 0;
}			


/*参考程序*/
#include <iostream>  
#include <fstream>  
  
using namespace std;  
  
ifstream fin("in.txt");  
#define cin fin   
  
struct Node  
{  
    int value;  
    Node* leftChild;  
    Node* rightChild;  
    int height;     //左子树高度 - 右子树高度  
    Node(int v):value(v),leftChild(NULL),rightChild(NULL),height(0){}  
};  
  
int getHeight(Node* node)  
{  
    if(node == NULL)return -1;  
    return node->height;  
  
}  
  
bool isBalanced(Node* parent)  
{  
    return abs(getHeight(parent->leftChild) - getHeight(parent->rightChild)) < 2;  
}  
  
Node* rotate_LL(Node* parent)  
{  
    Node* child = parent->leftChild;  
    parent->leftChild = child->rightChild;  
    child->rightChild = parent;  
  
    parent->height = max(getHeight(parent->leftChild),getHeight(parent->rightChild)) + 1;  
    child->height = max(getHeight(child->leftChild),getHeight(child->rightChild)) + 1;  
    return child;  
}  
  
Node* rotate_RR(Node* parent)  
{  
    Node* child = parent->rightChild;  
    parent->rightChild = child->leftChild;  
    child->leftChild = parent;  
  
    parent->height = max(getHeight(parent->leftChild),getHeight(parent->rightChild)) + 1;  
    child->height = max(getHeight(child->leftChild),getHeight(child->rightChild)) + 1;  
    return child;  
}  
  
Node* rotate_LR(Node* parent)  
{  
    Node* child = parent->leftChild;  
    parent->leftChild = rotate_RR(child);  
    return rotate_LL(parent);  
}  
  
Node* rotate_RL(Node* parent)  
{  
    Node* child = parent->rightChild;  
    parent->rightChild = rotate_LL(child);  
    return rotate_RR(parent);  
}  
  
Node* InsertNode(Node* root,int newValue)  
{  
    if(root!=NULL)  
    {  
        if(newValue > root->value)        //R  
        {  
            root->rightChild = InsertNode(root->rightChild,newValue);  
            if(!isBalanced(root))  
            {  
                if(newValue > root->rightChild->value) //R-R  
                {  
                    root = rotate_RR(root);  
                }else                           //R-L  
                {  
                    root = rotate_RL(root);  
                }  
            }  
        }else                           //L  
        {  
            root->leftChild = InsertNode(root->leftChild,newValue);  
            if(!isBalanced(root))  
            {  
                if(newValue > root->leftChild->value)  //L-R  
                {  
                    root = rotate_LR(root);  
                }else                           //L-L  
                {  
                    root = rotate_LL(root);  
                }  
            }  
        }  
    }else  
    {  
        root = new Node(newValue);  
    }  
    root->height = max(getHeight(root->leftChild),getHeight(root->rightChild)) + 1;  
    return root;  
}  
  
void PrintTree(Node* root)  
{  
    if(root != NULL)  
    {  
        cout<<root->value<<"--";  
        PrintTree(root->leftChild);  
        PrintTree(root->rightChild);  
    }  
}  
  
int main()  
{  
    int n;  
    cin>>n;  
  
    Node *root = NULL;  
  
    int x;  
    int i;  
    for(i=0;i<n;i++)  
    {  
        cin>>x;  
        root = InsertNode(root,x);  
    }  
    cout<<root->value<<endl;  
    system("PAUSE");  
    return 0;  
}  