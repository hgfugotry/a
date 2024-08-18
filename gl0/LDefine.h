#ifndef LDefine_h_
#define LDefine_h_
template<typename T>
class vec1
{
public:
    vec1(){}
    vec1(T x_){x=x_;}
    T x;
};

template<typename T>
class vec2:public vec1<T>
{
public:
    vec2(){}
    vec2(T x_,T y_):vec1<T>(x_){y=y_;}
    T y;
};

template<typename T>
class vec3:public vec2<T>
{
public:
    vec3(){}
    vec3(T x_,T y_,T z_):vec2<T>(x_,y_){z=z_;}
    T z;
};

template<typename T>
class vec4:public vec3<T>
{
public:
    vec4(){}
    vec4(T x_,T y_,T z_,T w_):vec3<T>(x_,y_,z_){w=w_;}
    T w;
};

#endif