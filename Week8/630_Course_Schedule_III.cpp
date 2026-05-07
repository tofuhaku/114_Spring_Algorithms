#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        priority_queue<int, vector<int>> pq;        // Record the courses duration
        int cur_time = 0;
        int count = 0;
        for (const auto& course : courses) {
            int duration = course[0];
            int lastday = course[1];
            if (cur_time + duration <= lastday) {
                pq.push(duration);
                cur_time += duration;
                count++;
            } else if (!pq.empty() && pq.top() > duration) {
                cur_time += duration - pq.top();
                pq.pop();
                pq.push(duration);
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    // courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
    vector<vector<int>> courses = {{100,200},{200,1300},{1000,1250},{2000,3200}};
    cout << sol.scheduleCourse(courses) << endl;
	return 0;
}