//TreeFun1.Преобразовать бинарное дерево поиска в двусвязный список без использования
//дополнительной памяти(создания новых объектов).При преобразовании поля left и right
//узлов бинарного дерева рассматриваются эквивалентными полям prev и next узлов
//двусвязного списка.Вывести исходное дерево и получившийся список.Элементы в
//результирующем списке должны сохранить свою упорядоченность.

#include "tree_to_list.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<int> elements;
    int count = GetValidatedCount();
    for (int i = 0; i < count; i++)
    {
        string prompt = "Введите элемент " + to_string(i + 1) + ": ";
        elements.push_back(GetNumber(prompt));
    }
    PrintInputElements(elements);
    Node* root = BuildTree(elements);
    cout << "\nСтруктура дерева:\n";
    PrintTree(root);
    Node* list = TreeToDoubleList(root);
    cout << "\nРезультат преобразования в двусвязный список:\n";
    PrintList(list);
    return 0;
}