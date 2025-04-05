#include <iostream>
#include <vector>
#include <algorithm>
#include "color.hpp"

using namespace std;

static vector<int>::iterator find(vector<int>& vtr, int element) // Passing by the reference so we do not get ivalidated vector iterator error
{
    vector<int>::iterator it;
    for (it = vtr.begin(); it < vtr.end(); it++)
    {
        if (*it == element) return it;
    }
    return it;
}

int main()
{
    vector<int> vtr;
    int n;
    cout << dye::yellow("--- Adding elements (0 to end) ---") << endl;
    do
    {
        cout << "Enter value: ";
        cin >> n;
        vtr.push_back(n);
    } while (n);

    cout << dye::green("--- FOR CYCLE OUTPUT ---") << endl;
    for (int i = 0; i < vtr.size(); i++)
    {
        cout << vtr[i] << " ";
    }
    cout << endl;

    cout << dye::light_blue("--- ITERATOR OUTPUT ---") << endl;
    vector<int>::iterator it;
    for (it = vtr.begin(); it < vtr.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << dye::red("--- DELETING THE LAST ELEMENT ---") << endl;
    vtr.pop_back();
    for (it = vtr.begin(); it < vtr.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << dye::light_green("First element: ") << vtr.front() << endl;
    cout << dye::light_green("Last element: ") << vtr.back() << endl;

    cout << dye::purple("\n--- SORTING THE VECTOR ---") << endl;
    sort(vtr.begin(), vtr.end());
    for (it = vtr.begin(); it < vtr.end(); it++)
    {
        cout << *it << " ";
    }

    cout << dye::aqua("\nSize: ") << vtr.size() << endl;

    cout << dye::light_yellow("--- FINDING AN ELEMENT ---") << endl;
    int toFind;
    cout << "Enter element: ";
    cin >> toFind;
    cout << "Element: " << *find(vtr, toFind) << endl;

    cout << dye::red_on_white("\n--- CLEARING THE VECTOR ---") << endl;
    vtr.clear();
    cout << dye::red("Size: ") << vtr.size() << endl;
}