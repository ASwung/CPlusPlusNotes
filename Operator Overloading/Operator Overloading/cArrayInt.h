#ifndef _CARRAYINT_H_
#define _CARRAYINT_H_
#include <stdlib.h>
class cArrayInt
{
public:
	cArrayInt();
	cArrayInt(int size);
	cArrayInt(cArrayInt& obj);
	~cArrayInt();

	// ���� [] ʵ�� ���Զ���� int ������ ȡֵ�븳ֵ ��m_Array[5] = 4;   int a = m_Array[3];�� 
	int& operator [](int index)   // ����Ϊ unsigned �ɷ�ֹ index Ϊ����
	{  //  (������ض���  �����������ã������ص�����ʱ����,ֻ��ȡֵ�����ܸ�ֵ)
		if (index > m_ArraySize - 1)	 // �����±겻�� ���� ��������һ��Ԫ�ص��±�
		{
			index = m_ArraySize;
		}
		return this->m_Array[index];   // ����ͨ������������������ֵ ���� obj[index] ���� obj.m_Array[index] 
	}
	// ���� -> ʵ�� �������ʹ�� -> ���ó�Ա  ����ͨ��ָ��
	cArrayInt* operator ->()  
	{
		return this;
	}
	// ���� = ʵ�� ���������ĸ�ֵ: obj1 = obj2; (����������� obj1 �������СΪ��)
	cArrayInt& operator =(const cArrayInt& obj)
	{
		delete m_Array;
		m_Array = new int[obj.m_ArraySize];
		m_ArraySize = obj.m_ArraySize;
		for (int k = 0; k < this->m_ArraySize; k++)
		{
			m_Array[k] = obj.m_Array[k];
		}
	 // memcpy(m_Array, obj.m_Array, sizeof(int) * obj.m_ArraySize));
		return *this;
	}
	
// ���� == �����
	friend bool operator ==(const cArrayInt& obj1, const cArrayInt& obj2)
	{
		if (obj1.m_Array == NULL || obj2.m_Array == NULL || obj1.m_ArraySize == 0 || obj1.m_ArraySize != obj2.m_ArraySize)
		{
			return false;
		}
		for (int i = 0; i < obj1.m_ArraySize; ++i)
		{
			if (obj1.m_Array[i] != obj2.m_Array[i])
			{
				return false;
			}
			if (i + 1 == obj1.m_ArraySize)
			{
				return true;
			}
		}
		return false;
	}
	
// ���� + ��������������飩
	friend cArrayInt operator +(const cArrayInt& obj1,const cArrayInt& obj2)
	{
		if (obj1.m_Array == NULL || obj2.m_Array == NULL || obj1.m_ArraySize == 0 || obj2.m_ArraySize == 0)
		{
			return false;
		}
		cArrayInt obj3(obj1.m_ArraySize + obj2.m_ArraySize);
		for (int i = 0; i < obj1.m_ArraySize; ++i)
		{
			obj3.m_Array[i] = obj1.m_Array[i];
		}
		int k = 0;
		for (int j = obj1.m_ArraySize; j < (obj1.m_ArraySize + obj2.m_ArraySize) && (k < obj2.m_ArraySize); ++j, ++k)
		{
			obj3.m_Array[j] = obj2.m_Array[k];
		}
		return obj3;
	}
// ���� - ����� (һԪ)
	cArrayInt operator -()
	{
		for (int i = 0; i < m_ArraySize; ++i)
		{
			m_Array[i] = -m_Array[i];
		}
		return *this;
	}


// ���� > �����
	friend bool operator >(const cArrayInt& obj1, const cArrayInt& obj2)
	{
		if (obj1.m_Array == NULL || obj2.m_Array == NULL || obj1.m_ArraySize == 0 || obj2.m_ArraySize == 0)
		{
			return false;
		}
		if (obj1.m_ArraySize > obj2.m_ArraySize)
		{
			return true;
		}
		if (obj1.m_ArraySize < obj2.m_ArraySize)
		{
			return false;
		}
		for (int i = 0; i < obj1.m_ArraySize; ++i)
		{
			if (obj1.m_Array[i] < obj2.m_Array[i])
			{
				return false;
			}
			else if (obj1.m_Array[i] > obj2.m_Array[i])
			{
				return true;
			}
		}
		return false;
	}
// ���� < �����
	friend bool operator <(const cArrayInt& obj1, const cArrayInt& obj2)
	{
		if (obj1.m_Array == NULL || obj2.m_Array == NULL || obj1.m_ArraySize == 0 || obj2.m_ArraySize == 0)
		{
			return false;
		}
		if (obj1.m_ArraySize < obj2.m_ArraySize)
		{
			return true;
		}
		if (obj1.m_ArraySize > obj2.m_ArraySize)
		{
			return false;
		}
		for (int i = 0; i < obj1.m_ArraySize; ++i)
		{
			if (obj1.m_Array[i] > obj2.m_Array[i])
			{
				return false;
			}
			else if (obj1.m_Array[i] < obj2.m_Array[i])
			{
				return true;
			}
		}
		return false;
	}


	void Insert(int size);   // ͨ�������С����Ԫ��
	void Resize(int size);	 // ͨ���µ������С�������� (�ɱ�����)
	void Sort(bool bUp);   // bUp Ϊ true ��С��������Ϊ false �Ӵ�С����
	void Input();
	void Print();    // ͨ�������С��ӡ����
	int GetSize() const;			 // ��õ�ǰ�������С
private:
	int *m_Array;
	int m_ArraySize;
};

#endif

