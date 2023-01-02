#include <iostream>
#include <set>

int main()
{
    std::set<int> * test = new std::set<int>[100];

    test[3].insert(1);
    test[20].insert(10);

    for( int n: test[3] ){
        std::cout << n << " " << std::endl;
    }

    for( int n: test[20] ){
        std::cout << n << " " << std::endl;
    }

    delete[] test;

    return 0;
}