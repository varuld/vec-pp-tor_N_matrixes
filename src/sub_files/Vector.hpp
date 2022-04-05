#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <vector>
#include <cassert>
#include <cmath>
#include <iostream>

template <class T>
class Vector
{
private:
//	T *mData;
//	int mSize;
	std::vector<T> mData;
public:

	Vector(const Vector<T>& otherVector) // copy constructor, overwiritten
	{
		int size_otherVector = otherVector.size();
		mData = std::vector<T> ( size_otherVector );
		for (int i = 0; i < size_otherVector; ++i )
		{
			mData[i] = otherVector.mData[i];
		}
	}
	Vector<T>(int size) // constructor
	{
		assert(size > 0);
		mData = std::vector<T>(size);
	}
	// Overridden destructor to correctly free memory
//	Vektor<T>::~Vektor()
//	{
//		delete[] mData;
//	}
	int size() const // get size, never modify data
	{
				return mData.size();
	}
	T& operator[](int i) // zero-based indexing
	{
		assert(i >= 0 && i <= size() ); // check if i is inside size of vektor
		return mData[i];
	}
	T const& operator[] (int i) const // zero-based indexing
	{
		assert( i >= 0);
		assert(i <= size() );
		return mData[i];
	}

	// operators
	Vector& operator=(const Vector& otherVector)
	{
		int size_otherVector = otherVector.size();
		assert(size() == size_otherVector );
		for (int i = 0 ; i < size_otherVector; ++i )
		{
			mData[i] = otherVector.mData[i];
		}
		return *this;
	}

	// assignment operator, assign V1 to V2
	Vector operator-() const // unary - operator/ scalar minus
	{
		Vector<T> vec( size() );
		for ( int i = 0 ; i < size(); ++i )
		{
			vec[i] = - mData[i];
		}
		return vec;
	}

	Vector operator+(const Vector<T>& v1) const // binary + opr
	{
		unsigned int size_v1 = v1.size();
		Vector<T> vec_plus( size_v1 );
		for (unsigned int i = 0 ; i < size_v1 ; ++i )
		{
			vec_plus[i] = mData[i] + v1.mData[i];
		}
		return vec_plus;
	}

	// Overloading the binary - operator
	// makes new product vector with result
	Vector operator-(const Vector<T>& v1) const // binary - opr
	{
		unsigned int size_v1 = v1.size();
		Vector<T> vec_minus( size_v1 );
		for (unsigned int i = 0 ; i < size_v1 ; ++i )
		{
			vec_minus[i] = mData[i] - v1.mData[i];
		}
		return vec_minus;
	}

	Vector operator*(T a_factor) const
	{
		unsigned int size_own = size();
		Vector vec_times( size_own );
		for (unsigned int i = 0 ; i < size_own ; ++i )
		{
			vec_times[i] = a_factor * mData[i];
		}
		return vec_times;
	}

	T CalculateNorm(int p=2) const
	{
		unsigned int size_own = size();
		double norm_val{0.0};
		double sum{0.0};
		for (unsigned int i = 0 ; i < size_own ; ++i )
		{
			sum += pow(fabs(mData[i]), p);
		}
		norm_val = pow(sum, 1.0/( (double)(p) ) );
		return norm_val;
	}

	Vector<T> const& getStorage() const
	{
				return mData;
	}
	void vectorprint()
	{
		std::cout << "[ ";
		for (int i = 0; i < size(); i++) {
			std::cout << mData[i] << ',';
		}
		std::cout << " ]" << '\n';
	}

};

#endif
