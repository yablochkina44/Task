#include <iostream>
using namespace std;


template <class T>
struct TNode
{
	T value;
	TNode* pNext;
};

#include <iostream>
using namespace std;

template <class T>
class TList
{
protected:

	TNode<T>* pFirst;

public:

	TList()
	{
		pFirst = NULL;
	}

	~TList()
	{
		while (pFirst != NULL)
		{
			TNode<T>* pDel = pFirst;
			pFirst = pFirst->pNext;
			delete[] pDel;
		}
	}


	void InsFirst(T val)
	{
		TNode<T>* newFirst = new TNode<T>;
		newFirst->value = val;
		newFirst->pNext = pFirst;

		pFirst = newFirst;

	}


	void DeleteEvenValue()
	{
		TNode<T>* current = pFirst;
		
		while (current->pNext != NULL)
		{
			if ((current->value) % 2 == 0)
			{
				if (current == pFirst)
				{
					TNode<T>* pDel = pFirst;
					pFirst = pFirst->pNext;
					current = current->pNext;
					delete[] pDel;
				}
				else
				{
					TNode<T>* pDel = current;
					current = current->pNext;
					delete[] pDel;
				}
				
			}
			else
			{
				current = current->pNext;
			}
			
		}
		delete current;
	}


	void PrintList()
	{
		int count = 0;
		TNode<T>* current = pFirst;
		while (current->pNext != NULL)
		{
			cout << current->value << " ";
			current= current->pNext;
			count++;
		}
		cout << endl;
		cout<<"Elements:" <<count<<endl;
	}

};
