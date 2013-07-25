#ifndef COLOR_HEADER
#define COLOR_HEADER

class Color
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

private:
	float _red;
	float _blue;
	float _green;
};

#endif