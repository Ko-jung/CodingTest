#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
	int answer = 0;

	int RideStart = distance(onboard.begin(), find(onboard.begin(), onboard.end(), 1));
	int RideEnd = onboard.size() - distance(onboard.rbegin(), find(onboard.rbegin(), onboard.rend(), 1)) - 1;

	// 1. 최소 목표에 맞추기
	//  - 1. 쭉쭉 틀다가 마지막에 꺼버리기 
	int Target1 = temperature > t2 ? t2 : t1;	// Temperature가 어디에 더 가까운지
	int AirOnTime = abs(temperature - Target1);
	int Case1 = AirOnTime * a + (RideEnd - AirOnTime) * b;
	
	// 2. 최소 목표보다 더 낮추거나 올려서 도중에 에어컨을 끄기
	//  - 1. 맨뒤 1에 딱맞게 나오는 에어컨 온도 찾기 
	int TargetIndex = (((float)RideEnd + RideStart) / 2) + 0.5;

	int Target2 = (temperature > t2 ? t2 - (TargetIndex - RideStart) : t1 - (RideEnd - TargetIndex));
	AirOnTime = abs(temperature - Target2);
	int Case2 = AirOnTime * a;

	// 그 사이로 완전탐색?
	//answer = min(Case1, Case2);
	int Start, End;
	Case1 > Case2 ? (Start = Case2, End = Case1) : (Start = Case1, End = Case2);
	Start++;
	for (Start; Start < End; Start++)
	{

	}

	// 실내온도와 희망온도가 다르다면 1분 뒤 실내온도가 희망온도와 같아지는 방향으로 1도 상승 또는 하강합니다.
	// 희망온도와 실내온도가 다르다면 매 분 전력을 a만큼 소비하고,
	// 
	// 실내온도가 희망온도와 같다면 에어컨이 켜져 있는 동안은 실내온도가 변하지 않습니다.
	// 희망온도와 실내온도가 같다면 매 분 전력을 b만큼 소비합니다. 

	return answer;
}

int main()
{
	cout << solution(28, 18, 26, 10, 8, {0, 0, 1, 1, 1, 1, 1}) << endl;
	cout << solution(-10, -5, 5, 5, 1, {0, 0, 0, 0, 0, 1, 0}) << endl;
	cout << solution(11, 8, 10, 10, 1, {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1}) << endl;
	cout << solution(11, 8, 10, 10, 100, {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1}) << endl;
}

// ================================ 답 ================================ 
// #include <string>
//#include <vector>
//#include <algorithm>
//
//#define MAX 99999999 // min에 걸리지 않을만큼 큰 값
//using namespace std;
//
//int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
//    int dp[1001][55]; // 온도 인덱스를 넉넉히
//    int answer = MAX;
//    int unit; // 외부온도로 가는 단위
//    int start, end; // 탐색 시작 ~ 종료 범위
//
//    fill(&dp[0][0], &dp[1000][55], MAX); // dp 배열을 MAX로 초기화
//
//    // 15씩 더해서 음수 없애줌
//    t1 += 15;
//    t2 += 15;
//    temperature += 15;
//
//    // t1보다 작은 경우 -> temperature = 최솟값
//    if (temperature < t1) {
//        unit = -1;
//        start = temperature;
//        end = t2;
//    }
//
//    //  t2보다 큰 경우 -> temperature = 최댓값
//    else {
//        unit = 1;
//        start = t1;
//        end = temperature;
//    }
//
//    // 초기 dp 값 세팅
//    dp[0][temperature] = 0;
//    dp[0][temperature - unit] = a;
//
//    for (int i = 1; i < onboard.size(); i++) {
//        for (int j = start; j <= end; j++) {
//            // 승객이 있을때는 온도가 t1 ~ t2 사이여야 함
//            if (onboard[i] == 1 && (j < t1 || j > t2)) continue;
//            // 온도가 외부온도와 같을 때(특수한 경우)
//            if (j == temperature) {
//                // 1. j 온도에서 OFF 2. j-unit 온도에서 OFF
//                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - unit]);
//            }
//            else {
//                // 1.j 온도에서 ON으로 유지  2.j+unit 온도에서 ON
//                dp[i][j] = min(dp[i - 1][j] + b, dp[i - 1][j + unit] + a);
//                // 3.j-unit 온도에서 OFF
//                dp[i][j] = min(dp[i][j], dp[i - 1][j - unit]);
//            }
//            // 마지막일 경우 해당 값으로 답을 찾음
//            if (i == onboard.size() - 1) answer = min(answer, dp[i][j]);
//        }
//    }
//    return answer;
//}
//