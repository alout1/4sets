#include "set_list.h"

namespace set_list
{
    Element::Element(char c)
    {
        data = c;
        next = nullptr;
    }    
    
    std::ostream& operator<<(std::ostream& out, Element& e)
    {
        out << e.data;
        return out;
    }
    
    Set::Set()
    {
        begin = nullptr;
        char* new_data = new char[MAX_SIZE + 1];
        strcpy(new_data, Vocabulary);
        shuffle(new_data, MAX_SIZE);
        int new_size = rand()%MAX_SIZE+1;
        for (int i = 0; i < new_size; ++i)
        {
                push_back(new_data[i]);
        }
        delete[] new_data;
    }
    
    Set::Set(const char* new_data)
    {   
        begin = nullptr;
        int list_size = strlen(new_data);
        if (list_size > 0)
        {
            for (int i = 0; i < list_size; ++i)
                    push_back(new_data[i]);   
            end->next = nullptr;
        }
        else
        {
            begin = nullptr;
            end = nullptr;
        }
        
    }
    
    Set::Set(Set& s)
    {
        Element* q = s.begin;
        Element* p = this->begin;
        if (q == nullptr)
            return;
        else 
            p = new Element(q->data);
        
        while (q->next != nullptr)
        {
            p->next = new Element(q->next->data);
            p = p->next;
            q = q->next;
        }
    }
    
    Set::~Set()
    {
        while (begin != nullptr)
            erase(0);
    }
     
    void Set::push_back(char c)
    {
            if (begin == nullptr)
            {
                    begin = new Element(c);
                    end = begin;
                    return;
            }
            else
            {
                    end->next = new Element(c);
                    end = end->next;
            }
        
    }
    
    void Set::erase(int index)
    {
        if (index == 0)
        {
            if (begin == nullptr)
                return;
            if (begin->next == nullptr)
            {
                delete begin;
                begin = nullptr;
                return;
            }
            else
            {
                    Element* q = begin;
                    begin = q->next;
                    delete q;
                    return;
            }
        }
        else 
        {
            Element* q = (*this)[index-1];
            Element* p = (*this)[index];
            if (p == end)
            {
                delete p;
                end = q;
            }
            else
            {
                q->next = p->next;
                delete p;
            }
        } 
    }
    
    int Set::size()
    {
        Element* q = begin;
        int i = 0;
        for (; q != nullptr; q = q->next, i++);
        return i;
    }
    
    void Set::shuffle(char *array, size_t n)
{ 
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          char t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}
    
    bool Set::contains(char c)
    {
        Element* q = begin;
        for ( ; q != nullptr; q = q->next)
            if (q->data == c)
                return true;
        return false;
    }
    
    Element* Set::operator [](int index)
    {
        Element* q = begin;
        for (int i = 0; i < index; ++i, q = q->next);
        return q;
    }
    
    Set& Set::operator=(Set& rhs)
    {
        int lhs_size = this->size(); 
        int rhs_size = rhs.size(); 
        for(int i = 0; i < lhs_size; ++i)
        {
            erase(0); 
        }
        for (int i = 0; i < rhs_size; ++i)
        {
            push_back( (rhs[i])->data ); 
        }
        return *this;
    }
    
    Set& Set::operator ~()
    {
        Set S("");
        for (int i = 0; i < MAX_SIZE + 1; ++i) // +1 ?
        {
            if (!this->contains(Vocabulary[i]))
            {
                S.push_back(Vocabulary[i]);
            }
        }
       (*this) = S; // o_o
       return *this ;
    }
    
    Set& Set::operator &(Set& rhs)
    {
        Set* S = new Set("");
        Element* q = begin;
        while (q != nullptr)
        {
            if (rhs.contains(q->data))
                S->push_back(q->data);
            q = q->next;
        }
        return *S;
    }
    
    std::ostream& operator<<(std::ostream& out, Set& s)
    {
        Element* q = s.begin;
        out << "{";
        if (q==nullptr) 
            out << "empty";
        while (q != nullptr)
        {
            out << *q;
            q = q->next;
        }
        out << "}";
        return out;
    }
    
}// namespace set_list
