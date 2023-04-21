#include <iostream>
using namespace std;

int tabs = 0;
int kol_vo = 0;

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
    return;
}

void pr_obh(Branch*& aBranch)
{
    if (NULL == aBranch)
        return;

    cout << aBranch->Data << endl;
    pr_obh(aBranch->LeftBranch);
    pr_obh(aBranch->RightBranch);
}


void add_elem(int aData, Branch*& aBranch)
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
            add_elem(aData, aBranch->LeftBranch);
        }
        else if (aData >= aBranch->Data) {
            add_elem(aData, aBranch->RightBranch);
        }
    }
}

void is_Empty(Branch*& aBranch)
{
    if (!aBranch)
    {
        cout << "Дерево пустое...";
    }
    else
    {
        cout << "Дерево не пустое...";
    }
}

int cnt, val;

void FindDouble(Branch*& aBranch)
{

    if (aBranch)
    {
        FindDouble(aBranch->LeftBranch);
        if (cnt && (aBranch->Data == val))
        {
            ++cnt;
            if ((cnt > 1) && (0 == aBranch->RightBranch))
            {
                for (int i = 0; i < cnt; i++)
                {
                    cout << val << endl;
                }
                cnt = 1;
            }
        }
        else
        {
            if (cnt > 1)
            {
                for (int i = 0; i < cnt; i++)
                {
                    cout << val << endl;
                }
            }
            val = aBranch->Data;
            cnt = 1;
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
    return;
}

int main()
{
    setlocale(LC_ALL, "rus");

    Branch* Root = 0;
    int vel;
    int element;
    int elem;

    cout << "Введите кол-во элементов для будущего дерева: ";
    cin >> vel;
    cout << endl;


    cout << "Проверим дерево на пустоту до его заполнения: " << endl;
    is_Empty(Root);
    cout << endl;

    cout << "Введите элементы бинарного дерева: ";
    for (int i = 0; i < vel; i++)
    {
        cin >> elem;
        Add(elem, Root);
    }

    cout << "Проверим дерево на пустоту после его заполнения: " << endl;
    is_Empty(Root);
    cout << endl;

    cout << "Вывод бинарного дерева: " << endl;
    print(Root);
    cout << endl;

    cout << "Прямой обход бинарного дерева: " << endl;
    pr_obh(Root);
    cout << endl;

    cout << "Вершины с одинаковыми номерами: " << endl;
    FindDouble(Root);

    cout << "Добавим новый элемент в бинарное дерево:" << endl;
    cout << "Введите новый элемент: ";
    cin >> element;
    add_elem(element, Root);

    cout << "Вывод бинарного дерева: " << endl;
    print(Root);
    cout << endl;

    cout << "Вывод бинарного дерева: " << endl;
    print(Root);
    cout << endl;

    cout << "Вершины с одинаковыми номерами: " << endl;
    FindDouble(Root);

    FreeTree(Root);
    cout << "Вся динамическая память очищена..." << endl;
    return 0;
}
