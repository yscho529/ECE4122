//
// Created by Brian Swenson on 1/29/18.
//

#pragma once
#include <iostream>


template<typename T>
class Vec3 {
public:
//fill in here
    // constructors
    Vec3(){}
    Vec3<T>(T val){ x = y = z = val; }
    Vec3<T>(T valX, T valY, T valZ){
        x = valX;
        y = valY;
        z = valZ;
    }
    Vec3<T>(const Vec3<T> &a){ x = a.x; y = a.y; z = a.z; }

    // get set
    T getX() const { return x; }
    T getY() const { return y; }
    T getZ() const { return z; }
    void setX(T _x) { x = _x; }
    void setY(T _y) { y = _y; }
    void setZ(T _z) { z = _z; }

    //operator overloads
    Vec3 operator+(const Vec3 rhs){ return Vec3(x+rhs.x, y+rhs.y, z+rhs.z); }
    void operator+=(const Vec3 rhs){
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
    }
    Vec3 operator-(const Vec3 rhs){ return Vec3(x-rhs.x, y-rhs.y, z-rhs.z); }
    void operator-=(const Vec3 rhs){
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
    }
    Vec3 operator/(int d) { return Vec3(x/d, y/d, z/d); }
    Vec3 operator*(int mult) { return Vec3(x*mult, y*mult, z*mult); }
    Vec3 operator++(int){
        Vec3 tmp(x,y,z);
        T tmpZ = z;
        z = y;
        y = x;
        x = tmpZ;
        return tmp;
    }
    Vec3 operator++() {
        T tmpZ = z;
        z = y;
        y = x;
        x = tmpZ;
        return Vec3(x, y, z);
    }
    Vec3 operator--(int){
        Vec3 tmp(x,y,z);
        T tmpX = x;
        x = y;
        y = z;
        z = tmpX;
        return tmp;
    }
    Vec3 operator--() {
        T tmpX = x;
        x = y;
        y = z;
        z = tmpX;
        return Vec3(x, y, z);
    }
    void operator*=(const Vec3 rhs){
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
    }
    void operator/=(const Vec3 rhs){
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
    }
    bool operator==(const Vec3 rhs){
        return(x==rhs.x && y==rhs.y && z==rhs.z);
    }
    bool operator!=(const Vec3 rhs){
        return(x!=rhs.x || y!=rhs.y || z!=rhs.z);
    }


    //dot product
    double dot(const Vec3<T> b){
        return x*b.x + y*b.y + z*b.z;
    }

private:
    T x;
    T y;
    T z;
};

//for printing
template<typename T>
std::ostream& operator<<(std::ostream& stream, const Vec3<T>& vec) {
    stream << "X=" << vec.getX() << ", Y=" << vec.getY() << ", Z=" << vec.getZ();
    return stream;
}