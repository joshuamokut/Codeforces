#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


const int N=2e5+50;

int n, m;
int par[N];
int minn[N];
int maxx[N];
int sz[N];
set<int> allPars;
set<int> allInRange;

void updateRange(int min, int max);

void initdsu(int n){
    for(int i=1; i<=n; i++){
        par[i]=i;
        minn[i]=i;
        maxx[i]=i;
        sz[i]=1;
        allPars.insert(i);
    }
}

int findPar(int u){
    while(u!=par[u]){
        par[u]=par[par[u]];
        u=par[u];
    }
    return u;
}

void mergedsu(int u, int v){
    u=findPar(u);
    v=findPar(v);
    if (v==u)
        return;

    if (sz[u]<sz[v]){
        swap(u, v);
    }

    par[v]=u;
    sz[u]+=sz[v];

    minn[u]=min(minn[u], minn[v]);
    maxx[u]=max(maxx[u], maxx[v]);

    allPars.erase(v);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;

    initdsu(n);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;

        mergedsu(u, v); //TODO implement this function: update par, minn, maxx, sz, allpars
    }
    int ans=0;
    while(!allPars.empty()){
        int par=*allPars.begin();
        int curMin=minn[par];
        int curMax=maxx[par];

        updateRange(curMin, curMax); //TODO implement this  function: put every number from curmin to curmax into the
        //TODO set allInrange

        while(!allInRange.empty()){

            int element=*allInRange.begin();
            int elementPar=findPar(element);
            int curPar=findPar(curMin);

            if (curPar!=elementPar){
                ans++;

                updateRange(minn[elementPar], curMin-1);
                updateRange(curMax+1, maxx[elementPar]);

                curMin=min(curMin, minn[elementPar]);
                curMax=max(curMax, maxx[elementPar]);

                mergedsu(elementPar, curPar);
            }

            allInRange.erase(element);
        }

        allPars.erase(par);
    }

    cout<<ans<<'\n';


}

void updateRange(int min, int max) {
    for(int i=min; i<=max; i++)
        allInRange.insert(i);
}
