#include "darr_stack.h"
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
#include "darr_stack.h"
#include <cstdio>
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
        DArrStack<char> arr_stk;
        /*
        char str[BUF_SIZE] = "Hello, world!";
        arr_stk.push_back(str, strlen(str));
        std::cout << arr_stk.GetTop() << std::endl;
        char *arr = arr_stk.pop();
        std::cout << arr << std::endl;
        delete []arr;
        */

        for (int i=0; i<128; i++)
        {
                char data[BUF_SIZE];
                memset(data, 0, sizeof (data));
                sprintf(data, "%d%c", i, '\0');
                arr_stk.push_back(data, strlen(data)+1);
        }

        for (int i=0; i<128; i++)
        {
                char *tmp = NULL;
                tmp = arr_stk.pop();
                std::cout << "[" << tmp << "]" << std::endl;
                //std::cout << "GetTop: [" << arr_stk.GetTop() << "]" << std::endl;
                delete []tmp;
        }

        char *tmp = arr_stk.pop();
        if (NULL == tmp)
                std::cout << "Stack is empty" << std::endl;
        else
                std::cout << tmp << std::endl;

        return 0;
}

}
