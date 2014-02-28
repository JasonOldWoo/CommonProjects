#include <iostream>
template <class T>
class DArrStack
{
public:
	// Constructor: stack max len is 128
	DArrStack()
	{
		elems = NULL;
		MaxSize = 128;
		elems = new T*[MaxSize];
		m_arrlen = new size_t[MaxSize];
		for (int tmp_cnt=0; tmp_cnt<MaxSize; tmp_cnt++)
		{
			elems[tmp_cnt] = NULL;
			m_arrlen[tmp_cnt] = 0;
		}
		m_top = -1;
	}
	~DArrStack()
	{
		for (int tmp_cnt=0; tmp_cnt<m_top; tmp_cnt++)
			delete [](elems[tmp_cnt]);
		delete []elems;
		delete []m_arrlen;
	}

	void push_back(T* item, size_t len)
	{
		if (!IsFull())
		{
			m_top++;
			if (elems[m_top])
				delete [](elems[m_top]);
			elems[m_top] = new T[len];
			memcpy(elems[m_top], item, len*sizeof(T));
			m_arrlen[m_top] = len;
		}
	}

	T* pop()
	{
		if (!IsEmpty())
		{
			char *ret = new char[m_arrlen[m_top]];
			memcpy(ret, elems[m_top], m_arrlen[m_top]);
			delete elems[m_top];
			m_arrlen[m_top] = 0;
			return ret;
		}
		else
			return NULL;
	}

	T *GetTop()
	{
		if (!IsEmpty())
			return elems[m_top];
		else
			return NULL;
	}

	bool IsFull()
	{
		if (m_top == MaxSize-1)
			return true;
		else
			return false;
	}

	bool IsEmpty()
	{
		if (-1 == m_top)
			return true;
		else
			return false;
	}

	void Destroy()
	{
		for (int tmp_cnt=0; tmp_cnt<MaxSize; tmp_cnt++)
		{
			delete [](elems[tmp_cnt]);
			elems[tmp_cnt] = NULL;
			m_arrlen[tmp_cnt] = 0;
		}
		m_top = -1;
	}

private:
	T **elems;
	size_t MaxSize;
	size_t *m_arrlen;
	int m_top;
};
