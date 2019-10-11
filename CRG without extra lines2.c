#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

int main()
{
    struct course
    {
        int id;
        char code[1000];
        char name[1000];
        int credit;
        int total_classes_in_week;
    } course[20];


    struct teacher
    {
        int id;
        char name[1000];
        int total_credit_taken;
        int total_course;
        int course_id[50];
        int total_classes_in_week;
    } teacher[20];

    struct weekday
    {
        char name[1000];
        int slot[9];
        struct teacher assigned_teacher[20];
        int total_classes;
        int assigned_teacher_id[9];
        struct course assigned_course[20];

    } weekday[7];



    struct total
    {
        int weekday_count;
        int theory_course;
        int prac_course;
        int all_course;
        int credit_limit;
        int teacher;
        float classes_in_week_altogether;
        float classes_in_day_in_float;
        int classes_in_day;
    } total;

    struct section
    {
        char name[1000];
        struct weekday section_weekday[5];
    } section[3];


    int i,j,k,l,m,q;

    int theory_course,prac_course;
    total.credit_limit=12;
    total.weekday_count=5;


    char ch, file_name[25];
    FILE *fp;
    printf("In which file is the name of the courses?\n");
    gets(file_name);
    fp = fopen(file_name, "r");

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    int z=0,zz=0;
    for ( ; ; )
    {
        i = fgetc(fp);

        if (i == EOF)   break;
        else
        {
            while (i != 10)
            {
                course[z].name[zz] = i;
                zz++;
                i = fgetc(fp);
                if (i == EOF)   break;
            }
            course[z].name[zz]=NULL;
            zz=0;
            z++;
        }
    }

    fclose(fp);

    FILE *fpprint;
    char file_name2[25];
    printf("In which file will the routine be printed?\n");
    gets(file_name2);
    fpprint=fopen(file_name2, "w");


    strcpy(weekday[0].name,"Monday");
    strcpy(weekday[1].name,"Tuesday");
    strcpy(weekday[2].name,"Wednesday");
    strcpy(weekday[3].name,"Thursday");
    strcpy(weekday[4].name,"Friday");
    strcpy(weekday[5].name,"Saturday");
    strcpy(weekday[6].name,"Sunday");

    strcpy(section[0].name,"A");
    strcpy(section[1].name,"B");


    printf("How many theory courses are there?\n");
    scanf("%d",&theory_course);
    printf("How many practical courses are there?\n");
    scanf("%d",&prac_course);

    int all_course=theory_course+prac_course;

    printf("Theory courses are:\n");
    for(i=0; i<theory_course; i++)
    {
        printf("%s\n",course[i].name);
    }

    printf("\nPractical courses are:\n");
    for(i=0; i<prac_course; i++)
    {
        printf("%s\n",course[i+theory_course].name);
    }

    for(i=0; i<all_course; i++)
    {
        printf("\nWhat is the credit for %s?\n",course[i].name);
        scanf("%d",&course[i].credit);
        course[i].total_classes_in_week=course[i].credit;

    }

    /*for(i=0; i<all_course; i++)
    {
        printf("%s has %d credits\nSo it will be needing %d classes\n",course[i].name, course[i].credit,course[i].total_classes_in_week);
    }*/

    for(i=0; i<all_course; i++)
    {
        total.classes_in_week_altogether=course[i].total_classes_in_week+total.classes_in_week_altogether;
    }

    printf("There'll be total %.0f classes altogether in a week\n",total.classes_in_week_altogether);

    total.classes_in_day_in_float=total.classes_in_week_altogether/total.weekday_count;
    //printf("total.classes_in_day_in_float is %f",total.classes_in_day_in_float);

    total.classes_in_day=ceil(total.classes_in_day_in_float);

    //printf("There'll be max %d classes in a single day\n",total.classes_in_day);

    int day_variable1=0;
    int chosen_option=1;

    if(day_variable1<total.classes_in_week_altogether-((total.classes_in_day-1)*total.weekday_count))
    {
        int chosen_weekday;
        printf("There'll be at least %d classes in a day. And on %.0f days there has to be %d classes.\n",total.classes_in_day-1,total.classes_in_week_altogether-((total.classes_in_day-1)*total.weekday_count),total.classes_in_day);
        printf("You can choose which days of the week you would like to have those extra classes.\nOr you can choose the default option.\n");
        printf("In the default option the extra classes will be given starting from the weekdays.\nThat is the first extra class will be on Monday, the second one on Tuesday and so on\n");
        printf("Would you like to choose the default option?\n");
        printf("1.Yes\n2.No\n");
        scanf("%d",&chosen_option);
        if(chosen_option==1)
        {
            printf("You have chosen the default option.\n");
        }
        else if(chosen_option==2)
        {
            for(i=0; i<total.weekday_count; i++)
            {
                weekday[i].total_classes=total.classes_in_day-1;
            }
            printf("On which of the following days would you like to have %.0f classes?\n",total.classes_in_week_altogether-((total.classes_in_day-1)*total.weekday_count));
            printf("1.Monday\n2.Tuesday\n3.Wednesday\n4.Thursday\n5.Friday\n");
            for(i=0; i<total.classes_in_week_altogether-((total.classes_in_day-1)*total.weekday_count); i++)
            {
                scanf("%d",&chosen_weekday);
                weekday[chosen_weekday-1].total_classes++;
            }
        }
    }

    int day_variable2=0;
    if(chosen_option==1)
    {
        for(i=0; i<total.weekday_count; i++)
        {
            weekday[i].total_classes=total.classes_in_day-1;
            if(day_variable2<total.classes_in_week_altogether-((total.classes_in_day-1)*total.weekday_count))
            {
                weekday[day_variable2].total_classes++;
                day_variable2++;
            }
        }
    }

    /*for(i=0; i<total.weekday_count; i++)
    {
        printf("%s has %d classes\n",weekday[i].name,weekday[i].total_classes);
    }*/

    printf("How many teachers?\n");
    scanf("%d",&total.teacher);
    for(i=0; i<total.teacher; i++)
    {
Givechoice:
        printf("How many courses will teacher with id %d teach?\n",i);
        scanf("%d",&teacher[i].total_course);
        printf("What is that course(s)?\n");
        for(k=0; k<all_course; k++)
        {
            printf("%d. %s\n",k+1,course[k].name);
        }
        for(j=0; j<teacher[i].total_course; j++)
        {
            scanf("%d",&teacher[i].course_id[j]);
            teacher[i].total_classes_in_week=teacher[i].total_classes_in_week+course[teacher[i].course_id[j]-1].total_classes_in_week;
            if(teacher[i].total_classes_in_week>(total.credit_limit/2))
            {
                printf("Sorry, this crosses the credit limit. Please give your choice again\n");
                teacher[i].total_classes_in_week=0;
                goto Givechoice;
            }
        }
    }


    for(i=0; i<total.teacher; i++)
    {
        printf("\nTeacher with ID %d will teach:\n",i);
        for(j=0; j<teacher[i].total_course; j++)
        {
            printf("%s\n",course[teacher[i].course_id[j]-1].name);
            //strcpy(teacher[i].course_code[j],course[teacher[i].course_id[j]-1].name);
            //printf("\n%s",teacher[i].course_code[j]);
        }
        printf("Total classes for this teacher %d\n",teacher[i].total_classes_in_week);
    }

    int day_slot=0;
    int whichday=0;
    int section_variable;
    for(section_variable=0; section_variable<1; section_variable++)
    {
        for(i=0; i<total.teacher; i++)
        {

            for(k=0; k<teacher[i].total_classes_in_week; k++)

            {
                if(whichday>total.weekday_count-1)
                {
                    whichday=0;
                    day_slot++;
                }
                if(day_slot<weekday[whichday].total_classes)
                {
                    section[section_variable].section_weekday[whichday].assigned_teacher_id[day_slot]=i;
                    //printf("%d day=%d slot=%d\n",section[section_variable].section_weekday[whichday].assigned_teacher_id[day_slot],whichday,day_slot);

                    whichday++;
                }
                else
                {
                    whichday++;
                    k--;
                }
            }

        }
    }

    int teacher_course_variable=0;

    for(section_variable=0; section_variable<1; section_variable++)
    {
        whichday=0;
        day_slot=0;
        for(i=0; i<total.teacher; i++)
        {
            j=0;
            for(l=0; l<teacher[i].total_course; l++)
            {
                for(k=0; k<course[teacher[i].course_id[j]-1].total_classes_in_week; k++)
                {
                    if(whichday>total.weekday_count-1)
                    {
                        whichday=0;
                        day_slot++;
                    }
                    if(day_slot<weekday[whichday].total_classes)
                    {
                        strcpy(section[section_variable].section_weekday[whichday].assigned_course[day_slot].name,course[teacher[i].course_id[j]-1].name);
                        //printf("%s is at section[%d].section_weekday[%d].assigned_course[%d].name",section[section_variable].section_weekday[whichday].assigned_course[day_slot].name,section_variable,whichday,day_slot);
                        //printf("%d day=%d slot=%d\n",section[section_variable].section_weekday[whichday].assigned_teacher_id[day_slot],whichday,day_slot);
                        whichday++;
                        //printf("\n");
                    }
                    else
                    {
                        whichday++;
                        k--;
                    }
                }
                j++;
            }
        }
    }

    for(i=0; i<total.weekday_count; i++)
    {
        for(j=0; j<weekday[i].total_classes; j++)
        {
            if(weekday[i].total_classes>2)
            {
                if(j==0)
                {
                    section[1].section_weekday[i].assigned_teacher_id[j]=section[0].section_weekday[i].assigned_teacher_id[weekday[i].total_classes-2];
                    //printf("Made this far111\n");
                }
                else if(j==1)
                {
                    section[1].section_weekday[i].assigned_teacher_id[j]=section[0].section_weekday[i].assigned_teacher_id[weekday[i].total_classes-1];
                    //printf("Made this far112\n");
                }
                else
                {
                    section[1].section_weekday[i].assigned_teacher_id[j]=section[0].section_weekday[i].assigned_teacher_id[j-2];
                    //printf("Made this far113\n");
                }
            }
            else
            {
                if(j==0)
                {
                    section[1].section_weekday[i].assigned_teacher_id[j]=section[0].section_weekday[i].assigned_teacher_id[1];
                    //printf("Made this far121\n");
                }
                else if(j==1)
                {
                    section[1].section_weekday[i].assigned_teacher_id[j]=section[0].section_weekday[i].assigned_teacher_id[0];
                    //printf("Made this far122\n");
                }
            }
        }
    }


    for(i=0; i<total.weekday_count; i++)
    {
        for(j=0; j<weekday[i].total_classes; j++)
        {
            if(weekday[i].total_classes>2)
            {
                if(j==0)
                {
                    strcpy(section[1].section_weekday[i].assigned_course[j].name,section[0].section_weekday[i].assigned_course[weekday[i].total_classes-2].name);
                    //printf("Made this far212\n");
                }
                else if(j==1)
                {
                    strcpy(section[1].section_weekday[i].assigned_course[j].name,section[0].section_weekday[i].assigned_course[weekday[i].total_classes-1].name);
                    //printf("Made this far213\n");
                }
                else
                {
                    strcpy(section[1].section_weekday[i].assigned_course[j].name,section[0].section_weekday[i].assigned_course[j-2].name);
                    //printf("Made this far214\n");
                }
            }
            else
            {
                if(j==0)
                {
                    strcpy(section[1].section_weekday[i].assigned_course[j].name,section[0].section_weekday[i].assigned_course[1].name);
                    //printf("Made this far221\n");
                }
                else if(j==1)
                {
                    strcpy(section[1].section_weekday[i].assigned_course[j].name,section[0].section_weekday[i].assigned_course[0].name);
                    //printf("Made this far222\n");
                }
            }
        }
    }



    int class_count=0;


    printf("\n\n\nClass Routine with teacher ID\n");
    for(section_variable=0; section_variable<2; section_variable++)
    {
        printf("\nSECTION %s:\n",section[section_variable].name);
        for(i=0; i<total.weekday_count; i++)
        {
            printf("%s:\t",weekday[i].name);
            if(i==0 || i==4)
            {
                printf("\t");
            }
            for(j=0; j<weekday[i].total_classes; j++)
            {
                if(class_count<total.classes_in_week_altogether+1)
                {
                    printf("%d\t",section[section_variable].section_weekday[i].assigned_teacher_id[j]);
                    class_count++;
                }
            }
            printf("\n");
        }
        class_count=0;
    }


    fprintf(fpprint,"Class Routine with teacher ID\n");
    for(section_variable=0; section_variable<2; section_variable++)
    {
        fprintf(fpprint,"\nSECTION %s:\n",section[section_variable].name);
        for(i=0; i<5; i++)
        {
            fprintf(fpprint,"%s:\t",weekday[i].name);
            if(i==0 || i==4 || i==1 || i==3)
            {
                fprintf(fpprint,"\t");
            }
            for(j=0; j<weekday[i].total_classes; j++)
            {
                if(class_count<total.classes_in_week_altogether+1)
                {
                    fprintf(fpprint,"%d\t",section[section_variable].section_weekday[i].assigned_teacher_id[j]);
                    class_count++;
                }
            }
            fprintf(fpprint,"\n");
        }
        class_count=0;
    }


    printf("\n\n\nClass Routine with courses:\n");
    for(section_variable=0; section_variable<2; section_variable++)
    {
        printf("\nSECTION %s:\n",section[section_variable].name);
        for(i=0; i<total.weekday_count; i++)
        {
            printf("%s:\t",weekday[i].name);
            if(i==0 || i==4)
            {
                printf("\t");
            }
            for(j=0; j<weekday[i].total_classes; j++)
            {
                if(class_count<total.classes_in_week_altogether+1)
                {
                    printf("%s\t",section[section_variable].section_weekday[i].assigned_course[j].name);
                    class_count++;
                }
            }
            printf("\n");
        }
        class_count=0;
    }


    fprintf(fpprint,"\n\n\nClass Routine with courses:\n");
    for(section_variable=0; section_variable<2; section_variable++)
    {
        fprintf(fpprint,"\nSECTION %s:\n",section[section_variable].name);
        for(i=0; i<total.weekday_count; i++)
        {
            fprintf(fpprint,"%s:\t",weekday[i].name);
            if(i==0 || i==4 || i==1 ||i ==3)
            {
                fprintf(fpprint,"\t");
            }
            for(j=0; j<weekday[i].total_classes; j++)
            {
                if(class_count<total.classes_in_week_altogether+1)
                {
                    fprintf(fpprint,"\t%s\t",section[section_variable].section_weekday[i].assigned_course[j].name);
                    class_count++;
                }
            }
            fprintf(fpprint,"\n");
        }
        class_count=0;
    }

    fclose (fpprint);

}


/*
Experiment 1:

File1.txt
File2.txt
5
5
3
3
4
3
2
1
1
1
1
1
4
2
1 2
1
3
2
4 5
5
6 7 8 9 10



Experiment 2:

File3.txt
File2.txt
6
5
3
3
3
4
3
2
1
1
1
1
1
6
2
1 2
2
3 4
1
4
2
3 5
2
6 7
2
8 9
2
10 11



Experiment 3:

File3.txt
File2.txt
6
5
2
2
2
2
2
2
2
2
2
2
2
11
1
1
1
2
1
3
1
4
1
5
1
6
1
7
1
8
1
9
1
10
1
11



Experiment 4:

File3.txt
File2.txt
6
5
1
1
1
1
1
1
1
1
1
1
1
11
1
1
1
2
1
3
1
4
1
5
1
6
1
7
1
8
1
9
1
10
1
11



Experiment 5:

File3.txt
File2.txt
6
5
1
1
1
1
1
1
1
1
1
1
1
2
6
1 2 3 4 5 6
5
7 8 9 10 11


Experiment 8:

File3.txt
File2.txt
6
5
3
3
3
4
3
2
1
1
1
1
1
2
3 4 5
6
2
1 2
2
3 4
1
4
2
3 5
2
6 7
2
8 9
2
10 11
*/
