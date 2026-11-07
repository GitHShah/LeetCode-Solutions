class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        vector<int>result(m,-1);

        using pii = pair<long long, long long>;
        priority_queue<pii, vector<pii>, greater<pii>> free;

        using tiii = tuple<long long, long long, long long>;
        priority_queue<tiii, vector<tiii>, greater<tiii>> busy;

        for(int i = 0 ; i < n ; i++){
            free.push({servers[i],i});
        }

        long long time = 0 ;

        for(int i = 0 ; i < m ; i++){
            long long val = tasks[i];

            if(i<time && !free.empty()){
                result[i] = free.top().second;
                busy.push({time+val,free.top().first,free.top().second});
                free.pop();
                continue;
            }

            while(!busy.empty()){
                auto [a, b, c] = busy.top();
                if(a<=time){
                    busy.pop();
                    free.push({b,c});
                }else{
                    break;
                }
            }

            if(!free.empty()){
                result[i] = free.top().second;
                busy.push({time+val,free.top().first,free.top().second});
                free.pop();
            }else{
                auto [a, b, c] = busy.top();
                time = a ; 
                while(!busy.empty()){
                    auto [a, b, c] = busy.top();
                    if(a<=time){
                        busy.pop();
                        free.push({b,c});
                    }else{
                        break;
                    }   
                }

                result[i] = free.top().second;
                busy.push({time+val,free.top().first,free.top().second});
                free.pop();
                continue;

            }

            time++;

        }

        return result;


    }
};