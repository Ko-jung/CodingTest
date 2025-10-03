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
    // 8진수 14 -> 10진수 4 + 8*1 12
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
    // Base -> 10진수로 변환
    int Left = GetDigit(Exp.Left, Base);
    int Right = GetDigit(Exp.Right, Base);

    cout << Left << " << " << Right << "||";

    // 계산 후 10 -> Base 진수 변환
    int Result;
    if (Exp.Oper == '+')
        Result = GetBaseNum(Left + Right, Base);
    else
        Result = GetBaseNum(Left - Right, Base);

    return Result;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;

    vector<Express> CompleteExpress;        // X 없는 표현식
    CompleteExpress.reserve(expressions.size());

    vector<Express> IncompleteExpress;      // X 있는 표현식
    IncompleteExpress.reserve(expressions.size());

    for (const auto& expression : expressions)
    {
        Express Temp;
        char cTemp; // '=' 받아줄거
        stringstream ss(expression);
        ss >> Temp.Left >> Temp.Oper >> Temp.Right >> cTemp;

        // X가 들어오는거 감지
        if (!(ss >> Temp.Result))
        {
            Temp.Result = -1;   // 음수 입력은 없다함    
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
    int MaxNum = 0; // 주어진 수식의 숫자를 확인하여 진수 후보 제외용 (5가 있으면 최소 6진수 이상)
    // 이걸 한번에 처리할 순 없나
    for (const auto& expression : expressions)
    {
        for (const auto& c : expression)
        {
            if (isdigit(c))
                MaxNum = max(MaxNum, c - '0');
        }
    }
    fill(Candidate.begin(), Candidate.begin() + MaxNum + 1, false);

    // 9확정
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
        // 후보 걸러내기
        for (int i = MaxNum + 1; i < 10; ++i)
        {
            for (const auto& vec : CompleteExpress)
            {
                int Result = Execute(vec, i);
                if (vec.Result != Result)
                {
                    // 후보 제외
                    Candidate[i] = false;
                    cout << i << " is False, " << Result << "&&&";
                    break;
                }
            }
        }

        // for(auto b : Candidate)
        //     cout << b << "!!";

        // 정해진 후보로 X 계산
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