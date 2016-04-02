/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define year 365
#define month 30
int monDiff(struct node *date1, struct node *date2);
int yearDiff(struct node *date1, struct node *date2);
struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head){
	if (date1head&&date2head){
		struct node *temp1, *temp2;
		int flag = 0;
		int totalDays = 0;
		temp1 = date1head;
		temp2 = date2head;
		for (int i = 0; i < 4; i++){
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		int mon, day;
		int years = yearDiff(temp1, temp2);
		if (years < 0){
			flag = 1;
			years *= -1;
		}
		totalDays = year*years;
		temp1 = date1head;
		temp2 = date2head;
		for (int i = 0; i < 2; i++){
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		mon = monDiff(temp1, temp2);
		if ((totalDays == 0)&&(mon<0)){
			mon *= -1;
			flag = 1;
		}
		else  if ((mon < 0) && flag){
			mon *= -1;
		}
		else if (!flag && (mon>0)){
			mon *= -1;
		}
		totalDays += month*mon;
		temp1 = date1head;
		temp2 = date2head;
		day = monDiff(temp1, temp2);
		if ((day < 0) && flag){
			day *= -1;
		}
		else if (!flag && (day>0)){
			day *= -1;
		}
		if ((totalDays == 0) && (day < 0))
			day *= -1;
		totalDays += day;
		return totalDays - 1;
	}
	return -1;
}
int yearDiff(struct node *date1, struct node *date2){
	int d1=0, d2=0;
	for (int i = 0; i < 4; i++){
		d1 = d1 * 10 + date1->data;
		d2 = d2 * 10 + date2->data;
		date1 = date1->next;
		date2 = date2->next;
	}
	return d1 - d2;
}
int monDiff(struct node *date1, struct node *date2){
	int d1 = 0, d2 = 0;
	for (int i = 0; i < 2; i++){
		d1 = d1 * 10 + date1->data;
		d2 = d2 * 10 + date2->data;
		date1 = date1->next;
		date2 = date2->next;
	}
	return d1 - d2;
}