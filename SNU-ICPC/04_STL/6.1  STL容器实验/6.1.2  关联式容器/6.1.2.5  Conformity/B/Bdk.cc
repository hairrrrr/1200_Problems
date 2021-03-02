#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

main() {
  int n;
  while (cin >> n && n) {
    int mx = 0, ret = 0;
    map<vector<int>, int> num_students;
    for (int i = 0; i < n; i++) {
      vector<int> v(5);
      for (int j = 0; j < 5; j++) cin >> v[j];
      sort(v.begin(), v.end());
      mx >?= ++num_students[v];
    }
    for (map<vector<int>, int>::iterator it = num_students.begin();
         it != num_students.end();
         ++it) {
      if (it->second == mx) ret += mx;
    }
    cout << ret << endl;
  }
}
