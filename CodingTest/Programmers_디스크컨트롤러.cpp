#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std; 

struct Job
{
    int InputTime;
    int RequiredTime;
    int JobNum;
    Job() {}
    Job(int it, int rt, int jn) : InputTime(it), RequiredTime(rt), JobNum(jn) {}
    bool operator>(const Job& a) const
    {
        if (RequiredTime != a.RequiredTime) return RequiredTime > a.RequiredTime;
        if (InputTime != a.InputTime) return InputTime > a.InputTime;
        return JobNum > a.JobNum;
    }
};

ostream& operator<<(ostream& os, const Job& a)
{
    os << "Job is: " << a.InputTime << ", " << a.RequiredTime << ", " << a.JobNum;
    return os;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector<int> TimeVec;

    priority_queue<Job, vector<Job>, greater<Job>> PQueue;
    //for (const auto& job : jobs)
    //{
    //    PQueue.emplace(job[0], job[1], i++);
    //}
    sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

    int i = 0 ;
    int Time = 0;
    while (true)
    {
        while (i < jobs.size() && jobs[i][0] <= Time)
        {
            PQueue.emplace(jobs[i][0], jobs[i][1], i);
            cout << "PQueue push, " << jobs[i][0] << ", " << jobs[i][1] << ", " << i << endl;
            i++;
        }

        if (PQueue.empty())
        {
            if (i >= jobs.size())
                break;
            else
            {
                Time++;
                continue;
            }
        }

        Job CurrentJob = PQueue.top();
        if (CurrentJob.InputTime <= Time)
        {
            PQueue.pop();
            Time += CurrentJob.RequiredTime;
            TimeVec.emplace_back(Time - CurrentJob.InputTime);
            cout << CurrentJob << " Time: " << Time << endl;
        }
        else
            Time++;
    }
    answer = std::accumulate(TimeVec.begin(), TimeVec.end(), 0) / TimeVec.size();
    return answer;
}

int main()
{
    cout << solution({  {0,3},
                        {1,9},
                        {4,5},
                        {3,5} });
}