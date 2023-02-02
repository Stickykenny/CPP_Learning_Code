#include <array>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>

using namespace std;

enum Fruit
{
    Apricot,
    Cherry,
    Mango,
    Raspberry,

    Fruit_Count,
};

void try_arrays()
{
    // Implement array tests here.
    array<string, Fruit_Count> fruit_names;
    fruit_names[Apricot]   = "apr";
    fruit_names[Cherry]    = "che";
    fruit_names[Mango]     = "man";
    fruit_names[Raspberry] = "rasp";
}

void try_lists()
{
    std::list<int> l1 { 1, 4, 6, 56 };
    std::list<int> l2(3, 5);
    std::list<int> l3 { 34, 45, 56 };
    std::list<int> l4 { 40, 45, 60 };

    l1.sort();
    l2.sort();
    l1.merge(l2);

    auto mid = l1.begin();
    std::advance(mid, l1.size() / 2); // avance l'iterateur de n position
    l1.splice(mid, l3);               // splice prend un iterateur
}

void try_stacks()
{
    // Implement stack tests here.
    stack<int, vector<int>> s1;
    s1.emplace(0);
    s1.emplace(1);
    s1.emplace(2);

    std::vector<int>                  v { 0, 1, 2 };
    std::stack<int, std::vector<int>> s2 { v };
    //     for (auto elem : s1)
    //     {
    //         cout << elem;
    //     }
}

int main()
{
    try_arrays();
    try_lists();
    try_stacks();

    return 0;
}