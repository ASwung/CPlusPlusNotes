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

	// 重载 [] 实现 对自定义的 int 数组类 取值与赋值 （m_Array[5] = 4;   int a = m_Array[3];） 
	int& operator [](int index)   // 声明为 unsigned 可防止 index 为负数
	{  //  (如果返回对象  而不返回引用，怎返回的是临时变量,只能取值，不能赋值)
		if (index > m_ArraySize - 1)	 // 数组下标不能 大于 数组的最后一个元素的下标
		{
			index = m_ArraySize;
		}
		return this->m_Array[index];   // 可以通过对象来获得数组里的值 可以 obj[index] 不需 obj.m_Array[index] 
	}
	// 重载 -> 实现 对象可以使用 -> 调用成员  不需通过指针
	cArrayInt* operator ->()  
	{
		return this;
	}
	// 重载 = 实现 对象与对象的赋值: obj1 = obj2; (深拷贝，但是以 obj1 的数组大小为主)
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
	
// 重载 == 运算符
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
	
// 重载 + 运算符（连接数组）
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
// 重载 - 运算符 (一元)
	cArrayInt operator -()
	{
		for (int i = 0; i < m_ArraySize; ++i)
		{
			m_Array[i] = -m_Array[i];
		}
		return *this;
	}


// 重载 > 运算符
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
// 重载 < 运算符
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


	void Insert(int size);   // 通过数组大小插入元素
	void Resize(int size);	 // 通过新的数组大小创建数组 (可变数组)
	void Sort(bool bUp);   // bUp 为 true 从小到大排序，为 false 从大到小排序
	void Input();
	void Print();    // 通过数组大小打印数组
	int GetSize() const;			 // 获得当前的数组大小
private:
	int *m_Array;
	int m_ArraySize;
};

#endif

