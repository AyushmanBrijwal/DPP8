#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> ts(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> in(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            in[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(in[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> ts;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        ts.push_back(node);
	        for(auto it : adj[node]) {
	            in[it]--;
	            if(in[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return ts;
	}
};



int main()
{

    	vector<int> adj[6];
    	adj[5].push_back(2);
    	adj[4].push_back(0);
    	adj[4].push_back(0);
    	adj[3].push_back(1);
    	adj[3].push_back(1);
    	adj[2].push_back(3);

    	Solution obj;
    	vector<int> v=obj.ts(6, adj);
    	for(auto it:v)
    	cout<<it<<" ";
    

    return 0;
}
