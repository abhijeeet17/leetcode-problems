class Solution{
public:
    struct Node{
        long long cnt,wav;
    };
    string s;
    Node dp[20][11][11];
    bool vis[20][11][11];
    Node dfs(int pos,bool tight,int a,int b){
        if(pos==s.size()) return {1,0};
        if(!tight&&vis[pos][a][b]) return dp[pos][a][b];
        int lim=tight?s[pos]-'0':9;
        Node ans={0,0};
        for(int d=0;d<=lim;d++){
            bool nt=tight&&(d==lim);
            if(b==10){
                Node nxt=(d==0)?dfs(pos+1,nt,10,10):dfs(pos+1,nt,10,d);
                ans.cnt+=nxt.cnt;
                ans.wav+=nxt.wav;
            }else if(a==10){
                Node nxt=dfs(pos+1,nt,b,d);
                ans.cnt+=nxt.cnt;
                ans.wav+=nxt.wav;
            }else{
                int add=((b>a&&b>d)||(b<a&&b<d));
                Node nxt=dfs(pos+1,nt,b,d);
                ans.cnt+=nxt.cnt;
                ans.wav+=nxt.wav+nxt.cnt*add;
            }
        }
        if(!tight){
            vis[pos][a][b]=true;
            dp[pos][a][b]=ans;
        }
        return ans;
    }
    long long solve(long long n){
        if(n<0) return 0;
        s=to_string(n);
        memset(vis,0,sizeof(vis));
        return dfs(0,true,10,10).wav;
    }
    long long totalWaviness(long long num1,long long num2){
        return solve(num2)-solve(num1-1);
    }
};