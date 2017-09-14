#ifndef MPC_H
#define MPC_H

#include <vector>
#include "Eigen-3.3/Eigen/Core"

using namespace std;

typedef struct{
  vector<double> x_sol;
  vector<double> y_sol;
  vector<double> delta_sol;
  vector<double> a_sol;
}Solution;

class MPC {
 public:
   vector<double> result_x;
   vector<double> result_y;
   MPC();

   virtual ~MPC();

   // Solve the model given an initial state and polynomial coefficients.
   // Return the first actuatotions.
   //vector<double> Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs);
   Solution Solve(Eigen::VectorXd state, Eigen::VectorXd coeffs);
   double prev_delta = 0;
   double prev_a = 0.1;
};

#endif /* MPC_H */
