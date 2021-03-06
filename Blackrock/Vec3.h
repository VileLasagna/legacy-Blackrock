#ifndef VEC3_H
#define VEC3_H

#include "Vec2.h"


template <class T>
class Vec3
{
public:

	Vec3() : x(0), y(0), z(0) {}
    Vec3(T x, T y, T z) {this->x = x; this->y = y; this->z = z;}
	Vec3 (const Vec2<T>& ref) {this->x = ref.X(); this->y = ref.Y(); this->z = 0;}
	Vec3 (const Vec3<T>& ref) {this->x = ref.X(); this->y = ref.Y(); this->z = ref.Z();}
	Vec3& operator= (const Vec3<T>& ref) {this->x = ref.X(); this->y = ref.Y(); this->z = ref.Z(); return *this;}

	T X() const { return x; }
    T Y() const { return y; }
	T Z() const { return z; }
    void setX(T x) { this->x = x; }
    void setY(T y) { this->y = y; }
	void setZ(T z) { this->z = z; }

	Vec3& operator+=(const Vec3& rhs)
    {
        this->x += rhs.x;
        this->y += rhs.y;
		this->z += rhs.z;
        return *this;
    }

	Vec3& operator*=(const T& f)
    {
        this->x *= f;
        this->y *= f;
		this->z *= f;
        return *this;
    }
    Vec3& operator*=(const Vec3<T>& f)
    {
        this->x *= f.X();
        this->y *= f.Y();
		this->z *= f.Z();
        return *this;
    }

	T dotProd(const Vec3<T>& rhs) const
	{
		T ret = x*rhs.X()+y*rhs.Y()+z*rhs.Z();
		return ret;
	}

	T sqMod() const
	{
		return this->dotProd(*this);
	}

	T mod() const
	{
		T sqm = this->sqMod();
		void* p = &sqm;
		if(typeid(T) == typeid(double))
		{
		   return sqrt( *((double*) p));
		}
		if(typeid(T) == typeid(long double))
		{
		   return sqrt( *((long double*) p));
		}
		if ( ( typeid(T) == typeid(float) ) || ( typeid(T) == typeid(int) ) || ( typeid(T) == typeid(long) ) || ( typeid(T) == typeid(short) ) )
		{
		   return sqrt( *((float*) p));
		}
		else
		{
		   return 0; //sqrt will probably make no sense on this type.
		}
	}


protected:

	T x;
	T y;
	T z;

};

template <class T>
Vec3<T> operator+(const Vec3<T>& a, const Vec3<T>& b)
{
    Vec3<T> res = a;
    res += b;
    return res;
}

template <class T>
Vec3<T> operator*(const Vec3<T>&a, T f)
{
    Vec3<T> res = a;
    res *= f;
    return res;
}

template <class T>
bool operator == (const Vec3<T>&a, const Vec3<T>& b)
{
	return ( (a.X()==b.X())&&(a.Y()==b.Y())&&(a.Z()==b.Z()));
}

template <class T>
bool operator != (const Vec3<T>&a, const Vec3<T>& b)
{
	return !(a==b);
}

template <class T>
Vec3<T> operator- (const Vec3<T>& v)
{
	Vec3<T> ret(-(v.X()), -(v.Y()), -(v.Z()));
	return ret;
}

template <class T>

Vec3<T> operator- (const Vec3<T>& a, const Vec3<T>& b)
{
	Vec3<T> ret(a.X() - b.X(), a.Y()-b.Y(), a.Z() - b.Z());
	return ret;
}

template <class T>
Vec3<T> crossProd (const Vec3<T>& a, const Vec3<T>& b)
{
	Vec3<T> ret(a.Y()*b.Z() - a.Z()*b.Y(), a.X()*b.Z() - a.Z()*b.X(), a.Y()*b.X() - a.X()*b.Y());
	return ret;
}


typedef Vec3<float> Vec3f;
typedef Vec3<int> Vec3i;
typedef Vec3<double> Vec3d;


#endif //VEC3_H