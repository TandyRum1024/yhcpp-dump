/*
    열혈CPP 문제 #01-2
    @ MjölkforDunk

    오버로딩 무언가
*/

#include <iostream>
using namespace std;

/*
    V Overload this
*/
void swap (int *a, int *b)
{
    /*
        int* ptr; // int's address
        ptr = &j; // point to int variable j
        *ptr = x; // Set the value of ptr's pointing variable (= j) to x
        
        ===========================================

        It's same as [j = x]... but much more fancier.
    */
    int tmp;
    tmp = *a;  // int -> value of int ptr
    *a   = *b; // pointer value -> pointer value (AKA set var 1's value to var 2's value.)
    *b   = tmp;
}

/// CHAR
/// ========================================================
void swap (char *a, char *b)
{
    char tmp;
    tmp = *a;
    *a   = *b;
    *b   = tmp;
}

/// DOUBLE
/// ========================================================
void swap (double *a, double *b)
{
    double tmp;
    tmp = *a;
    *a   = *b;
    *b   = tmp;
}

int main ()
{

    int int1 = 10, int2 = 42;
    cout << int1 << ' ' << int2 << endl;
    
    // OG func - void swap (int*, int*)
    cout << endl << "=============== ORIGINAL - INT ===============" << endl;
    cout << endl << "=============== BEFORE ===============" << endl;
    cout << int1 << ' ' << int2 << endl;
    cout << endl << "=============== AFTER ===============" << endl;
    swap(&int1, &int2);
    cout << int1 << ' ' << int2 << endl;

    // overload #1 - void swap (char*, char*)
    cout << endl << "=============== OVERLOAD #1 - CHAR VERSION ===============" << endl;
    char char1 = 'A', char2 = 'Z';
    cout << endl << "=============== BEFORE ===============" << endl;
    cout << char1 << ' ' << char2 << endl;
    cout << endl << "=============== AFTER ===============" << endl;
    swap(&char1, &char2);
    cout << char1 << ' ' << char2 << endl;

    // overload #2 - void swap (double*, double*)
    cout << endl << "=============== OVERLAOD #2 - DOUBLE VERSION ===============" << endl;
    double double1 = 42.0, double2 = 69.74;
    cout << endl << "=============== BEFORE ===============" << endl;
    cout << double1 << ' ' << double2 << endl;
    cout << endl << "=============== AFTER ===============" << endl;
    swap(&double1, &double2);
    cout << double1 << ' ' << double2 << endl;

    /* 
        ptr1 = &a;
        *ptr2 = *ptr1; <- ERROR : The ptr2 doesn't even points to a thing!
        So changing the value of ptr2's pointing var, You'il changing NOTHING!!
        And you'il get nasty error too.
    */
    return 0;
}