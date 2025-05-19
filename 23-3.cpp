//TreeFun12.Дано бинарное дерево с целыми числами в узлах и некоторое целое число S.
//Нужно найти в дереве все возможные пути, на которых сумма значений узлов будет равна S.

#include "tree_paths.h"
using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");
    vector<int> elements;
    Node* root = nullptr;
    int count = GetNumber("Введите количество элементов в дереве: ");
    while (count <= 0) 
    {
        cout << "Количество должно быть больше нуля!\n";
        count = GetNumber("Введите количество элементов в дереве: ");
    }
    for (int i = 0; i < count; i++) 
    {
        string prompt = "Введите элемент " + to_string(i + 1) + ": ";
        int value = GetNumber(prompt);
        elements.push_back(value);
        root = Insert(root, value);
    }
    cout << "\nВведенные элементы: ";
    for (int elem : elements) 
    {
        cout << elem << " ";
    }
    cout << endl;
    cout << "\nСтруктура дерева:\n";
    PrintTree(root);
    int S = GetNumber("\nВведите искомую сумму S: ");
    vector<vector<int>> result;
    vector<int> path;
    FindPaths(root, S, path, result);
    if (result.empty()) 
    {
        cout << "\nПутей с суммой " << S << " не найдено.\n";
    }
    else 
    {
        cout << "\nНайдены следующие пути с суммой " << S << ":\n";
        for (const auto& p : result) 
        {
            for (int val : p) 
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    return 0;
}