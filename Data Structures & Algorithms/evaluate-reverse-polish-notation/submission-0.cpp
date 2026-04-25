class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         std::stack<int> stack;
  for (std::string &t : tokens) {
    if (t == "+") {
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      stack.push(b + a);
    } else if (t == "-") {
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      stack.push(b - a);
    } else if (t == "*") {
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      stack.push(b * a);
    } else if (t == "/") {
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      stack.push(static_cast<int>(static_cast<double>(b) / a));
    } else {
      stack.push(std::stoi(t));
    }
  }
    return stack.top();
 
    }
};
