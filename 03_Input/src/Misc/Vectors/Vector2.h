#ifndef VECTOR2_HEADER
#define VECTOR2_HEADER

#include "Vector.h"

class Vector2 : public Vector {

public:
	Vector2(float x = 0.0, float y = 0.0);

	// Getters
	inline float GetY() const { return _y; }

	// Setters
	inline void SetY(float y) { _y = y; }
	inline void SetValues(float x, float y) { _x = x; _y = y; }
	inline void SetValues(const Vector2 &vector) { _x = vector.GetX(); _y = vector.GetY(); }

	Vector2 operator+(const Vector2 &rhs);
	Vector2 operator-(const Vector2 &rhs);
	Vector2 operator*(const Vector2 &rhs);

	Vector2 &operator+=(const Vector2 &rhs);
	Vector2 &operator-=(const Vector2 &rhs);
	Vector2 &operator*=(const Vector2 &rhs);

	virtual void SaveToOutputStream(std::ostream&) const;
	virtual bool LoadFromInputStream(std::istream&);

protected:
	float _y;

};

#endif