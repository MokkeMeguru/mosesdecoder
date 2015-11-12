/*
 * SearchNormal.h
 *
 *  Created on: 25 Oct 2015
 *      Author: hieu
 */

#ifndef SEARCHNORMAL_H_
#define SEARCHNORMAL_H_
#include <vector>
#include "../legacy/Range.h"
#include "../legacy/Bitmap.h"
#include "ArcLists.h"
#include "../TypeDef.h"

class Manager;
class Stack;
class Hypothesis;
class InputPath;
class TargetPhrases;
class TargetPhrase;
class Stacks;

class SearchNormal {
public:
	SearchNormal(Manager &mgr, Stacks &stacks);
	virtual ~SearchNormal();

	void Decode(size_t stackInd);

	const Hypothesis *GetBestHypothesis() const;

protected:
	Manager &m_mgr;
	Stacks &m_stacks;
	//ArcLists m_arcLists;


	void Extend(const Hypothesis &hypo);
	void Extend(const Hypothesis &hypo, const InputPath &path);
	void Extend(const Hypothesis &hypo,
			const TargetPhrases &tps,
			const Range &pathRange,
			const Bitmap &newBitmap,
			SCORE estimatedScore);
	void Extend(const Hypothesis &hypo,
			const TargetPhrase &tp,
			const Range &pathRange,
			const Bitmap &newBitmap,
			SCORE estimatedScore);

	int ComputeDistortionDistance(const Range& prev, const Range& current) const;

};

#endif /* SEARCHNORMAL_H_ */