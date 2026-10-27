class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        string temp1 = "";
        for(int i = 0 ; i < n ; i++){
            temp1.push_back('.');
        }
        ans.push_back(temp1);

        for(int i = 0 ; i < m-1 ; i++){
            string temp = "";
            for(int i = 0 ; i < n-1 ; i++){
                temp.push_back('#');
            }
            temp.push_back('.');
            ans.push_back(temp);

        }
        return ans;
    }
};