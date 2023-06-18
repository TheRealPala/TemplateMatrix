#include <iostream>
#include "MatrixTemplate.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    MatrixTemplate<int>* m = new MatrixTemplate(2,3, 3);
    m->printMatrix();
    m->setValue(0, 0, 1);
    m->printMatrix();
    MatrixTemplate<int> a = MatrixTemplate(*m);
    delete m;
    a.printMatrix();
    return 0;
}
