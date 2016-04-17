#include "patterns.h"

Pattern_t *PatternJobs::patterns = NULL;
int PatternJobs::num_patterns = 0;

PatternJobs::PatternJobs()
{
    
}

PatternJobs::~PatternJobs()
{

}

void PatternJobs::register_pattern(Pattern_t *pattern)
{
    if(patterns == NULL)
    {
        patterns = (Pattern_t *)malloc(sizeof(Pattern_t));
        memcpy(patterns, pattern, sizeof(Pattern_t));
        this->num_patterns+=1;
    }
}

void PatternJobs::process()
{
    static Pattern_t *pattern;
    for(int p = 0; p < num_patterns; p++)
    {
        pattern = &patterns[p];
        if(pattern->surf != NULL)
        {
            pattern->surf->generate();
            if(pattern->net != NULL)
            {
                pattern->net->process(pattern->surf);
            }
            if(pattern->sim != NULL)
            {
                pattern->sim->process(pattern->surf);
            }
        }
    }
}