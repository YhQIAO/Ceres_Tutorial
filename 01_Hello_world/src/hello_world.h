#include <iostream>
#include <ceres/ceres.h>
#include <glog/logging.h>


struct CostFunctor {
    template <typename T>
    bool operator()(const T* const x, T* residual) const {
        // min = f(x) = (10-x)
        residual[0] = 10.0-x[0];
        return true;
    }
};

class HelloWorld {
public:
    void runDemo();
};