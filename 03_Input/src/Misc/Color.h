#ifndef COLOR_HEADER
#define COLOR_HEADER

#include "../Serialize/Serializable.h"

class Color : public Serializable
{
public:
	Color();
	Color(float, float, float);
	~Color();

	float GetRed() const;
	float GetBlue() const;
	float GetGreen() const;

	void SetRed(float);
	void SetBlue(float);
	void SetGreen(float);
	void SetColors( float, float, float );

	virtual void SaveToOutputStream(std::ostream&) const;
	virtual bool LoadFromInputStream(std::istream&);

private:
	float _red;
	float _blue;
	float _green;
};

#endif