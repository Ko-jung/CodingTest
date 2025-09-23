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

// 이걸 열나게 반복
long CloserPoint(const vector<pair<int, int>>& Points, int Left, int Right)
{
	//cout << Left << ", " << Right << endl;
	long Answer = numeric_limits<long>::max();
	if (Left >= Right) return Answer;

	// 3이하일 땐 브루트포스를 조져도 문제X
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
		// 3. 우선적으로 1, 2를 구해서 최솟값을 찾는다. D = min(d1, d2)	
		int Mid = (Left + Right) / 2;
		long d1 = CloserPoint(Points, Left, Mid);
		long d2 = CloserPoint(Points, Mid + 1, Right);
		Answer = min(d1, d2);

		vector< pair<int, int>> Candidate;
		Candidate.reserve(Right - Left + 1);
		int MiddleX = (Points[Mid].first + Points[Mid + 1].first) / 2;
		for (int i = Left; i <= Right; i++)
		{
			// 4. D를 이용해서 3을 구할 때 넘을거같은건 계산조차 하지 않는다
			if ((MiddleX - Points[i].first) * (MiddleX - Points[i].first) >= Answer) continue;

			// 5. (3)이라는거 자체가 기준점을 기준으로 좌우 점을 잡아서 계산하는 거임
			// 6. x좌표가 [-D, +D] 사이에 있는 점만 비교를 하겠다. 그 이상은 어차피 D보다 크다
			Candidate.push_back(Points[i]);
		}

		// 7. 이제 [-D, +D] 사이에 있는 점들만 y좌표를 기준으로 정렬을 한다.
		sort(Candidate.begin(), Candidate.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
			return a.second < b.second;
			});

		// 8. y이 가장 작은 좌표부터 위로 y+D까지 비교를 한다.
		// 		이 비교는 7번을 넘지 않는다는데 논문 볼줄 모름
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

	// 분할 정복 해결법
	// 1.x로 정렬 후 (n/2+(n+1)/2) / 2로 중앙 구분 선을 정함
	sort(Points.begin(), Points.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.first < b.first;
		});

	// 2. 그러면 총 3개
	//		(1). 왼쪽에서 왼쪽으로 끝나는 선분,
	//		(2). 오른쪽에서 오른쪽으로 끝나는 선분
	//		(3). 왼쪽에서 오른쪽으로 끝나는 선분,
	//		으로 나뉘며 3개 중 최솟값이 정답이 되겠다

	long Answer = CloserPoint(Points, 0, N - 1);

	cout << Answer;
}