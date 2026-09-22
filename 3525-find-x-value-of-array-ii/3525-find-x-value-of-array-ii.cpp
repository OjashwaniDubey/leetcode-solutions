class Solution {
public:

    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int n, k;
    vector<int> nums;
    vector<Node> seg;

    Node merge(Node &L, Node &R) {
        Node res;

        // Product of entire segment
        res.prod = (L.prod * R.prod) % k;

        // Prefixes ending inside Left
        for (int r = 0; r < k; r++) {
            res.cnt[r] += L.cnt[r];
        }

        // Prefixes that enter Right
        for (int r = 0; r < k; r++) {
            int newRem = (L.prod * r) % k;
            res.cnt[newRem] += R.cnt[r];
        }

        return res;
    }

    void build(int idx, int l, int r) {

        if (l == r) {
            int rem = nums[l] % k;

            seg[idx].prod = rem;
            seg[idx].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, int value) {

        if (l == r) {
            int rem = value % k;

            seg[idx] = Node();

            seg[idx].prod = rem;
            seg[idx].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx, l, mid, pos, value);
        else
            update(2 * idx + 1, mid + 1, r, pos, value);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {

        if (ql <= l && r <= qr) {
            return seg[idx];
        }

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(2 * idx, l, mid, ql, qr);

        if (ql > mid)
            return query(2 * idx + 1, mid + 1, r, ql, qr);

        Node L = query(2 * idx, l, mid, ql, qr);
        Node R = query(2 * idx + 1, mid + 1, r, ql, qr);

        return merge(L, R);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        this->nums = nums;
        this->k = k;
        this->n = nums.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};