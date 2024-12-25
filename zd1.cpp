#include <iostream>
#include <stack>
#include <string>

using namespace std; 

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

void checkBrackets(const string& str) {
    stack<char> bracketStack;

    for (size_t i = 0; i < str.size(); ++i) {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            bracketStack.push(ch);  
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (bracketStack.empty() || !isMatchingPair(bracketStack.top(), ch)) {
                cout << "Помилка в позиції " << i << ": " << str.substr(0, i + 1) << endl;
                return;
            }
            bracketStack.pop();  
        }
        else if (ch == ';') {
            break;  
        }
    }

    if (bracketStack.empty()) {
        cout << "Рядок коректний." << endl;
    }
    else {
        cout << "Помилка: залишилися невідповідні дужки." << endl;
    }
}

int main() {
    string input;
    cout << "Введіть рядок (закінчуйте символом ';'): ";
    getline(cin, input);

    checkBrackets(input);
    return 0;
}
