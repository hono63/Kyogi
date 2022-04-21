#include <string>
#include <iostream>
#include <vector>
#include <stdint.h>
#include "atcoder/modint"

using namespace std;
using mint = atcoder::modint998244353;

int main()
{
  int N, K, M;
  
  cin >> N >> M >> K;
  
  //vector<vector<mint>> dp( N+1, vector(K, mint(0)) ); 
  mint count; 
  count = 1;
  int sik = N - 1; // 仕切り
  for (int t=1; t<=K-N; t++) { // 玉
    // 組み合わせ数 t+sik C sik を求める
    int sum = t + sik;
    int s = (sik > sum/2) ? (sum - sik) : sik;
    mint C;
    C = 1;
    for (int i=0; i<s; i++) {
      C *= (sum - i);
      //C *= (sum - i) / (s - i);
      //if (C >= 998244353) C-= 998244353;
      //C %= 998244353;
    }
    for (int i=0; i<s; i++) {
      C /= (s - i);
    }
    //cout << sum << "C" << s << ":" << C.val() << endl;
    //C %= 998244353;
    count += C;
    //count %= 998244353;
  }
  
  cout << count.val() << endl;
  
  return 0;
}