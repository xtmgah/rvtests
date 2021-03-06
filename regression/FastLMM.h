#ifndef _FASTLMM_H_
#define _FASTLMM_H_

class EigenMatrix;
class Matrix;

class FastLMM{
public:
  enum Test {
    SCORE = 0,
    LRT
  };
  enum Model {
    MLE = 0,
    REML
  };
public: // Make this Impl public to make optimization function easy to write
  class Impl;
  Impl* impl;
public:
  FastLMM(Test test, Model model);
  ~FastLMM();

  // @return 0 when success
  int FitNullModel(Matrix& Xnull, Matrix& y,
                   const EigenMatrix& kinshipU, const EigenMatrix& kinshipS);
  int TestCovariate(Matrix& Xnull, Matrix& y, Matrix& Xcol,
                    const EigenMatrix& kinshipU, const EigenMatrix& kinshipS);
  // NOTE: need to fit null model fit before calling this function  
  double GetAF(const EigenMatrix& kinshipU, const EigenMatrix& kinshipS);
  double GetPValue();
  // for LRT Test
  double GetNullLogLikelihood();
  double GetAltLogLikelihood();
  // for Score Test
  double GetUStat();
  double GetVStat();
};


#endif /* _FASTLMM_H_ */
