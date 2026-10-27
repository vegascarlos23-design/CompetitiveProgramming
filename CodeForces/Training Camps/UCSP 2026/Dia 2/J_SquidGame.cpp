#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<ll>> cap(n, vector<ll>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) cin >> cap[i][j];
    }

    // nextRoom[f][u] = máscara de habitaciones en piso f+1 alcanzables desde u en piso f
    vector<vector<int>> nextRoom(max(0, n - 1), vector<int>(k, 0));
    for (int i = 0; i < m; i++) {
        int f, u, v;
        cin >> f >> u >> v;
        f--; u--; v--;
        nextRoom[f][u] |= (1 << v);
    }

    int SZ = 1 << k;
    const ll INF = (1LL << 62);

    // Precalcular lowbit y prevMask para cada máscara
    vector<int> lowbit(SZ), prevMask(SZ);
    for (int mask = 1; mask < SZ; mask++) {
        for (int b = 0; b < k; b++) {
            if (mask & (1 << b)) {
                lowbit[mask] = b;
                prevMask[mask] = mask ^ (1 << b);
                break;
            }
        }
    }

    vector<ll> dp(SZ, INF), ndp(SZ), best(SZ), total(SZ);
    dp[SZ - 1] = 0; // inicialmente todas las habitaciones del piso 1 están en el lado de la fuente

    for (int floor = 0; floor < n; floor++) {
        // total[mask] = suma de capacidades de las habitaciones en mask en este piso
        total[0] = 0;
        for (int mask = 1; mask < SZ; mask++) {
            int b = lowbit[mask];
            total[mask] = total[prevMask[mask]] + cap[floor][b];
        }

        // g[mask] = dp[mask] + total[mask]
        for (int mask = 0; mask < SZ; mask++) {
            if (dp[mask] >= INF / 2) best[mask] = INF;
            else best[mask] = dp[mask] + total[mask];
        }

        // SOS DP: best[mask] = min_{superconjunto A de mask} (dp[A] + total[A])
        for (int bit = 0; bit < k; bit++) {
            int step = 1 << bit;
            for (int base = 0; base < SZ; base += step << 1) {
                for (int off = 0; off < step; off++) {
                    int mask = base + off;
                    if (best[mask + step] < best[mask]) {
                        best[mask] = best[mask + step];
                    }
                }
            }
        }

        // Respuesta para este turno: best[0] = min_A (dp[A] + total[A])
        if (floor) cout << ' ';
        cout << best[0];

        if (floor == n - 1) break;

        // Calcular reach[mask] para este piso: unión de nextRoom[floor][room] para cada room en mask
        vector<int> reach(SZ);
        reach[0] = 0;
        for (int mask = 1; mask < SZ; mask++) {
            int b = lowbit[mask];
            reach[mask] = reach[prevMask[mask]] | nextRoom[floor][b];
        }

        // Transición al siguiente piso
        fill(ndp.begin(), ndp.end(), INF);
        for (int B = 0; B < SZ; B++) {
            if (best[B] >= INF / 2) continue;
            ll cost = best[B] - total[B]; // dp[A] + total[A] - total[B] con A superconjunto de B
            int nxtMask = reach[B];
            if (cost < ndp[nxtMask]) ndp[nxtMask] = cost;
        }
        dp.swap(ndp);
    }

    cout << '\n';
    return 0;
}