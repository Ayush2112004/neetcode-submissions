/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool compare(Interval& a,Interval& b){
        return a.start<b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
      sort(intervals.begin(), intervals.end(), compare);
        if(intervals.empty()){
            return 0;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto interval:intervals){
            if(!pq.empty() && pq.top() <= interval.start) {
                pq.pop();
            }
            pq.push(interval.end);
        }

        return pq.size();
    }
};
