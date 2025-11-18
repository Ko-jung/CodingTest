#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;

    vector<int> DP(5'000'001, 1);
    int i = 1, j = 2;
    while (true)
    {
        while (i * j <= e)
        {
            DP[i * j]++;
            ++i;
        }
        if (i == 1)
            break;
        ++j;
        i = 1;
    }

    for (const auto& s : starts)
    {
        answer.push_back(distance(DP.begin(), max_element(DP.begin() + s, DP.begin() + e + 1)));
    }

    return answer;
}

int main()
{
    for(auto i : solution(8, { 1,3,7 }))
        cout << i << ", ";
    cout << endl;
}