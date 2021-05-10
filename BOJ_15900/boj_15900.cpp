#include <iostream>
#include <vector>
using namespace std;

vector<int> list[500000];
int answer = 0;

void DFS(int curNode, int prevNode, int depth) {
    if(list[curNode].size() == 1 && prevNode == list[curNode].at(0)) {
        answer += depth;
    }

    for(int i = 0; i < list[curNode].size(); i++) {
        int nextNode = list[curNode].at(i);
        if(nextNode != prevNode) {
            DFS(nextNode, curNode, depth + 1);
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;

    for(int i = 0; i < N - 1; i++) {
        int A, B;
        cin>>A>>B;

        list[A].push_back(B);
        list[B].push_back(A);
    }

    DFS(1, 0, 0);

    if(answer % 2 == 0) cout<<"No\n";
    else cout<<"Yes\n";
    return 0;
}