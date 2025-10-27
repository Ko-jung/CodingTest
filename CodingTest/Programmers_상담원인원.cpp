#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct Cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.first + a.second > b.first + b.second;
    }
};

//int CalculationTime(vector<vector<int>>& time, int couns)
//{
//    int waittime = 0;
//    priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> qTime;
//    for (const auto& t : time)
//    {
//        int a = t[0];
//        int b = t[1];
//         
//        // ���� �� ��ŭ �ϴ� ���
//        if (qTime.empty() || qTime.size() < couns)
//        {
//            qTime.emplace(a, a + b);
//        }
//        else
//        {
//            auto [Start, End] = qTime.top();
//            qTime.pop();
//
//            // ���� ����� �����ؾ��ϴ� �ð��� ���� ����� ������ �ð����� ������
//            if (a < End)
//            {
//                // ��ٸ� �ð���ŭ ���ϱ�
//                waittime += (End - a);
//                //��� �߰�
//                qTime.emplace(Start, End + b);
//            }
//            else
//            {
//                qTime.emplace(a, a + b);
//            }
//        }
//    }
//    return waittime;
//}

int GetWaitTime(vector<vector<int>> reqs, int n)
{
    int waitTime = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(0);
    }

    for (int i = 0; i < reqs.size(); i++)
    {
        int curr = pq.top();
        pq.pop();

        if (curr == 0)
            curr = reqs[i][0];

        if (curr > reqs[i][0])
        {
            waitTime += curr - reqs[i][0];
            curr += reqs[i][1];
        }
        else
        {
            curr = reqs[i][0] + reqs[i][1];
        }

        pq.push(curr);
    }

    return waitTime;
}

// ====================== gpt�ڵ� ====================== 
struct CompareEnd {
    // ���� End�� top�� ������ (min-heap)
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        if (a.second != b.second) return a.second > b.second;
        return a.first > b.first; // tie-breaker: ���� Start �켱
    }
};

int CalculationTime(std::vector<std::vector<int>>& time, int couns)
{
    if (time.empty() || couns <= 0) return 0;

    // 1) �ݵ�� ���۽ð� �������� ����
    sort(time.begin(), time.end(), [](const auto& A, const auto& B) {
        if (A[0] != B[0]) return A[0] < B[0];
        return A[1] < B[1];
        });

    int waittime = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, CompareEnd> qTime;

    for (const auto& t : time)
    {
        int a = t[0];
        int b = t[1];

        // �� ����(���� ä���� ���� ����) �ִ� ������ �ٷ� �Ҵ�
        if (qTime.size() < (size_t)couns)
        {
            qTime.emplace(a, a + b);
            continue;
        }

        // ���� ���� ������ ���縦 ������
        auto [prevStart, prevEnd] = qTime.top();
        qTime.pop();

        if (a < prevEnd)
        {
            // ���簡 ���� �� �������Ƿ� ���
            waittime += (prevEnd - a);
            // �� ����� prevEnd ������ �����ؼ� prevEnd + b ���� �ٻ�
            qTime.emplace(prevEnd, prevEnd + b);
        }
        else
        {
            // ���簡 �̹� ��������Ƿ� (a�� ����) a+b ���� �ٻ�
            qTime.emplace(a, a + b);
        }
    }

    return waittime;
}
//====================== ====================== ====================== 

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;

    // ���� ���� ������, ��ġ�� �ð��� ū ������� ���� �߰� ��ġ
    // Board[����][req][3]
    vector<vector<vector<int>>> Board(k + 1);

    // ������ ����
    for (const auto& req : reqs)
    {
        int a = req[0];
        int b = req[1];
        int c = req[2];

        Board[c].emplace_back(vector<int>{a, b});
    }

    // �������� ���� ���� ���� �ҿ�ð� ���
    vector<vector<int>> WaitTimeForEach(k+1, vector<int>(n + 1, 0));
    for (int i = 1; i <= k; i++)
    {
        vector<vector<int>> RequestTime = Board[i];
        if (RequestTime.size() == 0) continue;
        for (int counselors = 1; counselors <= (n - k) + 1; counselors++)
        {
            int wait = CalculationTime(RequestTime, counselors);
            //int wait = GetWaitTime(RequestTime, counselors);

            WaitTimeForEach[i][counselors] = wait;
        }
    }

    // Greedy Ž�� ����
    vector<int> Counselors(k + 1, 1); // �� ��
    int LastCount = n - k;
    while (LastCount--)
    {
        int MaxWaitTime = 0;
        int MaxIndex = 0;
        for (int i = 1; i <= k; i++)
        {
            int CounselorsNum = Counselors[i];
            int DiffTime = WaitTimeForEach[i][CounselorsNum] - WaitTimeForEach[i][CounselorsNum + 1];

            if (MaxWaitTime <= DiffTime)
            {
                MaxWaitTime = DiffTime;
                MaxIndex = i;
            }
        }

        // ���� ū ���� ���� ��ġ
        Counselors[MaxIndex]++;
    }

    for (int i = 1; i <= k; i++)
    {
        answer += WaitTimeForEach[i][Counselors[i]];
    }

    return answer;
}

int main()
{
    cout << solution(3,	5, {{10, 60, 1}, {15, 100, 3}, {20, 30, 1}, {30, 50, 3}, {50, 40, 1}, {60, 30, 2}, {65, 30, 1}, {70, 100, 2}}) << endl;
    cout << solution(2,	3, {{5, 55, 2}, {10, 90, 2}, {20, 40, 2}, {50, 45, 2}, {100, 50, 2}} ) << endl;
    cout << solution(1,	1000, {{5, 55, 1}, {10, 90, 1}} ) << endl;
    cout << solution(3,	5, {{5, 10, 1}, {10, 30, 1}, {15, 30, 1}, {20, 10, 1}, {30, 10, 1}} ) << endl;
}