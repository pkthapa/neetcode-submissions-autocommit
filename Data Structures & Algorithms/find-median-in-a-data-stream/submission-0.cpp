class MedianFinder {
    priority_queue<int> smallNumsHeap; // Max heap
    priority_queue<int, vector<int>, ::greater<int>> largeNumsHeap; // Min heap

public:
    MedianFinder() {}
    
    void addNum(int num) {
        // Always insert into 'smallNumsHeap'
        smallNumsHeap.push(num);

        if (!smallNumsHeap.empty() && !largeNumsHeap.empty() &&
            smallNumsHeap.top() > largeNumsHeap.top()) {
            largeNumsHeap.push(smallNumsHeap.top());
            smallNumsHeap.pop();
        }

        if (largeNumsHeap.size() > smallNumsHeap.size() + 1) {
            smallNumsHeap.push(largeNumsHeap.top());
            largeNumsHeap.pop();
        }
        if (smallNumsHeap.size() > largeNumsHeap.size() + 1) {
            largeNumsHeap.push(smallNumsHeap.top());
            smallNumsHeap.pop();
        }
    }
    
    double findMedian() {
        if (smallNumsHeap.size() > largeNumsHeap.size()) {
            return static_cast<double>(smallNumsHeap.top());
        }

        if (largeNumsHeap.size() > smallNumsHeap.size()) {
            return static_cast<double>(largeNumsHeap.top());
        }
        return static_cast<double>(smallNumsHeap.top() + largeNumsHeap.top()) / 2;
    }
};
