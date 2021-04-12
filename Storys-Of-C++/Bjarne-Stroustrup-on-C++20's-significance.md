## Bjarne Stroustrup on C++20's significance

By Blog Staff | Feb 21, 2020 11:26 AM | Tags: *None*

---

摘抄， 我觉得很有意义，顺着这篇文章对C++再一次进行回顾，看看👀哪些地方熟悉，哪些还未曾触及。



The following are notes from Bjarne Stroustrup, regarding the completion of C++20 on Saturday and summarizing his comments to the committee in the room:

> After the 79-0 vote deeming C++20 done on February 15, 2020 in Prague, I made a few comments to emphasize the significance of the event. I got to the lectern just after Herb Sutter had shown photos of the C++ standards committee members at the first meeting and the meetings that voted for the C++11, C++14, C++17, and C++20 standards. I was in all of those, so was Mike Miller from EDG and chair of the Core Working Group. We were the only ones in all photos. This is roughly what I said:
>
> This is a historical event:
>
> - 30 years of C++ standardization.
> - 40 years of C++.
> - C++20 is the 6th standard, the 3rd major standard; by “major” I mean “changes the way people think.”
> - This is something like the 75th meeting; I have been at about 70 of those.
>
> I’d like to add a personal note. For me, C++20 is special because it has essentially all from “The Design and Evolution” (1994). In particular, it has concepts, modules, and coroutines:
>
> - Concepts were not in D&E, but there were three pages of apologies for not having them. Then, neither I nor anyone else know how to design and implement them sufficiently well.
> - Modules were just a dream then, but they were specifically mentioned – I dreamed of a day where we could finally eliminate the preprocessor.
> - Coroutines were the  bread and butter for C++ during the first 10 years; they were missing in most other languages. I was sore having lost them to implementation problems on SPARC architecture.
>
> In addition, we get improved concurrency and a library with ranges, dates, and span.
>
> We (the C++ standards committee members) must be careful and responsible; we serve a huge community:
>
> - Serve the community at large, rather than just experts – “keep simple things simple.”
> - Be careful, the world changes; what seems essential or fashionable today may not be good in the longer term.
> - Be pragmatic, not doctrinaire; pragmatic and principled.
>
> This has guided the development of C++ so far. No, that’s not easy. We must balance many concerns. I suggest we:
>
> - Pursue the goal of a completely resource-safe and type-safe C++.
> - Support a wide variety of hardware well.
> - Maintain C++’s record of stability (compatibility) – “stability is a feature” – as much as makes sense.
>
> These aims have served C++ well throughout.
>
> I wonder who’ll be here in 30 years? That’ll be 2050.
>
> Thanks for listening. See you in Varna! (Varna is the location of the next ISO C++ Standards meeting).

\