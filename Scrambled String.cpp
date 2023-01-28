class Solution{
    public:
    unordered_map<string,int> m;
    
    bool isfeasible(string a , string b) {
        int n=a.size();
        if(a==b) return true;
        bool flag=false;
        
        string key=a;
        key+=" ";
        key+=b;
        
        if(m.find(key) != m.end()) return m[key];
        
        for(int i=1; i<n; i++) {
            
            if(isfeasible(a.substr(0,i),b.substr(0,i)) && isfeasible(a.substr(i,n-i),b.substr(i,n-i)))
            {
                flag=true;
                break;
            }
            
            if(isfeasible(a.substr(0,i),b.substr(n-i,i)) && isfeasible(a.substr(i,n-i),b.substr(0,n-i)))
            {
                flag=true;
                break;
            }
        }
        return m[key]=flag;
    }
    
    bool isScramble(string S1, string S2){
        //code here
        
        if(S1==S2) return true;
        
        int n=S1.size();
        if(n!=S2.size()) return false;
        
        return isfeasible(S1,S2);
    }    
};
