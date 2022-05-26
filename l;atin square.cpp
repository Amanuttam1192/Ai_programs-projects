// C++ program to print Latin Square
#include <iostream>
using namespace std;

// Function to print n x n Latin Square
void printLatin(int n)
{
	// A variable to control the rotation
	// point.
	int k = n+1;

	// Loop to print rows
	for (int i=1; i<=n; i++)
	{
		// This loops runs only after first
		// iteration of outer loop. It prints
		// numbers from n to k
		int temp = k;
		while (temp <= n)
		{
			cout << temp << " ";
			temp++;
		}

		// This loop prints numbers from 1 to k-1.
		for (int j=1; j<k; j++)
			cout << j << " ";

		k--;
		cout << endl;
	}
}

// Driver program to test above function
int main(void)
{
	int n = 5;

	// Invoking printLatin function
	printLatin(n);

	return 0;
}

// This code is contributed by kothavvsaakash.

