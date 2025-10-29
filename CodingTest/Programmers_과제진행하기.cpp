#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    sort(plans.begin(), plans.end(), [](const vector<string>& a, const vector<string>& b) {
        return a[1] < b[1];
        });

    // �������� �ؾ��� ��
    deque<vector<string>> Deque;
    // �ϴٰ� ���� ��
    stack<vector<string>> Stack;
    for (const auto& plan : plans)
    {
        Deque.push_back(plan);
        //cout << plan[0] << ", " <<  plan[1] << ", " <<  plan[2] << endl;
    }

    vector<string> NowStudy = Deque.front();
    Deque.pop_front();
    int NowTime;
    while (!Deque.empty())
    {
        string IngName = NowStudy[0];
        string IngStart = NowStudy[1];
        string sIngDuring = NowStudy[2];

        string Name = Deque.front()[0];
        string Start = Deque.front()[1];
        string sDuring = Deque.front()[2];

        stringstream ss(Start);
        int Hour, Min, During;
        char Temp;
        ss >> Hour >> Temp >> Min;
        During = stoi(sDuring);
        Min += Hour * 60;

        stringstream Ingss(IngStart);
        int IngHour, IngMin, IngDuring;
        Ingss >> IngHour >> Temp >> IngMin;
        IngDuring = stoi(sIngDuring);
        IngMin += IngHour * 60;

        // �߰��� ����
        if (Min < IngMin + IngDuring)
        {
            Stack.push(vector<string>{IngName, IngStart,
                to_string(IngMin + IngDuring - Min)});
            NowStudy = Deque.front();
            Deque.pop_front();
        }
        else
        {
            // answer.push_back(IngName);
            // NowStudy = Deque.front();
            // 
            // int CurrnetTime = IngMin + IngDuring;
            // 
            // // �Ϸ��ϰ� ������ �ð��ɶ� ���
            // while(Min > CurrnetTime && !Stack.empty())
            // {
            //     string SName = Stack.top()[0];
            //     string SStart = Stack.top()[1];
            //     string sSDuring = Stack.top()[2];
            //     Stack.pop();
            // 
            //     stringstream Stackss(SStart);
            //     int StackHour, StackMin, StackDuring;
            //     Stackss >> StackHour >> Temp >> StackMin;
            //     StackDuring = stoi(sSDuring);
            //     StackMin += StackHour * 60;
            // 
            //     int LeftTime = StackDuring - (Min - CurrnetTime);
            //     if (LeftTime > 0)
            //     {
            //         Stack.push(vector<string>{SName, SStart, to_string(LeftTime)});
            //         break;
            //     }
            //     else
            //         answer.push_back(SName);
            //     //NowStudy = Deque.front();
            //     CurrnetTime += StackDuring;
            // 
            // 
            // }
            // Deque.pop_front();

            // 1. ���� ���� �Ϸ� �� ���信 �߰�
            answer.push_back(IngName);

            // 2. ���� �ð� ���
            int IdleTime = Min - (IngMin + IngDuring); // IngName �Ϸ� �ð����� NextName ���� �ð������� �ð�

            // 3. ���� ���� ó�� (���� �ֱ� �ͺ���)
            while (IdleTime > 0 && !Stack.empty())
            {
                // Stack���� {�̸�, ���� �ð�(string)} ���·� ����Ǿ� �ִٰ� ����
                vector<string> Stopped = Stack.top();
                Stack.pop();

                string SName = Stopped[0];
                int SRemainingTime = stoi(Stopped[2]); // ���� �ð�(��)

                // ���� �ð����� ������ ���� �� �ִ� ���
                if (IdleTime >= SRemainingTime)
                {
                    IdleTime -= SRemainingTime;
                    answer.push_back(SName); // ���� ���� �Ϸ�
                }
                // ���� �ð����� ������ ���� �� ���� ���
                else // SRemainingTime > IdleTime
                {
                    SRemainingTime -= IdleTime;
                    // ���� �ð� ������Ʈ �� �ٽ� Stack�� Ǫ��
                    Stack.push(vector<string>{SName, "", to_string(SRemainingTime)});
                    IdleTime = 0; // ���� �ð� ����
                }
            }

            // 4. ���� ���� ����
            NowStudy = Deque.front();
            Deque.pop_front();
        }
    }

    answer.push_back(NowStudy[0]);

    while (!Stack.empty())
    {
        vector<string> s = Stack.top();
        Stack.pop();
        answer.push_back(s[0]);
    }

    return answer;
}

int main()
{
    cout << "[";
    for (const auto& s : solution({ {"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"} }))
    {
        cout << s << ", ";
    }
    cout << "]\n";
    cout << "[";
    for (const auto& s : solution({ {"science", "12:40", "50"}, {"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"} }))
    {
        cout << s << ", ";
    }
    cout << "]\n";
    cout << "[";
    for (const auto& s : solution({ {"aaa", "12:00", "20"}, {"bbb", "12:10", "30"}, {"ccc", "12:40", "10"} }))
    {
        cout << s << ", ";
    }
    cout << "]";
}