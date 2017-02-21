#ifndef _PAINT_H_
#define _PAINT_H_

#include <utility>
#include <defines.h>
#include <matrix.h>

namespace graphic
{
    class paint
    {
    public:
        void static draw_line_DDA(char * buffer,
                                  std::pair<uint,uint> size,
                                  std::pair<uint,uint> p1,
                                  std::pair<uint,uint> p2);

        void static draw_line_bresenham(char * buffer,
                                        std::pair<uint,uint> size,
                                        std::pair<uint,uint> p1,
                                        std::pair<uint,uint> p2);

        void static draw_circle_bresenham(char * buffer,
                                          std::pair<uint,uint> size,
                                          std::pair<uint,uint> center,
                                          std::pair<uint,uint> radius);
    };
}

#endif //_PAINT_H_
