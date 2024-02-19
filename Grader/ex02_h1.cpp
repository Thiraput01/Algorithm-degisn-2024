#include <bits/stdc++.h>

using namespace std;

int distance(const pair<int, int>& m, const pair<int, int>& n) {
    return (m.first - n.first) * (m.first - n.first) + (m.second - n.second) * (m.second - n.second);
}

int closestPairUtil(vector<pair<int, int>>& sortx, vector<pair<int, int>>& sorty) {
    if (sortx.size() == 1) return INT_MAX;
    if (sortx.size() == 2) return distance(sortx[0], sortx[1]);

    int mid = sortx.size() / 2;

    vector<pair<int, int>> leftx(sortx.begin(), sortx.begin() + mid + 1);
    vector<pair<int, int>> lefty;
    for (auto& p : leftx) lefty.push_back({p.second, p.first});
    sort(lefty.begin(), lefty.end());

    vector<pair<int, int>> rightx(sortx.begin() + mid + 1, sortx.end());
    vector<pair<int, int>> righty;
    for (auto& p : rightx) righty.push_back({p.second, p.first});
    sort(righty.begin(), righty.end());

    int m_dist = min(closestPairUtil(leftx, lefty), closestPairUtil(rightx, righty));

    int l_bound = sortx[mid].first - m_dist;
    int u_bound = sortx[mid].first + m_dist;

    for (auto& i : leftx) {
        if (l_bound < i.first && i.first < u_bound) {
            for (auto& j : righty) {
                if (l_bound < j.second && j.second < u_bound && i != j) {
                    m_dist = min(m_dist, distance(i, {j.second, j.first}));
                }
            }
        }
    }

    return m_dist;
}

int closestPair(vector<pair<int, int>>& points) {
    vector<pair<int, int>> sortx = points;
    vector<pair<int, int>> sorty = points;
    sort(sortx.begin(), sortx.end());
    sort(sorty.begin(), sorty.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    return closestPairUtil(sortx, sorty);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    cout << closestPair(points) << endl;

    return 0;
}
