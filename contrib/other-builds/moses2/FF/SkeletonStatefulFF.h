/*
 * SkeletonStatefulFF.h
 *
 *  Created on: 27 Oct 2015
 *      Author: hieu
 */

#ifndef SKELETONSTATEFULFF_H_
#define SKELETONSTATEFULFF_H_

#include "StatefulFeatureFunction.h"

namespace Moses2
{

class SkeletonStatefulFF : public StatefulFeatureFunction
{
public:
	SkeletonStatefulFF(size_t startInd, const std::string &line);
	virtual ~SkeletonStatefulFF();

  virtual FFState* BlankState(MemPool &pool) const;
  virtual void EmptyHypothesisState(FFState &state,
		  const Manager &mgr,
		  const InputType &input,
		  const Hypothesis &hypo) const;

  virtual void
  EvaluateInIsolation(MemPool &pool,
		  const System &system,
		  const Phrase &source,
		  const TargetPhrase &targetPhrase,
		  Scores &scores,
		  SCORE *estimatedScore) const;

  virtual void EvaluateWhenApplied(const Manager &mgr,
    const Hypothesis &hypo,
    const FFState &prevState,
    Scores &scores,
	FFState &state) const;

};

}

#endif /* SKELETONSTATEFULFF_H_ */
