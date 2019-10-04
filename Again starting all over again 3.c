//Allocate slots for teachers
//calculate course credit for each teacher so it doesn't cross max level

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
        //struct teacher course_teacher[20];
    } course[20];


    struct teacher
    {
        int id;
        char name[1000];
        int total_credit_taken;
        int total_course;
        int course_id[50];
        //char course_code[1000][1000];
        int dontpref[2];
        int total_classes_in_week;
        //int teaches_this_course_id[20];
        //char teaches_this_course_name[20][200];
    } teacher[20];

    struct weekday
    {
        char name[1000];
        int dontpref[3];
        int slot[7];
        struct teacher assigned_teacher[20];
        int total_classes;
        int assigned_teacher_id[7];
        struct course assigned_course[20];

    } weekday[5];



    struct total
    {
        int theory_course;
        int prac_course;
        int all_course;
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

    //float Allot_classes_for_course(float credit);
    int Swapfordontpref(totalweekdays,totalslotsperday,routine,dontpref,alreadyswap);


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
        printf("\nWhat is the credit for %s\n",course[i].name);
        scanf("%d",&course[i].credit);
        course[i].total_classes_in_week=course[i].credit;

    }

    for(i=0; i<all_course; i++)
    {
        printf("%s has %d credits\nSo it will be needing %d classes\n",course[i].name, course[i].credit,course[i].total_classes_in_week);
    }

    for(i=0; i<all_course; i++)
    {
        total.classes_in_week_altogether=course[i].total_classes_in_week+total.classes_in_week_altogether;
    }

    printf("There'll be total %f classes altogether in a week\n",total.classes_in_week_altogether);

    total.classes_in_day_in_float=total.classes_in_week_altogether/5;
    printf("total.classes_in_day_in_float is %f",total.classes_in_day_in_float);

    total.classes_in_day=ceil(total.classes_in_day_in_float);

    printf("There'll be max %d classes in a single day\n",total.classes_in_day);

    int day_variable=0;
    for(i=0; i<5; i++)
    {
        weekday[i].total_classes=total.classes_in_day-1;
        if(day_variable<total.classes_in_week_altogether-((total.classes_in_day-1)*5))
        {
            weekday[day_variable].total_classes++;
            day_variable++;
        }
    }

    for(i=0; i<5; i++)
    {
        printf("%s has %d classes\n",weekday[i].name,weekday[i].total_classes);
    }

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
        if(teacher[i].total_classes_in_week>6)
        {
            printf("Sorry, this crosses the credit limit. Please give your choice again\n");
            teacher[i].total_classes_in_week=0;
            goto Givechoice;
        }
        }
    }


    for(i=0; i<total.teacher; i++)
    {
        printf("\nTeacher with id %d will teach:",i);
        for(j=0; j<teacher[i].total_course; j++)
        {
            printf("\n%s",course[teacher[i].course_id[j]-1].name);
            printf("Total classes for this teacher %d\n",teacher[i].total_classes_in_week);
            //strcpy(teacher[i].course_code[j],course[teacher[i].course_id[j]-1].name);
            //printf("\n%s",teacher[i].course_code[j]);
        }
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
                if(whichday>4)
                {
                    whichday=0;
                    day_slot++;
                }
                section[section_variable].section_weekday[whichday].assigned_teacher_id[day_slot]=i;
                //printf("%d day=%d slot=%d\n",section[section_variable].section_weekday[whichday].assigned_teacher_id[day_slot],whichday,day_slot);
                whichday++;
            }

        }
    }

    int teacher_course_variable=0;

    for(section_variable=0; section_variable<1; section_variable++)
    {
        for(i=0; i<total.teacher; i++)
        {
            j=0;
            for(l=0; l<teacher[i].total_course; l++)
            {
                for(k=0; k<course[teacher[i].course_id[j]-1].total_classes_in_week; k++)
                {
                    if(whichday>4)
                    {
                        whichday=0;
                        day_slot++;
                    }
                    strcpy(section[section_variable].section_weekday[whichday].assigned_course[day_slot].name,course[teacher[i].course_id[j]-1].name);
                    printf("%s %s",section[section_variable].section_weekday[whichday].assigned_course[day_slot].name,course[teacher[i].course_id[j]-1].name);
                    //printf("%d day=%d slot=%d\n",section[section_variable].section_weekday[whichday].assigned_teacher_id[day_slot],whichday,day_slot);
                    whichday++;
                    printf("\n");
                }
                j++;
            }
        }
    }

    for(i=0; i<5; i++)
    {
        for(j=0; j<weekday[i].total_classes; j++)
        {
            if(j==0)
            {
                section[1].section_weekday[i].assigned_teacher_id[j]=section[0].section_weekday[i].assigned_teacher_id[weekday[i].total_classes-2];
                printf("Made this far1\n");
            }
            else if(j==1)
            {
                section[1].section_weekday[i].assigned_teacher_id[j]=section[0].section_weekday[i].assigned_teacher_id[weekday[i].total_classes-1];
                printf("Made this far2\n");
            }
            else
            {
                section[1].section_weekday[i].assigned_teacher_id[j]=section[0].section_weekday[i].assigned_teacher_id[j-2];
                printf("Made this far3\n");
            }
        }
    }


    int class_count=0;

    for(section_variable=0; section_variable<2; section_variable++)
    {
        printf("\nSECTION %s:\n",section[section_variable].name);
        for(i=0; i<5; i++)
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

    for(section_variable=0; section_variable<2; section_variable++)
    {
        fprintf(fpprint,"\nSECTION %s:\n",section[section_variable].name);
        for(i=0; i<5; i++)
        {
            fprintf(fpprint,"%s:\t",weekday[i].name);
            if(i==0 || i==4)
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

    for(section_variable=0; section_variable<2; section_variable++)
    {
        printf("\nSECTION %s:\n",section[section_variable].name);
        for(i=0; i<5; i++)
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

    for(section_variable=0; section_variable<2; section_variable++)
    {
        fprintf(fpprint,"\nSECTION %s:\n",section[section_variable].name);
        for(i=0; i<5; i++)
        {
            fprintf(fpprint,"%s:\t",weekday[i].name);
            if(i==0 || i==4)
            {
                fprintf(fpprint,"\t");
            }
            for(j=0; j<weekday[i].total_classes; j++)
            {
                if(class_count<total.classes_in_week_altogether+1)
                {
                    fprintf(fpprint,"%s\t",section[section_variable].section_weekday[i].assigned_course[j].name);
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
*/
