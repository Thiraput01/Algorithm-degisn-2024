#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mod_mat(vector<vector<int>> v, int k) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            v[i][j] %= k;
        }
    }
    return v;
}

vector<vector<int>> mul_mat(vector<vector<int>> &v1, vector<vector<int>> v2) {
    vector<vector<int>> res(2, vector<int>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                res[i][j] += v1[i][k] * v2[k][j];
            }
        }
    }
    return res;
}

vector<vector<int>> perform(vector<vector<int>> &v, int n, int k) {
    if (n == 1)
        return mod_mat(v, k);
    if (n % 2 == 0) {
        vector<vector<int>> tmp = perform(v, n / 2, k);
        vector<vector<int>> tmp_mul = mul_mat(tmp, tmp);
        return mod_mat(tmp_mul, k);
    } else {
        vector<vector<int>> tmp = perform(v, n / 2, k);
        vector<vector<int>> tmp1 = mul_mat(tmp, tmp);
        vector<vector<int>> tmp2 = mul_mat(tmp1, mod_mat(v, k)); // Store the result
        return mod_mat(tmp2, k);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> v(2, vector<int>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> result = perform(v, n, k);

    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
    }

    return 0;
}
