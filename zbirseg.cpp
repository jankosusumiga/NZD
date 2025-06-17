#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> niz(n);
    vector<int> prefiks(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> niz[i];
        prefiks[i + 1] = prefiks[i] + niz[i];
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << prefiks[b + 1] - prefiks[a] << '\n';
    }
    return 0;
}