#include<bits/stdc++.h>
using namespace std;

class Job {
public:
    char jobId;
    int profit;
    int deadline;
    Job() {
        cout << "Enter job id: ";
        cin >> jobId;
        cout << "Enter profit: ";
        cin >> profit;
        cout << "Enter deadline: ";
        cin >> deadline;
    }
    void printJob() {
        cout << "  " << jobId << "  " << profit << "  " << deadline << "\n";
    }
};

struct ValueCmp {
    bool operator()(const Job* a, const Job* b) const {
        return a->deadline < b->deadline;
    }
};

void schedule(vector<Job*>& v) {
    int n = v.size();
    sort(v.begin(), v.end(), [](Job* a, Job* b) { return a->deadline < b->deadline; });

    priority_queue<Job*, vector<Job*>, ValueCmp> pq;

    vector<Job*> result;

    for (int i = n - 1; i >= 0; i--) {
        int slot_available;
        if (i == 0) {
            slot_available = v[i]->deadline;
        }
        else {
            slot_available = v[i]->deadline - v[i - 1]->deadline;
        }
        pq.push(v[i]);

        while (slot_available > 0 && !pq.empty()) {
            Job* job = pq.top();
            pq.pop();
            slot_available--;
            result.push_back(job);
        }
    }

    sort(result.begin(), result.end(), [](Job* a, Job* b) { return a->deadline < b->deadline; });

    for (int i = 0; i < result.size(); i++)
        result[i]->printJob();
}

int main() {
    int n;
    cout << "Enter Job Numbers: ";
    cin >> n;
    vector<Job*> v(n);
    for (int i = 0; i < n; i++) {
        Job* j = new Job();
        v[i] = j;
    }
    schedule(v);
    return 0;
}
