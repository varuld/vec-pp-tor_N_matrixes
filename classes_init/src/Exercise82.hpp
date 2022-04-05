#ifndef SUBMISSION_EXERCISE82_HPP_
#define SUBMISSION_EXERCISE82_HPP_

template<typename T>
T CalcAbs(T val) {
	if (val > 0)
  {
    return val;
  }
  else
  {
    return - val;
  }
}


#endif /* SUBMISSION_EXERCISE82_HPP_ */
/*
same as above diff = typename vs class
does the same thing

template<class T>
T CalcAbs(T val) {
	if (val > 0)
  {
    return val;
  }
  else
  {
    return - val;
  }
}
*/
