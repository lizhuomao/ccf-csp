#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, L, S;
	cin >> n >> L >> S;
	L++;
	S++;
	set<pair<int, int> > A, B;
	map<pair<int, int>, int> persum;
	for (int i = 0; i < n; i++)	
	{
		int x, y;
		cin >> y >> x;
		A.insert(make_pair(y, x));
	}
	int tcnt = 0, ans = 0;
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
		{
			int tree;
			cin >> tree;
			if (tree == 1)
			{
				B.insert(make_pair(S - i - 1, j));	
				tcnt++;
			}
			
		}
	}
	for (set<pair<int, int> > :: iterator it = A.begin(); it != A.end(); it++)
	{
		int y = it -> first, x = it -> second;
		if (y + S > L || x + S > L) continue;
		int cnt = 0;
		for (set<pair<int, int> > :: iterator it1 = A.find(make_pair(y, x)); it1 != A.end(); it1++)
		{
			int y1 = it1 -> first, x1 = it1 -> second;
			if (y + S <= y1) break;
			if (x + S <= x1) continue;
			if (y1 >= y && x1 >= x)
			{
				//cout << "cnt" << y1 << " " << x1 << endl;
				cnt++;
			} 
		}
		//cout << y << " "<< x << endl;
		//cout << cnt << endl;
		bool flag = true;
		if (cnt == tcnt)
		{
			for (set<pair<int, int> > :: iterator it2 = B.begin(); it2 != B.end(); it2++)
			{
				if (A.find(make_pair(y + it2 -> first, x + it2 -> second)) == A.end())
				{
					flag = false;
					break;		
				}
			}
			if (flag == true) ans++;
		}
		
	}
	cout << ans;
	return 0;
}
