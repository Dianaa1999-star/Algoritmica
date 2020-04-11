#include <bits/stdc++.h>
#include <vector>
#include <fstream>
using namespace std;

const int mod = 1e9 + 7;


class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n, m;
    long long nr2 = 2;
    long long nr = 1;
    vector<int> dist;
    long** dp;
    // citesc datele de la tastatura
    void read_input() {
        ifstream f("bani.in");
        ios_base::sync_with_stdio(false);
        f.tie(NULL);
        f >> m >> n;
    }


  void print_output(long long result) {
    ofstream g("bani.out");
    g << result;
    g.close();
    }

    long long get_result() {
    // verific daca este setul de instructiuni 1
        if (m == 1) {
            long long copy = n;
            copy--;
            // ridic la puterea 2 la n - 1
            for (int j = copy; j > 0; j = j / 2) {
                if (j % 2 == 1) {
                    nr = (nr * nr2) % mod;
                }
                nr2 = (nr2 * nr2) % mod;
            }
            // aplic formula 5 * (2 ^ (n - 1))
            return (5 * nr) % mod;
        } else if (m == 2) {
            // dp[i][j] reprezinta numarul de modalitati de a aseza bacnotele
            // cand avem i bacnote si j reprezinta ultimul tip de bacnote pus
                dp = new long*[n + 1];
                    for (int i = 0; i < n + 1; ++i)
                        dp[i] = new long[6];
                // Calculez pentru cazul de baza. In functie de bacnota ,
                // in cazul d,exista 3 posibile alegeri valide
                    for (int i = 1; i <= 5; i++) {
                        if (i == 4) {
                            dp[2][i] = 3;
                        } else {
                            dp[2][i] = 2;
                        }
                    }
                    // pentru fiecare bacnota
                    for (int i = 3 ; i <= n ; ++i) {
                        for (int j = 1 ; j <= 5 ; ++j) {
                            // dp[i][j] va fi generat de multimea
                            // alegerilor de la pasul anterior
                            switch (j) {
                                case 1: {
                                    int prev = i;
                                    prev--;
                                    dp[i][j] = dp[prev][2] + dp[prev][3];
                                    dp[i][j] = dp[i][j] % mod;
                                    break;
                                }
                                case 2: {
                                    int prev = i;
                                    prev--;
                                    dp[i][j] =  dp[prev][4] + dp[prev][1];
                                    dp[i][j] = dp[i][j] % mod;
                                    break;
                                }
                                case 3: {
                                    int prev = i;
                                    prev--;
                                    dp[i][j] = dp[prev][3] + dp[prev][1];
                                    dp[i][j] = dp[i][j] % mod;
                                    break;
                                }
                                case 4: {
                                    int prev = i;
                                    prev--;
                                    dp[i][j] =  dp[prev][3]
                                    + dp[prev][2] + dp[prev][5];
                                    dp[i][j] = dp[i][j] % mod;
                                    break;
                                }
                                case 5: {
                                    int prev = i;
                                    prev--;
                                    dp[i][j] = dp[prev][1] + dp[prev][4];
                                    dp[i][j] = dp[i][j] % mod;
                                    break;
                                }
                            }
                        }
                    }
                // solutia e data de suma ultimelor posibilitati din matricea dp
                long sum = 0;
                int x = 1;
                    while (x <= 5) {
                        sum = (sum + dp[n][x]) % mod;
                        x++;
                    }
                return sum;
        }
    return 0;
    }
};
int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
