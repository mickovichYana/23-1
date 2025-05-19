#ifndef TREE_TO_LIST_H
#define TREE_TO_LIST_H
#include <iostream>
#include <queue>
#include <vector>
#include <string>

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val);
};
void ClearInput();// Очистка буфера ввода
int GetNumber(const std::string& prompt);// Получение числа от пользователя с проверкой
int GetValidatedCount();// Получение количества элементов дерева с валидацией
Node* BuildTree(const std::vector<int>& elements);// Построение бинарного дерева 
Node* TreeToDoubleList(Node* root);// Преобразование дерева в циклический двусвязный список
void PrintTree(Node* root, int space = 0, int gap = 4);// Вывод дерева 
void PrintList(Node* head);// Вывод двусвязного списка
void PrintInputElements(const std::vector<int>& elements);// Вывод введенных элементов
#endif