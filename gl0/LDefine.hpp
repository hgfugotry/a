#ifndef LDefine_hpp_
#define LDefine_hpp_

namespace LG
{
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
        vec2(vec1<T>v1,T y_){x=v1.x;y=y_;}
        T y;
    };

    template<typename T>
    class vec3:public vec2<T>
    {
    public:
        vec3(){}
        vec3(T x_,T y_,T z_):vec2<T>(x_,y_){z=z_;}
        vec3(vec1<T> v1,T y_,T z_){x=v1.x;y=y_;z=z_;}
        vec3(vec2<T> v2,T z){x=v2.x;y=v2.y;z=z_;}
        T z;
    };

    template<typename T>
    class vec4:public vec3<T>
    {
    public:
        vec4(){}
        vec4(T x_,T y_,T z_,T w_):vec3<T>(x_,y_,z_){w=w_;}
        vec4(vec1<T> v1,T y_,T z_,T w_){x=v1.x;y=y_;z=z_;w=w_;}
        vec4(vec2<T> v2,T z_,T w_){x=v2.x;y=v2.y;z=z_;w=w_;}
        vec4(vec3<T> v3,T w_){x=v3.x;y=v3.y;z=v3.z;w=w_;}
        T w;
    };
}

#endif