#include "RPN.hpp"

RPN::RPN() : stack() {}

RPN::RPN(const RPN& other) : stack(other.stack) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        stack = other.stack;
    return *this;
}

RPN::~RPN() {}

int RPN::ProcessInput(const std::string &input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
            {
                return((std::cerr << "Error: Invalid operators" << std::endl), 1);
            }

            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            int result;

            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else if (token == "/")
            {
                if (b == 0)
                {
                    return((std::cerr << "Error: Can't devide by zero" << std::endl), 1);
                }
                result = a / b;
            }

            stack.push(result);
        }
        else if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
        {
            stack.push(token[0] - '0');
        }
        else
        {
            return((std::cerr << "Error" << std::endl), 1);
        }
    }

    if (stack.size() != 1)
    {
        return((std::cerr << "Error: Invalid RPN" << std::endl), 1);
    }

    std::cout << stack.top() << std::endl;
    return 0;
}
