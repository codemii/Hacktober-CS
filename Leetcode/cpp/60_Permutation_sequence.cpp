class Solution {
public:

    long fib(int k){
        if(k==0){
            return 1;
        }
        if(k==1){
            return 1;
        }
        return k*fib(k-1);

    }

    string getPermutation(int n, int k) {
        string val="";
        vector<string> killme;
        for(int i=0;i<n;i++){
            string abc=to_string(i+1);
            killme.push_back(abc);
        }
        long fact=fib(n);
        k--;
        while(n!=0){
            fact=fact/n;
            n--;
            int g=floor(k/fact);
            int r=k%fact;
            val=val+killme[g];
            killme.erase(killme.begin()+g);
            k=r;
        }
        return val;
    }
};
