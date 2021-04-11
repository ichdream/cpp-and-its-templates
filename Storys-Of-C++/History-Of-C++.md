# History of C++

---

The C++ programming language has a history going back to 1979, when [Bjarne Stroustrup](http://www2.research.att.com/~bs/) was doing work for his Ph.D. thesis. One of the languages Stroustrup had the opportunity to work with was a language called Simula, which as the name implies is a language primarily designed for simulations. [The Simula 67 language](http://staff.um.edu.mt/jskl1/talk.html) - which was the variant that Stroustrup worked with - is regarded as the first language to support the object-oriented programming paradigm. Stroustrup found that this paradigm was very useful for software development, however the Simula language was far too slow for practical use.

**引子：**

最开始，源于Simula语言里面包含的面向对象编程思想， Bjarne Stroustrup发现这种编程范式可以提高编程效率，但是问题在于：这种编程语言只是应用在仿真，在实际工程应用中很慢。

> 补充：
>
> [C programming language](http://www.trytoprogram.com/c-programming/) was first introduced by Denis Ritchie at the AT &T’s Bell Laboratories USA in 1972 and was implemented for the first time in DEC PDP-11 computer. Denise Ritchie used the concepts of BCPL and B to develop C and added data typing and some other powerful features.

Shortly thereafter, he began work on "C with Classes", which as the name implies was meant to be a superset of the C language. His goal was to add object-oriented programming into the C language, which was and still is a language well-respected for its portability without sacrificing speed or low-level functionality. His language included [classes](http://www.cplusplus.com/doc/tutorial/classes/), basic [inheritance](http://www.cplusplus.com/doc/tutorial/inheritance/#inheritance), [inlining](http://www.cplusplus.com/doc/tutorial/functions2/#inline), [default function arguments](http://www.cplusplus.com/doc/tutorial/functions2/#default_values), and strong type checking in addition to all the features of the C language.

**尝试：**

在C语言的基础上，增加了“Class”这一语言特性，他想要的目标：既要有面向对象编程范式，同时还不能以有损C语言的速度优势以及底层操作能力。这个奠定了C++语言未来尝试扩展的方向。



The first C with Classes compiler was called **Cfront**, which was derived from a C compiler called CPre. It was a program designed to translate C with Classes code to ordinary C. A rather interesting point worth noting is that Cfront was written mostly in C with Classes, making it a self-hosting compiler (a compiler that can compile itself). Cfront would later be abandoned in 1993 after it became difficult to integrate new features into it, namely C++ [exceptions](http://www.cplusplus.com/doc/tutorial/exceptions/). Nonetheless, Cfront made a huge impact on the implementations of future compilers and on the Unix operating system.

In 1983, the name of the language was changed from C with Classes to C++. The ++ operator in the C language is an operator for incrementing a variable, which gives some insight into how Stroustrup regarded the language. Many new features were added around this time, the most notable of which are [virtual functions](http://www.cplusplus.com/doc/tutorial/polymorphism/#virtual), [function overloading](http://www.cplusplus.com/doc/tutorial/functions2/#function_overload), references with the & symbol, the const keyword, and single-line comments using two forward slashes (which is a feature taken from the language BCPL).

In 1985, Stroustrup's reference to the language entitled *The C++ Programming Language* was published. That same year, C++ was implemented as a commercial product. The language was not officially standardized yet, making the book a very important reference. The language was updated again in 1989 to include protected and static members, as well as inheritance from several classes.

In 1990, *The Annotated C++ Reference Manual* was released. The same year, Borland's Turbo C++ compiler would be released as a commercial product. Turbo C++ added a plethora of additional libraries which would have a considerable impact on C++'s development. Although Turbo C++'s last stable release was in 2006, the compiler is still widely used.

In 1998, the C++ standards committee published the first international standard for [C++ ISO/IEC 14882:1998](http://www.iso.org/iso/catalogue_detail.htm?csnumber=25845), which would be informally known as C++98. *The Annotated C++ Reference Manual* was said to be a large influence in the development of the standard. [The Standard Template Library](http://www.cplusplus.com/reference/stl/), which began its conceptual development in 1979, was also included. In 2003, the committee responded to multiple problems that were reported with their 1998 standard, and revised it accordingly. The changed language was dubbed [C++03](http://www.iso.org/iso/catalogue_detail.htm?csnumber=38110).

In 2005, the C++ standards committee released a technical report (dubbed TR1) detailing various features they were planning to add to the latest C++ standard. The new standard was informally dubbed C++0x as it was expected to be released sometime before the end of the first decade. Ironically, however, the new standard would not be released until mid-2011. Several technical reports were released up until then, and some compilers began adding experimental support for the new features.

In mid-2011, [the new C++ standard](http://www.iso.org/iso/iso_catalogue/catalogue_tc/catalogue_detail.htm?csnumber=50372) (dubbed C++11) was finished. The [Boost library project](http://www.boost.org/) made a considerable impact on the new standard, and some of the new modules were derived directly from the corresponding Boost libraries. Some of the new features included regular expression support (details on regular expressions may be found [here](http://www.regular-expressions.info/)), a comprehensive randomization library, a new C++ time library, atomics support, a standard threading library (which up until 2011 both C and C++ were lacking), a new [for loop](http://www.cplusplus.com/doc/tutorial/control/#for) syntax providing functionality similar to foreach loops in certain other languages, the auto keyword, new container classes, better support for unions and array-initialization lists, and variadic templates.



Written by [Albatross](https://www.cplusplus.com/user/N17f92yv/).

