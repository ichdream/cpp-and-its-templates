## Function Templates

什么是funtion templates?

> Function templates are functions that are parameterized so that they represent a family of functions.

关于这句话的翻译，上网搜了一下资料，大都直接翻译为“函数模版是被参数化的函数”，我对这个翻译法不是很满意，或者原文的定义也不好，对于一个没有接触过函数模版的人来说，这句显得太过简单，根本无法表达出函数模版的特点，作用，意义。最关键的词是“被参数化”，参数值的是什么，谁的参数，我们知道函数是具有参数的，那么这个参数是否是指函数的参数？如果不是，那么它们和函数参数是什么关系？这类参数有什么意义，主要用来做什么的？

带着上述问题，我搜索了下网络，基本上很难找到一个准确的定义和概括。

> cplusplus.com:
>
> Function templates are special functions that can operate with *generic types*. This allows us to create a function template whose functionality can be adapted to more than one type or class without repeating the entire code for each type.
>
> In C++ this can be achieved using *template parameters*. A template parameter is a special kind of parameter that can be used to pass a type as argument: just like regular function parameters can be used to pass values to a function, template parameters allow to pass also types to a function. These function templates can use these parameters as if they were any other regular type.
>
> 

---

### 1.1 A First Look at Function Template

> Function templates provide a functional behavior that can be called for different types.
>
> 🤔什么是functional behavior ? 大致意思，函数模版为不同的数据类型`types`提供实现同一个功能。也就是说，函数模版代表的是一个函数家族/函数簇，这个函数家族完成✅同一套逻辑/算法/功能。

作者继续给函数模版下了个不太严谨的定义，也叫解释：

> The representation looks a lot like an ordinary function, **except that some elements of the function are left undermined:** These elements are parameterized.
>
> 从函数模版的表示来看，它很像一个普通函数， **有一点不同：函数模版中一些元素未定义**，为什么未定义呢？因为，它们是要作为模版的参数，从而参数化模版。  





### 1.2 Template Argument Deduction

模版参数推导，⚠️，这个template argument的意思，注意它和template parameters， 有点类似函数的形式参数和实际参数。

这里用template argument deduction 而不是 template parameter deduction。我们要推导：就是根据传入的function argument，推导出具体的template argument，这时函数模版中的template parameters 就对应上具体的template arguments。



### 1.3 Multiple Template Parameters



### 1.4 Default Template Arguments



### 1.5 Overloading Function Template

涉及到多个函数模版时，这几个函数模版具有同样的名称。

重载🔃规则比较复杂，这一小节只是举了一些例子，详细的🔎重载解析规则见Appendix C。



### 1.6 But, Shouldn't We...?



#### 1.6.1 Pass by Value or by Reference ?



#### 1.6.2 Why not `linline` ?

通常，函数模版不必被声明 为`inline`



#### 1.6.3 Why not `constexpr` ?

`constexpr`的作用, 直接看原文解释一目了然：

> Since C++ 11, you can use `constexpr` to provide the ability to use code to compute some values at compile time.

例子：🌰

```cpp
// maxconstexpr.hpp
template<typename T1, typename T2>
constexpr auto max(T1 a, T2 b)
{
  return b < a ? a : b;
}
```



### 1.7 Summary

这一章讲的是函数模版，function template，主要覆盖知识点如下：

- 函数模版概念，定义

  > Funtion templates define a family of functions for different template arguments.

- 模版传参，参数推导

  > When you pass arguments to function parameters depending on template parameters, function templates deduce the template parameters to be instantiated for the corresponding parameter types.

  > 当你向跟模版参数(template parameters)有依赖关系的函数参数(function parameters)传递值时，函数模版推导模版参数(template parameters)，是为了初始化相应参数的类型。

  ⚠️：

  ​	函数模版有两类参数：function parameters和template parameters。我觉得还是不翻译地好，保留原文更加容易区分。

  ​	函数参数接受传入的值，而模版参数决定传入值的类型。

- Leading template parameters

  > You can **explicitly** **qualify** the **leading** template parameters.
  >
  > 注意三个加重的词：
  >
  > - explicitly 显示地
  > - qualify ？ 指定🈯️？
  > - leading 靠前的
  >
  > 例子：
  >
  > ```cpp
  > template<typename RT = long, typename T1, typename T2>
  > {
  >   return b < a ? a : b;
  > }
  > ```

  说实话，没搞懂这个leading template paramters到底是什么？以及qualify it到底是什么操作？🤔

  留着三刷时补充。

  > <font color = 'red'>**待完善，复习**</font>

- 默认模版参数default template parameters

  > You can define default arguments for template parameters. These may refer to previous template parameters and to be followed by parameters not having default arguments.

- 函数模版重载🔃overload function template

- 多个函数模版重载🔃时⚠️，确保它们之中只有一个跟调用参数相匹配。

  > When overloading function templates with other function templates, you should ensure that only one of them matches for any call.

- 函数模版重载🔃时，对直接定义模版参数的改动应该作出限制🚫。

  没读懂原文的意思：

  > when you overload function templates, limit your changes to specifying template parameters explicitly.

- 函数模版重载🔃：确保编译器看到所有可被重载版本的函数模版。

  > Ensure the complier sees all overloaded versions of function templates before you call them.