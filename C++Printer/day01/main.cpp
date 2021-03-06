//
//  main.cpp
//  day01
//
//  Created by yhp on 2018/10/16.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>
#include <string>
#include <new>
// 命名空间解决名字冲突的问题
// 匿名名字空间 -- 全局名字空间 ::var = 123 / var = 123
// c++ 结构体还可以是函数，甚至还可以是类型
// void* 类型 严格限制不能赋值给其他地址类型 c++ 强类型语言
using namespace std;
namespace andy {
    struct Student{
        char name[20];
        int  age;
        void show(){
            cout << name << " " << age  << " "<< "c++ learn" << endl;
        }
    };
    enum Color {
      RED,GREEN,BLUE
    };
//  函数重载
    void show(int n)
    {
        cout << "整数" << n << endl;
    }
    
    void show(double n)
    {
        cout << "小数" << n << endl;
    }
    void show(int n,int m)
    {
        cout << "一对整数" << n  <<"," << m << endl;
    }

    struct Person {
        char name[20];
        char gender;
    };
    
    void show(Person p)
    {
        cout << "一个人" << p.name <<"," << p.gender << endl;
    }
    
    void show(const char* name,char gender = 'M');
    
    void show(const char* name,char gender){
        cout << name << (gender == 'M'? "女" :"男") << endl;
    }
    
    inline int max(int a,int b){
        return a < b ? b : a;
    }
    
    struct Date{
        int year;
        int month;
        int day;
        
        void print(){
            cout << year << '-' << month << '-' << day << endl;
        }
    };
    
    void sort(Date a[],int n,int Date::*p){
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i].*p > a[j].*p) {
                    swap(a[i], a[j]);
                }
            }
        }
    }
    
    void swap(int* p,int* q){
        int t = *p;
        *p = *q;
        *q = t;
    }
    void swap(int& p,int& q){
        int t = p;
        p = q;
        q = t;
    }
    int& counter(){
        static int cnt = 0;
        ++cnt;
        return cnt;
    }
}

/** 强制类型转换
 1，static_cast<类型>(数据)用于数值类型之间y以及void* 和 其他*
 2，reinterpret_cast<类型>(数据)用于数值类型或者地址类型之间，或者地址类型相互之间
 3，const_cast<T*>(T 常量地址) 去掉const限制
 4，dynamic_cast 面向对象
 */

/**
 1,c 函数默认返回int 类型，c++ 作废
 2,c 空参数表示参数个数随意，c++中只表示无惨，函数在调用前必须声明或者定义
 */
// 哑元: 多余的形参，不需要指定名字,一般为了跟以前的版本兼容，e偶尔也用于其他用途
// 宏函数，C++ 基本不用 一般用inline代替，和g宏函数一样高效
/**
内存管理：c语言/malloc/free/calloc/realloc c++ new 类型 /delete 地址/ delete[] 地址
new(指定地址)类型，在指定的地方分配内存
 new 失败会throw 抛出异常，可以使用nothrow来
 */
/**
 引用: 本质上市指针，编译器自动取地址加型号
      引用必须初始化，用谁初始化它，它就跟谁是同一体
      引用使用变量本身，而不是复制数据
特别说明：形参是在调用时由实参初始化
 */

/**
 数组：
 c++ 风格用vector<类型> 数组名(长度，元素初始值)
 可以使用resize 来调整大小
 */

int main(int argc, const char * argv[]) {
    
    andy::Student s1 = {
        "andy",18
    };
    
    using namespace andy;
    Student s2;
    strcpy(s2.name, "alan");
    s2.age = 20;
    
    s1.show();
    s2.show();
    
//  匿名联合
    union {
        int x;
        char y[4];
    };
    
    x = 0x61626364;
    cout << hex << showbase << x << endl;
    y[1] = '0';// 0x30
    cout << hex << showbase << x << endl;
    
    Color c;
    c = GREEN;
    cout << c << endl;
    void*p = &c;
    Color* q;
//    q = p; 无法编译
    /**
     强制类型转换
     */
    q = (Color*)p;
    cout << *q << endl;
    
    int a = static_cast<int>(123.45);
    cout << dec << a << endl;
    int b = 100;
    void* p1 = &b;
    int* q1 = static_cast<int*>(p1);
    char* r = reinterpret_cast<char*>(q1);
    cout << "r=" << r << endl;
    const int c1 = b;
    cout << "c1=" << c1 << endl;
    *const_cast<int*>(&c1) = 200;
    cout << "c1=" << c1 << endl;
    
    show(123);
    Person fj = {
      "凤姐",'M'
    };
    show(fj);
    show(45.6);
    show(10, 20);
    show("andy");
    
    int x1 = 10;
    int y2 = 20;
    int z = max(x1, y2);
    
    cout << z << endl;
    
    int* pi = new int;
    int n = 200;
    char* pc = new char[n];
    double* pd = new (nothrow)double[n];
    long* pl = new long(123);
//    空圆括号的称为零初始化
    short* ps = new short();
    
    *pi = n + 1;
    strcpy(pc, "andy");
    pd[0] = 123.45;
    cout << *pi <<","<< pc <<","<< pd[0] <<","<< *pl <<","<< *ps << endl;
    
    delete pi;
    delete[] pc;
    delete[] pd;
    delete pl;
    delete ps;
    
    int Date::*p3 = &Date::year;
    Date a3 = {2018,5,16},b3 = {2019,1,1};
    cout << a3.*p3 << "," << b3.*p3 << endl;
    p3 = &Date::day;
    cout << a3.*p3 << "," << b3.*p3 << endl;
    
    Date t[4] = {
        a3,b3,{1970,1,1},{2012,12,21}
    };
    sort(t, 4, &Date::year);
    for (int i = 0; i < 4; i++) {
        t[i].print();
    }
    
    cout << counter() << endl;
    cout << counter() << endl;
    cout << counter() << endl;
    counter() = 0;
    cout << counter() << endl;
    cout << counter() << endl;
    cout << counter() << endl;
    
    return 0;
}
