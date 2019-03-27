#include<iostream>
#include<string>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x): val(x), left(NULL), right(NULL){}
};

TreeNode* deSerialize(string str, int & i) {
    if( str[i] == '#'){
        i++;
        return NULL;
    }
    TreeNode* res = new TreeNode(str[i]);
    i++;
    res->left = deSerialize(str, i);
    res->right = deSerialize(str, i);
    return res;
}

TreeNode* create(string str) {
    int index = 0;
    return deSerialize(str, index);
}

TreeNode* reverse(TreeNode* node) {
    if(node == NULL)
        return NULL;
    TreeNode* cur = node;
    TreeNode* pre = NULL;
    TreeNode* nxt = NULL;
    while(cur){
        nxt = cur->right;
        cur->right = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

void processNode(TreeNode* node){
    if(node == NULL){
        cout << "#" << endl;
        return ;
    }
    cout << node->val << " ";
    return ;
}

void processEdge(TreeNode* node) {
    if(node == NULL)
        return ;
    TreeNode* reversedHead = reverse(node);
    TreeNode* p = reversedHead;
    while(p) {
        processNode(p);
        p = p->right;
    }
    reverse(reversedHead);
}

void printPre(TreeNode* root) {
    if(root == NULL){
        cout << "this tree is empty" << endl;
    }
    processNode(root);
    if(root->left)
        printPre(root->left);
    if(root->right)
        printPre(root->right);
}

void morrisPre(TreeNode* root){
    if(root == NULL){
        return ;
    }
    TreeNode* cur = root;
    TreeNode* mostRight = NULL;
    while(cur) {
        mostRight = cur->left;
        if(mostRight){
            while(mostRight->right != NULL && mostRight->right != cur) 
                mostRight = mostRight->right;
            if(mostRight->right == NULL){
                processNode(cur);
                mostRight->right = cur;
                cur = cur->left;
                continue;
            } else {
                mostRight->right = NULL;
            }
        } else {
            processNode(cur);
        }
        cur = cur->right;
    }
}

void morrisIn(TreeNode* root) {
    if(root == NULL)
        return ;
    TreeNode* cur = root;
    TreeNode* mostRight = NULL;
    while(cur) {
        mostRight = cur->left;
        if(mostRight) {
            while(mostRight->right && mostRight->right != cur)
                mostRight = mostRight->right;
            if(mostRight->right == NULL) {
                mostRight->right = cur;
                cur = cur->left;
                continue;
            } else {
                mostRight->right = NULL;
            }
        } else {
        }
        processNode(cur);
        cur = cur->right;
    }
}


void morrisPost(TreeNode* root) {
    if(root == NULL) 
        return ;
    TreeNode* cur = root;
    TreeNode* mostRight = NULL;
    while(cur) {
        mostRight = cur->left;
        if(mostRight) {
            while(mostRight->right && mostRight->right != cur)
               mostRight = mostRight->right;
            if( mostRight->right == NULL) {
               mostRight->right = cur; 
               cur = cur->left;
               continue;
            } else {
                mostRight->right = NULL;
                processEdge(cur->left);
            }   
        } else {
        }
        cur = cur->right;
    }
    processEdge(root);
}





















