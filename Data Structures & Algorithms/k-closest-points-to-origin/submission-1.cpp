class Solution {
public:
    int distance(vector<int>& a) {
        return a[0] * a[0] + a[1] * a[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < points.size(); i++) {
            pq.push({distance(points[i]), i});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }

        return res;
    }
};