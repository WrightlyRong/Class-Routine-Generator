NOTE: I wanted to keep this as the journey I had gone through while writing this code. Hence I still kept the part that were later removed.
And added bunch of other thing so I won’t get bored the next time I go through this.
Assumptions:
1.	No room deficiency.
2.	All students of one section fill in one room for theory classes.
3.	Half students of one section fill in one room for practical classes.
4.	Sections=2;
5.	Weekdays=5;
6.	Total credit 1 teacher can take=12
7.	Number of classes=credits
8.	Credits will be integers
Algorithm:
1.	Names of input and output files are taken.
2.	Ask how many theory courses.
            Scan name of theory courses (from file)
            Scan credits of theory courses (Not from file)
3.	Ask how many practical courses.
        Scan name of practical courses (from file)
             Scan credits of practical courses (Not from file)
4.	Ask how many teachers.
For that many teachers, scan how many courses will each teacher take.
(Note that if he takes 1 course, it will be for both sections.
Hence 1 single teacher can take up to 2 courses with 3 credits
maximum (2 courses*3 credits*2 sections=12). While taking these courses as inputs, calculate total credits for that teacher so that it doesn’t exceed max level.)

5.	Assign how many classes will each course need according to their credits.
(more than 2 credits, 2 classes)
(1 to 2 credits, 1 class)
(less than 1 credit, biweekly classes)
[Changed]
Now: Number of classes in a week = credits
Credits will be integers
6.	Create new arrays to store the courses according to their number of classes in a week.
7.	Calculate total number of classes needed in a week [Changed]
Divide it by 5. Find number of classes needed in each weekday.
Assign classes for that many times on each day. Assigning process first day [0], then day [1] … And also for the number of classes for each course. Like if math has 2 classes, put 1st math class on day [0] and then 2nd math class on day [1]. 

[Note store courses by the teacher ID. Like if a teacher takes physics and math then, teacher [0][0] =math, 
teacher [0][1] =physics. That way we can check for the same slot for 2 sections, whether they clash or not. Like if routine [0][0][0] is teacher [0][0], then routine [1][0][0] cannot be teacher [0][1].
In routine [0][0][0], 1st 0 means section A, 2nd 0 means Monday, 3rd 0 means 1st period. So routine [1][0][0] means section B, Monday, 1st period. And teacher [0][0] means 1st course taken by teacher 0 and teacher [0][1] means 2nd course taken by teacher 0.]
Since number of classes is equal to the course credits, this portion is no longer needed.

8.	Consider 2 biweekly classes as 1 weekly class and while printing print an / between those 2 classes.
This is done to make the calculations easier and smooth.
[Changed]
For the same reason as 6.

9.	Use functions to calculate, assign and print. And also for swapping if we include that.
10.	Nope, not explaining the part where the actual routine is created. Too lengthy and time consuming. And I’m tired right now.

11.	Create course (id, code, name, credit, total classes in week, teacher), teacher (id, name, total taken credit, total course, course ID, course code, dontpref, total classes in week), weekday (dontpref, slot, assigned teacher, total classes), total (theory course, practical course, all course, teacher, classes in week, classes in day) structures. [Slight modification has been done here as well]
Fun fact: You cannot call a structure in another structure if that structure calls such a structure which calls the original structure.




For the USER:
1.	In the file, at first write the name of the theory courses. And then the name of the practical courses.


WHAT STILL NEEDS TO BE DONE:
•	Fix the problem for printing the course names. It seems that it is stored properly [or is it?] but when tried to print all together it doesn’t print what it’s supposed to.
•	Add that dontpref part if we still get more time. Or you can always modify it later.
 
