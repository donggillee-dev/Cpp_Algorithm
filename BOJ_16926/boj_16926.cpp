#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 300

int N, M, R, lower;
int arr[MAX][MAX];
void rotate();

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    lower = min(N, M) / 2;

    rotate();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void rotate() {
    for(int r = 0; r < R; r++) {
        for(int depth = 0; depth < lower; depth++) {
            //모서리를 위한 tmp, row, col 변수
            int tmp = 0;
            int left = depth;
            int right = M - 1 - depth;
            int top = depth;
            int bottom = N - depth - 1;
            //윗라인
            tmp = arr[top][left];
            for(int i = left; i < right; i++) {
                arr[top][i] = arr[top][i + 1];
            }

            for(int i = top; i < bottom; i++) {
                arr[i][right] = arr[i + 1][right];
            }

            for(int i = right; i > left; i--) {
                arr[bottom][i] = arr[bottom][i - 1];
            }

            for(int i = bottom; i > top; i--) {
                arr[i][left] = arr[i - 1][left];
            }
            arr[depth + 1][depth] = tmp;
        }
    }
}

