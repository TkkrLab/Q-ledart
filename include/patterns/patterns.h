#ifndef __PATTERNS_H__
#define __PATTERNS_H__

#include <string.h>
#include <stdlib.h>

#include <surface.h>
#include <network.h>
#include <matrixsim.h>

// include network interfaces here.
#include <network.h>
#include <lmcp.h>

// include available patterns also here.
#include <BouncingDot.h>

typedef struct
{
    Surface *surf;
    Network *net;
    MatrixSimulator *sim;
} Pattern_t;

class PatternJobs
{
public:
    PatternJobs();
    ~PatternJobs();
    void register_pattern(Pattern_t *);
    void process();
private:
    Pattern_t *patterns = NULL;
    size_t num_patterns = 0;
};

#endif