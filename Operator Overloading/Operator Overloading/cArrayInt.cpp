#include "stdafx.h"
#include "cArrayInt.h"

using namespace std;
cArrayInt::cArrayInt()
{
	m_Array = new int;
}

cArrayInt::cArrayInt(int size)
{
	m_ArraySize = size;
	m_Array = new int[m_ArraySize];
}

cArrayInt::cArrayInt(cArrayInt & obj)
{
	m_Array = new int[obj.m_ArraySize];
	this->m_ArraySize = obj.m_ArraySize;
	for (int i = 0; i < m_ArraySize; i++)
	{
		m_Array[i] = obj[i];
	}
}


cArrayInt::~cArrayInt()
{
	if (m_Array)
	{
		delete m_Array;
	}
}

void cArrayInt::Insert(int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> m_Array[i];
	}
}

void cArrayInt::Resize(int size)
{
	m_Array = (int*)realloc(m_Array, size * sizeof(int));
	m_ArraySize = size;
/*
	if (size > m_ArraySize)
	{
		int* intTemp = new int[size];
		memcpy(intTemp, m_Array, sizeof(int)*m_ArraySize);
		delete m_Array;
		m_Array = intTemp;
		m_ArraySize = size;
	}
	else
	{
		int* intTemp = new int[size];
		memcpy(intTemp, m_Array, sizeof(int)*size);
		delete m_Array;
		m_Array = intTemp;
		m_ArraySize = size;
	}
*/
}

void cArrayInt::Sort(bool bUp)
{
	int iTemp;
	if (bUp == true)
	{
		for (int i = 0; i < m_ArraySize - 1; i++)
		{
			for (int j = i; j < m_ArraySize - 1; j++)
			{
				if (m_Array[i] > m_Array[j + 1])
				{
					iTemp = m_Array[i];
					m_Array[i] = m_Array[j + 1];
					m_Array[j + 1] = iTemp;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < m_ArraySize - 1; i++)
		{
			for (int j = i; j < m_ArraySize - 1; j++)
			{
				if (m_Array[i] < m_Array[j + 1])
				{
					iTemp = m_Array[i];
					m_Array[i] = m_Array[j + 1];
					m_Array[j + 1] = iTemp;
				}
			}
		}
	}
}

void cArrayInt::Input()
{
	if (m_ArraySize <= 0 || m_Array == NULL)
	{
		return;
	}
	for (int i = 0; i < m_ArraySize; ++i)
	{
		cin >> this->m_Array[i];
	}
}

void cArrayInt::Print()
{
	if (m_ArraySize <= 0 || m_Array == NULL)
	{
		return;
	}
	for (int j = 0; j < m_ArraySize; j++)
	{
		cout << m_Array[j] << " ";
	}
}

int cArrayInt::GetSize()const 
{
	return m_ArraySize;
}
