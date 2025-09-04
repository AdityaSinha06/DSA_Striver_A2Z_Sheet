//from ith index, I can reach to maxm : (i + nums[i])th idx.
//so, ya by making these jumps : need to figure out :? can I reach to the last index or not!
//obs :> if nums[i] == 0 , can't make any jump
//else since all nums[i] > 0 :> can always reach to end.
//so brute-force 'd go like :> making all the possible jumps and then check that any of there lead us to the end or not.

//Brute-force:
// class Solution {
// private:
//     bool check(vector<int>& nums , int idx) {
//         //from idx I can jump from all (idx+1) to (idx + nums[idx]). given nums[idx] != 0.
//         if(idx >= (nums.size() - 1)) return true;
//         if(nums[idx] == 0) return false;

//         for(int i = idx+1; i <= (idx + nums[idx]); i++) {
//             if(check(nums , i)) return true;
//         }

//         return false;
//     }

// public:
//     bool canJump(vector<int>& nums) {
//         return check(nums , 0);
//     }
// };

//Optimal :
//we can solve this by : maintaing a max Index reached counter too. 
//Here, the code:
class Solution {
#include<bits/stdc++.h>
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() , maxIdxReached = 0;
        for(int i=0; i<n; i++) {
            if(i > maxIdxReached) return false;
            maxIdxReached = max(maxIdxReached , i+nums[i]);
            if(maxIdxReached >= n-1) return true;
        }

        return true;
    }
};