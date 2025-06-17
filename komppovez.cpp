#include <bits/stdc++.h>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> veze(v);
    vector<int> pripadnost(v, -1);
    for(int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        veze[a].push_back(b);
        veze[b].push_back(a);
    }
    int brojKomponenti = 1;
    for(int i = 0; i < v; i++) {
        if(pripadnost[i] == -1) {
            pripadnost[i] = brojKomponenti;
            // Red za BFS
            queue<int> f;
            f.push(i);
            while(!f.empty()) {
                // prolaz kroz komsije
                for(int j = 0; j < veze[f.front()].size(); j++) {
                    // ako komsija nije posecen posecuje se
                    if(pripadnost[veze[f.front()][j]] == -1) {
                        pripadnost[veze[f.front()][j]] = brojKomponenti;
                        f.push(veze[f.front()][j]);
                    }
                }
                f.pop();
            }
            brojKomponenti++;
        }
    }
    // ispis pripadnosti
    for(int i = 0; i < pripadnost.size(); i++) {
        cout << pripadnost[i] << ' ';
    }
    cout << '\n';
    return 0;
}