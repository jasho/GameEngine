#ifndef VECTOR3_HEADER
#define VECTOR3_HEADER

#include "Vector2.h"
#include <string>

#define STRING_VECTOR_SEPARATOR ";"

class Vector3 : public Vector2 {
public:
	Vector3(float x = 0.0, float y = 0.0, float z = 0.0);

	// Getters
	inline float GetZ() const { return _z; }

	// Setters
	inline void SetZ(float z) { _z = z; }
	inline void SetValues(float x, float y, float z) { _x = x; _y = y; _z = z; }
	inline void SetValues(const Vector3 &vector) { _x = vector.GetX(); _y = vector.GetY(); _z = vector.GetZ(); }

	std::string ToString() const;
	void FromString(const std::string &);

	Vector3 operator+(const Vector3 &rhs) const;
	Vector3 operator-(const Vector3 &rhs);
	Vector3 operator*(const Vector3 &rhs);
	Vector3 operator*(const int rhs);

	Vector3 &operator+=(const Vector3 &rhs);
	Vector3 &operator-=(const Vector3 &rhs);
	Vector3 &operator*=(const Vector3 &rhs);

	virtual void SaveToOutputStream(std::ostream&) const;
	virtual bool LoadFromInputStream(std::istream&);

protected:	
	float _z;

};

#endif