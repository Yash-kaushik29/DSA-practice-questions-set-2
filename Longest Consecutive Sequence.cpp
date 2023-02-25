class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;

        for(int i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }
        int longestStreak = 0;

        for(int i=0; i<nums.size(); i++) {
            int number = nums[i];
            if(m[number-1] == 0) {
                int currentNum = number;
                int currentStreak = 1;

                while(m[currentNum+1] >0) {
                   currentStreak+=1;
                   currentNum+=1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;   
    }
};
