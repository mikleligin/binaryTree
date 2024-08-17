
#include <iostream>

using namespace std;



struct Node
{
    int val = 0;
    Node* left;
    Node* right;
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};
class Tree
{
public:
    Node* head;
    Tree(int val) {
        head = new Node(val);
    }
    ~Tree()
    {
        delete head;
    }
    void input(int val) {
        recursiveInput(head, val);
    }
    void printValues() {
        recPrint(head);
    }
    void randomTree() {
        getRandomTree();
    }
    void printImageTree() {
        recBranchPrint("", head, false, 0);
    }
    
private:
    int getRandomVal(int a, int b)
    {
        
        return a + rand()%(b-a);
    }
    void getRandomTree() {
        for (size_t i = 0; i < getRandomVal(5, 200); i++)
        {
            input(getRandomVal(0, 500));
        }
    }
    void recursiveInput(Node* root, int val)
    {
        if (root->val < val)
        {
            if (root->left == nullptr)
            {
                root->left = new Node(val);
            }
            else {
                recursiveInput(root->left, val);
            }
        }
        else {
            if (root->right == nullptr)
            {
                root->right = new Node(val);
            }
            else {
                recursiveInput(root->right, val);
            }
        }

    }
    void recPrint(Node* root)
    {
        if (root==nullptr)
        {
            return;
        }
        recPrint(root->left);
        cout << root->val << " ";
        recPrint(root->right);
    }
    void recBranchPrint(string prefix, Node* root, bool isLeft, int count)
    {
        if (root != nullptr)
        {
            count++;
                cout << prefix;
                cout << (isLeft ? "|--" : "L__");
                cout << root->val << endl;
                recBranchPrint(prefix + (isLeft ? "|   " : "   "), root->left, true, count);
                recBranchPrint(prefix + (isLeft ? "|   " : "   "), root->right, false, count);
        }
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Tree tree(3);
    tree.randomTree();
    tree.printImageTree();
    cout << endl;
}