#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
	priority_queue<int> pq;
	pq.empty();

	for (int i = 0; i < enemy.size(); i++)
	{
		pq.push(enemy[i]);
		n -= enemy[i];
		if (n < 0)
		{
			if (k-- <= 0) { return i; }
			n += pq.top();
			pq.pop();
		}
	}
	return enemy.size();
}

int main()
{
	cout << solution(7, 3, {4,2,4,5,3,3,1}) << endl;
}