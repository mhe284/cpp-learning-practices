#include <iostream>
#include <string> 
#include <iomanip>
#include "Matrix.h" 

//CONSTRUCTORS 

Matrix::Matrix() {
	rows_ = 0; 
	cols_ = 0;
	fill_ = 0; 
	data_ = NULL; 
}

Matrix::Matrix (unsigned aRow, unsigned aColumn, double aFill) {
	rows_  = aRow;
	cols_ = aColumn;
	fill_ = aFill; 

	//Creating the Matrix
	double ** data; 

	//Creating the Rows 
	data = new double* [rows_]; 

	//Creating the Rows 
	for (unsigned i=0; i < rows_; i++) {
		data[i] = new double [cols_];

		//Intializing Fill into Elements in Row 
		for (unsigned a=0; a < cols_; a++) {
			data[i][a] = fill_; 
		}
	}

	//Assigning 
	data_ = data; 
}

//DESTRUCTOR 
Matrix::~Matrix() {
	//If data is NULL 
	if (data_ == NULL) { 
		return; 
	}

	//Deletes array of pointers (Rows)  
	for (unsigned i=0; i < rows_; i++) {
		delete [] data_[i]; 
	}

	//Deletes pointer to array of pointers (Columns) 
	delete [] data_; 
}

//ACCESSORS----------
bool Matrix::get (const unsigned& gRow, const unsigned& gColumn, double& rNum) const {
	//Checking Bounds and Getting 
	if ((gRow < rows_) && (gColumn < cols_)) {
		rNum = data_[gRow][gColumn]; 
		return true; 
	}
	return false; 
}

double* Matrix::get_row(unsigned aInt) {
	double* row; 
	row = new double [cols_];
	for (unsigned i=0; i < cols_; i++) {
		row[i] = data_[aInt][i];
	}
	return row; 
}

double* Matrix::get_col(unsigned aInt) {
	double* col; 
	col = new double [rows_];
	for (unsigned i=0; i < rows_; i++) {
		col[i] = data_[i][aInt];
	}
	return col; 
}

//MODIFIERS----------

void Matrix::clear() {
	//Deallocating any memory currently held by Matrix

	if (data_ == NULL) {
		return; 
	}
	for (unsigned i=0; i < rows_; i++) {
		delete [] data_[i]; 
	}
	delete [] data_;  

	//Resetting Rows and Columns 
	rows_ = 0; 
	cols_ = 0; 
	data_ = NULL; 
}

bool Matrix::set( unsigned gRow,  unsigned gColumn,  double gNum) {
	//Checking Bounds and Setting 
	if ((gRow < rows_) && (gColumn < cols_)) {
		data_[gRow][gColumn] = gNum;
		return true; 
	}

	return false; 
}

bool Matrix::add(const Matrix& m) {
	if ((rows_ != m.num_rows()) &&
		(cols_ != m.num_cols()) ) {
		return false; 
	}

	for (unsigned i=0; i < rows_; i++) {
		for (unsigned a=0; a < cols_; a++) {
			double value; 
			m.get(i, a, value); 
			data_[i][a] += value; 
		}
	}
	return true; 

}


//PRIVATE MEMBER FUNCTIONS 
void Matrix::copy(const Matrix& m) {
	//Copying Rows and Columns 
	rows_ = m.num_rows(); 
	cols_ = m.num_cols(); 

	//Creating the new data_ 
	data_ = new double* [rows_]; 

	for (unsigned i=0; i < rows_; i++) {
		data_[i] = new double [cols_];
		for (unsigned a=0; a < cols_; a++) { 
			double value; 
			m.get(i, a, value); 
			data_[i][a] = value; 
		}
	}
} 


//OTHER FUNCTIONS
Matrix::Matrix(Matrix&& m) {
    rows_ = m.rows_;
    cols_ = m.cols_;
    fill_ = m.fill_;
    data_ = m.data_;
    
    m.rows_ = 0;
    m.cols_ = 0;
    m.fill_ = 0;
    m.data_ = nullptr;
}

Matrix& Matrix::operator=(Matrix&& m) {
    if (this != &m) {
        clear();

        rows_ = m.rows_;
        cols_ = m.cols_;
        fill_ = m.fill_;
        data_ = m.data_;

        m.rows_ = 0;
        m.cols_ = 0;
        m.fill_ = 0;
        m.data_ = nullptr;
    }

    return *this;
}



Matrix& Matrix::operator=(const Matrix& m) {
	if (this != &m) {
		this -> clear(); 
		this -> copy(m); 
	}
	return *this; 
}


void Matrix::print() {
    std::cout << "Matrix:" << std::endl;
    if (rows_ == 0 || cols_ == 0) {
        std::cout << "[ ]" << std::endl;
        return;
    }
    std::cout << "[";
    for (unsigned i = 0; i < rows_; i++) {
        if (i > 0) std::cout << " ";
        for (unsigned a = 0; a < cols_; a++) {
            std::cout << std::setw(8) << data_[i][a];
            if (a < cols_ - 1) std::cout << " ";
        }
        if (i < rows_ - 1) std::cout << std::endl;
    }
    std::cout << " ]" << std::endl;
}




//OUTSIDE OF CLASS FUNCTIONS 
std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    if (m.num_rows() == 0 || m.num_cols() == 0) {
        out << "[ ]" << std::endl;
        return out;
    }
    out << "[";
    for (unsigned i = 0; i < m.num_rows(); i++) {
        if (i > 0) out << " ";
        for (unsigned a = 0; a < m.num_cols(); a++) {
            double value;
            m.get(i, a, value);
            out << std::setw(8) << value;
            if (a < m.num_cols() - 1) out << " ";
        }
        if (i < m.num_rows() - 1) out << std::endl;
    }
    out << " ]" << std::endl;
    return out;
}

bool operator==(const Matrix& m1, const Matrix& m2) {

	if ((m1.num_rows() == m2.num_rows()) && 
		(m1.num_cols() == m2.num_cols())) {
		for (unsigned i=0; i < m1.num_rows(); i++) {
			for (unsigned a=0; a < m2.num_cols(); a++) {
				double m1_value = m1.get(i,a,m1_value); 
				double m2_value = m2.get(i,a,m2_value); 
				//std::cout << m1_value << std::endl;
				//std::cout << m2_value<< std::endl;
				if (m1_value != m2_value) {
					return false; 
				}
			}
		} 
		return true; 
	}
	return false; 
}

bool operator!=(const Matrix& m1, const Matrix& m2){
	if ((m1.num_rows() == m2.num_rows()) && 
		(m1.num_cols() == m2.num_cols())) {
		for (unsigned i=0; i < m1.num_rows(); i++) {
			for (unsigned a=0; a < m2.num_cols(); a++) {
				double m1_value = m1.get(i,a,m1_value); 
				double m2_value = m2.get(i,a,m2_value); 
				if (m1_value != m2_value) {
					return true; 
				}
			}
		} 
		return false; 
	}
	return true; 
}