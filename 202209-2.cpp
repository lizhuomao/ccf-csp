#include "iostream" 
#include "vector"

using namespace std;

int main(void)
{
	int n, x;
	int a[31], suma = 0;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		suma += a[i];
	}
	vector<vector<int> > p(n + 1, vector<int>(suma + 1));
	for (int i = 0; i < p.size(); i++) p[i][0] = 0;
	for (int i = 0; i < p[0].size(); i++) p[0][i] = 0;
	for (int i = 1; i < p.size(); i++)
	{
		for (int j = 1; j < p[i].size(); j++)
		{
			int temp1, temp2;
			if (j - a[i - 1] < 0) temp1 = 0;
			else temp1 = p[i - 1][j - a[i - 1]] + a[i - 1];
			temp2 = p[i - 1][j];
			if (min(temp1, temp2) >= x) p[i][j] = min(temp1, temp2);
			else p[i][j] = max(temp1, temp2);
		}
	}
	for (int i = x; i <= suma; i++)
	{
		if (p[n][i] >= x)
		{
			cout << p[n][i];
			break;
		}
	}
	return 0;
}
