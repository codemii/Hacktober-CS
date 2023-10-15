class Solution {
public:
    
    vector<int> cross_product(pair<int, int> p, pair<int, int> q) {
        return {0, 0, p.first*q.second-p.second*q.first};
    }
    
    int direction(vector<int> a, vector<int> b, vector<int> c) {
        vector<int> cp = cross_product({b[0]-a[0], b[1]-a[1]}, {c[0]-b[0], c[1]-b[1]});
        if(cp[2] > 0) return 1;
        else if(cp[2] < 0) return -1;
        return 0;
    }
    
    long long dot(vector<int> a, vector<int> b) {
        return pow(a[0]-b[0], 2) + pow(a[1]-b[1], 2);
    }
    
    void print(vector<int> v) {
        for(auto& e: v) cout << e << ' ';
        cout << endl;
    }
    
    
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        
        // start = bottom leftmost point
        int start = 0;
        for(int i = 0; i < n; i++) {
            if(trees[i][0] < trees[start][0] || (trees[i][0] == trees[start][0] && trees[i][1] < trees[start][1])) {
                start = i;
            }
        }
        
        vector<vector<int>> ans;
        vector<bool> done(n, false);
        // ans stores leftmost point
        ans.push_back(trees[start]);
        done[start] = true;
        
        while(true) {
            int pt = 0;
            vector<int> temp;
            for(int i = 0; i < n; i++) {
                if(trees[i] == ans.back() || pt == i) continue;
                int d = direction(ans.back(), trees[pt], trees[i]);
                if(d == -1) {
                    pt = i;
                    temp.clear();
                }
                if(d == 0) {
                    if(dot(ans.back(), trees[i]) > dot(ans.back(), trees[pt])) {
                        if(ans.back() != trees[pt]) temp.push_back(pt);
                        pt=i;
                    } else {
                        temp.push_back(i);
                    }
                }
            }
            vector<int> c = {10,0};
           
            for(int idx: temp) if(!done[idx]) {ans.push_back(trees[idx]); done[idx]= true;}
            
            if(trees[pt] == ans.front()) break;
            if(!done[pt]) ans.push_back(trees[pt]);
            done[pt] = true;
        }
        return ans;
    }
};
