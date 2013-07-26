#ifndef VECTOR4_HEADER
#define VECTOR4_HEADER

#include "Vector3.h"

class Vector4 : public Vector3 {

public:
	Vector4(float x = 0.0, float y = 0.0, float z = 0.0, float w = 0.0);

	// Getters
	inline float GetW() const { return _w; }

	// Setters
	inline void SetW(float w) { _w = w; }
	inline void SetValues(const float x, const float y, const float z, const float w) { _x = x; _y = y; _z = z; _w = w; }
	inline void SetValues(const Vector4 &vector) { _x = vector.GetX(); _y = vector.GetY(); _z = vector.GetZ(); _w = vector.GetW(); }

	Vector4 operator+(const Vector4 &rhs);
	Vector4 operator-(const Vector4 &rhs);
	Vector4 operator*(const Vector4 &rhs);

	Vector4 &operator+=(const Vector4 &rhs);
	Vector4 &operator-=(const Vector4 &rhs);
	Vector4 &operator*=(const Vector4 &rhs);

	virtual void SaveToOutputStream(std::ostream&) const;
	virtual bool LoadFromInputStream(std::istream&);

protected:
	float _w;

};


#endif