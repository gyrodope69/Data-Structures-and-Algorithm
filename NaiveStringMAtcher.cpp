#include <bits/stdc++.h>
using namespace std;

void matchString(string s, string p)
{
  int n = s.length();
  int m = p.length();
  for (int i = 0; i <= n - m; i++)
  {
    int j;
    for (j = 0; j < m; j++)
    {
      if (s[i + j] != p[j])
      {
        break;
      }
    }
    if (j == m)
    {
      cout << "Pattern found at index" << i << endl;
      // return;
    }
  }
}

int main()
{
  string s, p;
  cin >> s;
  cin >> p;
  matchString(s, p);
  return 0;
}