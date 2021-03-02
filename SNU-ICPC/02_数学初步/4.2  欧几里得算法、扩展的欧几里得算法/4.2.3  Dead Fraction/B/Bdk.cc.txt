#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int gcd(int a, int b) {return (b == 0) ? a : gcd(b, a%b);}
int p10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000,
			   100000000, 1000000000};

main() {
	int i, j, k, x, num, den, rnum, rden;
	string s;

	while( cin >> s && s != "0" ) {
		rden = 2000000000;
		for( i = 0; i < s.size()-5; i++ ) {
			num = atoi(s.substr(i+2).c_str()) +
				  (p10[s.size()-5-i]-1) * atoi(s.substr(2, i).c_str());
			den = (p10[s.size()-5-i]-1) * p10[i];
			x = gcd(num, den);
			num /= x; den /= x;
			if( den < rden ) {rnum = num; rden = den;}
		}
		cout << rnum << '/' << rden << '\n';
	}
}

