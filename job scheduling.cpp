#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure representing each job
struct Job {
    int start;
    int finish;
};

// Function to compare jobs based on their finish times (used for sorting)
bool compareJobs(const Job& job1, const Job& job2) {
    return job1.finish < job2.finish;
}

// Function to solve the Interval Scheduling Problem using greedy approach
int intervalScheduling(vector<Job>& jobs) {
    int n = jobs.size();
    int count = 0; // Initialize count of selected jobs

    // Sort jobs based on their finish times
    sort(jobs.begin(), jobs.end(), compareJobs);

    // Select the first job (earliest finish time)
    int lastFinishTime = jobs[0].finish;
    count++;

    // Iterate over remaining jobs and select non-overlapping jobs with earliest finish times
    for (int i = 1; i < n; ++i) {
        if (jobs[i].start >= lastFinishTime) {
            count++;
            lastFinishTime = jobs[i].finish;
        }
    }

    return count;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    // Input job intervals from the user
    cout << "Enter the start and finish times for each job:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].start >> jobs[i].finish;
    }

    int maxJobs = intervalScheduling(jobs);

    cout << "Maximum number of non-overlapping jobs: " << maxJobs << endl;

    return 0;
}
