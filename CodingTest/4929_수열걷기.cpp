//길이가 유한하고, 오름차순 순서로 되어있는 두 수열이 주어진다.
// 두 수열에 공통으로 들어있는 원소는 교차점으로 생각할 수 있다.
//
//아래는 두 수열과 교차점은 굵게 나타낸 것이다.//
//	수열 1 = 3 5 '7' 9 20 '25' 30 40 '55' 56 '57' 60 62
//	수열 2 = 1 4 '7' 11 14 '25' 44 47 '55' '57' 100
//
//이 두 수열은 다음과 같이 걸을 수 있다.
//	1. 두 수열중 하나의 첫 번째 원소에서 걷기를 시작한다.걷는 것은 앞으로만 걸을 수 있다.
//	2. 교차점에 도착했을 때는, 현재 수열에서 계속 걸을지, 다른 수열로 갈아탈지 결정할 수 있다.
//방문한 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하시오.
//위의 예에서 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, 62와 같이 걷는다면 합이 450으로 최대가 된다.

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    std::string line;

    // 표준 입력을 개행 단위로 읽기
    while (std::getline(std::cin, line)) {
        std::vector<int> Numbers1;
        std::vector<int> Numbers2;

        map<int, int> NumVisited;
        map<int, int> NumVisited2;

        std::stringstream ss(line);
        int number;

        if (line == "0") break;

        // 공백을 기준으로 각 숫자를 분리
        int Count{ 0 };
        while (ss >> number) {
            if (Numbers1.capacity() == 0)
                Numbers1.reserve(number);
            else
            {
                Numbers1.push_back(number);
                NumVisited.insert({ number,Count++ });
            }
        }

        Count = 0;
        std::getline(std::cin, line);
        std::stringstream ss2(line);
        // 공백을 기준으로 각 숫자를 분리
        while (ss2 >> number) {
            if (Numbers2.capacity() == 0)
                Numbers2.reserve(number);
            else
            {
                Numbers2.push_back(number);
                if (NumVisited.find(number) != NumVisited.end())
                {
                    NumVisited2.insert({ number,Count });
                }
                Count++;
            }
        }

        auto it = Numbers1.begin();
        auto it2 = Numbers2.begin();
        int Sum{ 0 };
        for (const auto& visited : NumVisited2)
        {
            int Num = visited.first;

            // 현재 구역부터 다음 겹치는 구간까지의 합
            auto NextIt = find(it, Numbers1.end(), Num);
            auto NextIt2 = find(it2, Numbers2.end(), Num);
            int SplitSum = accumulate(it, NextIt, 0);
            int SplitSum2 = accumulate(it2, NextIt2, 0);

            it = NextIt; it2 = NextIt2;

            Sum = max(Sum + SplitSum, Sum + SplitSum2);
        }


        int SplitSum = accumulate(it, Numbers1.end(), 0);
        int SplitSum2 = accumulate(it2, Numbers2.end(), 0);
        Sum = max(Sum + SplitSum, Sum + SplitSum2);

        cout << Sum << endl;
    }
}