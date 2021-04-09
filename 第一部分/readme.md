## The Basics

这是全书第一部分，讲模版基础知识：模版的一些通用概念和语言特性。

首先，通过列举函数模版和类模版的一些例子来讨论一些通用的目标和概念。对应第1章和第2章

- 1 Function  Templates
- 2 Class Templates

接着，继续讲解一些重要fundamental模版特性，包括：

- nontype template parameters 第3章
- Variadic templates 第4章
- The keyword `typename` 第5章
- Member templates 第5章

还讨论了，如何处理移动语义`move semantics`: 第6章，如何声明参数：第7章，即pass by value or pass by reference ?

如何使用generic code（翻译成：通用代码？总感觉词不达意，这里保留原文）进行编译期编程：第8章。

最后，关于一些术语：给出一些general hints，（如何翻译？保留）：第10章，和模版的用法以及它在实际中的应用：第9章。



在这一部分的开始，作者花重墨描述为什么要使用模版，这其实讨论的是模版的价值，和潜在的应用，包含前景。



-----



## 补充材料

想要更加深刻的理解模版，建议先好好理解另外一个概念：范型generics。确切地说，它是一种编程模式，generic programming。关于泛型编程，也已经有非常长的历史了，感兴趣地深入挖掘一下，这是个非常大的topic，以后有机会希望专门梳理下这部分。



范型是一种编程思想，它允许类型（我觉得还是不翻译的好，`type`）可以作为方法（函数），类，接口的一个参数。例如，通过采用范型`array`, `map`等可以非常高效地被使用。

范性编程的思想的实现是为了提高编码的效率。泛型编程使得编程人员可以编写能工作于所有数据类型通用的算法程序。在算法逻辑和功能相同的前提下，它避免我们为不同数据类型编程不同的算法。



优势在于：

- 代码复用
- 避免函数重载
- 代码一旦完成✅可以被多次使用

**==在C++中，范型是通过模版来实现的。==**（这就解释了范型编程和模版之间的关系），也为C++中的模版找到了理论依据和历史来源。



### Generic Functions using Template:

```cpp
#include <iostream>
using namespace std;
  
// One function works for all data types.
// This would work even for user defined types
// if operator '>' is overloaded
template <typename T>
  
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}
  
int main()
{
  
    // Call myMax for int
    cout << myMax<int>(3, 7) << endl;
  
    // call myMax for double
    cout << myMax<double>(3.0, 7.0) << endl;
  
    // call myMax for char
    cout << myMax<char>('g', 'e') << endl;
  
    return 0;
}
```

**Output:**

```shell
7
7
g
```



### Generic Class using Template:

类模版可以定义一些东西something，在定义的过程中跟数据类型无关。Can be useful for classes like LinkedList, binary tree, Stack, Queue, Array, etc

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
	T* ptr;
	int size;

public:
	Array(T arr[], int s);
	void print();
};

template <typename T>
Array<T>::Array(T arr[], int s)
{
	ptr = new T[s];
	size = s;
	for (int i = 0; i < size; i++)
		ptr[i] = arr[i];
}

template <typename T>
void Array<T>::print()
{
	for (int i = 0; i < size; i++)
		cout << " " << *(ptr + i);
	cout << endl;
}

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	Array<int> a(arr, 5);
	a.print();
	return 0;
}

```

**Output:**

```shell
1 2 3 4 5
```



### Working with multi-type Generics:

也可以一次**将多个数据类型作为参数**传递给模版。

```cpp
#include <iostream>
using namespace std;

template <class T, class U>
class A {
	T x;
	U y;

public:
	A()
	{
		cout << "Constructor Called" << endl;
	}
};

int main()
{
	A<char, char> a;
	A<int, double> b;
	return 0;
}
```

**Output:**

```shell
Constructor Called
Constructor Called
```