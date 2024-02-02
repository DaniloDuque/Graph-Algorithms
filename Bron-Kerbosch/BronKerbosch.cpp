#include <bits/stdc++.h>
using namespace std;


#define int unsigned long long
#define SET(msk, i) ((msk)|(1ULL << (i)))
#define TEST(msk, i) ((msk)&(1ULL << (i)))
#define CLEAR(msk, i) ((msk)&~(1ULL << (i)))
#define vi vector<int>
#define vvi vector<vi>


vvi G;
int n, m, v1, v2;




int intersection(int C, vi &N) {
    int auxSet = 0;
    for (int i : N)
        auxSet = SET(auxSet, i);
    return C & auxSet;
}

int countBits(int n) {
    int c = 0;
    while (n) {
        c += n & 1; n >>= 1;
    }return c;
}

int pivot(int &P, int &X){
    for(int i = 0; i<n; i++) if(TEST(P|X, i)) return i;
    return -1;
}



int maximumClique(int R, int P, int X){

    if (!(P | X)) return countBits(R);

    int max = 1, inter = intersection(P, G[pivot(P, X)]);

    for (int i = 0; i < n; i++)

        if (TEST(P, i) && !TEST(inter, i)){
            max = std::max(max, maximumClique(SET(R, i), intersection(P, G[i]), intersection(X, G[i])));
            P = CLEAR(P, i);
            X = SET(X, i);
        }
    
    return max;

}

signed main(){

    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>m;
    G.assign(n, {});
    while (m--){

        cin >> v1 >> v2;
        G[v1].push_back(v2);
        G[v2].push_back(v1);

    }cout << maximumClique(0, (1ULL << n) - 1, 0) << '\n';
    return 0;

}
