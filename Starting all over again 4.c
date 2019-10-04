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
        float credit;
        float total_classes_in_week;
        //struct teacher course_teacher[20];
    } course[20];


    struct teacher
    {
        int id;
        char name[1000];
        float total_credit_taken;
        int total_course;
        int course_id[50];
        //char course_code[1000][1000];
        int dontpref[2];
        float total_classes_in_week;
    } teacher[20];

    struct weekday
    {
        char name[1000];
        int dontpref[3];
        int slot[7];
        struct teacher assigned_teacher[20];
        int total_classes;
        int assigned_teacher_id[7];

    } weekday[5];



    struct total
    {
        int theory_course;
        int prac_course;
        int all_course;
        int teacher;
        float classes_in_week_altogether;
        int classes_in_day;
    } total;


    int i,j,k,l,m,q;

    int theory_course,prac_course;

    float Allot_classes_for_course(float credit);
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


    strcpy(weekday[0].name,"Monday");
    strcpy(weekday[1].name,"Tuesday");
    strcpy(weekday[2].name,"Wednesday");
    strcpy(weekday[3].name,"Thursday");
    strcpy(weekday[4].name,"Friday");


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
        scanf("%f",&course[i].credit);
        course[i].total_classes_in_week=Allot_classes_for_course(course[i].credit);

    }

    for(i=0; i<all_course; i++)
    {
        printf("%s has %.2f credits\nSo it will be needing %.1f classes\n",course[i].name, course[i].credit,course[i].total_classes_in_week);
    }

    for(i=0; i<all_course; i++)
    {
        total.classes_in_week_altogether=course[i].total_classes_in_week+total.classes_in_week_altogether;
    }

    total.classes_in_week_altogether=ceil(total.classes_in_week_altogether);
    printf("There'll be total %.2f classes altogether in a week\n",total.classes_in_week_altogether);

    total.classes_in_day=total.classes_in_week_altogether/5;
    total.classes_in_day=ceil(total.classes_in_day);

    printf("There'll be %d classes in a single day\n",total.classes_in_day);

    for(i=0; i<5; i++)
    {
        weekday[i].total_classes=total.classes_in_day;
    }

    printf("How many teachers?\n");
    scanf("%d",&total.teacher);
    for(i=0; i<total.teacher; i++)
    {
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
        }
        teacher[i].total_classes_in_week=ceil(teacher[i].total_classes_in_week);
    }


    for(i=0; i<total.teacher; i++)
    {
        printf("\nTeacher with id %d will teach:",i);
        for(j=0; j<teacher[i].total_course; j++)
        {
            printf("\n%s",course[teacher[i].course_id[j]-1].name);
            printf("Total classes for this teacher %.2f\n",teacher[i].total_classes_in_week);
            //strcpy(teacher[i].course_code[j],course[teacher[i].course_id[j]-1].name);
            //printf("\n%s",teacher[i].course_code[j]);
        }
    }

    int day_slot=0;
    int whichday=0;
    for(i=0; i<total.teacher; i++)
    {

        if(whichday<5)
        {
            for(k=0; k<teacher[i].total_classes_in_week; k++)

            {
                if(whichday>4)
                {
                    whichday=0;
                    day_slot++;
                }
                weekday[whichday].assigned_teacher_id[day_slot]=i;
                printf("%d day=%d slot=%d\n",weekday[whichday].assigned_teacher_id[day_slot],whichday,day_slot);
                whichday++;
            }
        }
    }

    for(i=0; i<5; i++)
    {
        printf("%s:\t",weekday[i].name);
        if(i==0 || i==4)
        {
            printf("\t");
        }
        for(j=0; j<total.classes_in_day; j++)
        {
            printf("%d\t",weekday[i].assigned_teacher_id[j]);
        }
        printf("\n");
    }

}

float Allot_classes_for_course(float credit)
{
    float total_classes_in_week;
    if(credit>2)
    {
        total_classes_in_week=2;
    }
    else if(credit>=1 && credit<=2)
    {
        total_classes_in_week=1;
    }
    else if(credit<1)
    {
        total_classes_in_week=0.5;
    }
    return total_classes_in_week;
}


/*
File3.txt
6
5
3
3
3
4
3
2
1.5
0.75
0.75
0.75
1
6
2
1 2
2
3 4
2
5 6
2
7 8
2
9 10
1
11
*/
