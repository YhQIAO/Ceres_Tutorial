#include <ceres/ceres.h>
#include <glog/logging.h>


// struct NumericDiffCostFunctor {
//   bool operator()(const double* const x, double* residual) const {
//     residual[0] = 10.0 - x[0];
//     return true;
//   }
// };

class QuadraticCostFunction : public ceres::SizedCostFunction<1,1> {
public:
    virtual bool Evaluate(double const* const* parameters,
                        double* residuals,
                        double** jacobians) const {
    const double x = parameters[0][0];
    residuals[0] = 10 - x;

    // Compute the Jacobian if asked for.
    if (jacobians != nullptr && jacobians[0] != nullptr) {
      jacobians[0][0] = -1;
    }
    return true;
  }
};


int main(int argc, char** argv) {
    google::InitGoogleLogging(argv[0]);
    // The variable to solve for with its initial value. It will be
    // mutated in place by the solver.
    double x = 0.5;
    const double initial_x = x;
    // Build the problem.
    ceres::Problem problem;
    // Set up the only cost function (also known as residual). This uses
    // auto-differentiation to obtain the derivative (jacobian).

    ceres::CostFunction* cost_function = 
        new QuadraticCostFunction;
    problem.AddResidualBlock(cost_function, nullptr, &x);
    // Run the solver!


    ceres::Solver::Options options;
    options.minimizer_progress_to_stdout = true;
    ceres::Solver::Summary summary;
    Solve(options, &problem, &summary);
    std::cout << summary.BriefReport() << "\n";
    std::cout << "x : " << initial_x << " -> " << x << "\n";
    return 0;
}