//���̰� �����ϰ�, �������� ������ �Ǿ��ִ� �� ������ �־�����.
// �� ������ �������� ����ִ� ���Ҵ� ���������� ������ �� �ִ�.
//
//�Ʒ��� �� ������ �������� ���� ��Ÿ�� ���̴�.//
//	���� 1 = 3 5 '7' 9 20 '25' 30 40 '55' 56 '57' 60 62
//	���� 2 = 1 4 '7' 11 14 '25' 44 47 '55' '57' 100
//
//�� �� ������ ������ ���� ���� �� �ִ�.
//	1. �� ������ �ϳ��� ù ��° ���ҿ��� �ȱ⸦ �����Ѵ�.�ȴ� ���� �����θ� ���� �� �ִ�.
//	2. �������� �������� ����, ���� �������� ��� ������, �ٸ� ������ ����Ż�� ������ �� �ִ�.
//�湮�� ���� ���� �ִ밡 �Ǵ� ��θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//���� ������ 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, 62�� ���� �ȴ´ٸ� ���� 450���� �ִ밡 �ȴ�.

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

    // ǥ�� �Է��� ���� ������ �б�
    while (std::getline(std::cin, line)) {
        std::vector<int> Numbers1;
        std::vector<int> Numbers2;

        map<int, int> NumVisited;
        map<int, int> NumVisited2;

        std::stringstream ss(line);
        int number;

        if (line == "0") break;

        // ������ �������� �� ���ڸ� �и�
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
        // ������ �������� �� ���ڸ� �и�
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

            // ���� �������� ���� ��ġ�� ���������� ��
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