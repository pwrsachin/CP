/*interview bitmask dp - Shortest common superstring*/
vector< vector<int> > extr;
int getcomb(string &s1,string &s2){
    int n1 = s1.size();
    int n2 = s2.size();
    int var = min(n1,n2);
    int ans = 0;
    for(int i=1;i<=var;i++){
        if(s2.substr(0,i)==s1.substr(n1-i,i)){
            ans = max(ans,i);
        }
    }
    
    //if(ans==n2) return 0;
    return n2 - ans;
    
}

int dfs(int mask,int v,vector<string> &s,vector< vector<int> > &dp){
    int n = s.size();
    if(mask==0) return INT_MAX;
    if(dp[mask][v]!=-1) return dp[mask][v];
    int mins = INT_MAX;
    for(int j=0;j<n;j++){
        if((1<<j)&mask && j!=v){
            int comb = extr[v][j];
            mins = min(mins,dfs(mask^(1<<v),j,s,dp)+comb); 
        }
    }
    dp[mask][v] = mins;
    return dp[mask][v];
}

int Solution::solve(vector<string> &s) {
    int n = s.size();
    vector< vector<int> > dp((1<<n),vector<int>(n,-1));
    // dp[i][j] represents optimal length if strings availabe in mask i combined with last string put is j;
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        dp[(1<<i)][i] = s[i].size();
    }
    extr.resize(n);
    for(int j = 0; j < n; j ++){
        extr[j].resize(n);
        for(int k = 0; k < n; k ++){
            extr[j][k] = getcomb(s[k],s[j]);
        }
    }
   
    for(int i=0;i<n;i++) ans = min(ans,dfs((1<<n)-1,i,s,dp));
    return ans;
    
}

