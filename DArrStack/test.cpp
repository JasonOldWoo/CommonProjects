#include "darr_stack.h"
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
	DArrStack<char> arr_stk;
	char str[BUF_SIZE] = "Hello, world!";
	arr_stk.push_back(str, strlen(str));
	std::cout << arr_stk.GetTop() << std::endl;
	char *arr = arr_stk.pop();
	std::cout << arr << std::endl;
	delete []arr;
	return 0;
}
