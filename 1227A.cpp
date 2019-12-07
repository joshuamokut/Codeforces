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
    int t; cin>>t;

    while(t--){
        int n; cin>>n;

        int maxL=0;
        int minR=LLONG_MAX;

        while(n--){
            int l, r; cin>>l>>r;

            maxL=max(l, maxL);
            minR=min(r, minR);
        }

        cout<<max(0ll, -minR+maxL)<<'\n';
    }
}

