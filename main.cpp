#include "Vector.h"

int main()
{
    Vector<int, 3> v = {1, 2, 3};
    Vector<int, 3> v2({4, 5, 6});

    std::cout << "init test\n";
    std::cout << v <<'\n';
    std::cout << "v size: " << v.size() <<'\n';
    std::cout << v2 <<'\n';
    std::cout << "v2 size: " << v2.size() <<'\n';
    
    std::cout << "add test\n";
    v.add(v2);
    std::cout << v <<'\n';

    std::cout << "sub test\n";
    v.sub(v2);
    std::cout << v <<'\n';
    
    return 0;
}
