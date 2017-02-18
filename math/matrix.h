#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdexcept>

namespace math
{
    template <class T>
    class matrix
    {
    public:

        class single_row
        {
            friend class matrix;
        public:
            T& operator[](uint column)
            {
                if(0) // Need to add range verification
                    throw out_of_range("Range error message!");

                return m_matrix.m_buffer[column+];
            }
        private:
            single_row(matrix& mt) : m_matrix(mt) {}
            matrix& m_matrix; // reference to parent matrix class
            uint m_row_number;
        }; // class row

        single_row operator[](uint row)
        {
            m_row_mask.m_row_number = row;
            return 
        }

    private:
        T *m_buffer;
        single_row m_row_mask = single_row(*this);
    }; // class matrix
}

#endif //_MATRIX_H_
