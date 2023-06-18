//
// Created by ale on 18/06/23.
//

#ifndef UNTITLED2_MATRIXTEMPLATE_H
#define UNTITLED2_MATRIXTEMPLATE_H

#include <iostream>

template<typename T>
class MatrixTemplate {
private:
    T** matrix;
    T initVal;
    int rows;
    int cols;
public:
    MatrixTemplate(T initVal, int rows = 5, int cols = 5): rows(rows), cols(cols), initVal(initVal){
        allocMatrix(rows, cols);
        initMatrix();
    }

    void initMatrix() {
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; j++){
                matrix[i][j] = initVal;
            }
        }
    }

    void allocMatrix(int rows, int cols) {
        matrix = new T* [rows];
        for(int i = 0; i < rows; ++i){
            matrix[i] = new T[cols];
        }
    }

    ~MatrixTemplate(){
        deleteMatrix();
    }

    void deleteMatrix() const {
        for(int i = 0; i < rows; ++i){
            delete [] matrix[i];
        }
        delete [] matrix;
    };
    bool setValue(int r, int c, const T& val){
        if (r < rows && c < cols && r >= 0 && c >= 0){
            matrix[r][c] = val;
            return true;
        }
        return false;
    }
    T readValue(int r, int c) const {
        if (r < rows && c < cols && r >= 0 && c >= 0){
            return matrix[r][c];
        }
        return -1;
    }
    void printMatrix() const {
        std::cout << std::endl;
        for(int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                std::cout << matrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
    MatrixTemplate(const MatrixTemplate<T>& orig) {
        if (&orig != this) {
            rows = orig.rows;
            cols = orig.cols;
            initVal = orig.initVal;
            if (this->matrix)
                deleteMatrix();
            allocMatrix(rows, cols);
            initMatrix();
        }
    }

     MatrixTemplate<T>& operator=(const MatrixTemplate<T>& right) {
        if(this != & right){
            rows = right.rows;
            cols = right.cols;
            initVal = right.initVal;
            if (this->matrix)
                deleteMatrix();
            allocMatrix(rows, cols);
            initMatrix();
        }
        return *this;
    }
};
#endif //UNTITLED2_MATRIXTEMPLATE_H
