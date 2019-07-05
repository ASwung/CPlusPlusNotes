#ifndef _CEXCEPTION_H_
#define _CEXCEPTION_H_
#define MAX_NUM 100
class cException
{
public:
	cException()
	{
		m_size = 4;
	}

	~cException()
	{
		if (m_size != 0 || m_errInfo != NULL)
		{
			for (int i = 0; i < m_size; i++)
			{
				delete m_errInfo[i];
			}
			m_size = 0;
		
		}
	}
	char* m_errInfo[MAX_NUM]= 
	{
		"�±�Խ��",
		"��ȡ���󣬶��������ڴ�",
		"�������",
		"��������",
	};
	int m_size;
};
#endif // !_CEXCEPTION_H_

