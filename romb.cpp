#include <bits/stdc++.h>
using namespace std;

int skalarniProizvod(pair<int, int> a, pair<int, int> b) {
    return a.first * b.first + a.second * b.second;
}

pair<int, int> oduzmiVektor(pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

int main() {
    vector<pair<int, int>> tacke(4);
    for(int i = 0; i < 4; i++) {
        cin >> tacke[i].first >> tacke[i].second;
    }
    bool pronadjen = false;
    while(next_permutation(tacke.begin(), tacke.end())) {
        if(skalarniProizvod(oduzmiVektor(tacke[2], tacke[0]), oduzmiVektor(tacke[1], tacke[0])) ==
            skalarniProizvod(oduzmiVektor(tacke[2], tacke[3]), oduzmiVektor(tacke[1], tacke[3])) &&
            skalarniProizvod(oduzmiVektor(tacke[0], tacke[1]), oduzmiVektor(tacke[3], tacke[1])) ==
            skalarniProizvod(oduzmiVektor(tacke[3], tacke[2]), oduzmiVektor(tacke[0], tacke[2]))) {
                cout << "DA\n";
                pronadjen = true;
                break;
            }
    }
    if(!pronadjen)
        cout << "NE\n";
    return 0;
}