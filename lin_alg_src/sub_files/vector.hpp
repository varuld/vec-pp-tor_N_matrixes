#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <cassert>
#include <cmath>
#include <vector>
template<typename T>
class Vector
{
private:
	std::vector<T> mData; // data stored in vector

public:
    // copy constructor
  Vector(const Vector<T>& otherVector)
    {
        mData = std::vector<T> (otherVector.size());
        for (int i = 0; i < otherVector.size(); i++)
			//	for (int i : otherVector.size())
        {
            mData[i] = otherVector.mData[i];
        }
    }

	//explicit
	Vector(int size) // hard code at Vector(n) gir vec med n size
    {
        assert(size > 0);
				mData = std::vector<T>(size);
    }


	int size() const
    {
        return mData.size();
    }

	T& operator[](int i)
    {
        assert(i >= 0 && i < size());
        return mData[i];
    }

	T const& operator[] (int i)const
    {
        assert(i >= 0 && i < size());
        return mData[i];
    }

	// assignment operator
	Vector<T>& operator=(const Vector<T>& otherVector)
    {
        assert(size() == otherVector.size());

        for (int i = 0; i < size(); i++)
        {
            mData[i] = otherVector.mData[i];
        }
        return *this;
    }

    // overloading the unary - operator
	Vector<T> operator-() const
    {
        Vector<T> v(size());
        for (int i = 0; i < size(); i++)
        {
            v[i] = -mData[i];
        }
        return v;
    }

    // overloading the binary + operator
	Vector<T> operator+(const Vector<T>& v1) const
    {
        assert(size() == v1.size());

        Vector<T> v(size());
        for (int i = 0; i < size(); i++)
        {
            v[i] = mData[i] + v1.mData[i];
        }
        return v;
    }

    // overloading the binary - operator
	Vector<T> operator-(const Vector<T>& v1) const
    {
        assert(size() == v1.size());

        Vector<T> v(size());
        for (int i = 0; i < size(); i++)
        {
            v[i] = mData[i] - v1.mData[i];
        }
        return v;
    }

	// scalar multiplication
	Vector<T> operator*(T a) const
    {
        Vector<T> v(size());
        for (int i = 0; i < size(); i++)
        {
            v[i] = a*mData[i];
        }
        return v;
    }

	// p-norm method
	T CalculateNorm(int p = 2) const
    {
        T sum = 0.0;
        for (int i = 0; i < size(); i++)
        {
            sum += pow(std::abs(mData[i]), p);
        }
        return pow(sum, 1.0 / ((double)(p)));
    }

		std::vector<T> const& getStorage() const
		{
			return mData;
		}
};


#endif
