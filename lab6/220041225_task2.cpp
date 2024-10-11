#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
using namespace std;

class Matrix3D {
private:
    double matrix[3][3];  
    int incrementValue;
    int count;  

public:

    Matrix3D(double mat[3][3], int incVal = 1) : incrementValue(incVal), count(0) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                matrix[i][j] = mat[i][j];
        if (incVal < 0) incrementValue = 1;  
    }

   
    ~Matrix3D() {}

 
    Matrix3D(const Matrix3D& other) : incrementValue(other.incrementValue), count(other.count) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                matrix[i][j] = other.matrix[i][j];
    }

  
    double det() const {
        return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
               matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
               matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    }

   
    Matrix3D inverse() const {
        double determinant = det();
        if (determinant == 0) {
            throw runtime_error("Matrix is not invertible.");
        }
        
        double invDet = 1.0 / determinant;
        double invMatrix[3][3];

      
        invMatrix[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) * invDet;
        invMatrix[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) * invDet;
        invMatrix[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) * invDet;

        invMatrix[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) * invDet;
        invMatrix[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) * invDet;
        invMatrix[1][2] = (matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2]) * invDet;

        invMatrix[2][0] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) * invDet;
        invMatrix[2][1] = (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]) * invDet;
        invMatrix[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) * invDet;

        return Matrix3D(invMatrix);
    }

   
    void setIncrement(int val) {
        if (count == 0 && val > 0) {
            incrementValue = val;
            count++;
        } else if (val < 0) {
            cout << "Negative increment not allowed, keeping previous value.\n";
        } else {
            cout << "Cannot set increment, it has already been set once.\n";
        }
    }


    double (*getMatrix())[3] {
        return matrix;
    }

    
    void increment() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                matrix[i][j] += incrementValue;
            }
        }
    }

    
    friend Matrix3D operator+(const Matrix3D& m1, const Matrix3D& m2) {
        double result[3][3];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
            }
        }
        return Matrix3D(result);
    }

  
    friend Matrix3D operator-(const Matrix3D& m1, const Matrix3D& m2) {
        double result[3][3];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
            }
        }
        return Matrix3D(result);
    }

   
    friend Matrix3D operator*(const Matrix3D& m1, const Matrix3D& m2) {
        double result[3][3] = {0};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    result[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
                }
            }
        }
        return Matrix3D(result);
    }

   
    friend bool operator==(const Matrix3D& m1, const Matrix3D& m2) {
        return m1.det() == m2.det();
    }

    friend bool operator!=(const Matrix3D& m1, const Matrix3D& m2) {
        return !(m1 == m2);
    }

    friend bool operator>(const Matrix3D& m1, const Matrix3D& m2) {
        return m1.det() > m2.det();
    }

    friend bool operator<(const Matrix3D& m1, const Matrix3D& m2) {
        return m1.det() < m2.det();
    }

    friend bool operator>=(const Matrix3D& m1, const Matrix3D& m2) {
        return m1.det() >= m2.det();
    }

    friend bool operator<=(const Matrix3D& m1, const Matrix3D& m2) {
        return m1.det() <= m2.det();
    }
};

int main() {

    double mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double mat2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    Matrix3D m1(mat1);
    Matrix3D m2(mat2);

  
    Matrix3D sum = m1 + m2;
    Matrix3D difference = m1 - m2;
    Matrix3D product = m1 * m2;

 
    cout << "Sum Matrix Det: " << sum.det() << endl;
    cout << "Difference Matrix Det: " << difference.det() << endl;
    cout << "Product Matrix Det: " << product.det() << endl;

  
    m1.setIncrement(2);
    m1.increment();
    cout << "Matrix 1 after increment, Det: " << m1.det() << endl;

  
    if (m1 > m2) cout << "Matrix 1 is greater than Matrix 2" << endl;
    if (m1 != m2) cout << "Matrix 1 is not equal to Matrix 2" << endl;

    return 0;
}
