#include <string>
#include<stack>

using namespace std;
bool isOperand(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;
	return false;
}

int isHigherOrder(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}
	else if (c == '*' || c == '/') {
		return 2;
	}
	else if (c == '^') {
		return 3;
	}
	else
		return -1;
}
int operation(char op, int val1, int val2) {
	if (op == '+')
		return val1 + val2;
	else if (op == '-')
		return val1 - val2;
	else if (op == '*')
		return val1 * val2;
	else if (op == '/')
		if (val1)
			return val1 / val2;
		else if (op == '^')
			return pow(val1, val2);
		else
			return 0;
}

///----------------------------------------------------------------------------------
/// Given an expression in infix-notation, converts it to a string in post-fix notation 
/// 
string Infix2Postfix(string& s) {
	// Fill this in
	stack<char>st;
	string result;
	int i = 0;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == ' ')
			continue;
		if (isOperand(s[i])) {
			result += " ";
		}
		if (isdigit(s[i])) {
			result += s[i];
		}
		else if (s[i] == '(')
		{
			st.push('(');
		}
		else if (s[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				result += st.top();
				st.pop();
			}
			if (st.top() == '(') {
				char c = st.top();
				st.pop();
			}
		}
		else
		{
			while (!st.empty() && isHigherOrder(s[i]) <= isHigherOrder(st.top())) {
				result += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	return result;
} // end-Infix2Postfix

///----------------------------------------------------------------------------------
/// Given a string in post-fix notation, evaluates it and returns the result
/// 
int EvaluatePostfixExpression(string& s) {
	stack<int>values;
	stack<char>ops;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ')
			continue;
	while (!ops.empty()) {
			char op = ops.top();
			ops.pop();
			int val2 = values.top();
			values.pop();
			int val1 = values.top();
			values.pop();

			values.push(operation(op, val1, val2));
			}
			if (!ops.empty()) {
				ops.pop();
			}
		    else if (isdigit(s[i])) {
			  int num = 0;
			while (i < s.length() && isdigit(s[i])) {
				num = (num * 10) + (s[i] - '0');
				i++;
			}
			i--;
			values.push(num);
	     	}
		    else {
			while (!ops.empty() && isHigherOrder(ops.top()) >= isHigherOrder (s[i])) {
				int val2 = values.top();
				values.pop();

				int val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();
				int result = operation(op, val1, val2);

				values.push(result);
			}

			ops.push(s[i]);
			}

		while (!ops.empty()) {
			int val2 = values.top();
			values.pop();

			int val1 = values.top();
			values.pop();

			char op = ops.top();
			ops.pop();

			int result = operation(op, val1, val2);

			values.push(result);
		}
	}

	return values.top();
}
