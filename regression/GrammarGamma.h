#ifndef _GRAMMARGAMMA_H_
#define _GRAMMARGAMMA_H_

class EigenMatrix;
class Matrix;

class GrammarGamma{
public: // Make this Impl public to make optimization function easy to write
  class Impl;
  Impl* impl;
public:
  GrammarGamma();
  ~GrammarGamma();

  // @return 0 when success
  int FitNullModel(Matrix& Xnull, Matrix& y,
                   const EigenMatrix& kinshipU, const EigenMatrix& kinshipS);
  int TestCovariate(Matrix& Xnull, Matrix& y, Matrix& Xcol,
                    const EigenMatrix& kinshipU, const EigenMatrix& kinshipS);
  double GetAF(const EigenMatrix& kinshipU, const EigenMatrix& kinshipS);
  double GetPValue();
  double GetBeta();
  double GetBetaVar();
};

#endif /* _GRAMMARGAMMA_H_ */

