#ifndef MATH_3D_H
#define MATH_3D_H

struct Vector3f {
	float x, y, z;

	Vector3f() = default;
	Vector3f(float x, float y, float z) : x(x), y(y), z(z) { }
};

#endif /* MATH_3D_H */
