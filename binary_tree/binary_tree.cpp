#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
//非递归前序遍历 出根压右子树再压左子树
void preOrderIterative(Node* root){
    if(root == NULL){
        return;
    }
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
    }
}   

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
//非递归中序遍历 有根压根，左叶子压完出，根出就压右
void inOrderIterative(Node* root){
    stack<Node*> s;
    Node* curr = root;
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
//非递归后序遍历 
void postOrderIterative(Node* root){
    if(root == NULL){
        return;
    }
    stack<Node*> s1, s2;
    s1.push(root);
    //出根压s2，左叶子压s1，右叶子压s1  
    while(!s1.empty()){
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left){
            s1.push(curr->left);
        }
        if(curr->right){
            s1.push(curr->right);
        }
    }
    while(!s2.empty()){
        Node* curr = s2.top();
        s2.pop();
        cout<<curr->data<<" ";
    }
}
//求树的高度
int getHeight(Node* root) {
    if (!root) return 0;
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);
    return 1 + max(leftH, rightH);
}

//求树的节点总数
int countTreeNodes(Node* root) {
    if (!root) return 0;
    return 1 + countTreeNodes(root->left) + countTreeNodes(root->right);
}

//求叶子节点个数
int countLeaves(Node* root) {
    if (!root) return 0;
    // 左右都空才是叶子
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

//层序遍历
void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        cout << cur->data << " ";

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Preorder Traversal: ";
    preOrder(root);
    cout<<endl;

    cout<<"Inorder Traversal: ";
    inOrder(root);
    cout<<endl;

    cout<<"Postorder Traversal: ";
    postOrder(root);
    cout<<endl;

    return 0;
}