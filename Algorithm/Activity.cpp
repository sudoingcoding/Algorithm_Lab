#include<bits/stdc++.h>

using namespace std;

class Act {
public:
    int start;
    int end;
    Act() {
        cout << "Enter start: ";
        cin >> start;
        cout << "Enter end: ";
        cin >> end;
    }
    void printJob() {
        cout << "  " << start << "  " << end << "\n";
    }
};

bool compare(const Act& a, const Act& b) {
    return a.end < b.end;
}

int max_activities(const vector<Act>& v) {
    int n = v.size();
    if (n == 0) return 0;

    vector<Act> sorted_v = v;
    sort(sorted_v.begin(), sorted_v.end(), compare);

    int max_activities = 1;
    int prev_activity_end_time = sorted_v[0].end;

    for (int i = 1; i < n; i++) {
        if (sorted_v[i].start >= prev_activity_end_time) {
            max_activities++;
            prev_activity_end_time = sorted_v[i].end;
        }
    }

    return max_activities;
}

int main() {
    int n = 5;
    vector<Act> v;
    for (int i = 0; i < n; i++) {
        Act act;
        v.push_back(act);
    }

    int max_act = max_activities(v);
    cout << "Max Activities = " << max_act << endl;

    return 0;
}
