〈 돌아가기 스킬 체크 테스트 Level.2
C++ 레퍼런스
도움말
컴파일 옵션
테스트 종료
문제1
0 / (50.0)

문제2
47.6 / (50.0)
문제 설명
두 수의 최소공배수(Least Common Multiple)란 입력된 두 수의 배수 중 공통이 되는 가장 작은 숫자를 의미합니다.예를 들어 2와 7의 최소공배수는 14가 됩니다.정의를 확장해서, n개의 수의 최소공배수는 n 개의 수들의 배수 중 공통이 되는 가장 작은 숫자가 됩니다.n개의 숫자를 담은 배열 arr이 입력되었을 때 이 수들의 최소공배수를 반환하는 함수, solution을 완성해 주세요.

제한 사항
arr은 길이 1이상, 15이하인 배열입니다.
arr의 원소는 100 이하인 자연수입니다.
입출력 예
arr	result
[2, 6, 8, 14]	168
[1, 2, 3]	6
solution.cpp
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = arr[0];

    for (int i = 1; i < arr.size(); ++i)
    {
        answer = gcd(answer, arr[i]);
    }

    int Temp = arr[0];
    for (int i = 1; i < arr.size(); ++i)
    {
        Temp = (Temp * arr[i]) / answer;
    }

    return Temp;
}
실행 결과
테스트 1
입력값 〉[2, 6, 8, 14]
기댓값 〉	168
실행 결과 〉	테스트를 통과하였습니다.
테스트 2
입력값 〉[1, 2, 3]
기댓값 〉	6
실행 결과 〉	테스트를 통과하였습니다.
테스트 결과(~˘▾˘)~
2개 중 2개 성공
샘플 테스트 케이스를 통과했다는 의미로, 작성한 코드가 문제의 정답은 아닐 수 있습니다.
(샘플 테스트 케이스는[테스트 케이스 추가하기] 버튼을 통해 확인하실 수 있습니다.)
종료까지
00:01 : 40