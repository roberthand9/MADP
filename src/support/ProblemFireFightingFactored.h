/* REPLACE_MADP_HEADER */
/* REPLACE_CONTRIBUTING_AUTHORS_START
 * Frans Oliehoek 
 * Matthijs Spaan 
 * REPLACE_CONTRIBUTING_AUTHORS_END
 */

/* Only include this header file once. */
#ifndef _PROBLEMFIREFIGHTINGFACTORED_H_
#define _PROBLEMFIREFIGHTINGFACTORED_H_ 1

/* the include directives */
#include <iostream>
#include "Globals.h"
#include "FactoredDecPOMDPDiscrete.h"

class DecPOMDPDiscrete;

/**ProblemFireFightingFactored is a factored implementation of the
 * FireFighting problem introduced in (Oliehoek, Spaan, Vlassis, JAIR
 * 32, 2008). */
class ProblemFireFightingFactored : public FactoredDecPOMDPDiscrete
{
private:    
protected:
    enum observation_t { FLAMES, NOFLAMES };
    size_t _m_nrAgents;
    size_t _m_nrHouses;
    size_t _m_nrFireLevels;
    double _m_costOfMove;
    bool _m_forcePositionRepres;
    // this the probability agents receive for reducing the firelevel
    // to 1 if >1 agents are present, otherwise it reduces just by 1
    // level.
    double _m_multipleAgentExtinguishProb;
    
    bool _m_includePositions;

    size_t _m_nrStateFeatures;
    //vector that stores the number of values per state feature.
    std::vector<size_t> _m_nrPerStateFeatureVec;

    size_t _m_nrJointFirelevels;
    //vector that stores the number of values per state feature.
    std::vector<size_t> _m_nrFLs_vec;
    
    ///Construct all the observations and observation sets.
    virtual void ConstructObservations();

    std::vector< Index> GetStateVector(Index sI) const
    {
        return IndexTools::JointToIndividualIndices
            (sI, _m_nrPerStateFeatureVec );
    }
    ///Compute the probability of value yVal of state variable y, given ii=<Xs,As,Ys>
    virtual double ComputeTransitionProb(
        Index y,
        Index yVal,
        const std::vector< Index>& Xs,
        const std::vector< Index>& As,
        const std::vector< Index>& Ys
        ) const;        

    virtual double ComputeObservationProb(
        Index o,
        Index oVal,
        const std::vector< Index>& As,
        const std::vector< Index>& Ys,
        const std::vector< Index>& Os
        ) const;
    
    virtual size_t GetNrAgentsAtHouse(const std::vector< Index>& As,
                              Index hI) const;

    virtual size_t GetAgentLocation(Index action,
                                    Index agI) const;

    virtual std::string SoftPrintBriefDescription() const;
    virtual std::string SoftPrintDescription() const;

    ///Construct all the Actions and actionSets (the vector _m_actionVecs).
    virtual void ConstructActions();

    virtual Scope GetHousesAgentInfluences(Index agI) const;


    void InitializePFFF();

    virtual void SetYScopes();
    virtual void SetOScopes();

    double GetMultipleAgentExtinguishProb() const;
    std::string GetMultipleAgentExtinguishProbString() const;

public:
    ///Constructor
    ProblemFireFightingFactored(
            size_t nrAgents, size_t nrHouses, size_t nrFireLevels,
            double costOfMove=0.0, bool forcePositionRepres = false,
            double multipleAgentExtinguishProb = 1.0,
            bool initialize=true);

    /// Destructor.
    virtual ~ProblemFireFightingFactored(){};

    /// Returns a pointer to a copy of this class.
    virtual ProblemFireFightingFactored* Clone() const
        { return new ProblemFireFightingFactored(*this); }
};


#endif /* !_PROBLEMFIREFIGHTINGFACTORED_H_  */

// Local Variables: ***
// mode:c++ ***
// End: ***