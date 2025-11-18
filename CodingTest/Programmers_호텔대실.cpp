#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

string PlusTen(string Time)
{
    int H, M;
    char Temp;
    stringstream ss(Time);
    ss >> H >> Temp >> M;
    int Min = H * 60 + M + 10;

    string Return;
    Return += to_string(Min / 60) + ':' + to_string(Min % 60);
    return Return;
}

int solution(vector<vector<string>> book_time) {
    sort(book_time.begin(), book_time.end(), [](const vector<string>& a, const vector<string>& b) {
        return a[0] < b[0];
        });

    vector<string> Schedule;
    Schedule.push_back(book_time[0][1]);
    for (int i = 1; i < book_time.size(); i++)
    {
        bool IsPush = false;
        string MinTime = "25:00";
        int jIndex = -1, iIndex = -1;
        for (int j = 0; j < Schedule.size(); ++j)
        {
            string s = Schedule[j];
            // 현재 등록되어있는 스케쥴의 끝나는 시간
            string EndTime = PlusTen(s);
            // 끝나는 시간이 새로 들어올거보다 작다 = 바꿔도 된다
            if (EndTime <= book_time[i][0])
            {
                if (EndTime < MinTime)
                {
                    MinTime = EndTime;
                    jIndex = j;
                    iIndex = i;
                }
            }
            cout << "##" << EndTime << ", " << MinTime << ", " << book_time[i][0] << ", " << book_time[i][1] << endl;
        }
        if (jIndex == -1)
            Schedule.push_back(book_time[i][1]);
        else
            Schedule[jIndex] = book_time[iIndex][1];

        for (const auto s : Schedule)
            cout << s << " @@ ";
        cout << endl;
    }

    return Schedule.size();
}

int main()
{
    cout << solution({{"1:00", "2:01"}, {"2:10", "3:00"}, {"3:10", "4:00"}} ) << endl;
}