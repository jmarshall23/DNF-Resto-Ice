// dnAI.h
//

#include "dnAIClasses.h"

#undef DECLARE_CLASS
#define DECLARE_CLASS(x, y, z)
#include "../../dnGame/inc/dnGameClasses.h"

//
// DnRand 
// Basically a wrapper for krand from Duke3D.
//
class DnRand
{
public:
	DnRand()
	{
		randomseed = 17;
	}

	unsigned int GetRand()
	{
		randomseed = (randomseed * 27584621) + 1;
		return(((unsigned int)randomseed) >> 16);
	}

	bool ifrnd(int val1)
	{
		return (((GetRand() >> 8) >= (255 - (val1))));
	}
private:
	int randomseed;
};

extern DnRand dnRand;