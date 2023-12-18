# MedianContainer

# Task:

Напишете структура данни, която поддържа две операции:
1. Добавяне на число към извадката.
2. Смятане на медианата на досега добавените числа.
Изисквания:
1. Написан е на C++ 14
2. Използва се CMake for build system
3. Разрешена е употребата на контейнери и алгоритми от стандартната библиотека
4. Добре структуриран код ( лесен за четене и разбиране )
5. Има автоматични тестове
6. Хостнат е в github.com (или bitbucket.com, или gitlab.com )
7. Операциите добавяне на число и смятане на медиана имат минимална алгоритмична сложност

# First Review Feedback:

The task doesn't specify which operation is more oftenly used.
We can solve a specific task better when we know the full requirements.
Solving it with a general purpose solution is not fun.

# Problems to solve

Create a container with:
1. Fast Add
2. Fast Median Calculation

Additional steps:
CMake project + Unit tests

# Thoughts:

Some kind of a mix?

1. Normal Array has constant access to members, so I can always access median.
Issue: It has limited memory so add it limited.

2. Extendable containers like vectors might work but too many vector resizes are not great either.

3. Something dynamic like a list to be able to add without issues.

4. List can't give us median easily. 

5. A hypothetical median pointer?

5. List size increse with lower numbers will move the median pointer left which means double linked list? so we can move left?

6. How about the add? n/2 isn't a fast enough. Binary add will make it logN is that enough?

7. Using std::set might solve all our problems?