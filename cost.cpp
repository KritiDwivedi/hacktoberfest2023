
// CPP code to calculate the minimum cost
// to make the given parentheses balanced
#include <bits/stdc++.h>
using namespace std;

int costToBalance(string s)
{
	if (s.length() == 0)
		cout << 0 << endl;

	// To store absolute count of
	// balanced and unbalanced parentheses
	int ans = 0;

	// o(open bracket) stores count of '(' and
	// c(close bracket) stores count of ')'
	int o = 0, c = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			o++;
		if (s[i] == ')')
			c++;
	}

	if (o != c)
		return -1;

	int a[s.size()];
	if (s[0] == '(')
		a[0] = 1;
	else
		a[0] = -1;

	if (a[0] < 0)
		ans += abs(a[0]);

	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '(')
			a[i] = a[i - 1] + 1;
		else
			a[i] = a[i - 1] - 1;
		if (a[i] < 0)
			ans += abs(a[i]);
	}

	return ans;
}

// Driver code
int main()
{
	string s;
	s = ")))(((";

	cout << costToBalance(s) << endl;

	s = "))((";
	cout << costToBalance(s) << endl;

	return 0;
}
