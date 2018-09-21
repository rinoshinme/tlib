#ifndef tlib_matrix_h
#define tlib_matrix_h

#include "vector.h"

namespace tlib
{
    /*
     * fixed size matrix
     */
    template<typename T, int Rows, int Cols>
    class Matrix
    {
    private:
        T m_data[Rows][Cols];
    public:
        Matrix() {}
        Matrix(const std::vector<T>& diag)
        {
            for (int r = 0; r < Rows; ++r)
            {
                for (int c = 0; c < Cols; ++c)
                {
                    if (r == c)
                        m_data[r][c] = diag[r];
                    else
                        m_data[r][c] = 0;
                }
            }
        }
        
        T& operator()(int r, int c) { return m_data[r][c]; }
        const T& operator()(int r, int c) const { return m_data[r][c]; }
        
    public:
        static Matrix<T, Rows, Cols> zeros()
        {
            Matrix<T, Rows, Cols> matrix;
            for (int r = 0; r < Rows; ++r)
            {
                for (int c = 0; c < Cols; ++c)
                {
                    matrix(r, c) = 0;
                }
            }
            return matrix;
        }
        
        static Matrix<T, Rows, Cols> ones()
        {
            Matrix<T, Rows, Cols> matrix;
            for (int r = 0; r < Rows; ++r)
            {
                for (int c = 0; c < Cols; ++c)
                {
                    matrix(r, c) = 1;
                }
            }
            return matrix;
        }
    };
    
    template<typename T, int Rows, int Cols>
    Vector<T, Cols> operator*(const Matrix<T, Rows, Cols>& mat, const Vector<T, Cols>& vec);
    template<typename T, int Rows, int Cols>
    Vector<T, Rows> operator*(const Matrix<T, Rows, Cols>& mat, const Vector<T, Rows>& vec);
    
}

#endif /* tlib_matrix_h */
