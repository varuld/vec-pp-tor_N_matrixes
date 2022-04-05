#ifndef ML_PARAMETERES
#define ML_PARAMETERES
#include "armadillo.hpp"
#include <vector>
#include <random>
#include <utility>      // std::pair, std::make_pair

namespace knn_prm
{
  bool sortbysec(const std::pair<double,double> &a, const std::pair<double,double> &b)
  {
      return (a.second < b.second);
  }
 int k{5};
} /* knn_prm */

namespace prm
{
  double ErrorTolerance{1.0e-7};
  int whileIts{1000000};
  int print_rate{whileIts/100};
  double LearningRate{0.1};
  arma::rowvec random_weights(int TheSize)
  {
    // return arma::colvec with random doubles between -1 < rd < 0
    // for initial weights of model

    arma::rowvec init_weights(TheSize);
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(-1.0, 0.0);
    for (int i = 0; i < TheSize; ++i)
    {
      init_weights(i) = dis(gen);
    }
    return init_weights;
  }
  //weights{} // 2 * rand(N_entries) - 1 (num entries in dataX as random negative numbers)
} /* parameters */

#endif
