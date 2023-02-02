#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> values(4, 0);
    for (const auto v : values)
    {
        cout << v << endl;
    }

    int array[] = { 0, 1, 2, 3, 4, 5 };
    // int* iterator_on_2nd_element = &array[1];

    vector<int> part(&array[2], &array[5]);
    for (const auto v : part)
    {
        cout << v << endl; // 2 3 4
    }

    vector<int> full(array, array + 6); // array == &array [0]
    for (const auto v : full)
    {
        cout << v << endl; // 0 1 2 3 4 5
    }
    for (int left = 0, right = full.size() - 1; left < right; left++, right--)
    {
        swap(full[left], full[right]);
    }
    cout << "---\n";
    for (auto i = full.begin(); i != full.end(); i += 2)
    {
        i = full.insert(i, *i);
        // A chaque realoc du tableau, itérateurs deviennent invalides, c'est pour ca qu'on réassigne
        // l'itérateur i
    }
    for (const auto v : full)
    {
        cout << v << endl; // 0 1 2 3 4 5
    }

    while (!full.empty())
    {
        full.pop_back();
    }

    vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // supprime des indices 2 à 6
    v.erase(v.begin() + 2, v.begin() + 7);

    const auto it = std::find(v.begin(), v.end(), 8);
    if (it != v.end())
    {
        v.erase(it);
    }

    v.assign(5, 2);
    v.assign({ 0, 33, 8, -35 });
    v.clear();
    return 0;
}