#include <iostream>
#include <vector>
#include <algorithm>
#include "color.hpp"

using namespace std;

static vector<int> vectorIncrement(vector<int> vtr)
{
    vector<int> v;
    for (vector<int>::iterator it = vtr.begin(); it < vtr.end(); it++)
    {
        v.push_back(++(*it));
    }
    return v;
}

//По-ленивому
static bool predicate(int i, int j) { return i > j; }
static void sortByDescPredicate(vector<int>& vtr)
{
    sort(vtr.begin(), vtr.end(), predicate); 
}

//По-обычному
static void sortByDesc(vector<int>& vtr)
{
    for (int i = 0; i < vtr.size(); i++)
    {
        for (int j = i; j < vtr.size(); j++)
        {
            if (vtr[i] < vtr[j])
            {
                int temp = vtr[i];
                vtr[i] = vtr[j];
                vtr[j] = temp;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    // Ну по идее я 30-й в списке, последняя цифра 0, поэтому я сделал первый и десятый пункты
    vector<int> vtr(10);
    for (vector<int>::iterator it = vtr.begin(); it < vtr.end(); it++)
    {
        *it += rand() % 25;
    }
    cout << dye::light_blue("Initial vector before increment function call:") << endl;
    for (vector<int>::iterator it = vtr.begin(); it < vtr.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    vtr = vectorIncrement(vtr);
    cout << dye::light_green("\nNew vector after increment function call:") << endl;
    for (vector<int>::iterator it = vtr.begin(); it < vtr.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    //------------------------------------------------------------------------------
    //sortByDesc(vtr);
    sortByDescPredicate(vtr); // Оба варианта рабочие
    cout << dye::light_red("\nSorted vector:") << endl;
    for (vector<int>::iterator it = vtr.begin(); it < vtr.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

