/*=============================================================================
#     FileName: 9-chll.c
#         Desc: staff 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-10-01 00:46:03
#      History:
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

#define NAMESTRLEN 40
#define MAXSUBJECTS 8

typedef char namestr[NAMESTRLEN+1];

typedef struct {
    namestr given, others, family;
} fullname_t;

typedef struct {
    int yy,mm,dd;
} date_t;

typedef struct {
    int subjectcode;
    date_t enrolled;
    int status;
    int finalmark;
} subject_t;

typedef struct {
    fullname_t name;
    int employeenumber;
    date_t dob;
    date_t datecommenced;
    int status;
    int annualsalary;
} staff_t;

typedef struct {
    fullname_t name;
    int studentnumber;
    date_t dob;
    int nsubjects;
    subject_t subjects[MAXSUBJECTS];
} student_t;


void
swap_staff(staff_t *s1, staff_t *s2) {
    staff_t temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void 
sort_staff_by_number(staff_t *list, int nstaff) {
    /*linear sort*/
    int i, j;

    for(i=1; i<nstaff; i++) {
        for(j=i-1; j>=0 && list[j].employeenumber > list[j+1].employeenumber;
                j--) {
            swap_staff(list+j, list+j+1);
        }
    }
}
