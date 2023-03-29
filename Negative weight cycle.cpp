class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    vector<int> dis(n+1,1e9);
	    dis[0]=0;
	    
	    for(int i=0; i<n-1; i++) {
	        
	        for(auto edge: edges) {
	            
	            int u=edge[0];
	            int v=edge[1];
	            int w=edge[2];
	            
	            if(dis[u] != 1e9 && dis[u]+w < dis[v]) {
	                dis[v]=dis[u]+w;
	            }
	        }         
	    }
	    
	    int flag=0;
	    
	    for(auto edge: edges) {
	            
	       int u=edge[0];
	       int v=edge[1];
           int w=edge[2];
	            
	       if(dis[u]+w < dis[v]) {
	            flag=1;
	       }
	    }
	    
	    return flag;
	}
};
