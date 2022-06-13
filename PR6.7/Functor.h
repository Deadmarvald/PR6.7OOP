#pragma once

template<class T>
class Predicate
{
public:virtual bool operator () (T x) = 0;
};

template <class T>
class Zero : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		T zero = T();
		return x == zero;
	}
};

template<class T>
class Positive : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x > 0;
	}
};

template<class T>
class Negative : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};

template<class T>class Even : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return (int)x % 2 == 0;
	}
};

template<class T>
class Odd : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return (int)x % 2 != 0;
	}
};

template<class T>
void replace_copy(T* begin, T* end, T* to)
{
	for (T* from = begin; from <= end; from++)
	{
		*to = *from;
		to++;
	}
}

template<class T>
void replace_copy_if(T* begin, T* end, T* to, Predicate<T>& p)
{
	int n = 0;
	for (T* from = begin; from <= end; from++)
	{
		if (p(*to))
		{
			*to = *from;
			to++;
		}
		else
		{
			to++;
		}
	}
}