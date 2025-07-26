#include <iostream>

template<typename T>

class Array
{
	private:
		T				*data;
		unsigned int	_size;
	public:
		Array() : _size(0)
		{
			this->data = new T[this->_size];
		};
		Array(unsigned int n) : _size(n)
		{
			this->data = new T[this->_size];
		};
		Array(Array const &other)
		{
			this->_size = other._size;
			this->data = (this->_size > 0) ? new T[this->_size] : 0;
			for (unsigned int i = 0; i < this->_size; i++)
				this->data[i] = other.data[i];
		}
		Array &operator=(Array const &other)
		{
			if (this == &other)
				return *this;
			if (this->data)
				delete [] this->data;
			this->_size = other._size;
			this->data = (this->_size > 0) ? new T[this->_size] : 0;
			for (unsigned int i = 0; i < this->_size; i++)
				this->data[i] = other.data[i];
			return *this;
		}
		~Array()
		{
			if (this->data != NULL)
				delete [] this->data;
		}

		T &operator[](unsigned int index)
		{
			if (index >= this->_size)
				throw std::out_of_range("Array index out of range");
			return this->data[index];
		}
		const T &operator[](unsigned int index) const
		{
			if (index >= this->_size)
				throw std::out_of_range("Array index out of range");
			return this->data[index];
		}

		unsigned int size() const { return this->_size; };
};