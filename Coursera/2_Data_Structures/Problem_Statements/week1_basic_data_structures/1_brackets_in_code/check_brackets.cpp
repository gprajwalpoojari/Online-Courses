#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        struct Bracket bracket(next, position + 1);   
        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(bracket);    
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty()) {
                std::cout << bracket.position;
                return 0;
            }
            struct Bracket temp = opening_brackets_stack.top();
            if (temp.Matchc(bracket.type)) {
                opening_brackets_stack.pop();
            }
            else {
                std::cout << bracket.position;
                return 0;
            }
        }
    }

    // Printing answer, write your code here
    if (opening_brackets_stack.empty()) {
       std::cout << "Success";
    }
    else {
        struct Bracket bracket = opening_brackets_stack.top();
        std::cout << bracket.position;
        //std::cout << bracket.position;
    }
}
