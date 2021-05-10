#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin>>N>>Q;
    int lands[N + 1];
    fill_n(lands, N + 1, 0);

    for(int duck = 0; duck < Q; duck++) {
        int ori_idx;
        int cpy_idx;
        int stuck_idx = 0;

        cin>>ori_idx;
        cpy_idx = ori_idx;

        while(cpy_idx > 0) {
            if(lands[cpy_idx] == -1) {
                stuck_idx = cpy_idx;
            }
            cpy_idx /= 2;
        }

        if(stuck_idx == 0) {
            lands[ori_idx] = -1;
        }
        cout<<stuck_idx<<"\n";
    }

    return 0;
}