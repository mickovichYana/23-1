//TreeFun3.Реализовать для бинарного дерева интерфейс итератора, который будет возвращать
//значения элементов, находящихся в узлах дерева, в порядке "лево-корень-право".
//Преобразовывать дерево в список или иную структуру данных нельзя, рекурсию использовать
//запрещается.

#include "tree_iterator.h"
using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");
    vector<int> elements;
    Node* root = nullptr;
    int count = GetValidatedCount();
    InputElementsAndBuildTree(root, elements, count);
    PrintInputElements(elements);
    cout << "\nСтруктура дерева:\n";
    PrintTree(root);
    cout << "Обход дерева (левый-корень-правый): ";
    TreeIterator it(root);
    while (it.HasNext()) 
    {
        cout << it.next() << " ";
    }
    cout << "\n";
    return 0;
} 