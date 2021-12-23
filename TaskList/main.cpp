#include "List.cpp"
#include <iostream>

using namespace std;

void main()
{

    TList<int>* list = new TList<int>;

    for (int i = 0; i < 5; i++)
    {
        list->InsFirst(i);
    }
    list->PrintList();
    list->DeleteEvenValue();
    list->PrintList();

}