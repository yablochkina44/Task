#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;


struct TLink
{
	char str[81];
	TLink* pNext;
	TLink* pDown;
	int level;

	TLink(char* _str=NULL,TLink* _pNext=NULL, TLink* _pDown=NULL)
	{
		pNext = _pNext;
		pDown = _pDown;
		if (_str == NULL)
			str[0] = '\0';
		else
			strcpy(str,_str);
	}
};

class TText
{
protected:
	TLink* pFirst;
	TLink* pCurr;
	TStack <TLink*> stack;

public:

	
	void GoNextLine()
	{
		if (pCurr)
		{
			stack.Push(pCurr);
			pCurr = pCurr->pNext;
		}
	}
	void GoFirstLine()
	{
		if (pCurr)
		{
			pCurr = pFirst;
			stack.Clear;
		}
	}



	void InsNextLine(char str[])
	{
		if (pCurr)
		{
			TLink* tmp = new TLink(str);
			tmp->pNext = pCurr->pNext;
			pCurr->pNext = tmp;
		}
	}

	void InsNextSection(char str[])
	{
		if (pCurr)
		{
			TLink* tmp = new TLink(str);
			tmp->pDown = pCurr->pNext;
			pCurr->pNext = tmp;
		}
	}

	void InsDowntLine(char str[])
	{
		if (pCurr)
		{
			TLink* tmp = new TLink(str);
			tmp->pNext = pCurr->pDown;
			pCurr->pDown = tmp;
		}
	}

	void InsDownSection(char str[])
	{
		if (pCurr)
		{
			TLink* tmp = new TLink(str);
			tmp->pDown = pCurr->pDown;
			pCurr->pDown = tmp;
		}
	}

	void DelNextLine()
	{
		if (pCurr)
		{
			if (pCurr->pNext)
			{
				TLink* pDel = pCurr->pNext;
				pCurr->pNext = pDel->pNext;
				delete pDel;
			}
		}
	}

	void DelDownLine()
	{
		if (pCurr)
		{
			if (pCurr->pDown)
			{
				TLink* pDel = pCurr->pDown;
				pCurr->pDown = pDel->pNext;
				delete pDel;
			}
		}
	}
	
	void Read(char* fn)
	{
		ifstream ifs(fn);
		pFirst = ReadRec(ifs);
	}

	TLink* ReadRec(ifstream& ifs)
	{
		TLink* pHead, * tmp; char buf[81];
		while (!ifs.eof())
		{
			ifs.getline(buf, 80, '\n');
			if (buf[0] == '}')
			{
				break;
			}
			else if (buf[0] == '{')
			{
				tmp->pDown = ReadRec(ifs);
			}
			else
			{
				TLink* p = new TLink(buf);
				if (pHead == NULL)
					pHead = tmp = p;
				else
				{
					tmp->pNext = p;
					tmp = p;
				}
			}
		}
		return pHead;
	}



};