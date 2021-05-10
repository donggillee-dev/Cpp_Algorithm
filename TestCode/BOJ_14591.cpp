#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <cassert>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<pair<int,int> > vii;
typedef vector<pair<ll,int> > vli;
typedef vector<pair<ll,ll> > vll;
typedef vector<pair<db,db> > vdd;

#define mp make_pair
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const db PI = acos(-1);


vector<bool> visited;
vector<vector<int> > adj;
vector<int> result;
void dfs(int here){
    visited[here]=true;

    for(int i=0;i<adj[here].size();i++){
        int next = adj[here][i];
        if(!visited[next]) dfs(next);
    }
    result.push_back(here);
}

int main(){

    int n;
    scanf("%d",&n);

    adj.resize(n+1);
    visited.resize(n+1);

    for(int i=1;i<=n;i++){
        for(int j=1,t;j<=n;j++){
            scanf("%d",&t);
            if(t) adj[i].push_back(j);
        }
    }

    dfs(1);
    printf("%lu\n", result.size());
    for(int i=result.size()-1;i>=0;i--)
        printf("%d ", result[i]);

    return 0;
}