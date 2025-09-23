#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <algorithm>

using namespace std;

long GetDist(const pair<int, int>& a, const pair<int, int>& b)
{
	long dX = a.first - b.first;
	long dY = a.second - b.second;
	return dX * dX + dY * dY;
}

// �̰� ������ �ݺ�
long CloserPoint(const vector<pair<int, int>>& Points, int Left, int Right)
{
	//cout << Left << ", " << Right << endl;
	long Answer = numeric_limits<long>::max();
	if (Left >= Right) return Answer;

	// 3������ �� ���Ʈ������ ������ ����X
	if (Right - Left <= 3)
	{
		for (int i = Left; i <= Right; i++)
		{
			for (int j = i + 1; j <= Right; j++)
			{
				Answer = min(Answer, GetDist(Points[i], Points[j]));
			}
		}
	}
	//        0  9
	//      0 4, 5 9
	// 0 2, 3 4, 5 7, 8 9
	else
	{
		// 3. �켱������ 1, 2�� ���ؼ� �ּڰ��� ã�´�. D = min(d1, d2)	
		int Mid = (Left + Right) / 2;
		long d1 = CloserPoint(Points, Left, Mid);
		long d2 = CloserPoint(Points, Mid + 1, Right);
		Answer = min(d1, d2);

		vector< pair<int, int>> Candidate;
		Candidate.reserve(Right - Left + 1);
		int MiddleX = (Points[Mid].first + Points[Mid + 1].first) / 2;
		for (int i = Left; i <= Right; i++)
		{
			// 4. D�� �̿��ؼ� 3�� ���� �� �����Ű����� ������� ���� �ʴ´�
			if ((MiddleX - Points[i].first) * (MiddleX - Points[i].first) >= Answer) continue;

			// 5. (3)�̶�°� ��ü�� �������� �������� �¿� ���� ��Ƽ� ����ϴ� ����
			// 6. x��ǥ�� [-D, +D] ���̿� �ִ� ���� �񱳸� �ϰڴ�. �� �̻��� ������ D���� ũ��
			Candidate.push_back(Points[i]);
		}

		// 7. ���� [-D, +D] ���̿� �ִ� ���鸸 y��ǥ�� �������� ������ �Ѵ�.
		sort(Candidate.begin(), Candidate.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
			return a.second < b.second;
			});

		// 8. y�� ���� ���� ��ǥ���� ���� y+D���� �񱳸� �Ѵ�.
		// 		�� �񱳴� 7���� ���� �ʴ´ٴµ� �� ���� ��
		for (int i = 0; i + 1 < Candidate.size(); i++)
		{
			for (int j = i + 1; j < Candidate.size(); j++)
			{
				if ((Candidate[i].second - Candidate[j].second) * (Candidate[i].second - Candidate[j].second) >= Answer) break;

				long Dist = GetDist(Candidate[i], Candidate[j]);				
				Answer = min(Answer, Dist);
			}
		}
	}

	return Answer;
}

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> Points(N, pair<int,int>());
	for (auto& point : Points)
	{
		cin >> point.first >> point.second;
	}

	// ���� ���� �ذ��
	// 1.x�� ���� �� (n/2+(n+1)/2) / 2�� �߾� ���� ���� ����
	sort(Points.begin(), Points.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.first < b.first;
		});

	// 2. �׷��� �� 3��
	//		(1). ���ʿ��� �������� ������ ����,
	//		(2). �����ʿ��� ���������� ������ ����
	//		(3). ���ʿ��� ���������� ������ ����,
	//		���� ������ 3�� �� �ּڰ��� ������ �ǰڴ�

	long Answer = CloserPoint(Points, 0, N - 1);

	cout << Answer;
}