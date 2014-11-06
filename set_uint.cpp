#include "set_uint.h"

namespace set_uint
{
        bool Set::contains(char* str, char c)
        {
                for (size_t i = 0; i < strlen(str); ++i)
                {
                        if (str[i] == c)
                                return true;
                }
                return false;
        }
        
        Set::Set()
        {
                Data = rand() % 0xFFFF;
        }
        
        Set::Set(char* str)
        {
                Data = 0;
                for (int i = 0; i < MAX_SIZE; ++i)
                        if (contains(str, Vocabulary[i]))
                                Data |= (1u << (i));                        
        }
        
        Set::Set(Set& s)
        {
                this->Data = s.Data;
        }
        
        Set& Set::operator =(Set rhs)
        {
                this->Data = rhs.Data;
                return *this;
        }
        
        Set& Set::operator~() 
        {
            Set* s = new Set(*this);
            s->Data ^= ~0u; // X xor 1 = not X
            return *s;
        }
        
        Set& Set::operator&(Set& rhs)
        {
            Set* s = new Set(*this);
            s->Data &=  rhs.Data;
            return *s;
        }
        
        std::ostream& operator<<(std::ostream& out, Set& s)
        {
                out << "{";
                if (s.Data == 0)
                {
                        out << "empty";
                }
                else
                        for (int i = 0; i < MAX_SIZE; ++i) 
                                if ((s.Data >> i) %2 == 1 ) 
                                        out << Vocabulary[i];
                out << "}";
                return out;
        }
                
} // namespace set_uint
