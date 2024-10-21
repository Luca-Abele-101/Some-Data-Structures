#ifndef __LIMITED_SIZE_STACK_TESTING_HPP
#define __LIMITED_SIZE_STACK_TESTING_HPP

bool checkBalanceBrackets(const std::string& text, int maxDeep = 30);

bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize = 30);

int evaluatePostfix(const std::string& infix, size_t stackSize = 30);

class EvaluatingPostfixException : public std::exception
{
public:
	EvaluatingPostfixException(const char* reason) : reason_(reason) {}

	const char* what() const noexcept override
	{
		return reason_;
	}

private:
	const char* reason_;
};

#endif
