/* 
 * File:   main.cpp
 * Author: alex
 *
 * Created on 22 октября 2014 г., 0:57
 */

#include "set_array_char.h"
#include "set_list.h"
#include "set_array_bool.h"
#include "set_uint.h"

#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv) 
{
    srand(time(NULL));
    steady_clock::time_point t1, t2; 
    duration<double> time_span;
    
    cout<<"======================== char array\n";
    {
        t1 = steady_clock::now();
        
        using namespace set_array_char;
        //Set A("123ABCDEF"), B("BCED45678"), C("ABC23456"), D("9876532"), E("ABCDEF");
        Set A, B, C, D, E;
        cout << "A = " << A << "\nB = " << B << "\nC = " << C << "\nD = " << D << "\n";
        E = A & (~B) & (~(C & D));
        cout << "E = " << E << '\n';
        
        t2 = steady_clock::now();
        time_span = duration_cast<duration<double>>(t2 - t1);
        cout  << "time used: " << time_span.count() << " seconds." << endl;
    } 

    cout<<"======================== list\n";
    
    {
        t1 = steady_clock::now();
        
        using namespace set_list;
        //Set A("123ABCDEF"), B("BCED45678"), C("ABC23456"), D("9876532"), E("ABCDEF");
        Set A, B, C, D, E;
        cerr << "A = " << A << "\nB = " << B << "\nC = " << C << "\nD = " << D << "\n";
        E = A & (~B) & (~(C & D));
        cout << "E = " << E << '\n';
        
        t2 = steady_clock::now();
        time_span = duration_cast<duration<double>>(t2 - t1);
        cout  << "time used: " << time_span.count() << " seconds." << endl;
    }
     
  
    cout<<"======================== bool array\n";
    {
        t1 = steady_clock::now();
        
        using namespace set_array_bool;
        //Set A("123ABCDEF"), B("BCED45678"), C("ABC23456"), D("9876532"), E("ABCDEF");
        Set A, B, C, D, E;
        cout << "A = " << A << "\nB = " << B << "\nC = " << C << "\nD = " << D << "\n";
        E = A & (~B) & (~(C & D));
        cout << "E = " << E << '\n';
        
        t2 = steady_clock::now();
        time_span = duration_cast<duration<double>>(t2 - t1);
        cout  << "time used: " << time_span.count() << " seconds." << endl;
    } 
    
    cout<<"======================== uint\n";
    {
        t1 = steady_clock::now();
        
        using namespace set_uint;
        //Set A("123ABCDEF"), B("BCED45678"), C("ABC23456"), D("9876532"), E("ABCDEF");
        Set A, B, C, D, E;
        cout << "A = " << A << "\nB = " << B << "\nC = " << C << "\nD = " << D << "\n";
        E = A & (~B) & (~(C & D));
        cout << "E = " << E << '\n';
        
        t2 = steady_clock::now();
        time_span = duration_cast<duration<double>>(t2 - t1);
        cout  << "time used: " << time_span.count() << " seconds." << endl;
    } 
    
    return 0;
}

