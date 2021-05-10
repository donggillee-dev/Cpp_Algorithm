#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int N;
int dir_x[4] = {-1, 1, 0, 0};
int dir_y[4] = {0, 0, -1, 1};
vector< vector <int> > arr;
vector< vector <int> > DP;

int DFS(int x, int y) {
    if(DP[x][y] != 0) return DP[x][y];

    DP[x][y] = 1;

    for(int i = 0; i < 4; i++) {
        int nx = x + dir_x[i];
        int ny = y + dir_y[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        
        if(arr[x][y] < arr[nx][ny])
            DP[x][y] = max(DP[x][y], DFS(nx, ny) + 1);
    }

    return DP[x][y];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;

    int length = INT_MIN;
    arr.resize(N, vector<int>(N));
    DP.resize(N, vector<int>(N));

    int num;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin>>num;
            arr[i][j] = num;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            length = max(length, DFS(i, j));
        }
    }

    cout<<length;
    return 0;
}