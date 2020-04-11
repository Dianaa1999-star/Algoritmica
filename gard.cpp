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
    static int comp(pair<int, int> &m, pair<int, int> &p) {
        if (m.first < p.first) {
            return 1;
        } else if (m.first == p.first && m.second > p.second) {
            return 1;
        } else {
            return 0;
    }
}

 private:
    int n, m, p;
    vector<pair<int, int> >gard;

    void read_input() {
    ifstream f("gard.in");
    f >> n;
    // citesc datele si retin coordonatele capetelor bucatilor
    // de gard ca pereche
    int copy = n;
    copy--;
        while (copy >= 0) {
            f >> m >> p;
            // adaug in vectorul ce reprezinta gardul datele citite
            gard.push_back(make_pair(m, p));
            copy--;
        }
    }
    void print_output(int result) {
    ofstream g("gard.out");
    g << result;
    g.close();
    }

    int get_result() {
    // sortez  crescator dupa capatul din stanga
    // daca sunt egale sortez descrescator dupa capatul din dreapta
    sort(gard.begin(), gard.end(), comp);
    // iau prima bucata din gard
    pair<int, int> first1 = gard[0];
    int result = 0;
    int i = 1;
        // cat timp nu am parcurs toate bucatile ce alcatuiesc gardul
        while (i < (int)gard.size()) {
            // verific ca bucata curenta are capatul din
            // dreapta mai mic ca bucata anterioara
            if (first1.second >= gard[i].second) {
                // daca capatul din stanga a bucatii curente
                // e mai mare decat cel al bucatii anterioare
                // inseamna ca am o bucata redundanta
                if (first1.first <= gard[i].first) {
                    result++;
                }
            }
            // verific daca trec la alt interval si updatez
            // bucata de gard luata ca referinta
            if (gard[i].second > first1.second) {
                first1 = gard[i];
            }
            i++;
        }
    return result;
    }
};
int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
