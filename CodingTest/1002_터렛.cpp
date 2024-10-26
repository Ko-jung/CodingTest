//조규현과 백승환은 터렛에 근무하는 직원이다.하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다.
// 다음은 조규현과 백승환의 사진이다.
//
//
//
//이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다.
// 조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.
//
//조규현의 좌표 (x_1, y_1)와 백승환의 좌표 (x_2, y_2)가 주어지고,
// 조규현이 계산한 류재명과의 거리 r_1과 백승환이 계산한 류재명과의 거리 r_2가 주어졌을 때,
// 류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.


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