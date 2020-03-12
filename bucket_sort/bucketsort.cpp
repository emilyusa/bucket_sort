#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void bucket_sort(float a[], int n)
{
	vector<vector<float>> b(n);

	// 2) Put array elements in different buckets 
	for (int i = 0; i < n; i++)
	{
		int bi = n * a[i]; // Index in bucket 
		b[bi].push_back(a[i]);
	}

	// 3) Sort individual buckets 
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());

	// 4) Concatenate all buckets into arr[] 
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			a[index++] = b[i][j];
}

int main()
{
	float a[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	int n = sizeof(a) / sizeof(a[0]);

	bucket_sort(a, n);

	for (int i = 0; i < n; i++) 
		printf("%f ", a[i]);

	return 0;
}