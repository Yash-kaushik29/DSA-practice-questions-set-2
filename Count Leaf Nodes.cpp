void inorder(BinaryTreeNode<int> *root, int& leafNodes) {
    if(root == NULL) {
        return ;
    }

    inorder(root->left,leafNodes);

    if(root->left == NULL && root->right == NULL) {
        leafNodes++;
    }

    inorder(root->right,leafNodes);
}


int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int leafNodes = 0;
    inorder(root,leafNodes);
    return leafNodes;

}
