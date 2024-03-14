#include "../inc/MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(4);
    mstack.pop();

    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
}