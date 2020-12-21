#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF
#include "vector.hpp"

template<typename T>
class Matrix
{
private:
  // uses 1 vector to store all info in a list
	std::vector<T> mData;
	int nRows; int nCols;
	int size;
	//std::vector<Vector<T>> mData; // vector of vectors
	//T** mData; // entries of matrix
	//int mNumRows.size(), mNumCols.size(); // dimensions
	//T** mData; // entries of matrix
	//int mNumRows, mNumCols; // dimensions
	// Vector<Vector<T>> mData; // with own Vector struc inside own Vector  struc

public:

	// own refac matrix constructor
	Matrix(int numRows, int numCols)
	{
		nRows = numRows;
		nCols = numCols;
		size = numRows*numCols;
	  mData = std::vector<T> (size);

	  // mData = rows(cols);

	}


	// copy constructor
	Matrix(const Matrix<T>& otherMatrix)
    {
				mData = (otherMatrix.getStorage());

        /*for (int i = 0; i < otherMatrix.GetIndex(); i++)
        {
				std::vector<T>
            mData[i] = otherMatrix.mData[i];
        }*/
    }



	// should not need decontructor bc std::vector deltes the vector on auto
	// ~Matrix(){
		//		int rows  = GetNumberOfRows();
    //    for (int i = 0; i < rows; i++)
    //    {
    //        delete[] mData[i];
    //    }
        //delete[] mData;
    // }

	int GetIndex(int rows, int cols) const
	{
		return 2*(cols+rows);
	}
	int GetSize() const
	{
		return size;
	}
	int GetNumberOfRows() const
    {
        return nRows;
    }

	int GetNumberOfColumns() const
    {
        return nCols;
    }

	T& operator()(int i, int j) // read-write opr
    {
        assert(i >= 0);
        assert(i < nRows);
        assert(j >= 0);
        assert(j < nCols);

				int idx = GetIndex(i,j);
				return mData[idx];
    }

	T const& operator()(int i, int j) const // retrieve non-write opr
    {
        assert(i >= 0);
        assert(i < nRows);
        assert(j >= 0);
        assert(j < nCols);

				int idx = GetIndex(i,j);
				return mData[idx];
    }

	// overloaded assignment operator
	Matrix<T>& operator=(const Matrix<T>& otherMatrix)
    {
				int mNumRows = GetNumberOfRows();
				int mNumCols = GetNumberOfColumns();
        assert(mNumRows == otherMatrix.GetNumberOfRows());
        assert(mNumCols == otherMatrix.GetNumberOfColumns());

        for (int i = 0; i < mNumRows; i++)
        {
            for (int j = 0; j < mNumCols; j++)
            {
                mData[i][j] = otherMatrix.mData[i][j];
            }
        }
        return *this;
    }

	Matrix<T> operator-() const // unary -
    {
				Matrix<T> mat(nRows, nCols);
				for (int i = 0; i < nRows; i++)
        {
					for (int j = 0; j < nCols ; j++)
					{
						mat(i,j) = -mData[GetIndex(i,j)];
					}
        }
        return mat;

    }
		// overloading the binary + operator
	Matrix<T> operator+(const Matrix<T>& m1) const
    {
        assert(GetSize() != m1.GetSize());

        Matrix<T> mat(nRows, nCols);

        for (int i = 0; i < nRows; i++)
        {
					for (int j = 0; j < nCols ; j++)
					{
						mat(i,j) = mData[GetIndex(i,j)] - m1(i,j);
					}
        }
        return mat;
    }

		// overloading the binary - operator
	Matrix<T> operator-(const Matrix<T>& m1) const
		{

				assert(GetNumberOfRows() != m1.GetNumberOfRows());
				assert(GetNumberOfColumns() != m1.GetNumberOfColumns());

				Matrix<T> md(nRows, nCols);
				for (int i = 0; i < nRows;i++ )
				{
					for (int j = 0; j < nCols ; j++)
					{
						md(i,j) = mData[GetIndex(i,j)] - m1(i,j);
					}
				}
				return md;
		}

	// scalar multiplication
	Matrix<T> operator*(T a) const
	    {
	        Matrix<T> mat(nRows, nCols);
	        for (int i = 0; i < nRows; i++)
	        {
						for (int j = 0; j < nCols ; j++)
						{
							mat(i,j) = a*mData[GetIndex(i,j)];
						}
	        }
	        return mat;
	    }

		std::vector<T> const& getStorage() const
		{
			return mData;
		}
}; // class Matrix


//matrix-vector multiplications
template<typename T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
    int original_vector_size = v.size();
	assert(m.GetNumberOfColumns() == original_vector_size);

	int new_vector_length = m.GetNumberOfRows();
	Vector<T> new_vector(new_vector_length);

	for (int i = 0; i < new_vector_length; i++)
	{
		for (int j = 0; j < original_vector_size; j++)
		{
			new_vector[i] += m(i,j)*v[j];
		}
	}

	return new_vector;
}
template<typename T>
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfRows() == original_vector_size);

	int new_vector_length = m.GetNumberOfColumns();
	Vector<T> new_vector(new_vector_length);

	for (int i = 0; i < new_vector_length; i++)
	{
		for (int j = 0; j < original_vector_size; j++)
		{
			new_vector[i] += v[j]*m(j,i);
		}
	}

	return new_vector;
}

#endif
