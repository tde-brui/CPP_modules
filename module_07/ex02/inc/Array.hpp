#include <iostream>

template <class T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	
	public:
		Array() : _array(NULL), _size(0) {};
		Array(unsigned int n) : _array(new T[n]), _size(n) {};
		Array(const Array &array)
		{
			this->_array = new T[array._size];
			this->_size = array._size;
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = array._array[i];
		}
		Array &operator=(const Array &array)
		{
			if (this == array)
				return *this;
			delete[] this->_array;
			this->_array = new T[array._size];
			this->_size = array._size;
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = array._array[i];
			return *this;
		}

		~Array()
		{
			delete[] this->_array;
		}

		T	&operator[](unsigned int i)
		{
			if (i >= this->_size)
				throw std::out_of_range("Index out of range");
			return this->_array[i];
		}

		size_t size() const
		{
			return this->_size;
		}
};