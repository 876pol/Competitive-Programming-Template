#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * MATH
 */

/**
 * Returns GCD (greatest common divisor)
 *
 * @param a, b one number to find GCD of.
 * @returns GCD of `a` and `b`.
 */
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }

/**
 * Returns LCM (least common multiple)
 *
 * @param a, b one number to find LCM of.
 * @returns LCM of `a` and `b`.
 */
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

/**
 * Returns nCr (n choose r)
 *
 * @param n first number of nCr.
 * @param r second number of nCr.
 * @returns nCr of `n` and `r`.
 */
ll ncr(ll n, ll r) {
    if (r > n - r) r = n - r;
    ll C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]);
    return C[r];
}

/**
 * Returns nCr % p (n choose r mod p)
 *
 * @param n first number of nCr.
 * @param r second number of nCr.
 * @param p modulus value.
 * @returns nCr mod p of `n`, `r`, and `p`.
 */
ll ncrmodp(ll n, ll r, ll p) {
    if (r > n - r) r = n - r;
    ll C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
    return C[r];
}
/**
 * Returns x ^ y (x to the power of y)
 *
 * @param x the base.
 * @param y the exponent.
 * @returns x ^ y of `x` and `y`.
 */
ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = res * x;
        y = y >> 1;
        x = x * x;
    }
}
/**
 * Returns x ^ y % p (x to the power of y mod p)
 *
 * @param x the base.
 * @param y the exponent.
 * @param p modulus value.
 * @returns x ^ y % p of `x`, `y`, and `p`.
 */
ll powermod(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

/**
 * Checks if an integer is prime
 *
 * @param a number to check.
 * @returns true if it's prime else false.
 */
bool is_prime(ll n) {
    if (n == 1) return 0;
    for (ll i = 2; i <= round(sqrt(n)); ++i)
        if (n % i == 0) return 0;
    return 1;
}

/**
 * Generates all primes numbers up to integer
 *
 * @param n runs sieve up to integer n.
 * @returns a boolean array where the value at index `i` is `true` if the number
 * is prime.
 */
vector<bool> sieve_of_eratosthenes(ll n) {
    vector<bool> prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p])
            for (ll i = p * p; i <= n; i += p) prime[i] = false;
    }
    return prime;
}

/**
 * Big Integer class
 */
struct BigInt {
    int sign;
    string s;

    BigInt() {}
    BigInt(string x) { *this = x; }
    BigInt(ll x) { *this = to_string(x); }

    BigInt negative() {
        BigInt x = *this;
        x.sign *= -1;
        return x;
    }

    BigInt normalize(int newSign) {
        for (int a = s.size() - 1; a > 0 && s[a] == '0'; a--)
            s.erase(s.begin() + a);
        sign = (s.size() == 1 && s[0] == '0' ? 1 : newSign);
        return *this;
    }

    void operator=(string x) {
        int newSign = (x[0] == '-' ? -1 : 1);
        s = (newSign == -1 ? x.substr(1) : x);
        reverse(s.begin(), s.end());
        this->normalize(newSign);
    }

    bool operator==(const BigInt &x) { return (s == x.s && sign == x.sign); }

    bool operator<(const BigInt &x) {
        if (sign != x.sign) return sign < x.sign;
        if (s.size() != x.s.size())
            return (sign == 1 ? s.size() < x.s.size() : s.size() > x.s.size());
        for (int a = s.size() - 1; a >= 0; a--)
            if (s[a] != x.s[a])
                return (sign == 1 ? s[a] < x.s[a] : s[a] > x.s[a]);
        return false;
    }

    bool operator<=(const BigInt &x) { return (*this < x || *this == x); }

    bool operator>(const BigInt &x) { return (!(*this < x) && !(*this == x)); }

    bool operator>=(const BigInt &x) { return (*this > x || *this == x); }

    BigInt operator+(BigInt x) {
        BigInt curr = *this;
        if (curr.sign != x.sign) return curr - x.negative();
        BigInt res;
        for (int a = 0, carry = 0; a < s.size() || a < x.s.size() || carry;
             a++) {
            carry += (a < curr.s.size() ? curr.s[a] - '0' : 0) +
                     (a < x.s.size() ? x.s[a] - '0' : 0);
            res.s += (carry % 10 + '0');
            carry /= 10;
        }
        return res.normalize(sign);
    }

    BigInt operator-(BigInt x) {
        BigInt curr = *this;
        if (curr.sign != x.sign) return curr + x.negative();
        int realSign = curr.sign;
        curr.sign = x.sign = 1;
        if (curr < x) return ((x - curr).negative()).normalize(-realSign);
        BigInt res;
        for (int a = 0, borrow = 0; a < s.size(); a++) {
            borrow = (curr.s[a] - borrow - (a < x.s.size() ? x.s[a] : '0'));
            res.s += (borrow >= 0 ? borrow + '0' : borrow + '0' + 10);
            borrow = (borrow >= 0 ? 0 : 1);
        }
        return res.normalize(realSign);
    }

    BigInt operator*(BigInt x) {
        BigInt res("0");
        for (int a = 0, b = s[a] - '0'; a < s.size(); a++, b = s[a] - '0') {
            while (b--) res = (res + x);
            x.s.insert(x.s.begin(), '0');
        }
        return res.normalize(sign * x.sign);
    }

    BigInt operator/(BigInt x) {
        if (x.s.size() == 1 && x.s[0] == '0') x.s[0] /= (x.s[0] - '0');
        BigInt temp("0"), res;
        for (int a = 0; a < s.size(); a++) res.s += "0";
        int newSign = sign * x.sign;
        x.sign = 1;
        for (int a = s.size() - 1; a >= 0; a--) {
            temp.s.insert(temp.s.begin(), '0');
            temp = temp + s.substr(a, 1);
            while (!(temp < x)) {
                temp = temp - x;
                res.s[a]++;
            }
        }
        return res.normalize(newSign);
    }

    BigInt operator%(BigInt x) {
        if (x.s.size() == 1 && x.s[0] == '0') x.s[0] /= (x.s[0] - '0');
        BigInt res("0");
        x.sign = 1;
        for (int a = s.size() - 1; a >= 0; a--) {
            res.s.insert(res.s.begin(), '0');
            res = res + s.substr(a, 1);
            while (!(res < x)) res = res - x;
        }
        return res.normalize(sign);
    }

    string toString() {
        string ret = s;
        reverse(ret.begin(), ret.end());
        return (sign == -1 ? "-" : "") + ret;
    }
};

/**
 * QUERIES
 */

/**
 * Performs binary search
 *
 * @param arr sorted array to search through.
 * @param x element to search for.
 * @returns true if element is in array.
 */
bool binary_search(vector<ll> &arr, ll x) {
    ll a = 0, b = arr.size() - 1;
    while (a <= b) {
        ll k = (a + b) / 2;
        if (arr[k] == x) {
            return true;
        }
        if (arr[k] > x)
            b = k - 1;
        else
            a = k + 1;
    }
    return false;
}

/**
 * Sparse Table class for static RMQ (range minimum query)
 *
 * @tparam T class for Sparse Table to contain.
 * @tparam F function that takes two arguments of type `T` and returns `T`.
 */
template <class T, T (*F)(T, T)>
struct sparse_table {
    vector<vector<T>> table;

    /**
     * Class Constructor
     *
     * @param a array to build the Sparse Table from.
     */
    sparse_table(vector<T> a) {
        ll n = a.size() + 1;
        ll h = ceil(log2(n));
        table = vector<vector<T>>(h, vector<T>(n));
        for (ll i = 0; i < n; i++) table[0][i] = a[i];
        for (ll i = 1; i < h; i++) {
            for (ll j = 0; j + (1 << i) <= n; j++) {
                table[i][j] =
                    F(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    /**
     * Query array in range
     *
     * @param l, r range [l, r) to query.
     * @returns answer to the query.
     */
    T query(ll l, ll r) {
        if (r - l == 0) return T();
        ll p = 31 - __builtin_clz(r - l);
        return F(table[p][l], table[p][r - (1 << p)]);
    }
};

/**
 * Binary Indexed Tree / Fenwick Tree class
 *
 * @tparam T class for the Binary Indexed Tree to contain.
 * @tparam F function that takes two arguments of type `T` and returns `T`.
 */
template <class T, T (*F)(T, T)>
struct binary_indexed_tree {
    vector<T> bit;
    vector<T> array;
    ll size;

    /**
     * Class Constructor
     *
     * @param a array to build the Binary Indexed Tree from.
     */
    binary_indexed_tree(vector<T> a) {
        size = a.size() + 1;
        bit.assign(size, 0);
        array.assign(size, 0);
        for (size_t i = 0; i < a.size(); i++) update(i, a[i]);
    }

    /**
     * Query array in range starting from 0
     *
     * @param r returns query in range [0, r].
     * @returns answer to the query.
     */
    T query(ll r) {
        T ret = 0;
        for (++r; r > 0; r -= r & -r) ret = F(ret, bit[r]);
        return ret;
    }

    /**
     * Query array in range
     *
     * @param l, r returns query in range [l, r].
     * @returns answer to the query.
     */
    T query(ll l, ll r) { return query(r) - query(l - 1); }

    /**
     * Update value in array
     *
     * @param idx index of array to change.
     * @param delta amount to change.
     */
    void update(ll idx, T delta) {
        array[idx] = F(array[idx], delta);
        for (++idx; idx < size; idx += idx & -idx)
            bit[idx] = F(bit[idx], delta);
    }
};
/**
 * Segment Tree class
 *
 * @tparam T class for the Segment Tree to contain.
 * @tparam F function that takes two arguments of type `T` and returns `T`.
 */
template <class T, T (*F)(T, T)>
struct segment_tree {
    ll n;
    vector<T> tree;

    /**
     * Class Constructor
     *
     * @param arr array to build the Segment Tree from.
     */
    segment_tree(vector<T> &arr) {
        n = arr.size();
        tree.resize(2 * n);
        if (!n) return;
        copy(arr.begin(), arr.end(), tree.begin() + n);
        for (ll i = n - 1; i > 0; --i)
            tree[i] = F(tree[i << 1], tree[i << 1 | 1]);
    }

    /**
     * Update value in array
     *
     * @param index index of array to change.
     * @param value new value for index.
     */
    void update(ll index, T &value) {
        tree[index += n] = value;
        for (; index > 1; index >>= 1)
            tree[index >> 1] = F(tree[index], tree[index ^ 1]);
    }

    /**
     * Query array in range
     *
     * @param l, r returns query in range [l, r).
     * @returns answer to the query.
     */
    T query(ll l, ll r) {
        T ans = (*this)[l++];
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if ((l & 1) != 0) ans = F(ans, tree[l++]);
            if ((r & 1) != 0) ans = F(ans, tree[--r]);
        }
        return ans;
    }

    /**
     * Accesses the specified element
     *
     * @param pos index of the elemnt to return
     * @returns value of element
     */
    T operator[](ll pos) { return tree[n + pos]; }

    /**
     * Gets size of segment tree
     *
     * @returns size of segment tree.
     */
    ll size() { return n; }
};

/**
 * GRAPHS AND TREES
 */

/**
 * DSU (disjointed set union) class
 */
struct DSU {
    vector<ll> parent;
    vector<ll> rank;
    ll size;

    /**
     * Class Constructor
     *
     * @param size size of DSU.
     */
    DSU(ll size) {
        this->parent.resize(size);
        this->rank.resize(size);
        for (ll i = 0; i < size; i++) this->parent[i] = i;
        this->size = size;
    }

    /**
     * Finds the root of an element
     *
     * @param node element to find root of.
     * @returns root of element.
     */
    ll find(ll node) {
        if (this->parent[node] != node)
            this->parent[node] = find(this->parent[node]);
        return this->parent[node];
    }

    /**
     * Creates union between two elements
     *
     * @param node1, node2 elements to unite.
     */
    void unify(ll node1, ll node2) {
        ll root1 = find(node1);
        ll root2 = find(node2);
        if (this->rank[root1] < this->rank[root2]) {
            this->parent[root1] = root2;
        } else if (this->rank[root1] > this->rank[root2]) {
            this->parent[root2] = root1;
        } else {
            this->parent[root2] = root1;
            this->rank[root1]++;
        }
    }
};

/**
 * Class to calculate the LCA of nodes in a tree
 */
struct LCA {
    ll n, l, root;
    vector<vector<ll>> adj;
    ll timer;
    vector<ll> tin, tout;
    vector<vector<ll>> up;

    LCA(vector<vector<ll>> &adj, ll root) {
        this->adj = vector<vector<ll>>(adj);
        n = adj.size();
        this->root = root;
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<ll>(l + 1));
        dfs(root, -1);
    }

    void dfs(ll v, ll p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (ll i = 1; i <= l; ++i) {
            if (up[v][i - 1] != -1)
                up[v][i] = up[up[v][i - 1]][i - 1];
            else
                up[v][i] = -1;
        }
        for (ll u : adj[v]) {
            if (u != p) dfs(u, v);
        }
        tout[v] = ++timer;
    }

    bool is_ancestor(ll u, ll v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    ll lca(ll u, ll v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (ll i = l; i >= 0; --i) {
            if (!is_ancestor((up[u][i] == -1 ? root : up[u][i]), v))
                u = (up[u][i] == -1 ? root : up[u][i]);
        }
        return (up[u][0] == -1 ? root : up[u][0]);
    }

    ll kth_ancestor(ll n, ll k) {
        ll boss = n;
        for (ll i = 0; i <= 63; i++)
            if (k & (1ll << i)) {
                if (boss == -1) return -1;
                boss = up[boss][i];
            }
        return boss;
    }
};

/**
 * Performs DFS recursively (depth-first search)
 *
 * @param graph adjacency list representation of a graph.
 * @param curr start node of search.
 * @param visited an empty array of booleans that gets filled with value
 * `true` if it's possible to reach a node from `start`.
 */
void diameter_util1(vector<vector<ll>> &graph, ll curr, vector<bool> &visited) {
    visited[curr] = true;
    for (ll sub : graph[curr]) {
        if (!visited[sub]) diameter_util1(graph, sub, visited);
    }
}

/**
 * Performs DFS (depth-first search)
 *
 * @param graph adjacency list representation of a graph.
 * @param start start node of search.
 * @returns an array of booleans with value `true` if it's possible to reach a
 * node from `start`.
 */
vector<bool> dfs(vector<vector<ll>> &graph, ll start) {
    stack<ll> stack;
    stack.push(start);
    vector<bool> visited(graph.size());
    while (!stack.empty()) {
        ll node = stack.top();
        stack.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (ll sub : graph[node]) stack.push(sub);
    }
    return visited;
}

/**
 * Performs BFS (breadth-first search)
 *
 * @param graph adjacency list representation of a graph.
 * @param start start node of search.
 * @returns the distance between `start` and `end` else `-1` if there is no
 * path.
 */
vector<ll> bfs(vector<vector<ll>> &graph, ll start) {
    queue<ll> queue;
    queue.push(start);
    vector<ll> distance(graph.size(), -1);
    ll dist = 0;
    while (!queue.empty()) {
        for (ll i = 0, t = queue.size(); i < t; i++) {
            ll node = queue.front();
            queue.pop();
            if (distance[node] != -1) continue;
            distance[node] = dist;
            for (ll sub : graph[node]) queue.push(sub);
        }
        dist++;
    }
    return distance;
}

/**
 * Performs Bellman-Ford's algorithm for shortest path
 *
 * @param edges edge list representation of a graph, where each edge is
 * represented by a `pair<pair<ll, ll>, ll>`, where the
 * first pair represents the start and end of an edge, and the second integer
 * represents the weight.
 * @param start start node of algorithm.
 * @param size number of nodes in the graph.
 * @returns an array of distances between `start` and every other node, else an
 * empty array if the graph contains a negative cycle.
 */
vector<ll> bellman_ford(vector<pair<pair<ll, ll>, ll>> &edges, ll start,
                        ll size) {
    vector<ll> distance(size, LLONG_MAX);
    distance[start] = 0;
    for (ll i = 0; i < size - 1; i++) {
        bool not_changed = true;
        for (auto edge : edges) {
            if (distance[edge.first.first] == LLONG_MAX) continue;
            if (distance[edge.first.first] + edge.second <
                distance[edge.first.second]) {
                distance[edge.first.second] =
                    distance[edge.first.first] + edge.second;
                not_changed = false;
            }
        }
        if (not_changed) return distance;
    }
    for (auto edge : edges) {
        if (distance[edge.first.first] == LLONG_MAX) continue;
        if (distance[edge.first.first] + edge.second <
            distance[edge.first.second]) {
            return vector<ll>();
        }
    }
    return distance;
}

/**
 * Performs Dijkstra's algorithm
 *
 * @param graph adjacency list representation of a graph where each edge is
 * represented as a `pair<ll, ll>`, where the first pair is the
 * weight and the second pair is the destination.
 * @param start start node of search.
 * @returns an array of distances between `start` and every other node.
 */
vector<ll> dijkstra(vector<vector<pair<ll, ll>>> &graph, ll start) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        queue;
    vector<ll> distance(graph.size(), LLONG_MAX);
    vector<bool> visited(graph.size());
    distance[start] = 0;
    queue.push(make_pair(0, start));
    while (!queue.empty()) {
        ll a = queue.top().second;
        queue.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto u : graph[a]) {
            ll w = u.first, b = u.second;
            if (distance[a] != LLONG_MAX && distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                queue.push(make_pair(distance[b], b));
            }
        }
    }
    return distance;
}
/**
 * Performs Floyd-Warshall's algorithm
 *
 * @param matrix adjacency matrix representation of a graph.
 * @returns a distance matrix.
 */
vector<vector<ll>> floyd_warshall(vector<vector<ll>> &matrix) {
    ll n = matrix.size();
    vector<vector<ll>> distance(matrix);
    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (distance[i][k] != LLONG_MAX &&
                    distance[k][j] != LLONG_MAX) {
                    distance[i][j] =
                        min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }
    return distance;
}

/**
 * Performs Kruskal's algorithm
 *
 * @param edges edge list representation of a graph, where each edge is
 * represented by a `pair<ll, pair<ll, ll>>`, where the first integer represents
 * the weight and the second pair represents the start and end of an edge.
 * @param size the number of nodes in the graph.
 * @returns an edge list representing the minimum spanning tree.
 */
vector<pair<ll, pair<ll, ll>>> kruskal(vector<pair<ll, pair<ll, ll>>> edges,
                                       ll size) {
    DSU dsu(size);
    sort(edges.begin(), edges.end());
    vector<pair<ll, pair<ll, ll>>> mst;
    for (ll i = 0; i < edges.size(); i++) {
        if (dsu.find(edges[i].second.first) !=
            dsu.find(edges[i].second.second)) {
            dsu.unify(edges[i].second.first, edges[i].second.second);
            mst.push_back(edges[i]);
        }
    }
    return mst;
}

/**
 * Performs Topological Sort with Kahn's Algorithm
 *
 * @param graph adjacency list representation of a graph.
 * @returns the topological sorting of `graph`.
 */
vector<ll> kahn(vector<vector<ll>> &graph) {
    ll n = graph.size();
    vector<ll> in_degree(n, 0);
    for (ll u = 0; u < n; u++) {
        for (auto itr = graph[u].begin(); itr != graph[u].end(); itr++)
            in_degree[*itr]++;
    }
    queue<ll> q;
    for (ll i = 0; i < n; i++)
        if (in_degree[i] == 0) q.push(i);
    ll cnt = 0;
    vector<ll> top_order;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        top_order.push_back(u);
        for (auto itr = graph[u].begin(); itr != graph[u].end(); itr++)
            if (--in_degree[*itr] == 0) q.push(*itr);
        cnt++;
    }
    if (cnt != n) {
        return vector<ll>();
    }
    return top_order;
}

/**
 * Utility function for `vector<ll> find_cycle_undirected`
 */
bool find_cycle_undirected_util(int v, int par, vector<bool> &visited,
                                vector<ll> &parent, vector<vector<ll>> &graph,
                                ll &cycle_start, ll &cycle_end) {
    visited[v] = true;
    for (ll u : graph[v]) {
        if (u == par) continue;
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (find_cycle_undirected_util(u, parent[u], visited, parent, graph,
                                       cycle_start, cycle_end))
            return true;
    }
    return false;
}

/**
 * Finds a cycle in an undirected graph with dfs
 *
 * @param graph adjacency list representation of a graph.
 * @returns the nodes that make up a cycle or an empty array if there is no
 * negative cycle.
 */
vector<ll> find_cycle_undirected(vector<vector<ll>> &graph) {
    vector<bool> visited(graph.size());
    vector<ll> parent(graph.size(), -1);
    ll cycle_start = -1, cycle_end = 0;
    for (ll v = 0; v < graph.size(); v++) {
        if (!visited[v] &&
            find_cycle_undirected_util(v, parent[v], visited, parent, graph,
                                       cycle_start, cycle_end))
            break;
    }
    if (cycle_start == -1) {
        return vector<ll>();
    } else {
        cout << cycle_start << endl;
        vector<ll> cycle;
        cycle.push_back(cycle_start);
        for (ll v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        return cycle;
    }
}

/**
 * Utility function for `vector<ll> find_cycle_directed`
 */
bool find_cycle_directed_util(ll v, vector<ll> &color, vector<ll> &parent,
                              vector<vector<ll>> &graph, ll &cycle_start,
                              ll &cycle_end) {
    color[v] = 1;
    for (ll u : graph[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (find_cycle_directed_util(u, color, parent, graph, cycle_start,
                                         cycle_end))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

/**
 * Finds a cycle in an directed graph with dfs
 *
 * @param graph adjacency list representation of a graph.
 * @returns the nodes that make up a cycle or an empty array if there is no
 * negative cycle.
 */
vector<ll> find_cycle_directed(vector<vector<ll>> &graph) {
    ll n = graph.size();
    vector<ll> color(n);
    vector<ll> parent(n, -1);
    ll cycle_start = -1, cycle_end;
    for (ll v = 0; v < n; v++) {
        if (color[v] == 0 && find_cycle_directed_util(v, color, parent, graph,
                                                      cycle_start, cycle_end))
            break;
    }
    if (cycle_start == -1) {
        return vector<ll>();
    } else {
        vector<ll> cycle;
        cycle.push_back(cycle_start);
        for (ll v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        return cycle;
    }
}

/**
 * Utility function for `ll diameter`
 */
pair<ll, ll> all_longest_paths_util1(ll curr, vector<vector<ll>> &tree,
                                     vector<bool> &visited) {
    pair<ll, ll> depth = make_pair(0, curr);
    visited[curr] = true;
    for (ll sub : tree[curr]) {
        if (!visited[sub])
            depth = max(depth, all_longest_paths_util1(sub, tree, visited));
    }
    depth.first++;
    return depth;
}

/**
 * Finds the diameter of a tree with dfs
 *
 * @param tree adjacency list representation of a tree.
 * @returns the diameter of the tree.
 */
ll diameter(vector<vector<ll>> &tree) {
    vector<bool> visited(tree.size());
    pair<ll, ll> p = all_longest_paths_util1(1, tree, visited);
    fill(visited.begin(), visited.end(), 0);
    return all_longest_paths_util1(p.second, tree, visited).first - 1;
}

/**
 * Utility function for `vector<ll> all_longest_paths`
 */
pair<ll, ll> all_longest_paths_util1(ll curr, vector<vector<ll>> &tree,
                                     vector<bool> &visited) {
    pair<ll, ll> depth = make_pair(0, curr);
    visited[curr] = true;
    for (ll sub : tree[curr]) {
        if (!visited[sub])
            depth = max(depth, all_longest_paths_util1(sub, tree, visited));
    }
    depth.first++;
    return depth;
}

/**
 * Utility function for `vector<ll> all_longest_paths`
 */
void all_longest_paths_util2(vector<vector<ll>> &tree, ll curr,
                             vector<bool> &visited, vector<ll> &dists,
                             ll curr_dist) {
    visited[curr] = true;
    dists[curr] = curr_dist;
    for (ll sub : tree[curr]) {
        if (!visited[sub])
            all_longest_paths_util2(tree, sub, visited, dists, curr_dist + 1);
    }
}

/**
 * Finds the longest paths from all nodes in a tree.
 *
 * @param tree adjacency list representation of a tree.
 * @returns vector<ll> containing all longest paths in a tree.
 */
vector<ll> all_longest_paths(vector<vector<ll>> &tree) {
    vector<bool> visited(tree.size());
    pair<ll, ll> p = all_longest_paths_util1(1, tree, visited);
    ll a = p.second;
    fill(visited.begin(), visited.end(), 0);
    ll b = all_longest_paths_util1(p.second, tree, visited).second;
    vector<ll> dists1(tree.size()), dists2(tree.size());
    fill(visited.begin(), visited.end(), 0);
    all_longest_paths_util2(tree, a, visited, dists1, 0);
    fill(visited.begin(), visited.end(), 0);
    all_longest_paths_util2(tree, b, visited, dists2, 0);
    for (ll i = 0; i < dists1.size(); i++) {
        dists1[i] = max(dists1[i], dists2[i]);
    }
    return dists1;
}
