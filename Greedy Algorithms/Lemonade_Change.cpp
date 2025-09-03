//Leetcode:860

// here , I observed when'd I need to return a change:> only when the cust. give a $10 , $20 bill
//$5 : no return
//$10 : return 1 $5
//$20 : retrun $15 :> (3 $5) or (1 $10 and 1 $5)

//so maintain a $5 cnt , $10 cnt. 
//if got $5 :> $5cnt++
//if got $10 :> if $5cnt >=1 $5cnt-- and $10cnt++  else return false
//if got $20 :> greedily :> we'd keep more change to us so that we can use it for further.
//   so, if ($10cnt >= 1 && $5cnt >= 1) then do --$10cnt && --$5cnt
// else do $5cnt -= 3.


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size() , fiveCnt = 0 , tenCnt = 0;
        for(int i=0; i<n; i++) {
            if(bills[i] == 5) {
                ++fiveCnt;
            } else if(bills[i] == 10) {
                if(fiveCnt < 1) return false;
                ++tenCnt;
                --fiveCnt;
            } else {
                if(tenCnt >= 1 && fiveCnt >=1) {
                    --tenCnt; --fiveCnt;
                } else if(fiveCnt >= 3) {
                    fiveCnt -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};