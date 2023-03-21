class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>st;
        vector<int>dist(V,1e9);
        dist[S]=0;
        
        //dist,node
        st.insert({0,S});
        
        while(!st.empty()) {
            auto it=*(st.begin());
            int dis=it.first;
            int node=it.second;
            
            st.erase(st.begin());
            
            for(auto it:adj[node]) {
                int edgewt=it[1];
                int adjnode=it[0];
                
                if(dis+edgewt < dist[adjnode]) {
                    
                    if(dist[adjnode]!=1e9)
                    st.erase({dist[adjnode],adjnode});
                    
                    st.insert({dis+edgewt,adjnode});
                    dist[adjnode]=dis+edgewt;
                }
            }
        }
        return dist;
    }
};
