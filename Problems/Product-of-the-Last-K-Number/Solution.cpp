#include <bits/stdc++.h>
using namespace std;
class product {
public:
   vector <int> a;
   product() {
      a.push_back(1);
   }
   void add(int num) {
      if(num == 0){
         a.clear();
         a.push_back(1);
      }
      else{
         a.push_back(a.back() * num);
      }
   }
   int Product(int k) {
      int n = (int)a.size();
      return k > n - 1? 0 : a[n - 1] / a[n - k - 1];
   }
};
main(){
   product s;
   (s.add(3));
   (s.add(0));
   (s.add(2));
   (s.add(5));
   (s.add(4));
   cout << (s.Product(2)) << endl;
   cout << (s.Product(3)) << endl;
   cout << (s.Product(4)) << endl;
   (s.add(8));
   cout << (s.Product(2)) << endl;
}
