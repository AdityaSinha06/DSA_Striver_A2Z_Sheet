//One-of the way that striked is : calculate the final counts of "(" , ")" , "*".
//we can't judge the final op just on the basis of final counts of * , ( , ). coz the positioning of * also matters.
//eg :> (*)) :> at the end : cnt = -1 , starCnt = 1 :> ya , it can be resolved just by looking at nos :> abs(cnt) - starCnt = 0
//but here: ())* :> cnt = -1 , starCnt = 1 :> it can't be resolved coz the position of * isn't correct to resolve.

//so, one of the possible way :> is to try out, all the possible ways in-place of * :> then check if any these is valid.

//Brute-Force:

//trying all cases in place of * :> using recursion
// class Solution {
// public:
//     bool fun(string& s , int idx , int cnt) {
//         if(cnt < 0) return false;
//         if(idx == s.length()) {
//             if(cnt == 0) return true;
//             return false;
//         }

//         if(s[idx] == '(') {
//             return fun(s , idx + 1 , cnt + 1);
//         } 

//         else if(s[idx] == ')') {
//             return fun(s , idx + 1 , cnt - 1);
//         }

//         else { // in-place of * :> we tried out all possible ways :> '(' , ')' , ""
//             return (fun(s , idx+1 , cnt+1) || fun(s , idx+1 , cnt-1) || fun(s , idx+1 , cnt));
//         }
//     }

//     bool checkValidString(string s) {
//         return fun(s , 0 , 0);
//     }
// };

//tc :> at-worst : O(3^n) , sc :> O(n)

//better: using dp : then tc : O(n^2) , sc : O(n^2)

//Optimal : Greedy approach : -> go with ranges :> means here also, we'll considering all the possible cases of cnt we can get in place of * : "(" , ")" , " "
//now , the question'd be resolved to check if its a valid parenthesis , just see at the end we are getting cnt == 0 or not.


class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length() , minCnt = 0 , maxCnt = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                ++minCnt; ++maxCnt;
            } else if(s[i] == ')') {
                --minCnt; --maxCnt;
            } else {
                //in-place of * : "(" , ")" , "" , cnt'd reduce for ) , increase for (
                --minCnt; ++maxCnt;
            }
            
            if(minCnt < 0) minCnt = 0; 
            if(maxCnt < 0) return false; 
        }      

        return (minCnt == 0);
    }
};

// if(minCnt < 0) minCnt = 0;
// minCnt = the minimum number of unclosed ( we must have at this point.
// When we see a *, we treat it as a ) in the minimum case, so minCnt--.
// But what if there are more ) than ( so far? Then minCnt might go negative.
// A negative minCnt makes no sense — you can’t have “-1 open parentheses” left to close.
// So we clamp it to 0.
// This keeps the minimum case valid by saying:
// “If we have more ) than ( so far, then in the minimum interpretation, we just ignore the extra ) by treating some earlier * as empty.”

//if(maxCnt < 0) return false;
// maxCnt = the maximum possible number of unclosed ( we could have (if every * was "(").
// Every time we see a ), we do maxCnt--.
// If maxCnt ever becomes negative -> that means there are definitely more ) than ( + * combined.
// In other words:
// “No matter how we assign *, there aren’t enough opens left to match these closes.”
// So we immediately return false, because the string cannot ever be valid anymore.