struct Tree {
    int n;
    vector<int> h;
    vector<vector<int> > jump;
    vector<vector<pii> > ke;

    void init(int n1) {
        n = n1;
        h.resize(n); ke.resize(n);

        jump.resize((int)log2(n)+1);
        for (int j=0;j<=(int)log2(n);++j) jump[j].resize(n);
    }

    void add_edge(int u,int v,int w) {
        ke[u].pb(w,v); ke[v].pb(w,u);
    }

    void build(int u,int cha) {
        if (cha == -1) jump[u][0] = -1;

        for (auto [w,v]:ke[u]) {
            if (v == cha) continue;

            h[v] = h[u] + 1; jump[0][v] = u;
            build(v,u);
        }
    }

    void dp() {
        for (int j=1;j<=(int)log2(n);++j)
            for (int i=0;i<n;++i) jump[j][i] = (jump[j-1][i] == -1) ? -1 : jump[j-1][jump[j-1][i]];
    }

    int lca(int x,int y) {
        if (h[x] < h[y]) swap(x,y);

        for (int k=(int)log2(n);k>=0;--k)
            if (h[x] - (1<<k) >= h[y]) {
                x = jump[k][x];
            }

        if (x == y) return x;

        for (int k=log2(n);k>=0;--k)
            if (jump[k][x] != jump[k][y]) {
                x = jump[k][x];
                y = jump[k][y];
            }

        return jump[0][x];
    }
};

//  jump[k][i]: parent 2^j of node i.
    h[i]: depth of node i.
