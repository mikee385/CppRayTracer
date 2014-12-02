#ifndef TABLE_HEADER_GUARD
#define TABLE_HEADER_GUARD

#include <stdexcept>
#include <vector>

namespace table
{
    template< typename T>
    class Table
    {
    private:
        std::vector<T> _data;
        size_t _width;
        size_t _height;

        size_t GetIndex(size_t row, size_t column) const
        {
            if (row >= _height)
                throw std::out_of_range("row");
            if (column >= _width)
                throw std::out_of_range("column");

            return row*_width + column;
        }

    public:
        typedef typename std::vector<T>::const_reference const_reference;

        Table(size_t width, size_t height)
            : _width(width), _height(height), _data(width * height)
        {}

        Table(size_t width, size_t height, const_reference value)
            : _width(width), _height(height), _data(width * height, value)
        {}

        size_t GetWidth() const
        {
            return _width;
        }

        size_t GetHeight() const
        {
            return _height;
        }

        void Set(size_t row, size_t column, const_reference value)
        {
            _data[GetIndex(row, column)] = value;
        }

        const_reference Get(size_t row, size_t column) const
        {
            return _data[GetIndex(row, column)];
        }
    };
}

#endif
