class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.length();
        long long ans = 0 ;
        int start = 0 ;
        int curr = 0 ;

        int last1 = -1;
        int last2 = -1;
        

        while(curr<n){
            if(s[curr]=='a'){
                last1 = curr;
            }

            if(s[curr]=='b'){
                if(last1!=-1){
                    last2 = last1;
                }
            }

            if(s[curr]=='b'){
                if(last1!=-1){
                    last2 = max(last1,last2);
                }
            }

            if(s[curr]=='c'){
                if(last2!=-1){
                    start = max(start,last2+1);
                }
            }

            ans+=(curr-start+1);
            curr++;
    

            
        }

        return ans;
        
    }
};