/**
*    Username : adhoc_king
*    Name : adhoc_king
*/

// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

#define pb push_back
#define mp make_pair
#define scani(n) scanf("%d",&n);
#define EPS 1e-9
#define FOR(i,n) for(int i=0; i<n; i++)
#define X first
#define Y second
#define arrinput for(int i=0; i<n; i++) cin>>arr[i];
#define sumarr for(int i=0; i<n; i++) sum+=arr[i];
#define memarr memset(arr, 0, sizeof(arr));
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define forr(i,n) for(int i=n-1; i>=0; i--)

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<int> BigInt;


class BigInteger {

private:

    void Set(BigInt &vec) {
        while(vec.size()>1 && vec.back()==0) vec.pop_back();
    }
    void Print(BigInt vec) {
        // Set(vec);   // this is redundant
        printf("%d", (vec.size()==0) ? 0 : vec.back());
        for(int i=vec.size()-2; i>=0; i--) printf("%09d", vec[i]); printf("\n");
    }   
	

public:

    BigInt anoopam;

	BigInteger(string s) {
		BigInt ans;
		//if(s[0] == '-') return ans; // Negatives not allowed
		if(s.size() == 0) {
			ans.push_back(0);
			//return ans;
		}
		while(s.size()%9 != 0) s = '0'+s;
		for(int i=0; i<s.size(); i+=9) {
			int x = 0;
			for(int j=i; j<i+9; j++) x = x*10 + (s[j]-'0');
			ans.insert(ans.begin(), x);
		}
		Set(ans);
        	anoopam = ans;
		//return ans;
	}

    // BigInteger(char c[]) {
    //     string s = "";
    //     for(int i=0; i<strlen(c); i++) s = s+c[i]; // n^2 change this ASAP
    //     BigInteger(s);      
    // }
    // BigInteger(ll x) {
    //     string s = "";
    //     while(x>0) { s = (char)(x%10+'0') + s; x /= 10; }  // n^2 here also
    //     BigInteger(s);
    // }
    // BigInteger(int x) {
    //     BigInteger((ll) x);
    // }
	
	
	friend ostream & operator << (ostream &out, const BigInteger &vec);
	friend istream & operator >> (istream &in, BigInteger &vec);
	
};

void Print(BigInteger ans) {
        // Set(vec);   // this is redundant
    BigInt vec = ans.anoopam;
    printf("%d", (vec.size()==0) ? 0 : vec.back());
    for(int i=vec.size()-2; i>=0; i--) printf("%09d", vec[i]); printf("\n");
}  

ostream & operator << (ostream &out, const BigInteger &vec) {
	Print(vec);  // change this to format: out<<
	return out;
}

istream & operator >> (istream &in, BigInteger &vec) {
	string s;
	getline(in, s);
	vec = BigInteger(s);
	return in;
}

int main() 
{

    BigInteger A = BigInteger("123456789987654321");
    cout<<A;

    return 0;
}
