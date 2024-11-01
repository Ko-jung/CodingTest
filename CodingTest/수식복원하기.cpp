//����� ���� Ȥ�� ���� ������ ���� �� ���� ��� ������ ������ ã�ҽ��ϴ�.�� ���ĵ��� �����ϴ� ����� �� ������ ����ϴ� ���� ü�谡 10������ �ƴ϶�� ���� �˾Ƴ½��ϴ�. (2 ~9���� �� �ϳ��Դϴ�.)
//
//���ĵ� �� �� ���� ������ �ᱣ���� ������ ������, ����� �� ������ ����ϴ� ������ �µ��� ������ �ᱣ���� ä�� ������ �մϴ�.
//
//������ �� �����Դϴ�.
//
//<����>
//
//14 + 3 = 17
//13 - 6 = X
//51 - 5 = 44
//X�� ǥ�õ� �κ��� ������ �ᱣ���Դϴ�.
//51 - 5 = 44���� �� ������ ����ϴ� ������ 8�������� �� �� �ֽ��ϴ�.���� 13 - 6 = X�� ������ �ᱣ���� ä�� ������ 13 - 6 = 5�� �˴ϴ�.
//
//������ �� �ٸ� �����Դϴ�.
//
//<����>
//
//1 + 1 = 2
//1 + 3 = 4
//1 + 5 = X
//1 + 2 = X
//�־��� ���ĵ鿡�� �� ������ ����� ������ 6 ~9���� �� �ϳ����� �� �� �ֽ��ϴ�.
//1 + 5 = X�� �ᱣ���� 6������ �� 10, 7 ~9������ �� 6�� �˴ϴ�.�̿� ���� �ᱣ���� ��Ȯ���� ������ ? �� ����� 1 + 5 = ? �� ���� �ᱣ���� ä�� �ֽ��ϴ�.
//1 + 2 = X�� �ᱣ���� 6 ~9�������� ��� 3���� �����ϴ�.���� 1 + 2 = X�� ������ �ᱣ���� ä�� ������ 1 + 2 = 3�� �˴ϴ�.
//
//���� Ȥ�� ���� ���ĵ��� ��� 1���� ���ڿ� �迭 expressions�� �Ű������� �־����ϴ�.
// �̶� �ᱣ���� ������ ���ĵ��� �ᱣ���� ä�� �־� ������� ���ڿ� �迭�� ��� return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

// �� �ؿ� �ؼ�

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


// �־��� ���� 10������
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

// �־��� ���� ������ ������� �����ϰ� 10������ ��ȯ �� ��� �Ͽ� �´��� Ȯ�� ( ex) 12 + 5 = 17�� 8�������� �´��� Ȯ���ϱ� ���� 10������ ��ȯ)
// X�� ǥ���� ���� �ռ� ����� ���� �ĺ��� ������ 10���� �������� ����ϰ� N������ ��ȯ.
// �ռ� ����� ����� �ٸ��� "?"