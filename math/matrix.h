#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdexcept>
#include <ostream>

#ifndef uint
typedef unsigned int uint;
#endif

namespace math
{
    template <class T>
    class matrix
    {
    public:
        matrix()
            : m_rows(1)
            , m_columns(1)
            , m_buffer(new T[1])
            , m_row_mask(*this)
            , m_persistent(false)
        {}

        matrix(uint r, uint c, T *buffer = NULL)
            : m_rows(r)
            , m_columns(c)
            , m_row_mask(*this)
        {
            m_persistent = buffer != NULL;
            m_buffer = m_persistent ? buffer : new T[r*c];
        }

        matrix(const matrix &obj)
            : m_rows(obj.m_rows)
            , m_columns(obj.m_columns)
            , m_persistent(false)
            , m_row_mask(*this)
        {
            uint length = m_rows*m_columns;
            m_buffer = new T[length];
            for(uint i = 0; i < length; ++i)
                m_buffer = obj.m_buffer;
        }

        ~matrix() { delete[] m_buffer; }

        uint rows() const { return m_rows; }
        uint columns() const { return m_columns; }

        T* to_buffer()
        {
            m_persistent = true;
            return m_buffer;
        }

        T* to_buffer() const
        {
            uint length = m_rows*m_columns;
            T* buffer = new T[length];
            for(uint i = 0; i < length; ++i)
                buffer = m_buffer;

            return buffer;
        }

        class single_row
        {
            friend class matrix;
        public:
            T& operator[](uint column)
            {
                if(column >= m_columns)
                    throw std::out_of_range("column out of range.");
                if(m_row >= m_rows)
                    throw std::out_of_range("row out of range.");

                return m_matrix.m_buffer[column+m_row*m_rows];
            }
        private:
            single_row(matrix& mt) : m_matrix(mt) {}
            matrix& m_matrix; // reference to parent matrix class
            uint m_row;
        }; // class row

        single_row operator[](uint row)
        {
            m_row_mask.m_row = row;
            return m_row_mask;
        }

    private:
        const uint m_rows, m_columns;
        T *m_buffer;
        bool m_persistent;
        single_row m_row_mask;
    }; // class matrix
}

#endif //_MATRIX_H_
