//다음 소스는 N번째 피보나치 수를 구하는 C++ 함수이다.
//
//			int fibonacci(int n) {
//			    if (n == 0) {
//			        printf("0");
//			        return 0;
//			    }
//			    else if (n == 1) {
//			        printf("1");
//			        return 1;
//			    }
//			    else {
//			        return fibonacci(n‐1) + fibonacci(n‐2);
//			    }
//			}
// 
//fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.//
//		fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
//		fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
//		두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
//		fibonacci(0)은 0을 출력하고, 0을 리턴한다.
//		fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
//		첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
//		fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.
// 
//1은 2번 출력되고, 0은 1번 출력된다.N이 주어졌을 때, fibonacci(N)을 호출했을 때,
// 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	vector<pair<int, int>> DP(40 + 1);
	DP[0] = pair<int, int>(1, 0);
	DP[1] = pair<int, int>(0, 1);
	for (int i = 2; i < DP.size(); i++)
	{
		DP[i].first = DP[i - 1].first + DP[i - 2].first;
		DP[i].second = DP[i - 1].second + DP[i - 2].second;
	}
	for (int TestCase = 0; TestCase < T; TestCase++)
	{
		int N;
		cin >> N;

		cout << DP[N].first << " " << DP[N].second << endl;
	}
}