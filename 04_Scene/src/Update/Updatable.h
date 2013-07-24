#ifndef UPDATABLE_HEADER
#define UPDATABLE_HEADER

#include "../Misc/Vectors/Vector3.h"

#ifndef DEFAULT_UPDATABLE_FREQUENCY
#define DEFAULT_UPDATABLE_FREQUENCY 30
#endif

class Updatable 
{
public:	
	virtual ~Updatable();
	virtual void Update();
	
	int CheckTime();

protected:
	Updatable(int frequency = DEFAULT_UPDATABLE_FREQUENCY);

	int _freq;	// Frequency in Hz.
	long long _lastUpdateTime; // Time when the last update happened.
};

#endif
