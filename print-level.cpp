#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//TreeNode class
template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

// print level wise
void printLevelWise(TreeNode<int> *root){
    queue<TreeNode<int>*>pending;
    pending.push(root);
    while(pending.size()!=0){
        TreeNode<int>*front=pending.front();
        pending.pop();
        cout<<front->data<<":";
        for(int i=0; i<front->children.size(); i++){
            if(i<((front->children.size())-1))
            	cout<<front->children[i]->data<<",";
            else
            	cout<<front->children[i]->data;
            pending.push(front->children[i]);
        }
        cout<<endl;
    }
}

//count nodes
int numNodes(TreeNode<int>*root){
    int ans=1;
    for(int i=0; i<root->children.size(); i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}

//take input level wise
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout<<"Enter root data: ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter number of children of "<<front->data<<": ";
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            cout<<"Enter data for "<<i+1<<" child of "<<front->data<<": ";
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
    int num = numNodes(root);
    cout<<"Nodes are: "<<num<<endl;
    return 0;
}