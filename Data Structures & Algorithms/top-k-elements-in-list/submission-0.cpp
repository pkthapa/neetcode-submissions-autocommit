class Solution {
    using mypair = pair<int, int>;
    struct mycompare {
        bool operator()(mypair p1, mypair p2) {
            return p1.second > p2.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<mypair, vector<mypair>, mycompare> minHeap;

        unordered_map<int, int> m;
        for (auto& num : nums) {
            m[num]++;
        }

        for (auto& x : m){
            minHeap.push(x);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return result;
    }
};
