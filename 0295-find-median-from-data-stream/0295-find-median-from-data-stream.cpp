class MedianFinder {
public:
    // minheap stores larger half
    priority_queue<int,vector<int>,greater<int>> minheap;

    // maxheap stores smaller half
    priority_queue<int> maxheap;

    MedianFinder() {
    }
    
    void addNum(int num) {

        // Step 1: Decide where to insert
        if(!minheap.empty() && num > minheap.top()){
            minheap.push(num);
        } else {
            maxheap.push(num);
        }

        // Step 2: Balance heaps

        // If minheap has more elements, move one to maxheap
        if(minheap.size() > maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }

        // If maxheap has more than 1 extra element
        if(maxheap.size() - minheap.size() > 1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    double findMedian() {

        // If both heaps are equal in size
        if(maxheap.size() == minheap.size()){
            return (maxheap.top() + minheap.top()) / 2.0;
        }

        // Otherwise maxheap has one extra element
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */