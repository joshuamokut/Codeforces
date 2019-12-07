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

        vector<int> q(n);

        for(int i=0; i<n; i++)
            cin>>q[i];

        set<int>opts;

        vector<int> ans(n);

        int last=0;
        bool ok=true;
        for(int i=0; i<n; i++)
        {
            if (q[i]==last){
                if (opts.empty())
                {
                    ok=false;
                    break;
                }

                ans[i]=*opts.begin();
                opts.erase(opts.begin());
            }
            else{
                ans[i]=q[i];
                for(int j=ans[i]-1; j>last; j--){
                    opts.insert(j);
                }
                last=ans[i];
            }
        }

        if (!ok){
            cout<<"-1\n";
            continue;
        }
        for(auto to: ans)
            cout<<to<<' ';
        cout<<'\n';
    }
}

