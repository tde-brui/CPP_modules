#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {};
        ~MutantStack() {};
        MutantStack(const MutantStack &mutantstack) { *this = mutantstack; };
        MutantStack &operator=(const MutantStack &mutantstack) { (void)mutantstack; return *this; };

        
};