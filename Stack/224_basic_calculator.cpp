class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int currentNumber = 0;
        int sign = 1;
        stack<int> st;

        for (char c : s) {
            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                result += sign * currentNumber;
                currentNumber = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * currentNumber;
                currentNumber = 0;
                result *= st.top(); st.pop();
                result += st.top(); st.pop();
            }
        }
        result += sign * currentNumber;

        return result;
    }
};