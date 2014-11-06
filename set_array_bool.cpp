#include "set_array_bool.h"

namespace set_array_bool {
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
                for (int i = 0; i < MAX_SIZE; ++i)
                {
                        Data[i] = rand() % 2;
                }
        }
        
        Set::Set(char* str)
        {
                for (int i = 0; i < MAX_SIZE; ++i)
                {
                        if (contains(str, Vocabulary[i]))
                                Data[i] = true;
                        else
                                Data[i] = false;
                }
        }
        
        Set::Set(Set& s)
        {
            for (int i = 0; i < MAX_SIZE; ++i)
            {
                this->Data[i] = s.Data[i];
            }
        }
        
        Set& Set::operator =(Set rhs)
        {
            std::swap(this->Data, rhs.Data);
            return *this;
        }
        
        Set& Set::operator~() 
        {
            Set* s = new Set(*this);
            for (int i = 0; i < MAX_SIZE; ++i)
            {
                s->Data[i] = !this->Data[i];
            }
            return *s;
        }
        
        Set& Set::operator&(Set& rhs)
        {
            Set* s = new Set(*this);
            for (int i = 0; i < MAX_SIZE; ++i)
            {
                s->Data[i] &=  rhs.Data[i];
            }
            return *s;
        }
        
        std::ostream& operator<<(std::ostream& out, Set& s)
        {
                bool f = 0;
                out << "{";
                for (int i = 0; i < MAX_SIZE; ++i)
                {
                        if (s.Data[i] == true)
                        {
                                out << Vocabulary[i]; 
                                f = 1;         
                        }
                }
                if (f==0)
                        out << "empty";
                out << "}";
                return out;
        }
                
} // namespace set_array_bool
