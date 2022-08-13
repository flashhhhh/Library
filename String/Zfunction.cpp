vector<int> zfunc(string s) {
    int n = s.size();
    vector<int> z(n);

    z[0] = n;
    for (int i=1,l=0,r=0;i<n;++i) {
        if (i <= r) z[i] = min(r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];

        if (i+z[i]-1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

// z[i]: LCP(s[0..n-1], s[i..n-1])
//
// Link: https://judge.yosupo.jp/problem/zalgorithm
