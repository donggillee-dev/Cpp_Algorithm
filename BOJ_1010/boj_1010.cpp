#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M;
    cin>>T;

    for(int tc = 0; tc < T; tc++) {
        cin>>N>>M;

        int result = 1;

        for(int j = 1; j <= N; j++) {
            result = result*(M-j+1)/j;
        }
        cout<<result<<"\n";
    }

    return 0;
}