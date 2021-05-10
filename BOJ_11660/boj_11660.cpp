#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N, M;
    cin>>N>>M;

    int arr[N + 1][N + 1];
    int dp[N + 1][N + 1];

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }
    
    int answer = 0;
    int x1, x2, y1, y2;
    for(int i = 0; i < M; i++) {
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        answer = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];

        cout<<answer<<'\n';
    }
}