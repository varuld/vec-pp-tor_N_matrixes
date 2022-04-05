#include "ml_parameters.hpp"
#include "arma_load_save.hpp"
#include "armadillo.hpp"
#include <utility>      // std::pair, std::make_pair
#include <algorithm>    // std::sort
//#include <cmath> // could be a arma cmath for sqrt and power-of function
#include <vector>

void DBugPrint(std::string breakpoint)
{
  std::cout << breakpoint << '\n';
}

void ComputeDistanceBetweenXiAndX(arma::rowvec x_i, arma::rowvec x, arma::colvec dis)
{
  arma::colvec DiffX;
  DiffX = x_i - x;
  dis = arma::sqrt(DiffX);
  DiffX.clear();
  // dis = arma::sqrt((x_i - x))
}
double Distance(arma::rowvec x, arma::rowvec x_i)
{
  //DBugPrint("Distance, start");
  arma::rowvec dx; dx = x - x_i;
  arma::rowvec dx_sq; dx_sq = arma::square(dx);
  double d = arma::sum(dx_sq);

  return d;
  //return arma::accu(arma::square((x - x_i)));
}

int LabelVector(arma::rowvec point, arma::mat field, arma::colvec field_labels_Y)
{
  int FieldSize = (field.n_rows); // -1 to account for 0-inexing
  //DBugPrint("LabelVector, start");
  //std::cout << FieldSize << '\n';
  std::vector<double> hold_the_fucking_D;
  arma::rowvec field_row;
  //DBugPrint("LabelVector, fielding");
  arma::mat::row_iterator it_field = field.begin_row(0);
  arma::mat::row_iterator it_field_slut = field.end_row(FieldSize-1);
  //DBugPrint("LabelVector, iterators");
  int itsz = 0;
  //for (; it_field != it_field_slut; it_field++)
  for (int i = 0; i < FieldSize; ++i)
  {
    //DBugPrint("LabelVector, for loop start");
    field_row = field.row(i);
    //DBugPrint("LabelVector, def vec-row");
    double d = Distance(point, field_row);
    //DBugPrint("LabelVector, distance find");
    hold_the_fucking_D.push_back(d);
    //DBugPrint("LabelVector, for loop end");
    //std::cout << "LabelVector, for loop it; " << itsz << '\n';
    //itsz += 1;
  }
  //DBugPrint("LabelVector, after for loop");
  int no_labels = hold_the_fucking_D.size();

  std::vector<std::pair<double, double>> P;
  //typedef std::vector<std::pair<double, double> > LabelPairs;

  for (int i = 0; i < no_labels; ++i)
  {
    double y = field_labels_Y(i);
    double d = hold_the_fucking_D.at(i);
    //P_I = std::make_pair(y, d);
    //std::pair<double, double> P_I;
    //P_I.first = field_labels_Y(i); P_I.second = hold_the_fucking_D.at(i);
    P.push_back(std::make_pair(y, d));
  }
  std::sort(P.begin(), P.end(), knn_prm::sortbysec);

  int freq1 = 0;     // Frequency of group -1
  int freq2 = 0;     // Frequency of group 1
  for (unsigned int i = 0; i < knn_prm::k ; ++i)
  {
    if (P[i].first == -1)
      freq1 += 1;
    else if (P[i].first == 1)
      freq2 += 1;
  }
  return (freq1 > freq2 ? -1 : 1);
}
arma::colvec NearestNeighbourLoop(arma::mat Points, arma::mat CompareField, arma::colvec YValues)
{
  std::vector<int> LablesForXtest;
  //Points.each_row( [](arma::rowvec& point){ int lb =  LabelVector(point, CompareField, YValues); LablesForXtest.push_back(lb);} );

  int NumberOfPoints = (Points.n_rows); // -1 to account for 0-inexing
  //DBugPrint("Labelling start");
  arma::rowvec Points_row;
  //DBugPrint("points vector");
  arma::mat::row_iterator it_Points = Points.begin_row(0);
  //DBugPrint("[0]points it's");
  arma::mat::row_iterator it_Points_slut = Points.begin_row(NumberOfPoints-1);
  //DBugPrint("[1]points it's");

  //std::vector<int> LablesForXtest;
  //DBugPrint("Labelling start, foer");

  for (int i = 0; i < NumberOfPoints; ++i)
  {
    //DBugPrint("Labelling start, start of");
    Points_row = Points.row(i);
    //DBugPrint("Labelling start, midte");
    int lb = LabelVector(Points_row, CompareField, YValues);
    //std::cout << lb << '\n';
    //DBugPrint("Labelling making label");
    LablesForXtest.push_back(lb);
  }
  //DBugPrint("Labelling for loop slut");
  //arma::rowvec PointLabelsMx(LablesForXtest);
  arma::colvec PointLabels = arma::conv_to<arma::colvec>::from(LablesForXtest);
  //DBugPrint("write labels");

  return PointLabels;
}

int main()
{
  arma::mat X; X = arma_load_mat("dataX.dat");
  arma::colvec Y; Y = arma_load_mat("dataY.dat");

  arma::mat X_test; X_test = arma_load_mat("dataXtest.dat");

  DBugPrint("Loading of data; done");
  //X_test.each_row( [](arma::rowvec& a){ std::cout << size(a) << '\n'; } );

  /*
  arma::mat::const_row_iterator it = X_test.begin_row(17);
  arma::rowvec test; test = X_test.row(*it);
  int rlen = test.n_cols;
  std::cout << rlen << '\n';
  */

  //FindAllDimsOfMatrix(X_test);

  arma::colvec LabelsOfXtest = NearestNeighbourLoop(X_test, X, Y);
  arma::icolvec xLabelsInts = arma::conv_to<arma::icolvec>::from(LabelsOfXtest);
  typedef std::vector<int> stdvec;
  stdvec ud_knn = arma::conv_to< stdvec >::from(xLabelsInts);
  DBugPrint("KNN done");
  save_labels(ud_knn, "NN.dat");
  //save_arma_cvec(LabelsOfXtest, "NN.dat");
  DBugPrint("Written labels");


  return 0;
}
