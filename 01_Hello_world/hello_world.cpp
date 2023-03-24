#include "hello_world.h"


void HelloWorld::runDemo() {

    double x = 0.5;
    const double initial_x = x;

    ceres::Problem problem;

    ceres::CostFunction* cost_function = 
        new ::ceres::AutoDiffCostFunction<CostFunctor,1,1>(new CostFunctor);
    
    problem.AddResidualBlock(cost_function, nullptr, &x);
    
    // run solver
    ceres::Solver::Options options;
    options.minimizer_progress_to_stdout = true;
    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);
    std::cout << summary.BriefReport() << std::endl;
    std::cout << "x: "<<initial_x << "--> " << x << std::endl;

}
