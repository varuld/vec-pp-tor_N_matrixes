#ifndef SPARSE_VECTOR_HPP
#define SPARSE_VECTOR_HPP

#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

#include "vector.hpp"
#include "Matrix.hpp"

template<class T>
class SparseVector
{
private:
	//Add your data members here!
//	int nValues; // size of value holding vector
	unsigned int sizeTot{0}; // total size of vector
//	Vector<T> mData;
	//Vector<int> mIndex;
	std::vector<int> mIndex{0}; // index array
	//Vector<T> mData;
	std::vector<T> mData; // value array

public:
	//creates an empty vector of dimensionality 0.
	SparseVector()
	{
		//unsigned int sizeTot{0};
		//std::vector<int> mIndex{0};
		//std::vector<T> mData{0};
	}

	// Creates a vector of dimensionality dim. It starts with 0 nonzero elements
	// which need to be set using setValue
	// make 2 x n matrix/vector with 2 n sized vectors, an index vector and an value vector
	SparseVector(unsigned int dim) // unsigned int = negative numbers cant be represented, only 0 -> n
	{
		sizeTot = dim;
	}

	//copy constructor, needed for SparseVector<T> operator+, set z=x
	SparseVector(const SparseVector<T>& otherSP_vec)
	{

		sizeTot = otherSP_vec.sizeTot;
		//mData = otherSP_vec.mData;
		//mIndex = otherSP_vec.mIndex;
		int numberOfVals = mData.size();
		mData = std::vector<T> (otherSP_vec.mData.size());
		for (int i=0; i < numberOfVals; i++)
		{
			mData[i] = otherSP_vec.mData[i];
		}
		mIndex = std::vector<int> (numberOfVals);
		for (int i=0; i < numberOfVals; i++)
		{
			mIndex[i] = otherSP_vec.mIndex[i];
		}
	}


	// assignment operators and copy constructor should be automatically
	// generated by the compiler when using a std::vector for internal storing.
	// However, test that assignment works!

	//sets the value v_i of the vector. if it does not exist it is added
	void printsp() const
	{
		if (sizeTot == 0)
		{
			std::cout << "Vector is dim 0" << '\n';
		}
		else if (mData.size() == 0)
		{
			std::cout << "Vector has no non-zero elements" << '\n';
		}
		else
		{
			std::cout << "The vector has size =" << sizeTot << '\n';
			std::cout << "The nonzero elements at index is: " << '\n';
			for (int i =0; i< mData.size(); i++)
			{
				std::cout << "[" << mIndex[i] << "," << mData[i] << "]" << '\n';
			}
		}
	}

	void setValue(unsigned int index, T value) // set or add value at given index
  {

  // starts with check of if index exist already, then checks if 'index' is lgerger than largest, then inserts in need be
		assert(index <= sizeTot); // cant write outside scope of vector

		bool index_exist = std::binary_search(mIndex.begin(), mIndex.end(), index); // is there index value = to 'index' ?

		if (index_exist) // if 'index' IS in mIndex
		{
			std::vector<int>::iterator it_mI = std::lower_bound(mIndex.begin(), mIndex.end(), index); // *it_mI should = index, have indx_of_n
			auto position = std::distance(mIndex.begin(), it_mI); // gives number of elements into mIndex where index is
			typename std::vector<T>::iterator it_val = mData.begin() + position; // iterator for mData with same relative indentation as it_mI
			*it_val = value; // writes value to indx_of_n in mData vector
		}
		else // if 'index' is not in mIndex
		{
			std::vector<int>::iterator last_index_val = mIndex.end();

			if ( *last_index_val < index) // if 'index' is larger than largest/last mIndex value
			{
				// adds to the back
				mIndex.push_back(index);
				mData.push_back(value);
			}
			else // if 'index' is smaler than last mIndex value with no-match, it should be slottet in
			{
				std::vector<int>::iterator it_indset_below_index = std::upper_bound(mIndex.begin(), mIndex.end(), index); // iterator to insert below

				auto indset_position_val = std::distance(mIndex.begin(), it_indset_below_index);
				typename std::vector<T>::iterator it_indset_below_val = mData.begin() + indset_position_val;

				it_indset_below_index = mIndex.insert(it_indset_below_index,index);
				it_indset_below_val = mData.insert(it_indset_below_val,value);

			}
		}
	}

	//returns the value v_i of the vector. Returns 0 if the value is not stored
	T getValue(unsigned int index)const
	{
		// checks if values exists
		bool index_exists{ std::binary_search(mIndex.begin(), mIndex.end(), index) };
		// auto idx = std::lower_bound(mIndex.begin(), mIndex.end(), index);

		// if the value exixts, return value at  greater or equal to index
		// which gives right value bq we know index exixts
		if  (index_exists)
		{
			auto it_val_indx { std::lower_bound(mIndex.begin(), mIndex.end(), index) };
			int PlacementOfValue = std::distance(mIndex.begin(), it_val_indx);

			return mData[PlacementOfValue];
		}
		else
		{
			return 0;
			// T val = mData[*idx];
			// return val;
		}
	}

	// needed for SparseVector \times Matrix(dense) operations
	int getIndex(int is_index_this) const
	{
		bool indx_match{ binary_search(mIndex.begin(), mIndex.end(), is_index_this) };
		auto it_indx{ std::lower_bound(mIndex.begin(), mIndex.end(), is_index_this) };
		int indx_place = std::distance(mIndex.begin(), it_indx);

	 // bool no_match = (idx == mIndex.end() && *idx != is_index_this);
		if (indx_match)
		{
			return indx_place;
		}
		else
		{
			return 0;
		}

		// ikke findes; then return -1
	}



	//returns the dimensionality of the vector
	unsigned int size() const {return sizeTot;}

	// returns the number stored elements
	unsigned int nonZeroes() const {return mData.size();}

	//returns the index of the ith stored nonzero entry (in increasing order)
	unsigned int indexNonZero(unsigned int i)const
	{
		unsigned int idx = mIndex[i];
		return idx;
	}

	//returns the value of the ith stored nonzero entry (in increasing order)
	T valueNonZero(unsigned int i) const
	{
		assert(i <= mData.size());
		return mData[i];
		// int j = mIndex[i];
		// T val = mData[j];
		// return val;
	}

	//adds x too the current vector(current vector = c_v)
	// for addding 2 sparse vectors together
	SparseVector<T>& operator+= (SparseVector<T> const& x)
	{
		if (sizeTot < x.sizeTot)
		{
			sizeTot = x.sizeTot;
		}
		int len_x = x.nonZeroes();

		// for all elements in x.vector, find lowest index match in org.vector
		//
		for  (int i = 0 ; i < len_x ; ++i)
		{
			// checks if x' ith index exists in c_v
			int x_indx{ x.mIndex[i] };
			bool indx_findes = std::binary_search(mIndex.begin(), mIndex.end(), x_indx);

			// auto idx_exixts = std::lower_bound(mIndex.begin(), mIndex.end(), x.mIndex[i]);

			// bool checks if, given pointer to end of org.vector, it's a match
			// bool no_match = (idx_exixts == mIndex.end() && *idx_exixts != x.mIndex[i]);

			// given a match, add the values of the matching idx's
			// and writes to org.vector
			if (indx_findes)
			{
				auto  it_indexOfIndexMatch{ std::lower_bound(mIndex.begin(), mIndex.end(), x_indx) };
				int PlacementOfValue = std::distance(mIndex.begin(),it_indexOfIndexMatch);

				T valueNew{ mData[PlacementOfValue] + x.mData[i] };
				setValue(PlacementOfValue, valueNew);
			}

			//if (std::find(mIndex.begin(),mIndex.end(), x.mIndex[i]) != mIndex.end())

			else // for non-match
			{
				int x_idx{ x.mIndex[i] };
				T valNew{x.mData[i]};
				setValue(x_idx, valNew);
			}

			}
			// return *this;
		}

	//subtracts x from the current vector
	// for subtrting 2 sparse vectors from each other
	SparseVector<T>& operator-= (SparseVector<T> const& x)
	{

		if (sizeTot < x.sizeTot)
		{
			sizeTot = x.sizeTot;
		}
		int len_x = x.nonZeroes();

	// for all elements in x.vector, find lowest index match in org.vector
	//
		for  (int i = 0 ; i < len_x ; ++i)
		{
			// checks if x' ith index exists in c_v
			int x_indx{ x.mIndex[i] };
			bool indx_findes = std::binary_search(mIndex.begin(), mIndex.end(), x_indx);

			// given a match, add the values of the matching idx's
			// and writes to org.vector
			if (indx_findes)
			{
				auto it_indexOfIndexMatch{ std::lower_bound(mIndex.begin(), mIndex.end(), x_indx) };
				int PlacementOfValue = std::distance(mIndex.begin(), it_indexOfIndexMatch);
				T valueNew{ mData[PlacementOfValue] - x.mData[i] };
				setValue(PlacementOfValue, valueNew);
			}

			//if (std::find(mIndex.begin(),mIndex.end(), x.mIndex[i]) != mIndex.end())

			else // for non-match
			{
				int x_idx{ x.mIndex[i] };
				T valNew{ -x.mData[i] };
				setValue(x_idx, valNew);
			}
		}
	}
};

/*
// computes z= x+y, equivalent to z=x, z+=y
template<class T>
SparseVector<T> operator+(SparseVector<T> const& x, SparseVector<T> const& y)
{
	SparseVector<T> z = SparseVector<T> (x);
	z += y;

	return z;
}

// computes z= x-y, equivalent to z=x, z-=y
template<class T>
SparseVector<T> operator-(SparseVector<T> const& x, SparseVector<T> const& y)
{
	SparseVector<T> z = SparseVector<T>(x);
	z -= y;

	return z;
};


// computes the matrix-vector product of a dense matrix and sparse vector z=Ax.
// The result is a dense vector.
template<class T>
Vector<T> operator* (Matrix<T> const& A, SparseVector<T> const& x)
{
	int vec_len = x.sizeTot;
	int matrix_len = A.GetNumberOfColumns();
	assert(matrix_len == vec_len);

	int len_z = A.GetNumberOfRows();
	Vector<T> z = Vector<T> (len_z);

	for (int i = 0; i < vec_len; i++)
	{
		if (x.getIndex(i) == -1)
		{break;}
		else
		{
			for (int j = 0; j < matrix_len; j++)
			{
				T sum = A(j,i) * x.mData[i]; // A[col][row] * v[i=row]
				sum += z[j]; // sum = sum + z[row]
				z.insert(j, sum); // z[row] = sum + z[row]
			}
		}
	}
	return z;
};

// computes the matrix-vector product of a dense matrix and sparse vector z=x^TA.
// The result is a dense vector.
template<class T>
Vector<T> operator* (SparseVector<T> const& x, Matrix<T> const& A)
{
	int len_vec = x.sizeTot;
	int mat_len = A.GetNumberOfRows();
	assert(len_vec == mat_len);

	int len_z = A.GetNumberOfColumns();
	Vector<T> z = Vector<T> (len_z);

	for (int i =0; i < len_vec;i++)
	{
		if (x.getIndex(i) == -1)
		{break;}
		else
		{
		T sum;
			for (int j=0; j < mat_len ; j++)
			{
				sum += x.mData[i] * A(j,i);
			}
		z.insert(i, sum);
		}
	}
	return z;

};
*/

#endif
