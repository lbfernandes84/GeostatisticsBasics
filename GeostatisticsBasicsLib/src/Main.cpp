#include <iostream>
#include <Eigen/Dense> // Inclui a maioria das funcionalidades de Matrizes/Vetores


int main() {
    Eigen::MatrixXd M(2, 2); // Matriz de double 2x2
    M(0, 0) = 3;
    M(1, 0) = 2.5;
    M(0, 1) = -1;
    M(1, 1) = M(0, 1) + M(1, 0);

    std::cout << "Matriz M:\n" << M << std::endl;

    return 0;
}