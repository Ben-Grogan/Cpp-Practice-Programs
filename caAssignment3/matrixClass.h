#include <iostream>
#include <string>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H

class matrix{

    private:
        unsigned int numRows;
        unsigned int numCols;
        int** data;

    public:
        matrix( unsigned int m , unsigned int n );
        matrix(const matrix &mat);
        matrix ( int** array , unsigned int m , unsigned int n );

        ~matrix();

        unsigned int rows() const;
        unsigned int columns() const;

        int get ( unsigned i , unsigned j ) const;
        void set ( unsigned i , unsigned j , int value );

        matrix operator+(const matrix& mat) const;
        matrix operator-( const matrix& mat ) const;
        matrix operator*( const matrix& mat ) const;
        matrix operator~() const;
        bool operator==(const matrix& mat) const;
        string toStr() const;
};

#endif