//������ȭ����� ���� ���� ���Ƹ����� ���Ƹ� Ȱ���� �ϴ� ������ �����̴� ���� �ð��� ƴŸ ���ھ߱� ������ �ϱ�� �ߴ�.
//
//������ 1���� 9������ ���� �ٸ� ���� �� ���� ������ �� �ڸ� ���� ���������� �����Ѵ�. (��: 324)
//�����̴� 1���� 9������ ���� �ٸ� ���� �� ���� ������ �� �ڸ� ���� �������� ���´�. (��: 123)
//�����̰� ���� �� �ڸ� ���� �ִ� ���ڵ� �� �ϳ��� ������ �� �ڸ� ���� ������ �ڸ��� ��ġ�ϸ� ��Ʈ����ũ �� ������ ����.
// ���ڰ� ������ �� �ڸ� ���� �ֱ� �ϳ� �ٸ� �ڸ��� ��ġ�ϸ� �� �� ������ ����.
//��) ������ 324�� ���� ������
//	429�� 1 ��Ʈ����ũ 1 ���̴�.
//	241�� 0 ��Ʈ����ũ 2 ���̴�.
//	924�� 2 ��Ʈ����ũ 0 ���̴�.
// 
//������ �����̰� ���� ���� �� ��Ʈ����ũ �� �������� �����ش�.
//�����̰� ������ �� �ڸ� ���� ��Ȯ�ϰ� ���߾� 3 ��Ʈ����ũ�� �Ǹ� ������ ������.
// �ƴ϶�� �����̴� ���ο� ���� ������ �ٽ� �������� ���´�.
//���� �����̿� ������ ������ �ϰ� �ִ� ���߿� �ִ�.
// �����̰� �������� � ������ ����Ҵ���, �׸��� ������ ������ ������ � ����� �ߴ����� �Է����� �־�����.
// �� �Է��� �������� �������� ������ �����ϰ� ���� ���ɼ��� �ִ� ���� �� �� �������� �˾Ƹ����� �Ѵ�.
//
//�Ʒ��� ���� ��츦 �����غ���.
//	����: 123
//	���� : 1 ��Ʈ����ũ 1 ��.
//	���� : 356
//	���� : 1 ��Ʈ����ũ 0 ��.
//	���� : 327
//	���� : 2 ��Ʈ����ũ 0 ��.
//	���� : 489
//	���� : 0 ��Ʈ����ũ 1 ��.
//�̶� ������ ���� 324�� 328, �̷��� �� �����̴�.
//
//������ ���Ƹ��� ������ �� ������ ���� ���̶� �������� ������ ���̰��� �����ϰ� ���Ѵ�.
// �׷��Ƿ� ������ ��鿡�� ����� ����.
//
//�������� ������� ������ ������ ���� ������ ���� �Է����� �־��� �� 
// ������ �����ϰ� ���� ���ɼ��� �ִ� ���� �� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct BaseBall
{
	int Suggestion;
	int Strike;
	int Ball;

	BaseBall() {}
	BaseBall(int sug, int str, int b) :Suggestion(sug), Strike(str), Ball(b){}
};

bool FindDuplicateAndZero(int x)
{
	string str = to_string(x);
	
	if (str[0] == '0' || str[1] == '0' || str[2] == '0'
		|| str[0] == str[1] || str[0] == str[2] || str[1] == str[2])
		return true;

	return false;
}

pair<int, int> FindSkriteBall(int Ans, int x)
{
	int Skrite{ 0 };
	int Ball{ 0 };

	string AnsString = to_string(Ans);
	string XString = to_string(x);

	if (AnsString[0] == XString[0]) Skrite++;
	if (AnsString[1] == XString[1]) Skrite++;
	if (AnsString[2] == XString[2]) Skrite++;

	if (AnsString[0] == XString[1]) Ball++;
	if (AnsString[0] == XString[2]) Ball++;
	if (AnsString[1] == XString[0]) Ball++;
	if (AnsString[1] == XString[2]) Ball++;
	if (AnsString[2] == XString[0]) Ball++;
	if (AnsString[2] == XString[1]) Ball++;

	return { Skrite, Ball };
}

int main()
{
	int N;
	cin >> N;

	vector<bool> Candidate(987 + 1, true);
	for (int i = 123; i < Candidate.size(); i++)
	{
		Candidate[i] = !FindDuplicateAndZero(i);
	}

	vector<BaseBall> Try;
	for (int i = 0; i < N; i++)
	{
		int Suggestion, Strike, Ball;
		cin >> Suggestion >> Strike >> Ball;
		Try.emplace_back(BaseBall{ Suggestion, Strike, Ball });

		for (int i = 123; i < Candidate.size(); i++)
		{
			if (!Candidate[i]) continue;

			pair<int, int> TempBaseBall = FindSkriteBall(Suggestion, i);
			if (TempBaseBall.first != Strike || TempBaseBall.second != Ball)
			{
				Candidate[i] = false;
			}
			else
			{
				//cout << i << " ";
			}
		}
	}

	cout << count(Candidate.begin() + 123, Candidate.end(), true);
}


//1. ������ Ƚ�� n�� �Է¹޴´�.
//2. ����� �迭�� �ϴ��� ��� true�� �����Ѵ�.
//3. 123���� 987���� ���� 0�� �����ϰų� �ߺ� ���� �ִ� ��� ����� �迭�� �ش� �ε����� false�� �����Ѵ�.
//4. n�� �ݺ��ϸ� �Ʒ��� �����Ѵ�.
//	4 - 1. ���ڸ� ����, ��Ʈ����ũ ����, �� ������ �Է¹޴´�.
//	4 - 2. 123���� 987���� ���� true�� �ε����� ���� ��Ʈ����ũ�� �� ������ �˻��Ѵ�.
//	4 - 3. ���� ��Ʈ����ũ�� �� ������ �Է¹޾Ҵ� ���ڿ� �ϳ��� �ٸ� �ε����� �߰��ϸ� �ش� �ε����� ����� �迭�� false�� �ٲ۴�.
//5. 123���� 987���� ���� ����� �迭���� true�� ���� Ƚ���� �� ����Ѵ�.