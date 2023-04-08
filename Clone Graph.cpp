class Solution {
public:
    Node* cloneGraph(Node* node) {

        unordered_map<Node* , Node* > m;

        if(node == NULL)
        {
            return NULL;
        }

        // make clone of root node
        Node* clone = new Node(node->val);
        m[node] = clone;

        queue<Node*>q;
        q.push(node);

        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();

            // we traverse through neighbors of original node
            for(Node* adj : curr->neighbors)
            {
                // if duplicate node of current node is present then we make a new one 
                // and also add it in map and queue as it is not visited previously
                if(m.find(adj) == m.end())
                {
                    Node* adjacent = new Node(adj->val);
                    m[adj] = adjacent;
                    q.push(adj);
                }
                // connect duplicate node with its duplicate neighbors.
                m[curr] -> neighbors.push_back(m[adj]);
            }
        }
        return m[node];
    }
};
