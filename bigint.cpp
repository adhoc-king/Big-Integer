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
	int size;
    // BigInteger() {}    // need to maket this 

    BigInteger(const char* c) {
        string s = "";
        for(int i=0; i<strlen(c); i++) s = s+c[i]; // n^2 change this ASAP
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
        this->anoopam = ans;
        this->size = ans.size();
    }

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
        this->anoopam = ans;
        this->size = ans.size();
    }

    BigInteger(long long x) {
        string s = "";
        while(x>0) { s = (char)(x%10+'0') + s; x /= 10; }  // n^2 here also
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
        this->anoopam = ans;
        this->size = ans.size();
    }

    // BigInteger(int x) {
    //     BigInteger((ll) x);
    // }
	
	friend ostream & operator << (ostream &out, const BigInteger &vec);
	friend istream & operator >> (istream &in, BigInteger &vec);
	friend bool operator < (BigInteger&, BigInteger&);
	friend bool operator > (BigInteger&, BigInteger&);
	friend bool operator == (BigInteger&, BigInteger&);
	friend bool operator != (BigInteger&, BigInteger&);
	friend bool operator <= (BigInteger&, BigInteger&);
	friend bool operator >= (BigInteger&, BigInteger&);
	friend bool operator < (BigInteger&, long long&);
	friend bool operator > (BigInteger&, long long&);
	friend bool operator == (BigInteger&, long long&);
	friend bool operator != (BigInteger&, long long&);
	friend bool operator <= (BigInteger&, long long&);
	friend bool operator >= (BigInteger&, long long&);
	friend bool operator < (long long&, BigInteger&);
	friend bool operator > (long long&, BigInteger&);
	friend bool operator == (long long&, BigInteger&);
	friend bool operator != (long long&, BigInteger&);
	friend bool operator <= (long long&, BigInteger&);
	friend bool operator >= (long long&, BigInteger&);
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

bool operator < (BigInteger& b1, BigInteger& b2) {
	// Set(b1);
	// Set(b2);
	BigInt i1=b1.anoopam, i2=b2.anoopam;
	if(i1.size() != i2.size()) return (i1.size() < i2.size());
	for(int i=i1.size()-1; i>=0; i--) {
		if(i1[i] != i2[i]) return (i1[i] < i2[i]);
	}
	return false;
}

bool operator > (BigInteger& b1, BigInteger& b2) {
	return (b2 < b1);
}

bool operator == (BigInteger& b1, BigInteger& b2) {
	return (!(b1 < b2) && !(b2 < b1));
}

bool operator != (BigInteger& b1, BigInteger& b2) {
	return !(b1 == b2);
}

bool operator <= (BigInteger& b1, BigInteger& b2) {
	return (b1 < b2 || b1 == b2);
}

bool operator >= (BigInteger& b1, BigInteger& b2) {
	return (b2 < b1 || b1 == b2);
}

bool operator < (BigInteger& b1, long long& b2) {
    BigInteger b3 = BigInteger(b2);
    return b1 < b3;
}

bool operator > (BigInteger& b1, long long& b2) {
    BigInteger b3 = BigInteger(b2);
    return b3 < b1;
}

bool operator == (BigInteger& b1, long long& b2) {
    BigInteger b3 = BigInteger(b2);
    return b1 == b3;
}

bool operator != (BigInteger& b1, long long& b2) {
    BigInteger b3 = BigInteger(b2);
    return b1 != b3;
}

bool operator <= (BigInteger& b1, long long& b2) {
    BigInteger b3 = BigInteger(b2);
    return b1 <= b3;
}

bool operator >= (BigInteger& b1, long long& b2) {
    BigInteger b3 = BigInteger(b2);
    return b1 >= b3;
}

bool operator < (long long& b1, BigInteger& b2) {
    BigInteger b3 = BigInteger(b1);
    return b3 < b2;
}

bool operator > (long long& b1, BigInteger& b2) {
    BigInteger b3 = BigInteger(b1);
    return b2 < b3;
}

bool operator == (long long& b1, BigInteger& b2) {
    BigInteger b3 = BigInteger(b1);
    return b3 == b2;
}

bool operator != (long long& b1, BigInteger& b2) {
    BigInteger b3 = BigInteger(b1);
    return b3 != b2;
}

bool operator <= (long long& b1, BigInteger& b2) {
    BigInteger b3 = BigInteger(b1);
    return b3 <= b2;
}

bool operator >= (long long& b1, BigInteger& b2) {
    BigInteger b3 = BigInteger(b1);
    return b3 >= b2;
}

int main() 
{
    string str = "123456789987654321";
    string str1 = "323456789987654321";
    char ch[] = "123456789987654321";
    BigInteger A = BigInteger(str);
    cout<<A;
    BigInteger B = BigInteger(str1);
    cout<<B;
    bool x = B<A;
    cout<<x<<"\n";
    x = A<B;
    cout<<x<<"\n";

    return 0;
}
