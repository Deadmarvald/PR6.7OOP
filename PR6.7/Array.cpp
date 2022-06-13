#include "Array.h"
#include <iostream>
#include <stdexcept>
#include <exception>

using namespace std;

Array::Array(const size_t& n)
throw(bad_alloc, invalid_argument)
{
	First = 0;
	Count = Size = n;
	elems = new double[Size];
	for (unsigned int i = 0; i < Size; i++)
		elems[i] = 0;
}

Array::Array(const double* first, const double* last)
throw(bad_alloc, invalid_argument)
{
	First = 0;
	if (first <= last) {
		Count = Size = (last - first) + 1;
		elems = new double[Size];
		for (unsigned int i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}

Array::Array(const size_t first, const size_t last)
throw(bad_alloc, invalid_argument)
{
	if (first <= last) {
		First = first;
		Count = Size = (last - first) + 1;
		elems = new double[Size];
		for (unsigned int i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}

Array::Array(const Array& t) throw(bad_alloc)
	: Size(t.Size), Count(t.Count), First(t.First), elems(new double[Size])
{
	for (unsigned int i = 0; i < Size; ++i)
		elems[i] = t.elems[i];
}

Array& Array::operator =(const Array& t)
{
	Array tmp(t);
	swap(tmp);
	return *this;
}

Array::~Array()
{
	delete[]elems;
	elems = 0;
}

void Array::push_back(const double& v)
{
	if (Count == Size) // м≥сц€ нема
		resize(Size * 2); // зб≥льшили "м≥стк≥сть"
	elems[Count++] = v; // присвоњли
}

void Array::pop_back()
{
	if (size() > 0)
	{
		double* tmp = new double[size() - 1];
		for (size_t i = 0; i < size() - 1; ++i)
			tmp[i] = elems[i];
		delete[] elems;
		elems = tmp;
		Size = size() - 1;
	}
}

double& Array::operator [](size_t index) throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}

const double& Array::operator [](size_t index) const
throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}

void Array::resize(size_t newsize) throw(bad_alloc)
{
	if (newsize > capacity())
	{
		double* data = new double[newsize];
		for (size_t i = 0; i < Count; ++i)
			data[i] = elems[i];
		delete[] elems;
		elems = data;
		Size = newsize;
	}
}

void Array::swap(Array& other)
{
	std::swap(elems, other.elems); // стандартна функц≥€ обм≥ну
	std::swap(Size, other.Size);
}

size_t Array::capacity() const
{
	return Size;
}

size_t Array::size() const
{
	return Count;
}

bool Array::empty() const
{
	return Count == 0;
}

ostream& operator <<(ostream& out, const Array& tmp)
{
	for (size_t j = 0; j < tmp.Count; j++)
		out << tmp[j] << " ";
	out << endl;
	return out;
}

istream& operator >>(istream& in, Array& tmp)
{
	double x;

	for (size_t j = 0; j < tmp.Count; j++)
	{
		cout << "elem є " << j + 1 << " = "; in >> x;
		tmp.elems[j] = x;
	}

	return in;
}

void Array::print()
{
	for (int i = 0; i < size(); i++)
		cout << elems[i] << " ";
	cout << "\n\n";
}