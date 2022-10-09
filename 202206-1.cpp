#include <iostream>
#include <math.h>


using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin >> n;
	float nums[1005];
	nums[n] = 0;
	nums[n + 1] = 0;
	for (int i = 0; i < n; i++) 
	{
		cin >> nums[i];
		nums[n] += nums[i];
	}
	nums[n] /= n;
	for (int i = 0; i < n; i++)
	{
		nums[n + 1] += pow(nums[i] - nums[n], 2);
	}
	nums[n + 1] /= n;
	for (int i = 0; i < n; i++)
	{
		nums[i] =(nums[i] - nums[n]) / sqrt(nums[n + 1]);
		cout << nums[i] << endl; 
	}
	return 0;
}
