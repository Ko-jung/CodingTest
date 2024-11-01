//당신은 덧셈 혹은 뺄셈 수식이 여러 개 적힌 고대 문명의 유물을 찾았습니다.이 수식들을 관찰하던 당신은 이 문명이 사용하던 진법 체계가 10진법이 아니라는 것을 알아냈습니다. (2 ~9진법 중 하나입니다.)
//
//수식들 중 몇 개의 수식은 결괏값이 지워져 있으며, 당신은 이 문명이 사용하던 진법에 맞도록 지워진 결괏값을 채워 넣으려 합니다.
//
//다음은 그 예시입니다.
//
//<수식>
//
//14 + 3 = 17
//13 - 6 = X
//51 - 5 = 44
//X로 표시된 부분이 지워진 결괏값입니다.
//51 - 5 = 44에서 이 문명이 사용하던 진법이 8진법임을 알 수 있습니다.따라서 13 - 6 = X의 지워진 결괏값을 채워 넣으면 13 - 6 = 5가 됩니다.
//
//다음은 또 다른 예시입니다.
//
//<수식>
//
//1 + 1 = 2
//1 + 3 = 4
//1 + 5 = X
//1 + 2 = X
//주어진 수식들에서 이 문명에서 사용한 진법이 6 ~9진법 중 하나임을 알 수 있습니다.
//1 + 5 = X의 결괏값은 6진법일 때 10, 7 ~9진법일 때 6이 됩니다.이와 같이 결괏값이 불확실한 수식은 ? 를 사용해 1 + 5 = ? 와 같이 결괏값을 채워 넣습니다.
//1 + 2 = X의 결괏값은 6 ~9진법에서 모두 3으로 같습니다.따라서 1 + 2 = X의 지워진 결괏값을 채워 넣으면 1 + 2 = 3이 됩니다.
//
//덧셈 혹은 뺄셈 수식들이 담긴 1차원 문자열 배열 expressions가 매개변수로 주어집니다.
// 이때 결괏값이 지워진 수식들의 결괏값을 채워 넣어 순서대로 문자열 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

// 맨 밑에 해석

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Expression
{
	int L;
	int R;
	int Result;
	bool IsPlus;
};


// 주어진 수를 10진수로
int Get10(int x)
{


}

vector<string> solution(vector<string> expressions)
{
	vector<string> answer;

	vector<Expression> Answer;
	vector<Expression> Guess;
	int Maxnum{ -10 };
	for (const auto& e : expressions)
	{
		stringstream s(e);
		int r, l, result;
		char c1, c2, c3;
		if (*e.rbegin() == 'X')
		{
			s >> r >> c1 >> l >> c2 >> c3;
			if(c1 == '+')
				Guess.emplace_back(r, l, 0, true);
			else
				Guess.emplace_back(r, l, 0, false);
		}
		else
		{
			s >> r >> c1 >> l >> c2 >> result;
			if (c1 == '+')
				Answer.emplace_back(r, l, result, true);
			else
				Answer.emplace_back(r, l, result, false);
		}

		for (const auto& c : e)
		{
			if (isdigit(c))
			{
				Maxnum = max(Maxnum, (int)(c - '0'));
			}
		}
	}

	vector<int> Candidate;
	for (int i = Maxnum + 1; i <= 9; i++)
	{
		bool IsCandidate = true;
		for (const auto& exp : Answer)
		{
			int Result = exp.IsPlus ? exp.L + exp.R : exp.L - exp.R;

			string IntStr;
			int Temp = Result;
			while (Temp)
			{
				IntStr += Temp % i;
				Temp /= i;
			}

			reverse(IntStr.begin(), IntStr.end());

			if (stoi(IntStr) != Result)
			{
				IsCandidate = false;
				break;
			}
		}

		if (IsCandidate) Candidate.emplace_back(i);
	}

	return answer;
}

int main()
{
	solution({ "14 + 3 = 17",  "13 - 6 = X" ,  "51 - 5 = 44" });
	solution({ "1 + 1 = 2", "1 + 3 = 4", "1 + 5 = X", "1 + 2 = X" });
	solution({ "10 - 2 = X", "30 + 31 = 101", "3 + 3 = X", "33 + 33 = X" });
	solution({ "2 - 1 = 1", "2 + 2 = X", "7 + 4 = X", "5 - 5 = X" });
	solution({ "2 - 1 = 1", "2 + 2 = X", "7 + 4 = X", "8 + 4 = X" });
}

// 주어진 수를 가능한 진수라고 가정하고 10진수로 변환 후 계산 하여 맞는지 확인 ( ex) 12 + 5 = 17이 8진수에서 맞는지 확인하기 위해 10진수로 변환)
// X가 표현된 수는 앞서 계산한 진수 후보를 가지고 10진수 기준으로 계산하고 N진수로 변환.
// 앞서 계산한 결과와 다르면 "?"