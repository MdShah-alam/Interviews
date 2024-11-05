#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& matrix, vector<bool>& visited, int node, int n) {
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (matrix[node][i] == 1 && !visited[i]) {
            dfs(matrix, visited, i, n);
        }
    }
}

int countCreatorCommunities(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<bool> visited(n, false);
    int communityCount = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(matrix, visited, i, n);
            communityCount++;
        }
    }
    return communityCount;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> matrix;
    for(int i=0;i<n;i++){
        vector<int>v(n);
        for(int j=0;j<n;j++)
            cin>>v[j];
        matrix.push_back(v);
    }
    cout << countCreatorCommunities(matrix) << endl;  // Output should be 2
    return 0;
}
/**

4
1 1 0 0
1 1 1 0
0 1 1 0
0 0 0 1

*/
