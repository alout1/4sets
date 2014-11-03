#ifndef SET_UINT_H
#define	SET_UINT_H

#include <iostream>
#include <cstdlib>
#include <string.h>

namespace set_uint
{
    typedef uint16_t uint;
    const int MAX_SIZE = 16;
    const char Vocabulary[] = "0123456789ABCDEF";
    
    class Set
    {
    private:
        uint Data;
        bool contains(char* str, char c);
    public:
        Set();
        Set(char*);
        Set(Set&);
        Set& operator=(Set rhs);
        bool& operator[](int index);
        Set& operator~();
        Set& operator&(Set& rhs);
        friend std::ostream& operator<<(std::ostream& out, Set& s);
        
    }; // class Set
    
}// namespace set_uint
#endif	/* SET_UINT_H */

