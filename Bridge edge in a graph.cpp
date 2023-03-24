class Solution
{
	bool isBridgeFlag=false;
    void dfs(int node,int &timer,int parent,vector<int> &disc,vector<int> &low,vector<bool> &vis,vector<int> adj[],int c,int d){
        vis[node]=true;
        disc[node]=timer;
        low[node]=timer;
        timer++;
        for(int i=0;i<adj[node].size();i++){
            int nbr=adj[node][i];
            if(nbr==parent){
                continue;
            }
            if(vis[nbr]){
                low[node]=min(low[node],disc[nbr]);
            }
            else{
                dfs(nbr,timer,node,disc,low,vis,adj,c,d);
                low[node]=min(low[node],low[nbr]);
                if(low[nbr]>disc[node]){
                    // cout<<nbr<<" "<<node<<endl;
                    if((nbr==c && node==d) || (nbr==d && node==c)){
                        isBridgeFlag=true;
                    }
                }
            }
        }
    }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) {
        isBridgeFlag=false;
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        vector<bool> vis(V,false);
        int timer=0;
        for(int i=0;i<V;i++){
            if(vis[i]){
                continue;
            }
            dfs(i,timer,-1,disc,low,vis,adj,c,d);
        }
        return isBridgeFlag;  
    }
};
