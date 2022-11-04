#include <iostream>
#include <vector>
#include <string>
int main() {
    std::vector<std::string> s = {"(", "{", "}", "[", "]", ")", "(", ")", "[", "]"};
    std::vector<std::string> stack = {};
    stack.push_back(s.at(0));
    for (int i = 1; i < s.size(); i++) {
        stack.push_back(s.at(i));
        int n = stack.size();
        if (stack.at(n - 1) == ")" && stack.at(n - 2) == "(") {
            stack.pop_back();
            stack.pop_back();

        } else if (stack.at(n - 1) == "]" && stack.at(n - 2) == "[") {
            stack.pop_back();
            stack.pop_back();

        } else if (stack.at(n - 1) == "}" && stack.at(n - 2) == "{") {
            stack.pop_back();
            stack.pop_back();

        }
        if (stack.empty() && i < s.size() - 1) {
            stack.push_back(s.at(i + 1));
            i++;
        }
    }
    if (stack.empty()){
        std::cout << "Correct sequence" << std::endl;
    }
    else{
        std::cout << "Incorrect sequence" << std::endl;
    }
}


