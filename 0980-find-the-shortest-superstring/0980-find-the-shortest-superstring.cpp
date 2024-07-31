class Solution {
private:
    //mem is a memoization table comprising of two variables
    //prev->the index of the previous string that has been included in the super string
    //config->a bitmask which represents which strings have already been included in the 
    //super string and which have not.(1->not included,0->included)
    
    //common[i][j]=if words[j][0:index] matches with the suffix of words[i], then I will store
    //words[j][index+1:end] in common[i][j] so that I can add this part to my answer in the recursive call
    vector<vector<string>>mem,common;
    //computes the maximum index in string t which overlaps with string s and returns everything
    //after that index.
    string addStrings(string s,string t){
        bool found=false;
        int index=-1;
        for(int i=0;i<s.size();i++){
            //first character matches
            if(s[i]==t[0]){
                //starting from the end and checking whether that prefix of t matches with the current suffix of s
                for(int j=t.size()-1;j>=0;j--){
                    if(s.substr(i)==t.substr(0,j+1)){
                        index=j;
                        found=true;
                    }
                }
                if(found){
                    break;
                }
            }
        }
        return t.substr(index+1);
    }
    string solve(vector<string>&words,int prev,int config){
        if(config==0){
            return "";
        } else if(mem[prev][config]!="1"){
            return mem[prev][config];
        } else {
            string ans="";
            int curr=config;
            //iterate through all the words that have not yet been included in the super string
            while(curr){
                //finding the rightmost set bit in curr
                int pos=log2(curr&(-curr));
                curr-=curr&(-curr);
                //words[prev] is already included in the super string therefore we will add the 
                //part of words[pos]  which does not overlap with words[prev] and then perform 
                //a recursive call.
                string cand=common[prev][pos]+solve(words,pos,config^(1<<pos));
                if(ans==""){
                    ans=cand;
                } else {
                    if(ans.size()>=cand.size()){
                        ans=cand;
                    }
                }
            }
            return mem[prev][config]=ans;
        }
    }
public:
    string shortestSuperstring(vector<string>& words) {
        int n=words.size();
        mem=vector<vector<string>>(n,vector<string>(1<<n,"1"));
        common=vector<vector<string>>(n,vector<string>(n,""));
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i!=j){
                    common[i][j]=addStrings(words[i],words[j]);
                }
            }
        }
        string ans="";
        int config=(1<<n)-1;
        //trying every index as a starting point and returning the minimum super string
        for(int i=0;i<n;i++){
            string cand=words[i]+solve(words,i,config^(1<<i));
            if(ans==""){
                ans=cand;
            } else {
                if(ans.size()>cand.size()){
                    ans=cand;
                }
            }
        }
        return ans;
    }
};