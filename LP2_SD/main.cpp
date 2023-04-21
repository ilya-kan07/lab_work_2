#include <iostream>
using namespace std;

int tabs = 0;
int count_tabs = 0;
int counter, value;

struct Branch;
void Add(int aData, Branch*& aBranch);
void print(Branch* aBranch);
void traversal_tree(Branch*& aBranch);
void insert_element(int aData, Branch*& aBranch);
void is_Empty(Branch*& aBranch);
void FindDouble(Branch*& aBranch);
void FreeTree(Branch* aBranch);

int main()
{
    setlocale(LC_ALL, "rus");

    Branch* Root = 0;
    int count_elements;
    int element;
    int elem;

    cout << "Введите кол-во элементов для будущего дерева: ";
    cin >> count_elements;
    cout << endl;

    cout << "Проверим дерево на пустоту: " << endl;
    is_Empty(Root);
    cout << endl;

    cout << "Введите элементы бинарного дерева: ";
    for (int i = 0; i < count_elements; i++)
    {
        cin >> elem;
        Add(elem, Root);
    }

    cout << "Проверим дерево на пустоту: " << endl;
    is_Empty(Root);
    cout << endl;

    cout << "Вывод бинарного дерева: " << endl;
    print(Root);
    cout << endl;

    cout << "Прямой обход бинарного дерева: " << endl;
    traversal_tree(Root);
    cout << endl;

    cout << "Вершины с одинаковыми номерами: " << endl;
    FindDouble(Root);

    cout << "Добавим новый элемент в бинарное дерево:" << endl;
    cout << "Введите новый элемент: ";
    cin >> element;
    insert_element(element, Root);

    cout << "Вывод бинарного дерева: " << endl;
    print(Root);
    cout << endl;

    cout << "Вершины с одинаковыми номерами: " << endl;
    FindDouble(Root);

    FreeTree(Root);
    cout << "Вся динамическая память очищена..." << endl;
    return 0;
}

struct Branch
{
    int Data;
    Branch* LeftBranch;
    Branch* RightBranch;
};

void Add(int aData, Branch*& aBranch)
{
    if (!aBranch)
    {
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->LeftBranch = 0;
        aBranch->RightBranch = 0;
        return;
    }
    else
        if (aBranch->Data > aData)
        {
            Add(aData, aBranch->LeftBranch);
        }
        else
        {
            Add(aData, aBranch->RightBranch);
        };
}

void print(Branch* aBranch)
{
    if (!aBranch) return;
    tabs += 7;

    print(aBranch->LeftBranch);

    for (int i = 0; i < tabs; i++) cout << " ";
    cout << aBranch->Data << endl;

    print(aBranch->RightBranch);

    tabs -= 7;
}

void traversal_tree(Branch*& aBranch)
{
    if (NULL == aBranch)
        return;

    cout << aBranch->Data << endl;
    traversal_tree(aBranch->LeftBranch);
    traversal_tree(aBranch->RightBranch);
}

void insert_element(int aData, Branch*& aBranch)
{
    if (!aBranch)
    {
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->LeftBranch = 0;
        aBranch->RightBranch = 0;
        return;
    }
    else
    {
        if (aData < aBranch->Data) {
            insert_element(aData, aBranch->LeftBranch);
        }
        else if (aData >= aBranch->Data) {
            insert_element(aData, aBranch->RightBranch);
        }
    }
}

void is_Empty(Branch*& aBranch)
{
    if (!aBranch)
    {
        cout << "Дерево пустое";
    }
    else
    {
        cout << "Дерево не пустое";
    }
}

void FindDouble(Branch*& aBranch)
{

    if (aBranch)
    {
        FindDouble(aBranch->LeftBranch);
        if (counter && (aBranch->Data == value))
        {
            ++counter;
            if ((counter > 1) && (0 == aBranch->RightBranch))
            {
                for (int i = 0; i < counter; i++)
                {
                    cout << value << endl;
                }
                counter = 1;
            }
        }
        else
        {
            if (counter > 1)
            {
                for (int i = 0; i < counter; i++)
                {
                    cout << value << endl;
                }
            }
            value = aBranch->Data;
            counter = 1;
        }
        FindDouble(aBranch->RightBranch);
    }
}

void FreeTree(Branch* aBranch)
{
    if (!aBranch)
        return;

    FreeTree(aBranch->LeftBranch);
    FreeTree(aBranch->RightBranch);

    delete aBranch;
}
