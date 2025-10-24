#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
	int answer = 0;

	int RideStart = distance(onboard.begin(), find(onboard.begin(), onboard.end(), 1));
	int RideEnd = onboard.size() - distance(onboard.rbegin(), find(onboard.rbegin(), onboard.rend(), 1)) - 1;

	// 1. �ּ� ��ǥ�� ���߱�
	//  - 1. ���� Ʋ�ٰ� �������� �������� 
	int Target1 = temperature > t2 ? t2 : t1;	// Temperature�� ��� �� �������
	int AirOnTime = abs(temperature - Target1);
	int Case1 = AirOnTime * a + (RideEnd - AirOnTime) * b;
	
	// 2. �ּ� ��ǥ���� �� ���߰ų� �÷��� ���߿� �������� ����
	//  - 1. �ǵ� 1�� ���°� ������ ������ �µ� ã�� 
	int TargetIndex = (((float)RideEnd + RideStart) / 2) + 0.5;

	int Target2 = (temperature > t2 ? t2 - (TargetIndex - RideStart) : t1 - (RideEnd - TargetIndex));
	AirOnTime = abs(temperature - Target2);
	int Case2 = AirOnTime * a;

	// �� ���̷� ����Ž��?
	//answer = min(Case1, Case2);
	int Start, End;
	Case1 > Case2 ? (Start = Case2, End = Case1) : (Start = Case1, End = Case2);
	Start++;
	for (Start; Start < End; Start++)
	{

	}

	// �ǳ��µ��� ����µ��� �ٸ��ٸ� 1�� �� �ǳ��µ��� ����µ��� �������� �������� 1�� ��� �Ǵ� �ϰ��մϴ�.
	// ����µ��� �ǳ��µ��� �ٸ��ٸ� �� �� ������ a��ŭ �Һ��ϰ�,
	// 
	// �ǳ��µ��� ����µ��� ���ٸ� �������� ���� �ִ� ������ �ǳ��µ��� ������ �ʽ��ϴ�.
	// ����µ��� �ǳ��µ��� ���ٸ� �� �� ������ b��ŭ �Һ��մϴ�. 

	return answer;
}

int main()
{
	cout << solution(28, 18, 26, 10, 8, {0, 0, 1, 1, 1, 1, 1}) << endl;
	cout << solution(-10, -5, 5, 5, 1, {0, 0, 0, 0, 0, 1, 0}) << endl;
	cout << solution(11, 8, 10, 10, 1, {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1}) << endl;
	cout << solution(11, 8, 10, 10, 100, {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1}) << endl;
}

// ================================ �� ================================ 
// #include <string>
//#include <vector>
//#include <algorithm>
//
//#define MAX 99999999 // min�� �ɸ��� ������ŭ ū ��
//using namespace std;
//
//int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
//    int dp[1001][55]; // �µ� �ε����� �˳���
//    int answer = MAX;
//    int unit; // �ܺοµ��� ���� ����
//    int start, end; // Ž�� ���� ~ ���� ����
//
//    fill(&dp[0][0], &dp[1000][55], MAX); // dp �迭�� MAX�� �ʱ�ȭ
//
//    // 15�� ���ؼ� ���� ������
//    t1 += 15;
//    t2 += 15;
//    temperature += 15;
//
//    // t1���� ���� ��� -> temperature = �ּڰ�
//    if (temperature < t1) {
//        unit = -1;
//        start = temperature;
//        end = t2;
//    }
//
//    //  t2���� ū ��� -> temperature = �ִ�
//    else {
//        unit = 1;
//        start = t1;
//        end = temperature;
//    }
//
//    // �ʱ� dp �� ����
//    dp[0][temperature] = 0;
//    dp[0][temperature - unit] = a;
//
//    for (int i = 1; i < onboard.size(); i++) {
//        for (int j = start; j <= end; j++) {
//            // �°��� �������� �µ��� t1 ~ t2 ���̿��� ��
//            if (onboard[i] == 1 && (j < t1 || j > t2)) continue;
//            // �µ��� �ܺοµ��� ���� ��(Ư���� ���)
//            if (j == temperature) {
//                // 1. j �µ����� OFF 2. j-unit �µ����� OFF
//                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - unit]);
//            }
//            else {
//                // 1.j �µ����� ON���� ����  2.j+unit �µ����� ON
//                dp[i][j] = min(dp[i - 1][j] + b, dp[i - 1][j + unit] + a);
//                // 3.j-unit �µ����� OFF
//                dp[i][j] = min(dp[i][j], dp[i - 1][j - unit]);
//            }
//            // �������� ��� �ش� ������ ���� ã��
//            if (i == onboard.size() - 1) answer = min(answer, dp[i][j]);
//        }
//    }
//    return answer;
//}
//