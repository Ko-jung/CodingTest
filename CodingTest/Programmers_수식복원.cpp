#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Express
{
    int Left;
    char Oper;
    int Right;
    int Result;
};

int GetDigit(int Num, int Base)
{
    // 8���� 14 -> 10���� 4 + 8*1 12
    int ReturnNum = 0;
    int Count = 0;
    while (Num)
    {
        int Temp = Num % 10;
        ReturnNum += (pow(Base, Count) * Temp);
        Num /= 10;
        Count++;
    }
    return ReturnNum;
}

int GetBaseNum(int Num, int Base)
{
    string Temp;
    while (Num)
    {
        Temp += (Num % Base + '0');
        Num /= Base;
    }
    reverse(Temp.begin(), Temp.end());
    return stoi(Temp);
}

int Execute(const Express& Exp, int Base)
{
    // Base -> 10������ ��ȯ
    int Left = GetDigit(Exp.Left, Base);
    int Right = GetDigit(Exp.Right, Base);

    cout << Left << " << " << Right << "||";

    // ��� �� 10 -> Base ���� ��ȯ
    int Result;
    if (Exp.Oper == '+')
        Result = GetBaseNum(Left + Right, Base);
    else
        Result = GetBaseNum(Left - Right, Base);

    return Result;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;

    vector<Express> CompleteExpress;        // X ���� ǥ����
    CompleteExpress.reserve(expressions.size());

    vector<Express> IncompleteExpress;      // X �ִ� ǥ����
    IncompleteExpress.reserve(expressions.size());

    for (const auto& expression : expressions)
    {
        Express Temp;
        char cTemp; // '=' �޾��ٰ�
        stringstream ss(expression);
        ss >> Temp.Left >> Temp.Oper >> Temp.Right >> cTemp;

        // X�� �����°� ����
        if (!(ss >> Temp.Result))
        {
            Temp.Result = -1;   // ���� �Է��� ������    
            IncompleteExpress.push_back(Temp);
        }
        else
        {
            CompleteExpress.push_back(Temp);
        }
    }

    // for (const auto & vec : CompleteExpress)
    // {
    //     cout << vec.Left << " " << vec.Oper << " " << vec.Right << " = "  << vec.Result << "//";
    // }    

    vector<bool> Candidate(10, true);
    int MaxNum = 0; // �־��� ������ ���ڸ� Ȯ���Ͽ� ���� �ĺ� ���ܿ� (5�� ������ �ּ� 6���� �̻�)
    // �̰� �ѹ��� ó���� �� ����
    for (const auto& expression : expressions)
    {
        for (const auto& c : expression)
        {
            if (isdigit(c))
                MaxNum = max(MaxNum, c - '0');
        }
    }
    fill(Candidate.begin(), Candidate.begin() + MaxNum + 1, false);

    // 9Ȯ��
    if (MaxNum == 8)
    {
        for (auto& vec : IncompleteExpress)
        {
            int Result = Execute(vec, 9);
            vec.Result = Result;
        }
    }
    else
    {
        // �ĺ� �ɷ�����
        for (int i = MaxNum + 1; i < 10; ++i)
        {
            for (const auto& vec : CompleteExpress)
            {
                int Result = Execute(vec, i);
                if (vec.Result != Result)
                {
                    // �ĺ� ����
                    Candidate[i] = false;
                    cout << i << " is False, " << Result << "&&&";
                    break;
                }
            }
        }

        // for(auto b : Candidate)
        //     cout << b << "!!";

        // ������ �ĺ��� X ���
        for (int i = 0; i < 10; ++i)
        {
            if (!Candidate[i]) continue;

            for (auto& vec : IncompleteExpress)
            {
                int Result = Execute(vec, i);
                if (vec.Result == -1)
                    vec.Result = Result;
                else if (vec.Result != Result)
                    vec.Result = (int)'?';
            }
        }
    }

    for (auto vec : IncompleteExpress)
    {
        //cout << vec.Left << " " << vec.Oper << " " << vec.Right << " = "  << vec.Result << "//";
        string AnswerStr = to_string(vec.Left) + " "
            + vec.Oper + " "
            + to_string(vec.Right) + " = "
            + to_string(vec.Result);

        answer.push_back(AnswerStr);
    }


    return answer;
}

int main()
{
    cout << "[";
    for(const auto& s : solution({ "10 - 2 = X", "30 + 31 = 101", "3 + 3 = X", "33 + 33 = X" }))
        cout << "\"" << s << "\"" << ", ";
    cout << "]\n";
}