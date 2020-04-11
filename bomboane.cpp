#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;


class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n, m;
    vector<int> left, right;
    // dp[i][j] reprezinta in cate moduri
    // poti da j bomboane la primii i copii
    long long dp[2005][2005];
    void read_input() {
        ifstream f("bomboane.in");
        f >> n >> m;
        left.resize(n + 1, 0);
        right.resize(n + 1, 0);
        // pentru fiecare elev citesc intervalul
        // de probleme
        int i = 1;
            while (i <= n) {
                f >> left[i] >> right[i];
                i++;
            }
    }
    void print_output(int result) {
    ofstream g("bomboane.out");
    g << result;
    g.close();
    }

    int get_result() {
    int modk = 1e9 + 7;
    // iau cazul de baza
    dp[0][0] = 1LL;
        // iau fiecare copil
        for (int i = 1; i <= n; i++) {
            // iau j bomboane
            for (int j = 1; j <= m ; j++) {
                int ok = 1;
                int p = left[i];
                // primii i copii iau atatea bomboane
                // in atatea moduri ca primii i-1
                while (p <= right[i] && ok == 1) {
                    // j-ul este in intervalul specific
                    // fiecarui copil
                    if ( j >= p ) {
                        dp[i][j] = dp[i-1][j-p] + dp[i][j];
                        dp[i][j] =  dp[i][j] % modk;
                    } else {
                    ok = 0;
                    }
                p++;
                }
            }
        }
    return dp[n][m];
    }
};
int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
