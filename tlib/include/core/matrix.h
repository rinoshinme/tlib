#ifndef tlib_matrix_h
#define tlib_matrix_h

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
        Matrix();
        Matrix(const std::vector<T>& diag);
        static Matrix zeros();
        static Matrix ones();
        
        
    };
}

#endif /* tlib_matrix_h */
