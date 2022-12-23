#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

vector<string> split_args(const string &s) {
    int f = 0, q = 0;
    vector<string> args = {""};
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == ',' && !q && !f) {
            args.push_back("");
            i++;
            continue;
        }
        args.back().push_back(s[i]);
        if (s[i] == '\\') {
            args.back().push_back(s[++i]);
            args.back().push_back(s[++i]);
        }
        if (s[i] == '\"') q = !q;
        if (s[i] == '(' && !q) f++;
        if (s[i] == ')' && !q) f--;
    }
    return args;
}

template <class K, class V>
ostream &operator<<(ostream &out, const pair<K, V> &obj) {
    return out << "(" << obj.first << ", " << obj.second << ")";
}

template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &out, const T &obj) {
    out << '[';
    for (auto it = obj.begin(); it != obj.end(); it++)
        out << &", "[2 * (it == obj.begin())] << *it;
    return out << ']';
}

template <class T>
ostream &operator<<(ostream &out, const queue<T> &obj) {
    queue<T> q(obj);
    vector<T> t;
    while (!q.empty()) t.push_back(q.front()), q.pop();
    return out << t;
}

template <class T>
ostream &operator<<(ostream &out, const stack<T> &obj) {
    stack<T> s(obj);
    vector<T> t;
    while (!s.empty()) t.push_back(s.top()), s.pop();
    reverse(t.begin(), t.end());
    return out << t;
}

template <class T, class S, class C>
ostream &operator<<(ostream &out, const priority_queue<T, S, C> &obj) {
    priority_queue<T, S, C> q(obj);
    vector<T> t;
    while (!q.empty()) t.push_back(q.top()), q.pop();
    reverse(t.begin(), t.end());
    return out << t;
}

template <class T>
ostream &operator<<(ostream &out, const priority_queue<T> &obj) {
    priority_queue<T> q(obj);
    vector<T> t;
    while (!q.empty()) t.push_back(q.top()), q.pop();
    reverse(t.begin(), t.end());
    return out << t;
}

#define dbg(...)                                                  \
    [](const auto &...x) {                                        \
        vector<string> vs = split_args(#__VA_ARGS__);             \
        cerr << "LINE " << __LINE__ << ":\n";                     \
        ll ind = 0;                                               \
        ((cerr << "  " << vs[ind++] << " = " << x << endl), ...); \
    }(__VA_ARGS__)

#define STRUCT_DBG1(struct_obj, T1)                            \
    ostream &operator<<(ostream &out, const struct_obj &obj) { \
        return out << "[" << obj.T1 << "]";                    \
    }
#define STRUCT_DBG2(struct_obj, T1, T2)                        \
    ostream &operator<<(ostream &out, const struct_obj &obj) { \
        return out << "[" << obj.T1 << ", " << obj.T2 << "]";  \
    }
#define STRUCT_DBG3(struct_obj, T1, T2, T3)                             \
    ostream &operator<<(ostream &out, const struct_obj &obj) {          \
        return out << "[" << obj.T1 << ", " << obj.T2 << ", " << obj.T3 \
                   << "]";                                              \
    }
#define STRUCT_DBG4(struct_obj, T1, T2, T3, T4)                         \
    ostream &operator<<(ostream &out, const struct_obj &obj) {          \
        return out << "[" << obj.T1 << ", " << obj.T2 << ", " << obj.T3 \
                   << ", " << obj.T4 << "]";                            \
    }
#define STRUCT_DBG5(struct_obj, T1, T2, T3, T4, T5)                     \
    ostream &operator<<(ostream &out, const struct_obj &obj) {          \
        return out << "[" << obj.T1 << ", " << obj.T2 << ", " << obj.T3 \
                   << ", " << obj.T4 << ", " << obj.T5 << "]";          \
    }
#define STRUCT_DBG6(struct_obj, T1, T2, T3, T4, T5, T6)                  \
    ostream &operator<<(ostream &out, const struct_obj &obj) {           \
        return out << "[" << obj.T1 << ", " << obj.T2 << ", " << obj.T3  \
                   << ", " << obj.T4 << ", " << obj.T5 << ", " << obj.T6 \
                   << "]";                                               \
    }
#define STRUCT_DBG7(struct_obj, T1, T2, T3, T4, T5, T6, T7)              \
    ostream &operator<<(ostream &out, const struct_obj &obj) {           \
        return out << "[" << obj.T1 << ", " << obj.T2 << ", " << obj.T3  \
                   << ", " << obj.T4 << ", " << obj.T5 << ", " << obj.T6 \
                   << ", " << obj.T7 << "]";                             \
    }
#define STRUCT_DBG8(struct_obj, T1, T2, T3, T4, T5, T6, T7, T8)          \
    ostream &operator<<(ostream &out, const struct_obj &obj) {           \
        return out << "[" << obj.T1 << ", " << obj.T2 << ", " << obj.T3  \
                   << ", " << obj.T4 << ", " << obj.T5 << ", " << obj.T6 \
                   << ", " << obj.T7 << ", " << obj.T8 << "]";           \
    }
