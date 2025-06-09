#include <cstdlib>
#include <iostream>

class Matrix {
public:  
	//CONSTRUCTORS & DESTRUCTOR 
	Matrix (); 
	Matrix (unsigned aRow, unsigned aColumn, double aFill);
	Matrix(const Matrix& m) { copy(m); }
	~Matrix(); 

	//ACCESSORS 
	unsigned num_rows() const { return rows_; }
 	unsigned num_cols() const { return cols_; }

	bool get(const unsigned& gRow, const unsigned& gColumn, double& rNum) const ; 
	double* get_row(unsigned aInt); 
	double* get_col(unsigned aInt); 

	//MODIFIERS  
	void clear(); 
	bool set( unsigned gRow,  unsigned gColumn,  double gNum); 
	bool add(const Matrix& m);

	//OTHER FUNCTIONS
	void print();
    Matrix(Matrix&& m);
    Matrix& operator=(Matrix&& m);
	Matrix& operator=(const Matrix& m); 
	friend std::ostream& operator<<(std::ostream& out, const Matrix& m); 
	friend bool operator==(const Matrix& m1, const Matrix& m2); 
	friend bool operator!=(const Matrix& m1, const Matrix& m2); 

private: 
	//PRIVATE MEMBER FUNCTIONS
	void copy(const Matrix& m);

	//REPRESENTATION
	unsigned rows_;
	unsigned cols_; 
	double fill_; 
	double ** data_; 

}; 