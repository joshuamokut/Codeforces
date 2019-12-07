#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define int long long
const int N=2e5+50;



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;cin>>n;

    int minn=LLONG_MAX;


    for(int i=1; i*i<=n; i++){
        if (n%i==0){
            minn=min(minn, i+n/i);
        }
    }

    cout<<minn*2<<'\n';
}

