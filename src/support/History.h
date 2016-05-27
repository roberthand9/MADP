/* REPLACE_MADP_HEADER */
/* REPLACE_CONTRIBUTING_AUTHORS_START
 * Frans Oliehoek 
 * Matthijs Spaan 
 * REPLACE_CONTRIBUTING_AUTHORS_END
 */

/* Only include this header file once. */
#ifndef _HISTORY_H_
#define _HISTORY_H_ 1

/* the include directives */
#include <iostream>
#include "Globals.h"

///History is a general class for histories.
class History 
{
private:    
    
protected:
    
    /// How long (how many time-steps) is this history?
    /** For example, history at... 
     * ts 0 - length 0 (received no action yet... )
     * ts 1 - length 1 (hist= (a0) )
     * ts 2 - length 2 (hist= (a0,a1) ) */
    size_t _m_length;
    
public:
    // Constructor, destructor and copy assignment.
    /// (default) Constructor
    History(){};
    /// Destructor.
    virtual ~History(){};
    
    /// Returns the length of the history, i.e., the number of time steps.
    size_t GetLength() const
        {
            return(_m_length);
        }

    ///Set the length of the history, i.e., the number of time steps.
    void SetLength(size_t length)
        {
            _m_length=length;
        }
    
    /// Returns a pointer to a copy of this class.
    virtual History* Clone() const = 0;

    virtual void Print() const = 0;
};


#endif /* !_HISTORY_H_ */

// Local Variables: ***
// mode:c++ ***
// End: ***