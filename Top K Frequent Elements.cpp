class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;
        vector<int> ans;

        unordered_map<int, int> mp;

        for(auto num: nums) {
            mp[num]++;
        }

        for(auto it: mp) {
            min_pq.push({it.second, it.first});
            if(min_pq.size() > k) min_pq.pop();
        }

        while(!min_pq.empty()) {
            int num = min_pq.top().second;
            min_pq.pop();
            ans.push_back(num);
        }

        return ans;
    }
};
