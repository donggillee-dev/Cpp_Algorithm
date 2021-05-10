#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin>>N>>M>>V;
    vector<int> v;

    int length = N - V + 1;
    int tmp;
    for(int i = 0; i < N; i++) {
        cin>>tmp;
        v.push_back(tmp);
    }

    for(int i = 0; i < M; i++) {
        int move;
        cin>>move;

        if(move < N) cout<<v.at(move)<<"\n";
        else {
            move -= (V - 1);
            move %= length;
            move += (V - 1);
            cout<<v.at(move)<<"\n";
        }
    }

    return 0;
}