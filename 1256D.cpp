#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <random>
#include <time.h>
using namespace std;

typedef long long ll;
#define int ll

const int N=2e5+50;
int n, m;
int a[N];
pair<int, int>heroes[N];

void solve();
void stress();

signed  main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;

    while(t--) {
        cin>>n;

        cin>>m;

        string s; cin>>s;
        int lastOne=0;
        for(int i=0; i<n && m; i++){
            if (s[i]=='0'){
                if (i-lastOne<=m){
                    m-=i-lastOne;

                    s[i]='1';
                    s[lastOne]='0';

                    lastOne++;
                }
                else{
                    s[i]='1';
                    s[i-m]='0';
                    m=0;
                }
            }
        }

        cout<<s<<'\n';

    }

    return 0;
}

void stress() {

}

void solve(){

}
