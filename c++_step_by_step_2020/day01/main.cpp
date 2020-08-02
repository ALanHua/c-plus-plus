//
//  main.cpp
//  day01
//
//  Created by yhp on 2020/8/1.
//  Copyright © 2020 none. All rights reserved.
//

#include <iostream>
#include "math.h"
#include "test.h"

using namespace std;

void test(void){
    int age;
    cin >> age;
    cout << "age is " << age << endl;
    
    getchar();
    getchar();
    
}

/*
 function overload
 函数重载
 */
int sum(int v1,int v2){
    return v1 + v2;
}

int sum(int v1,int v2,int v3){
    return v1 + v2 + v3;
}

void func(int v1,double v2){
    cout << "int v1,double v2" << endl;
}

void func(double v1,int v2){
    cout << "double v1,int v2" << endl;
}

/*
 实参可能存在隐式转换
 */
void display(int a){
    cout << "display int" << a << endl;
}

void display(long a){
    cout << "display long" << a << endl;
}

void display(double a){
    cout << "display double" << a << endl;
}

// 默认参数 只能按照从右到左
// 函数有声明和实现，默认参数只能放在声明上
// 默认参数只能是字面量或者全局变量
int sum2(int v1 = 5,int v2 = 6){
    return v1 + v2;
}

int func2(int v1,int v2,int v3 = 10){
    return v1 + v2 + v3;
}
 
void fun2(int v1,void(*p)(int) = display){
    p(v1);
}

// extern "C"
// 表示需要使用c语言的方式编译代码
// 函数声明需要加，实现不需要加
extern "C" void func3(void){
}

// inline 内敛函数
// 编译器将函数调用展开成函数体代码
// 函数代码体积不大，频繁调用的函数最好定义成内敛函数
// 非内敛函数调用需要开辟栈空间，结束回收栈空间
// 递归函数不会是内核函数即使添加inline标志
inline int sum3(int v1,int v2){
    return v1 + v2;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout << sum(10,30) << endl;
    cout << sum(10,30,20) << endl;
    func(10, 10.5);
    func(10.5, 10);
    display(10);
    display(10L);
    display(10.0);
    cout << sum2() << endl;
    fun2(20);
    
    cout << add(10,100) << endl;
    
    return 0;
}
