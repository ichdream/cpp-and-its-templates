## Function Templates

什么是funtion templates?

> Function templates are functions that are parameterized so that they represent a family of functions.

关于这句话的翻译，上网搜了一下资料，大都直接翻译为“函数模版是被参数化的函数”，我对这个翻译法不是很满意，或者原文的定义也不好，对于一个没有接触过函数模版的人来说，这句显得太过简单，根本无法表达出函数模版的特点，作用，意义。最关键的词是“被参数化”，参数值的是什么，谁的参数，我们知道函数是具有参数的，那么这个参数是否是指函数的参数？如果不是，那么它们和函数参数是什么关系？这类参数有什么意义，主要用来做什么的？

带着上述问题，我搜索了下网络，基本上很难找到一个准确的定义和概括。

---

### 1.1 A First Look at Function Template

> Function templates provide a functional behavior that can be called for different types.
>
> 🤔什么是functional behavior ? 大致意思，函数模版为不同的数据类型`types`提供实现同一个功能。也就是说，函数模版代表的是一个函数家族/函数簇，这个函数家族完成✅同一套逻辑/算法/功能。

作者继续给函数模版下了个不太严谨的定义，也叫解释：

> The representation looks a lot like an ordinary function, **except that some elements of the function are left undermined:** These elements are parameterized.
>
> 从函数模版的表示来看，它很像一个普通函数， **有一点不同：函数模版中一些元素未定义**，为什么未定义呢？因为，它们是要作为模版的参数，从而参数化模版。  







### 1.2 Template Argument Dedution



### 1.3 Multiple Template Parameters



### 1.4 Default Template Arguments



### 1.5 Overloading Function Template



### 1.6 But, Shouldn't We...?



### 1.7 Summary



