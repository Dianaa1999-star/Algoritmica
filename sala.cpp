#include <bits/stdc++.h>
#include <set>
#include <fstream>
#include <algorithm>
using namespace std;

const int maxim = 1e6 + 5;
class Task {
 public:
    pair <int, int> myvector[maxim];
    long long mysum;
    multiset <int> v;
    long long res;
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n, m;
    void read_input() {
        ifstream f("sala.in");
        ios_base::sync_with_stdio(false);
        f.tie(NULL);
        f >> n >> m;
        int i = 1;
        // retin greutatea si numarul de repetari per gantera
        while (i <= n) {
            f >> myvector[i].first >> myvector[i].second;
            i++;
        }
    }

  void print_output(long long  result) {
    ofstream g("sala.out");
    g << result;
    g.close();
    }

    long long get_result() {
    // sortez in ordine descrescatoare vectorul cu toate ganterele
    sort(myvector + 1, myvector + n + 1, greater<pair <int, int> >());
    // iau fiecare gantera
    int i = 1;
        while (i <= n) {
            //  rezultatul va fi maximul dupa formula numarTotalRepetari
            // ∗ greutateaCeleiMaiUsoareGantereFolosite
            res = max(res, myvector[i].first * 1LL *
            (myvector[i].second + mysum));
             switch ((int)v.size() < m - 1) {
                case 1: {
                // adaug la numarul total de repetari
                mysum = mysum + 1LL * myvector[i].second;
                v.insert(myvector[i].second);
                i++;
                }
                break;
                case 0: {
                // verific daca gasesc o varianta mai buna de a alege
                // numarul maxim de repetari si updatez alegerea
                // ganterelor, recalculand numarul total de repetari
                    if (myvector[i].second > *v.begin()) {
                         mysum = mysum - 1LL * *v.begin();
                         mysum = mysum + 1LL * myvector[i].second;
                         v.erase(v.begin());
                         v.insert(myvector[i].second);
                    }
                i++;
                }
                break;
            }
        }
    return res;
    }
};
int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
