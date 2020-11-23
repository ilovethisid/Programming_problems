#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	int* A;
	int* length;
	int lgst_length_total = 1;

	cin >> N;

	A = new int[N];
	length = new int[N];
	// length[i] : largest length of increasing sequence
	// which ends with A[i]

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		length[i] = 1;
	}
	// get inputs

	if (N == 1)
	{
		cout << lgst_length_total << endl;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			int lgst_length = 0;

			for (int j = 0; j < i; j++) 
			{	
				if (A[j] < A[i])
				{
					if (length[j] + 1 > lgst_length)
					{
						lgst_length = length[j] + 1;
					}
				}
			}

			if (lgst_length == 0)
			{
				lgst_length = 1;
			}

			length[i] = lgst_length;
			
			if (lgst_length > lgst_length_total)
			{
				lgst_length_total = lgst_length;
			}
		}

		cout << lgst_length_total << endl;
	}
}