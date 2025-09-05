//approach:
//s1: get all the divisors of n, sort them
//s2: get all the combinations of k eles , such that their product is n //hell-yeah!!
//--> consider each combination is in sorted(non-decreasing)
//s3: compute the maxDiff for each : c[k-1] - c[0]
//s4: select the split having minDiff out of all these maxDiffs.

class Solution {
#include<bits/stdc++.h>
private:
    void fillSplits(vector<int>& divisors , int idx , long long currProd , int currK , vector<int>& split , vector<vector<int>>& splits) {
        if(currK == 0) {
            if(currProd == divisors.back()) {
                splits.push_back(split);
            }

            return;
        }        

        for(int i=idx; i<divisors.size(); i++) {
            if(currProd * divisors[i] <= divisors.back()) {
                split.push_back(divisors[i]);
                fillSplits(divisors , i , currProd*divisors[i] , currK-1 , split , splits);

                split.pop_back();
            } else {
                return;
            }
        }
    }
    
public:
    vector<int> minDifference(int n, int k) {
        vector<int> divisors;
        for(int i=1; i<=sqrt(n); i++) {
            if(n%i == 0) {
                divisors.push_back(i);
                if(n/i != i) {
                    divisors.push_back(n/i);
                }
            }
        }

        sort(divisors.begin() , divisors.end());

        vector<vector<int>> splits;
        vector<int> split;
        fillSplits(divisors , 0 , 1 , k , split , splits);

        int minDiff = INT_MAX;
        for(auto &vec : splits) {
            minDiff = min(minDiff , vec[k-1] - vec[0]);
        }   

        for(auto &vec : splits) {
            if((vec[k-1] - vec[0]) == minDiff) {
                return vec;
            }
        }

        return {};
    }
};