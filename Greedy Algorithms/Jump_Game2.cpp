//need to return the minimum number of jumps required to reach to the last index.
//so, ya: one of the way is to try out all the possible cases: at which we can reach to the end , and maintain the count of jumps also.
//then select the minimum out of them.
// class Solution {
// private: 
//     int findMinJumps(vector<int>& nums , int idx , int nJumps) {
//         if(idx >= (nums.size() - 1)) return nJumps;

//         int minJumps = INT_MAX;
//         for(int i=idx+1; i<=(idx + nums[idx]); i++) {
//             minJumps = min(minJumps , findMinJumps(nums , i , nJumps+1));
//         }

//         return minJumps;
//     }

// public:
//     int jump(vector<int>& nums) {
//         return findMinJumps(nums , 0 , 0);
//     }
// };

//tc : O(n^n) , sc : O(n)

//here, the greedy approach would be : since I need to find the minimum number of jumps , so I need take maximum size jumps (bigger Jumps)         
//so lets maintain a range which I can reach from the st. Idx :: now in that range, I have to jump to the maxm number only. coz :: jumps are : i - i + nums[i] , so when nums[i] is max ::> the jumps is obv. largest.
//so, to ease the job instead of looking for the maxm ele : look for the farthest that I can go, its just same as previous.

class Solution {
#include<bits/stdc++.h>
public:
    int jump(vector<int>& nums) {
        int n = nums.size() , l = 0 , r = 0 , jumpsCnt = 0;
        while(r < n-1) {
            int farthest = r;
            for(int i=l; i<=r; i++) {
                farthest = max(farthest , i+nums[i]);
            }

            l = r+1;
            r = farthest;
            ++jumpsCnt;
        }

        return jumpsCnt;
    }
};