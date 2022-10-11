class Solution {
public:
//给你两个字符串，求第一个匹配项的下标
//haystack = "sadbutsad", needle = "sad"
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        if(m==0) return 0;
        vector<int> next(m,0);
        //这里是m
        for(int i=1,j=0;i<m;i++){
            while(j>0&&needle[j]!=needle[i]) j=next[j-1];
            if(needle[j]==needle[i]) j++;
            next[i]=j;
        }
        for(int i=0,j=0;i<n;i++){
            while(j>0&&needle[j]!=haystack[i]) j=next[j-1];
            if(needle[j]==haystack[i]) j++;
            if(j==m) return i-m+1;
        }
        return -1;
    }
};