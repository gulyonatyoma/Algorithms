// #include <bits/stdc++.h>
// using namespace std;


// int main() {
//     stack<pair<long long, long long>> stck;
//     stack<long long> popstck;
//     long long n, t, ans;
//     ans = 0;
//     cin >> n;
//     for (long long i = 0; i < n; ++i) {
//         cin >> t;
//         if (stck.empty()) {
//             stck.push({t, 1});
//         } else {
//             if (t == stck.top().first) {
//                 stck.push({t, stck.top().second + 1});
//             } else {
//                 if (stck.top().second >= 3) {
//                     long long iterations = stck.top().second;
//                     ans += iterations;
//                     for (long long j = 0; j < iterations; ++j) {
//                         stck.pop();
//                     }
//                 }
//                 stck.push({t, 1});
//             }
//         }
//     }
//     cout << ans;
//     return 0;
// }


#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> balls(n);
    for (int i = 0; i < n; i++) {
        cin >> balls[i];
    }
    int ans = 0;
    balls.push_back(100);
    vector<pair<int, int>> lens;
    lens.push_back({balls[0], 1});
    for (int i = 1; i < balls.size(); i++) {
        if (lens.empty()) {
            lens.push_back({balls[i], 1});
        } else {
            if (balls[i] == lens.back().first) {
                lens.push_back({balls[i], lens.back().second + 1});
            } else {
                if (lens.back().second >= 3) {
                    ans += lens.back().second;
                    const int q = lens.back().second;
                    for (int j = 0; j < q; j++) {
                        lens.pop_back();
                    }
                    if (lens.empty()) {
                        lens.push_back({balls[i], 1});
                    } else {
                        if (balls[i] == lens.back().first) {
                            lens.push_back({balls[i], lens.back().second + 1});
                        } else {
                            lens.push_back({balls[i], 1});
                        }
                    }
                } else {
                    lens.push_back({balls[i], 1});
                }
            }
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}