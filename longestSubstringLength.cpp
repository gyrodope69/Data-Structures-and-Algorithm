#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256,-1);
        int left = 0 , right = 0 , n = s.size() , len = 0;
        while(right<n)
        {
            if(mpp[s[right]]!=-1)
            {
                left = max(mpp[s[right]]+1 , left);
            }
            mpp[s[right]] = right ;
            
            len = max(len,right-left+1);
            right++;
        }
        return len;
    }
};
int main()
{
    Solution ob;
    string s;
    cout<<"Enter a string : ";
    cin>>s;
    cout<<"Maximum unique substring length is : "<<ob.lengthOfLongestSubstring(s);
    return 0;
}