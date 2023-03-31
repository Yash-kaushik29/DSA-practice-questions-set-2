class Solution{
public:
    void solve(string s, int &i, int n, Node* node)
    {
        if(i<n && isdigit(s[i]))
        {
            int digit = 0;
            while(isdigit(s[i]))
            {
                int temp = s[i] - '0';
                digit=digit*10+temp;
                i++;
            }
            node->data = digit;
        }
        
        if(i<n && s[i] == '(' && s[i+1]!=')')
        {
            node->left = new Node(-1);
            i++;
            solve(s,i,n,node->left);
        }
        
        else if(s[i]=='(' && s[i+1]==')')
        {
            i+=2;
        }
        
        if(i<n && s[i]=='(' && s[i+1]!=')')
        {
            i++;
            node->right = new Node(-1);
            solve(s,i,n,node->right);
        }
        
        else if(s[i]=='(' && s[i+1]==')')
        {
            i+=2;
        }
        
        if(i>=n || s[i] == ')')
        {
            i++;
            return;
        }
    }

    Node *treeFromString(string str){
        int n = str.size();
        Node* node = new Node(-1);
        int i=0;
        solve(str,i,n,node);
        
        return node;
    }
};
