class Solution {
  public:
    int findMin(int n) {
        // code here
        
        //we need to find the minimum no of coins :> so we'll start from higher denomination to lower ones.
        //that's the greedy approach. 
        
        vector<int> denomination = {10,5,2,1};
        
        int amt = n , Tcnt = 0 , i = 0;
        while(amt > 0) {
            if(amt >= denomination[i]) {
                int cnt = amt / denomination[i];
                amt -= cnt * denomination[i];
                
                Tcnt += cnt;
            }
            
            ++i;
        }
        
        return Tcnt;
    }

};