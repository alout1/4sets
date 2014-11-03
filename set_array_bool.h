#ifndef SET_ARRAY_BOOL_H
#define	SET_ARRAY_BOOL_H

#include <iostream>
#include <cstdlib>
#include <string.h>

namespace set_array_bool
{
    const int MAX_SIZE = 16;
    const char Vocabulary[] = "0123456789ABCDEF";
    
    class Set
    {
    private:
        bool Data[MAX_SIZE];
        bool contains(char* str, char c);
    public:
        Set();
        Set(char*);
        Set(Set&);
        Set& operator=(Set rhs);
        Set& operator~();
        Set& operator&(Set& rhs);
        friend std::ostream& operator<<(std::ostream& out, Set& s);
        
    }; // class Set
} // namespace set_array_bool

#endif	/* SET_ARRAY_BOOL_H */

