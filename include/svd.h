/*****************************************************************************
 *                                    svd.h
 *
 * Class template of Singular Value Decomposition.
 *
 * For an m-by-n matrix A, the singular value decomposition is an m-by-m
 * orthogonal matrix U, an m-by-n diagonal matrix S, and an n-by-n orthogonal
 * matrix V so that A = U*S*V'. For economy size, U is m-by-p, S is p-by-p
 * and V is n-by-p;
 *
 * The singular values, sigma[k] = S[k][k], are ordered so that sigma[0] >=
 * sigma[1] >= ... >= sigma[n-1].
 *
 * The singular value decompostion always exists, so the constructor will
 * never fail. The matrix condition number and the effective numerical rank
 * can be computed from this decomposition.
 *
 * Adapted form Template Numerical Toolkit.
 *
 * Zhang Ming, 2010-01, Xi'an Jiaotong University.
 *****************************************************************************/


#ifndef SVD_H
#define SVD_H


#include <matrix.h>


namespace itlab
{

	template <typename Real>
	class SVD
	{

	public:

        SVD();
		~SVD();

        void dec( const Matrix<Real> &A );
        void decomposition( const Matrix<Real> &A );
		Matrix<Real> getU() const;
		Matrix<Real> getV() const;
		Matrix<Real> getSM();
		Vector<Real> getSV() const;

		Real norm2() const;
		Real cond() const;
		int  rank();

    private:

        // row and column dimensions
		int m;
		int n;
		bool mLTn;

		// the orthogonal matrix and singular value vector
		Matrix<Real> U;
		Matrix<Real> V;
		Vector<Real> s;

	};
	// class SVD


    #include <svd-impl.h>

}
// namespace itlab


#endif
// SVD_H