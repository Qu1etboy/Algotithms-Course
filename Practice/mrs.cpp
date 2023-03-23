/*
  Maximum Rectangle Sum
  หลักการคือ ขยาย array ออกไปเรื่อยๆ ทั้งด้านซ้ายและขวา 
  โดยเก็บผลรวมของแต่ละแถวเอาไว้ใส่ใน array sum และใช้ 
  Kadane's algorithm (mss) แก้ เก็บค่ามากสุดไว้ใน ans
  ทําไปเรื่อย ๆ จน left = cols

  Note: 
    Code below solved it in O(n^4)

    There is a better way that can be solved in O(n^3)
    see https://stackoverflow.com/a/21940302
    
    ps. I don't know how to do it in O(n^3)

*/

#include <iostream>

using namespace std;

// used Kadane's algorithm to find maximum subsequence sum
int mss(int t[], int n) {
  int ans = -10000, mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(t[i] + mx, t[i]);
    ans = max(ans, mx);
  }
  return ans;
}

int main() {
  int rows = 4, cols = 4;
  int s[4][4] = { { 0, -2, -7, 0 },
                  { 9, 2, -6, 2 },
                  { -4, 1, -4, 1 },
                  { -1, 8, 0, -2 }
                };
  int ans = -10000;
  
  // O(n^4)
  for (int left = 0; left < cols; left++) {
    for (int right = 0; right < cols; right++) {
      int sum[4] = {};
      // loop through number of rows
      for (int i = 0; i < rows; i++) {
        // find sum of current rows from left to right
        for (int j = left; j <= right; j++) {
          sum[i] += s[i][j];
        }       
        // cout << sum[i] << endl;
      }
      // compute Kadane's algorithm and keep only max value
      ans = max(ans, mss(sum, 4));
      // cout << "current max: " << ans << endl;
      // cout << "-----" << endl;
    }
  }

  cout << ans << endl; // 15
}