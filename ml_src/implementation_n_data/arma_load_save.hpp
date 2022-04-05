#ifndef ARMA_LOAD_SAVE
#define ARMA_LOAD_SAVE
#include "armadillo.hpp"
#include <iostream>
#include <string>
#include <fstream>
/*
  // overloading of loading and save functions
  // for all arma types i want to use
*/
void JobsDone(bool IsJobDone, std::string Operation, std::string OperationOn)
{
  if (IsJobDone == true)
  {
    std::cout << "[OK]- " << Operation << OperationOn << '\n';
  }
  else
  {
    std::cout << "[FAIL]- " << Operation << OperationOn << '\n';
  }
}

arma::mat arma_load_mat(std::string mx_file)
{
  arma::mat MX;
  bool load_MX = MX.load(mx_file, arma::raw_ascii);

  if (load_MX == true)
  {
    JobsDone(load_MX, "Load of: ", mx_file);
    return MX;
  }
  else
  {
    JobsDone(load_MX, "Load of: ", mx_file);
  }
}
arma::colvec arma_load_cvec(std::string mx_file)
{
  arma::colvec MX;
  bool load_MX = MX.load(mx_file, arma::raw_ascii);
  if (load_MX == true)
  {
    JobsDone(load_MX, "Load of: ", mx_file);
    return MX;
  }
  else
  {
    JobsDone(load_MX, "Load of: ", mx_file);
  }
}
arma::vec arma_load_vec(std::string mx_file)
{
  arma::vec MX;
  bool load_MX = MX.load(mx_file, arma::raw_ascii);
  if (load_MX == true)
  {
    JobsDone(load_MX, "Load of: ", mx_file);
    return MX;
  }
  else
  {
    JobsDone(load_MX, "Load of: ", mx_file);
  }
}
arma::rowvec arma_load_rvec(std::string mx_file)
{
  arma::colvec MX;
  bool load_MX = MX.load(mx_file, arma::raw_ascii);

  if (load_MX == true)
  {
    JobsDone(load_MX, "Load of: ", mx_file);
    return MX;
  }
  else
  {
    JobsDone(load_MX, "Load of: ", mx_file);
  }
}
void save_labels(std::vector<int> labels, std::string save_file)
{
  std::ofstream file_write_to(save_file, std::ios::out);
  if (file_write_to.is_open())
  {
    for (std::vector<int>::const_iterator i = labels.begin(); i != labels.end(); ++i)
    {
      if ( i != labels.begin())
      {
        file_write_to << '\n';
      }
      file_write_to << *i;
    }
    file_write_to << std::endl;
    file_write_to.close();
  }
}
void save_arma_mat(arma::mat tnesor, std::string save_file)
{
  tnesor.save(save_file, arma::raw_ascii);
}
void save_arma_cvec(arma::colvec tnesor, std::string save_file)
{
  tnesor.save(save_file, arma::raw_ascii);
}
void save_arma_ivec(arma::icolvec tnesor, std::string save_file)
{
  tnesor.save(save_file, arma::raw_ascii);
}
void save_arma_vec(arma::vec tnesor, std::string save_file)
{
  save_arma_cvec(tnesor, save_file);
}
void save_arma_rvec(arma::rowvec tnesor, std::string save_file)
{
  tnesor.save(save_file, arma::raw_ascii);
}
#endif
