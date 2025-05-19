#include "tree_to_list.h"
#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <string>
using namespace std;

Node::Node(int val) : data(val), left(nullptr), right(nullptr) {}

void ClearInput()// Очистка буфера ввода
{
    cin.clear();
    cin.ignore(1000, '\n');
}

int GetNumber(const string& prompt)// Получение числа от пользователя с проверкой
{
    int value;
    while (true)
    {
        cout << prompt;
        string input;
        getline(cin, input);
        try
        {
            size_t pos;
            value = stoi(input, &pos);
            if (pos != input.length())
            {
                throw invalid_argument("Некорректные символы в числе");
            }
            return value;
        }
        catch (const invalid_argument&)
        {
            cout << "Ошибка! Пожалуйста, введите целое число.\n";
        }
    }
}

int GetValidatedCount()// Получение количества элементов дерева с валидацией
{
    int count = GetNumber("Введите количество элементов в дереве: ");
    while (count <= 0)
    {
        cout << "Количество должно быть больше нуля!\n";
        count = GetNumber("Введите количество элементов в дереве: ");
    }
    return count;
}

Node* BuildTree(const vector<int>& elements)// Построение бинарного дерева
{
    if (elements.empty()) return nullptr;
    queue<Node*> q;
    Node* root = new Node(elements[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < elements.size())
    {
        Node* current = q.front();
        q.pop();
        if (i < elements.size())
        {
            current->left = new Node(elements[i]);
            q.push(current->left);
            i++;
        }
        if (i < elements.size())
        {
            current->right = new Node(elements[i]);
            q.push(current->right);
            i++;
        }
    }
    return root;
}

Node* TreeToDoubleList(Node* root)// Преобразование дерева в циклический двусвязный список
{
    if (!root) return nullptr;
    queue<Node*> q;
    q.push(root);
    Node* head = nullptr;
    Node* prev = nullptr;
    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
        if (!head) head = current;
        current->left = prev;
        if (prev)
            prev->right = current;
        prev = current;
    }
    if (head && prev)
    {
        head->left = prev;
        prev->right = head;
    }
    return head;
}

void PrintTree(Node* root, int space, int gap)// Вывод дерева 
{
    if (!root) return;
    space += gap;
    PrintTree(root->right, space);
    cout << string(space - gap, ' ');
    cout << root->data << endl;
    PrintTree(root->left, space);
}

void PrintList(Node* head)// Вывод двусвязного списка
{
    if (!head) {
        cout << "Список пуст!" << endl;
        return;
    }
    Node* current = head;
    do
    {
        cout << current->data;
        current = current->right;
        if (current != head)
        {
            cout << " <-> ";
        }
    } while (current && current != head);
    cout << endl;
}

void PrintInputElements(const vector<int>& elements)// Вывод введенных элементов
{
    cout << "\nВведенные элементы: ";
    for (int elem : elements)
    {
        cout << elem << " ";
    }
    cout << endl;
}