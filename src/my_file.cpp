#include <iostream>
#include <Eigen/Core>

void print_arg(int arg) {
    std::cout << "Integer arg: " << arg << std::endl;
}

void print_arg(double arg) {
    std::cout << "Double arg: " << arg << std::endl;
}

void print_arg(const std::vector<int> & v) {
    std::cout << "Integer vector of length " << v.size() << " : ";
    for(const auto & it : v)
        std::cout << it << " ";
    std::cout << std::endl;
}

long factorial(long n) {
    if(n < 0)
        throw std::runtime_error("factorial(n) with n < 0 is undefined!");

    long fac = 1;
    for(long i = n; i > 0; i--)
        fac *= i;

    return fac;
}

long binomial_coefficient(long n, long k) {
    if(n < k)
        throw std::runtime_error("n must be >= k for binomial coefficient");
    if(n < 0) 
        throw std::runtime_error("n must be >= 0 for binomial coefficient");
    if(k < 0) 
        throw std::runtime_error("k must be >= 0 for binomial coefficient");

    return factorial(n) / (factorial(k) * factorial(n-k));
}

long double_factorial(long n) {
    if(n < -1)
        throw std::runtime_error("n must be >= -1 for double factorial");

    long fac = 1;
    for(long i = n; i > 0; i -= 2)
        fac *= i;
    return fac;
}

double dot_product(const std::vector<double> & v1,
                   const std::vector<double> & v2) {
    double dot = 0.0;

    if(v1.size() != v2.size())
        throw std::runtime_error("Cannot perform dot product of vectors with different sizes");

    for(size_t i = 0; i < v1.size(); i++)
        dot += v1[i] * v2[i];

    return dot;
}

void matmul(Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> m1, Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> m2) {
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> result(m1.rows(), m2.cols());

    return result;
}
