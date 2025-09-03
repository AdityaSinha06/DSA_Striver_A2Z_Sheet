class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //return the maximum number of children to whom we can assign cookies.

        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        int i = 0 , j = 0 , cnt = 0;
        while(i < g.size() && j < s.size()) {
            if(s[j] >= g[i]) { // if the cookie size I'm holding is atleast the child's greed , assign it and move to next.
                ++cnt;
                ++j; ++i;
            } else { // means the cookie I'm holding is lesser than child's greed and since children are sorted a/c their greed so next one will have greed >= currGreed :> so withdraw bigger cookies. :: go to next cookies (as they are also sorted a/c size)
                ++j;
            }
        }

        return cnt;
    }
};