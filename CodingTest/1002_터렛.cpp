//�������� ���ȯ�� �ͷ��� �ٹ��ϴ� �����̴�.������ ���� ���簨�� ��� �α����� �������� �ʴ´�.
// ������ �������� ���ȯ�� �����̴�.
//
//
//
//�̼����� �������� ���ȯ���� ����� ����(�����)�� ��ġ�� ����϶�� ����� ���ȴ�.
// �������� ���ȯ�� ���� �ڽ��� �ͷ� ��ġ���� ���� �������� �Ÿ��� ����ߴ�.
//
//�������� ��ǥ (x_1, y_1)�� ���ȯ�� ��ǥ (x_2, y_2)�� �־�����,
// �������� ����� �������� �Ÿ� r_1�� ���ȯ�� ����� �������� �Ÿ� r_2�� �־����� ��,
// ������� ���� �� �ִ� ��ǥ�� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.


#include <iostream>
#include <cmath>

using namespace std;

double GetDistance(int x, int y, int x2, int y2)
{
	return sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		pair<int, int> Pos1;
		pair<int, int> Pos2;

		int r1, r2;

		cin >> Pos1.first >> Pos1.second;
		cin >> r1;
		cin >> Pos2.first >> Pos2.second;
		cin >> r2;
		
		if (Pos1.first == Pos2.first && Pos1.second == Pos2.second && r1 == r2)
		{
			cout << "-1" << endl;
			continue;
		}

		double Distance = GetDistance(Pos1.first, Pos1.second, Pos2.first, Pos2.second);
		if (abs(r1 - r2) == Distance || r1 + r2 == Distance) cout << "1" << endl;
		else if (abs(r1 - r2) < Distance && Distance < (r1 + r2)) cout << "2" << endl;
		else cout << "0" << endl;
	}
}