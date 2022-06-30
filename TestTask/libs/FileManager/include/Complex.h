#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>
#include <fstream>

/**
* @brief Complex - это шаблонный класс комплексных чисел
*/

template <class Type>
class Complex{
    public:
    /**
    * @brief Complex конструктор по умолчанию
    */
    Complex():re(0),im(0)
    {}
    /**
    * @brief Complex конструктор с одним параметром для вещественной части
    */
    Complex(Type Re):re(Re),im(0)
    {}
    /**
    * @brief Complex конструктор с двумя параметрами для задания вещественной
    * и мнимой части комплексного числа
    */
    Complex(Type Re,Type Im):re(Re),im(Im)
    {}
    /**
    * @brief Complex конструктор копирования
    */

    Complex (const Complex& c):re(c.re),im(c.im)
    {}
    /**
    * @brief Complex деструктор
    */
    ~Complex()
    {}

    /**
    * @brief real метод для вывода вещественной части комплесного числа
    */
    Type real() const
    {
        return re;
    }

    /**
    * @brief imag метод для вывода мнимой части комплесного числа
    */
    Type imag() const
    {
        return im;
    }

    /**
    * @brief abs метод для вычисления модуля комплексного числа
    */
    Type abs()
    {
        return sqrt(re*re+im*im);
    }

    /**
    * @brief arg метод для вычисления аргумента комплексного числа в радианах
    */
    Type arg()
    {
      return atan(im/re);
    }

    /**
    * @brief argDeg метод для вычисления аргумента комплексного числа в градусах
    */
    Type argDeg()
    {
        return arg()*180/M_PI;
    }


    friend std::ostream& operator<<(std::ostream &os, Complex<Type> const& c)
    {
        os<<c.re<<' '<<c.im<<std::endl;
        return os;
    }


    friend std::ifstream& operator>>(std::ifstream &in, Complex<Type>& c)
    {
        in>>c.re;
        in>>c.im;
        return in;
    }

    template<typename U>
    Complex<Type>& operator=(const Complex<U>& c)
    {
        re=c.real();
        im=c.imag();
        return *this;
    }

    template<typename U>
    Complex<Type>& operator+=(const Complex<U>& c)
    {
        re+=c.real();
        im+=c.imag();
        return *this;
    }

    Complex& operator+=(Type a)
    {
        re+=a;
        return *this;
    }

    template<typename U>
    Complex<Type>& operator-=(const Complex<U> c)
    {
        re-=c.real();
        im-=c.imag();
        return *this;
    }

    template<typename U>
    Complex<Type>& operator-=(const U a)
    {
        re-=a;
        return *this;
    }


    Complex operator-() const
    {
      return Complex(-re,-im);
    }

    /*
    *  перегрузка префиксного инкремента
    */
    Complex& operator++(){
        ++re;
        return *this;
    }

    /*
    *  перегрузка постфиксного инкремента
    */
    Complex  operator++(int){
        Complex tmp(*this);
        ++(*this);
        return tmp;
    }

    /*
    *  перегрузка префиксного декремента
    */
    Complex& operator--(){
        --re;
        return *this;
    }

    /*
    *  перегрузка постфиксного декремента
    */
    Complex operator--(int){
        Complex<Type> tmp(*this);
        --(*this);
        return tmp;
    }

    bool operator==(const Complex<Type> &c) const;



    private:
    Type re;
    Type im;
};




template<typename T, typename U>
Complex<T> operator+(Complex<T> c1, Complex<U> c2)
{
    Complex<T> r=c1;
    return r+=c2;
}


template<typename T, typename U>
Complex<T>& operator+(Complex<T> c1,U c2)
{
    Complex<T> r=c1;
    return r+=c2;
}


template<typename T, typename U>
Complex<U>& operator+(T c1,Complex<U> c2)
{
    Complex<U> r=c2;
    return r+=c1;
}

template<typename T, typename U>
Complex<T>& operator-(Complex<T> c1, Complex<U> c2)
{
    Complex<T> r=c1;
    return r-=c2;
}

template<typename T, typename U>
Complex<T>& operator-(Complex<T> c1,U c2)
{
    Complex<T> r=c1;
    return r-=c2;
}


template<typename T, typename U>
Complex<T>& operator-(T c1,const Complex<U>& c2)
{
   Complex<T> r=c1;
   return r-=c2;;
}


//template<class T>
//Complex<T>& operator-(Complex<T> c1,T c2)
//{
//    Complex<T> r=c1;
//    return r-=c2;
//}

//template<class T>
//Complex<T>& operator-(T c1,Complex<T> c2)
//{
//    Complex<T> r=c2;
//    return r-=c1;
//}

template<class T>
bool Complex<T>::operator==(const Complex<T> &c) const
{
    return (re == c.re && im == c.im);
}


#endif
