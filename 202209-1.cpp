#include "iostream"

using namespace std;

int main(void)
{
	int n, m;
	int ai;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> ai;
		cout << m % ai << " ";
		m /= ai;
	}
	return 0;
}
