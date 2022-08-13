vector<int> manacher(const string& s){
    string t;
    for(auto& c:s){
        t.push_back(c);
        t.push_back('$');
    }
    t.pop_back();
    int n = t.size(); vector<int> m(n);

    for (int i=0,l=-1,r=-1;i<n;++i) {
        if (i <= r) m[i] = min(r-i, m[l+r-i]);
        while (i-m[i] >= 0 && i+m[i] < n && t[i-m[i]] == t[i+m[i]]) ++m[i];

        if (i+m[i] > r) l = i - m[i], r = i + m[i];
    }

    for (int i=0;i<n;++i)
        if (i&1) m[i] = (m[i]/2) * 2;
    else m[i] = (m[i]+1) /2 *2 -1;

    return m;
}

// m[i]: largest j such that t[(i-j)...(i+j)] is a palindrome.
//
// Link: https://judge.yosupo.jp/problem/enumerate_palindromes
