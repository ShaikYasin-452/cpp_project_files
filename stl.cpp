#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    // 1. vector
    vector<int> vec = {10, 20, 30};
    vec.push_back(40);
    cout << "Vector: ";
    for (int i : vec) cout << i << " ";
    cout << endl;

    // 2. list
    list<string> names = {"Yasin", "Aamir"};
    names.push_front("Shaik");
    cout << "List: ";
    for (auto n : names) cout << n << " ";
    cout << endl;

    // 3. deque
    deque<int> dq;
    dq.push_back(5);
    dq.push_front(2);
    cout << "Deque: ";
    for (int i : dq) cout << i << " ";
    cout << endl;

    // 4. stack
    stack<int> stk;
    stk.push(1); stk.push(2); stk.push(3);
    cout << "Stack Top to Bottom: ";
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    // 5. queue
    queue<string> q;
    q.push("apple"); q.push("banana");
    cout << "Queue Front to Back: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // 6. priority_queue
    priority_queue<int> pq;
    pq.push(50); pq.push(10); pq.push(40);
    cout << "Priority Queue (Max to Min): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // 7. set
    set<int> s = {3, 1, 2, 2};
    cout << "Set (Unique + Sorted): ";
    for (int i : s) cout << i << " ";
    cout << endl;

    // 8. map
    map<int, string> m;
    m[101] = "Yasin";
    m[102] = "Shaik";
    cout << "Map (ID -> Name): ";
    for (auto p : m)
        cout << "[" << p.first << ":" << p.second << "] ";
    cout << endl;

    // 9. unordered_set
    unordered_set<string> uset = {"dog", "cat", "dog"};
    cout << "Unordered Set: ";
    for (auto str : uset) cout << str << " ";
    cout << endl;

    // 10. unordered_map
    unordered_map<string, int> umap;
    umap["pen"] = 10;
    umap["book"] = 50;
    cout << "Unordered Map: ";
    for (auto p : umap)
        cout << "[" << p.first << ":" << p.second << "] ";
    cout << endl;

    // 11. algorithm
    vector<int> nums = {4, 2, 1, 3};
    sort(nums.begin(), nums.end());
    cout << "Sorted Vector: ";
    for (int i : nums) cout << i << " ";
    cout << endl;

    // find
    if (find(nums.begin(), nums.end(), 3) != nums.end())
        cout << "Found 3 in vector" << endl;
    else
        cout << "3 Not Found" << endl;

    return 0;
}
