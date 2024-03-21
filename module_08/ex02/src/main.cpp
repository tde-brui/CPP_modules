#include "../inc/MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(4);

    std::cout << "Looping through stack..." << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;

    mstack.pop();

    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    std::cout << "Begin: " << *mstack.begin() << std::endl;
    std::cout << std::endl;

    std::cout << "Looping through stack..." << std::endl;
    for (auto &elem : mstack)
    {
        std::cout << elem << std::endl;
    }
}