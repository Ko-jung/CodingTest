#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int FindAns(const vector<int>& q, const vector<int>& comp)
{
    int Return = 0;
    // q와 comp 둘다 정렬이 되어있다는 가정하에
    int A = 0, B = 0;
    while (A < 5 && B < 5)
    {
        if (q[A] == comp[B])
        {
            Return++;
            A++, B++;
        }
        else if (q[A] < comp[B])
        {
            A++;
        }
        else
        {
            B++;
        }
    }
    return Return;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;

    int m = q.size();
    vector<bool> Combination(n, false);
    for (int i = 0; i < 5; ++i)
        Combination[i] = true;

    do
    {
        vector<int> Combi;
        Combi.reserve(5);
        for (int i = 0; i < n; ++i)
        {
            if (Combination[i])
                Combi.push_back(i + 1);
        }

        bool IsAnswer = true;
        for (int i = 0; i < m; ++i)
        {
            if (ans[m] != FindAns(q[m], Combi))
            {
                IsAnswer = false;
                continue;
            }
        }

        if (IsAnswer)
        {
            for (auto& i : Combi)
                cout << i << ", ";
            cout << "//";

            answer++;
        }

        // [1, 2, 3, 4, 5 ] -> 2
        // [3, 4, 7, 9, 10]
    } while (prev_permutation(Combination.begin(), Combination.end()));

    return answer;
}

int main()
{
    solution(10, {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {3, 7, 8, 9, 10}, {2, 5, 7, 9, 10}, {3, 4, 5, 6, 7}}, {2, 3, 4, 3, 3});
}