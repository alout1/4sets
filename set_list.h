 #ifndef SET_LIST_H
#define	SET_LIST_H

#include <iostream>
#include <cstdlib>
#include <string.h>

namespace set_list
{
    const int MAX_SIZE = 16;
    const char Vocabulary[] = "0123456789ABCDEF";
    
    class Element
    {
    private:
        char data;
        
    public:
        Element* next;
        explicit Element(char);
        friend std::ostream& operator<<(std::ostream& out, Element& e);
        friend class Set;
    }; // class Element
    
    class Set
    {
    private:
        Element* begin;
        Element* end;
        bool contains(char c);
        void shuffle(char *array, size_t n);
        
    public:
        Set();
        Set(const char *);
        Set(Set&);
        ~Set();
        void push_back(char c);
        void erase(int);
        int size();
                
        Element* operator[](int index);
        Set& operator =(Set& rhs);
        Set& operator~();
        Set& operator&(Set& rhs);
        friend std::ostream& operator<<(std::ostream& out, Set& s);
    }; // class Set
} // namespace set_list


#endif	/* SET_LIST_H */

