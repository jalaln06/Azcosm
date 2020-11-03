#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

long long PostfixNotation(string str)
{
	stack <long long> postfix;
	long long x = 0, y = 0, result = 0, symbol = 0; //x lower than y : first x than y
	for (size_t i = 0; i < (size_t)str.length(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9') //if str[i] - number
		{
			symbol = (long long)(str[i] - '0'); //cinvert (char)str[i] to long long
			postfix.push(symbol);
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*')
		{
			y = postfix.top();
			postfix.pop();
			x = postfix.top();
			postfix.pop();
			switch (str[i])
			{
			case '+':
			{
				result = x + y; //sum in int
				break;
			}
			case '-':
			{
				result = x - y; //minus in int
				break;
			}
			case '*':
			{
				result = x * y; //multiplication in int
				break;
			}
			}
			postfix.push(result);
		}
	}
	return postfix.top();
}

int main()
{
	ifstream fin("postfix.in");
	ofstream fout("postfix.out");
	string str;
	getline(fin, str);
	long long result = PostfixNotation(str);
	fout << result;
	return 0;
}