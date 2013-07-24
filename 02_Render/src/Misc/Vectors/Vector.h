#ifndef VECTOR_HEADER
#define VECTOR_HEADER

class Vector {

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

protected:
	float _x;

};

#endif