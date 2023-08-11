Leetcode 231
// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count1=0;
      while(n>0){
         int d= n&1;
         if(d==1){
             count1++;
         }
  n=n>>1;


      }
      if(count1==1){
          return true;
      }
      else{
          return  false;
      }
       
    }
};