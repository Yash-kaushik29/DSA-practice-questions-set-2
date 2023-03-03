void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    // Your code goes here
    if(root == NULL)    return;
    if(root->key == key){
        findPreSuc(root->left, pre, suc, key);
        findPreSuc(root->right, pre, suc, key);
        return;
    }
    if(key < root->key){
        suc = root;
        return findPreSuc(root->left, pre, suc, key);
    }
    pre = root;
    return findPreSuc(root->right, pre, suc, key);

}
