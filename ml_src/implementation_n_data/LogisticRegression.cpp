#include "ml_parameters.hpp"
#include "arma_load_save.hpp"
#include "armadillo.hpp"

#include <random>
#include <vector>
#include <iostream>
#include <cmath>

void DBugPrint(std::string breakpoint)
{
  std::cout << breakpoint << '\n';
}
arma::rowvec deltaWeightsLoop(arma::mat X, arma::colvec y, arma::rowvec w)
{
  int N = X.n_rows;
  int cols = X.n_cols;
  double norm_factor = 1.0/(double)N;
  arma::rowvec deltaWeights(cols);

  arma::rowvec x_i;
  arma::rowvec to_sum;
  double scarlar;
  double scar_zero;

  for (int i = 0; i < N ; ++i)
  {
    x_i = X.row(i);
    scar_zero = arma::as_scalar(y[i]) * arma::dot(w.t(), x_i);
    scarlar = arma::as_scalar(y[i]) * (1.0/ (1.0 + std::exp(scar_zero) ) );
    to_sum = arma::as_scalar(scarlar) * x_i;
    deltaWeights = deltaWeights + to_sum;
  }
  deltaWeights = arma::as_scalar(-norm_factor) * deltaWeights;

  return deltaWeights;
}
/*
double NormOfVector(arma::rowvec Weights)
{
  double EpsiDiff = arma::norm(Weights);
  return EpsiDiff;
}
*/
int main()
{
  /*- load data -*/
  arma::mat X; X = arma_load_mat("dataX.dat");
  arma::colvec Y; Y = arma_load_mat("dataY.dat");

  std::cout << size(X) << '\n';

  /*- prepping data for proccesing  -*/
  int Xlines = X.n_rows;
  //int Xentries = X.n_cols;
  //arma::colvec Ones; Ones.ones(Xlines);
  //arma::mat Xp = arma::join_rows(Ones, X);
  //int XpEntries = Xp.n_cols;
  int X_size = X.n_cols;

  arma::rowvec init_w; init_w.zeros( X_size );

  arma::rowvec fin_w; fin_w = init_w;

  //bool FirstLoop = true;
  //arma::rowvec tmp;
  //arma::rowvec diffW; //diffW = fin_w - init_w;
  //double epsilon = 0.0; //= NormOfVector(diffW);
  double gradientdiff = 0.0;
  arma::rowvec gradVec;

  int whileIterations = 0;

  do
  {
    //std::cout << "Running while loop" << '\n';

    //FirstLoop = false;
    //tmp = fin_w;
    gradVec = deltaWeightsLoop(X, Y, fin_w);
    //diffW = tmp - fin_w;
    fin_w = fin_w - gradVec * prm::LearningRate;
    gradientdiff = arma::norm(gradVec);//NormOfVector(diffW);
    whileIterations += 1;

    if (whileIterations > prm::whileIts)
    {
      std::cout << "Exided iteration limit of ;" << whileIterations << '\n';
      break;
    }
    if (whileIterations % prm::print_rate == 0)
    {std::cout << "While Itr no; " << whileIterations << ", at gradientdiff; " << gradientdiff << '\n';}
  } while (gradientdiff > prm::ErrorTolerance);
  //while (FirstLoop!=false && gradientdiff > prm::ErrorTolerance);

  if (gradientdiff < prm::ErrorTolerance)
  {
    arma::mat X_test; X_test = arma_load_mat("dataXtest.dat");
    int XTestLines = X_test.n_rows;

    //arma::colvec TestOne; TestOne.ones(XTestLines);

    //arma::mat TestP = arma::join_rows(TestOne, X_test);


    arma::mat labY = fin_w * X_test.t();
    std::cout << size(labY) << '\n';
    arma::colvec labtrans(labY.t());
    arma::colvec trans_int_lab(labtrans); // arma::conv_to<arma::icolvec>::from(labtrans);//trans_int_lab(labtrans);
    arma::colvec YLabels = arma::sign(trans_int_lab);
    arma::icolvec IntYLabels = arma::conv_to<arma::icolvec>::from(YLabels);
    typedef std::vector<int> stdvec;
    stdvec ud = arma::conv_to< stdvec >::from(IntYLabels);

    //IntYLabels.replace(0,-1);
    save_labels(ud, "LogReg.dat");
    //save_arma_ivec(IntYLabels, "LogReg.dat");
    std::cout << "LogReg.dat = " << size(YLabels)  << '\n';
    std::cout << '\n'<< "Completet the fit!" << '\n';

  }
  else
  {
    std::cout << '\n'<< "fit not done" << '\n';
    std::cout << "gradientdiff =; " <<  gradientdiff << '\n';
  }


  return 0;
}
