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





### 2.4 Friends





### 2.5 Specializations of Class Templates





### 2.6 Partial Specialization







### 2.7 Default Class Template Argument







### 2.8 Type Aliases







### 2.9 Class Template Argument Deduction





### 2.10 Templatized Aggregates





### 2.11 Summary



