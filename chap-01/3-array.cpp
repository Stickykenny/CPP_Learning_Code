#include <iostream>
#include <vector>

int main()
{
    int array[] = { 0, 1, 2, 3 };
    // int array2[50] = {};
    for (int i = 0; i < 4; ++i)
    {
        std::cout << array[i] << std::endl;
    }
    for (int values : array)
    {
        std::cout << values << std::endl;
    }

    std::vector<int> v = {};
    v.emplace_back(4);
    v.emplace_back(5);
    for (int i = 0; i < 4; ++i)
    {
        std::cout << v[i] << std::endl; // can go over v[3]
    }
    return 0;
}
