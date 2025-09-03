class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        
        vector<pair<double , int>> valPerwt(n);    
        for(int i=0; i<n; i++) {
            valPerwt[i] = {(double)val[i]/wt[i] , i};
        }
        
        sort(valPerwt.begin() , valPerwt.end() , [](auto a , auto b) {
            return a.first > b.first; 
        });
        
        int currCap = capacity;
        double totalVal = 0;
        for(int i=0; i<n; i++) {
            if(wt[valPerwt[i].second] <= currCap) { // if the wt of curr item is under the rem. capacity, pick it up and reduce the rem capacity.
                currCap -= wt[valPerwt[i].second];
                totalVal += val[valPerwt[i].second];
            } else { //here, it means the wt is > rem Cap , so just break the item and utilise full capacity.
                if(currCap != 0) {
                    totalVal += valPerwt[i].first * currCap;
                    currCap = 0;
                }
                
                break;
            }
        }
        
//Can also do it like this: 
//       for(int i=0; i<n; i++) {
//           if(remCapacity == 0) break;
//             else if(remCapacity - wt[valPerwt_Idx[i].second] >= 0) {
//                 maxVal += val[valPerwt_Idx[i].second];
//                 remCapacity -= wt[valPerwt_Idx[i].second];
//             } else {
//                 maxVal += valPerwt_Idx[i].first*remCapacity;
//                 remCapacity = 0;
//             }
//         }
        

        return totalVal;
    }
};
