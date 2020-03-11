#pragma once
#include "Wrapper.h"
#include "Sequence\Sequence1.hpp"

#ifdef NDEBUG
// if NDEBUG is defined, then we are in Release Configuration
typedef Sequence1<Integer> IntegerSequence;
#else
//
// else NDEBUG is not defined, then we are in Debug Configuration
//


#include "Sequence\SequenceChecking.hpp"

typedef SequenceChecking1<Sequence1, Integer> IntegerSequence;


#endif // NDEBUG


