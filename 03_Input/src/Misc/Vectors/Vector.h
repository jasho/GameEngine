#ifndef VECTOR_HEADER
#define VECTOR_HEADER

#include "../../Serialize/Serializable.h" 

class Vector : public Serializable
{

public:
	Vector(float x = 0.0);

	// Getters
	inline float GetX() const { return _x; }

	// Setters
	inline void SetX(float x) { _x = x; }
	inline void SetValues(float x) { _x = x; }
	inline void SetValues(const Vector &vector) { _x = vector.GetX(); }

	Vector operator+(const Vector &rhs);
	Vector operator-(const Vector &rhs);
	Vector operator*(const Vector &rhs);

	Vector &operator+=(const Vector &rhs);
	Vector &operator-=(const Vector &rhs);
	Vector &operator*=(const Vector &rhs);

	virtual void SaveToOutputStream(std::ostream&) const;
	virtual bool LoadFromInputStream(std::istream&);

protected:
	float _x;

};

#endif