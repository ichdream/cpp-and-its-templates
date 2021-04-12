## Chapter 2 Class Templates

[toc]

---

跟函数模版定义类似，类也可以用一个或者多个类型`type`作为参数，从而形成class template。

类模版再标准库非常常见，比如容器container有关的classes，都是模版类。



整个章节通过栈stack作为例子开展。



### 2.1 Implementation of Class Template Stack

```hpp
//stack1.hpp
#include <vector>
#include <cassert>

template<typename T>
class Stack {
  private:
  	std::vector<T> elems;
  public:
  	void push(T const& elem);
  	void pop();
  	T const& top() const;
  	bool empty() const {
      return elems.empty();
    }
};

template<typename T>
void Stack<T>::push(T const& elem)
{
  elems.push_back(elem);
}

template<typename T>
void Stack<T>::pop()
{
  assert(!elem.empty());
  elems.pop_back();
}

template<typename T>
T const& Stack<T>::top() const
{
  assert(!elems.empty());
  return elems.back();
}
```

类模版的实现其实借用了标准库中的另一个容器container vector<>，好处😋在于不用自己实现内存管理，复制构造函数，赋值操作符，专注于模版类的接口实现。



### 2.2 Use of Class Template Stack

C++17之前，要想使用类模版创建的对象，必须直接/显现地(explicitly)指定模版参数值（注意⚠️，这里是arguments）。

C++17引入了类的参数值模版推导，因此如果可以通过构造函数推演得出derived from the constructor, 就可以跳过模版参数值的指定。



### 2.3 Partial Usage of Class Templates

类模版通常会对用来初始化它的那些模版参数值进行多次操作，包括构造过程和析构过程。这很有可能会让人认为，这些模版参数(template arguments，一个具体的类型，比如int, string)必须提供这个类模版成员函数所有必须的操作符©️（运算）。

But, 事实并非如此：

> Template arguments only have to provide all necessary operations that are needed(instead of that could be needed).

总结来说，这个特性可以使我们使用模版的部分功能，即使有功能操作符还未实现，但是并不影响其它功能的使用。



#### 2.3.1 Concepts

上面👆提到🤔️一个问题：

> How do we know which operations are required for a template to be able to get instantiated.

`concept`通常用于表示在模版库中会被反复要求一组限制🚫。原文：

> The term *concept* is often used to denote a set of constraints that is repeatedly required in a template library.

作者举标准库中的例子：

> For example, the C++ standard library relies on such concepts as *random access iterator* and *default constructible*.



正文中对于`concept`的介绍内容很短，但其实深入理解Concept很关键。📴

> A *concept* is a named set of constraints on one or more template parameters.

问几个问题：

- <font color="yellow">**为什么需要concept**？</font>

  在C++进行模版编程时，我们有时想要对模版参数template parameters进行限制🚫，只有满足要求的template parameters才能继续进行后续的模版初始化过程。

  这样做的好处😋，在于出问题了能够准确地知道bug出现在什么地方，否则的话，template会报告出一大堆信息💻。

  >
  >
  >例子：🌰
  >
  >1.不用concept， 我们要检查T是否满足要求，函数内部实现：
  >
  >```cpp
  >template<typename T>
  >T inc(T a)
  >{
  >  static_assert(std::is_integral<T>::value)
  >    return a++;
  >}
  >int main(int argc, const char* argv[])
  >{
  >  int a = 0;
  >  std::cout << inc(&a) << std::endl;
  >  return 0;
  >}
  >```
  >
  >结果：<font color="y">编译阶段出现问题了，inc函数不能传递指针，T只有是整数类型才可以。从编译出错信息很难定位。</font>
  >
  >2.使用concept
  >
  >```cpp
  >template<typename T>
  >concept Integral = std::is_integral<T>::value;
  >
  >template<Integral T>
  >T inc(T a)
  >{
  >  return a++;
  >}
  >int main(int argc, const char* argv[])
  >{
  >  int a = 0;
  >  std::cout << inc(&a) << endl;
  >  return 0;
  >}
  >```
  >
  >结果：编译阶段报错，很明显可以看出是由于T不满足模版的限制条件。
  >
  >**补充：**除了上述的concept写法，还有另外几种写法：
  >
  >写法2⃣️：
  >
  >```cpp
  >template<typename T> requires Integral<T>
  >T inc(T a)
  >{
  >  return a++;
  >}
  >```
  >
  >写法3⃣️：
  >
  >```cpp
  >template<typename>
  >T inc(T a) requires Integral<T>
  >{
  >  return a++;
  >}
  >```
  >
  >我个人还是比较喜欢😍第3种写法的，比较直观，一眼就可以看清楚👀限制条件是什么。
  >
  >写法4⃣️：
  >
  >```cpp
  >Integral auto inc(Integral auto a)
  >{
  >  return ++a;
  >}
  >```
  >
  >备注：这种写法是Bjarne Stroustrup老爷子比较📒推崇的写法。

  

- <font color="yellow">**concept发展到现在怎么样了？**</font>

  C++11将它除去到语言特性中，理由：需要消耗太多的committee resources

  > While C++11 was being a developed, a rich concept system was designed for it, but integrating the feature into the language specification ended up requiring too many committee resources, and that version of concepts was eventually dropped from C++11.
  >
  > Some time later, a different design of the feature was proposed, and it appears that it will eventually make it into the language in some form.
  >
  > In fact, just before the book went to press, the standardization committee voted to integrate the new design into the draft for C++20.

  C++20已经正式添加进去了。

  > C++20 有了concepts库：
  >
  > The concepts library provides definitions of fundamental library concepts that can be used to perform compile-time validation of template arguments and perform function dispatch based on properties of types. These concepts provide a foundation for equational reasoning in programs.
  >
  > Most concepts in the standard library impose both syntactic and semantic requirements. It is said that a standard concept is *satisfied* if its syntactic requirements are met, and is *modeled* if it is satisfied and its semantic requirements (if any) are also met.
  >
  > In general, only the syntactic requirements can be checked by the compiler. If the validity or meaning of a program depends whether a sequenced of template arguments models a concept, and the concept is satisfied but not modeled, or if a semantic requirement is not met at the point of use, the program is ill-formed, no diagnostic required.

  

### 2.4 Friends



### 2.5 Specializations of Class Templates





### 2.6 Partial Specialization







### 2.7 Default Class Template Argument







### 2.8 Type Aliases







### 2.9 Class Template Argument Deduction





### 2.10 Templatized Aggregates





### 2.11 Summary



