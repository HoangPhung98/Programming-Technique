#include<iostream>
#include<string>
using namespace std;
int monthArr[14];
int d,m,y;
struct Date{
	int day;
	int month;
	int year;
}date, date2, sumDate, subDate;
void scanDate(){
	scanf("%d",&d);
	scanf("%d",&m);
	scanf("%d",&y);
}

void printDate(Date date){
	printf("%5d / %d / %d \n", date.day, date.month, date.year);
}
void setDate(Date &date,int day, int month, int year){
	date.day = day;
	date.month = month;
	date.year = year;
	printf("* Set date: \n");
	printf("%5d / %d / %d \n", date.day, date.month, date.year);

}
void creatMonthArr(int monthArr[]){
	monthArr[1]=31;
	monthArr[2]=28;
	monthArr[3]=31;
	monthArr[4]=30;
	monthArr[5]=31;
	monthArr[6]=30;
	monthArr[7]=31;
	monthArr[8]=31;
	monthArr[9]=30;
	monthArr[10]=31;
	monthArr[11]=30;
	monthArr[12]=31; monthArr[13]=31;
}
long toNumberOfDay(Date date){
	long numberOfDay = 0;
	numberOfDay = (date.year - 1) * 365;
	for(int i=1; i< date.month; i++) numberOfDay += monthArr[i];
	numberOfDay+=date.day;
	return numberOfDay;
}
Date toDate(long numberOfDay){
	Date temp;
	temp.year = numberOfDay / 365 ;
	temp.month = 0;
	temp.day = 0;
	if(numberOfDay==0) return temp;
	
	numberOfDay %= 365;
	
	if(numberOfDay > 0){
		temp.month = 0;
		while(numberOfDay >= monthArr[temp.month+1]){
			temp.month++;
			numberOfDay -= monthArr[temp.month];
		}
		if(numberOfDay == 0){
			temp.day = monthArr[temp.month];
		}else{
			temp.day = numberOfDay;
			temp.month++;
		}
	}else{
		temp.month = 12;
		temp.day = 31;
	}
	
	return temp;
}

//****************Add
Date operator +(Date date1, Date date2){
	Date temp;
	int sumMonth, sumDay;
	//caculate year
	temp.year = date1.year + date2.year;
	//caculate month
	sumMonth = date1.month + date2.month;
	if(sumMonth>12){
		temp.year+=sumMonth/12;
		sumMonth%=12;
	}
	temp.month = sumMonth;
	//caculate day
	sumDay = date1.day + date2.day;
	if(sumDay > monthArr[temp.month] ){
		temp.month ++;
		    if(temp.month>12){
		    	temp.year++;
		    	temp.month = 1;
			}
		sumDay -= monthArr[temp.month];
	}
	temp.day = sumDay;
	return temp;
}
Date operator ++(Date &date, int){
	date.day ++;
	if(date.day>monthArr[date.month]){
		date.day = 1;
		if(date.month == 12){
			date.year ++;
			date.month = 1;
		}else{
			date.month ++;
		}
	}
	Date temp;
	temp = date;
	return temp;
}
Date& operator ++(Date &date){
	date.day ++;
	if(date.day>monthArr[date.month]){
		date.day = 1;
		if(date.month == 12){
			date.year ++;
			date.month = 1;
		}else{
			date.month ++;
		}
	}
	return date;
}
Date operator +=(Date &date, int days){
	//add year
	date.year += days / 365;
	days = days % 365;
	
	//add month
		/*gia su hôm nay là ngày 15/10/2016. days = 5 , ta cân cong them so days kia vào.
		  		days -= monthArr[date.month] - date.day;
		  		days = 5 - (31-15) = -10
		  		chua sang thang khac nen date.day += days, date.month khong thay doi.
		  		Muc dich: chuyen ngay bat dau tinh toan len ngay so 0 cua thang tiep theo
		*/
	days -= monthArr[date.month] - date.day;
	if(days <0){
		date.day += days;
		return date;
	}
	if(days == 0){
		date.day = monthArr[date.month];
		return date;
	}
	if(days > 0){
		date.day = 0;
		date.month ++;
		
		while(days >= monthArr[date.month]){
			days -= monthArr[date.month];
			
			if(date.month + 1 == 13 ){
				date.month = 1;
				date.year++;
			}else{
				date.month ++ ;
			}
		}
	}
	
	//add day
		/* them nhung ngay con thua*/
	date.day += days;
	return date;
}
//**************Add End />

//**************Sub
Date operator -(Date date1, Date date2){
	Date temp;
	long numberOfDay = toNumberOfDay(date1) - toNumberOfDay(date2);
	return toDate(numberOfDay);
}
Date operator --(Date &date, int){
	date.day --;
	if(date.day == 0){
		if(date.month == 1){
			date.year --;
			date.month = 12;
		}else{
			date.month --;
		}
		date.day = monthArr[date.month];

	}
	Date temp;
	temp = date;
	return temp;
}
Date& operator --(Date &date){
	date.day --;
	if(date.day == 0){
		if(date.month == 1){
			date.year --;
			date.month = 12;
		}else{
			date.month --;
		}
		date.day = 1;

	}
	return date;
}
Date operator -=(Date &date, int days){
	//add year
	date.year -= days / 365;
	days = days % 365;
	
	//sub month
		/*gia su hôm nay là ngày 15/10/2016. days = 5 , ta cân tru di so days kia vào.
		  		days -= date.day;
		  		days = 5 -15 = -10
		  		chua sang thang khac nen date.day -= days, date.month khong thay doi.
		  		Muc dich: chuyen ngay bat dau tinh toan len ngay so 0 cua thang truoc
		*/
	days -= date.day;
	if(days <0){
		date.day -= days;
		return date;
	}
	if(days == 0){
		date.month--;
		if(date.month == 0) date.month = 12;
		date.day = monthArr[date.month];
		return date;
	}
	if(days > 0){
		date.month --;
		
		while(days >= monthArr[date.month]){
			days -= monthArr[date.month];
			
			if(date.month - 1 == 0 ){
				date.month = 12;
				date.year--;
			}else{
				date.month -- ;
			}
		}
		
		date.day = monthArr[date.month];
	}
	
	//sub day
		/* tru nhung ngay con thua*/
	date.day -= days;
	return date;
}
//****************Sub end />
int main(){
	
	creatMonthArr(monthArr);
//	scanDate();
	
	
	date2.day = 9;
	date2.month = 9;
	date2.year = 2016;
	
	
	printf("===== TEST ADD DATE =====\n");
	setDate(date,15,10,2016);
	printDate(date2);
	sumDate = date + date2;
	printf("   sumDate: date + date2 =");
	printDate(sumDate);
	
	setDate(date,15,10,2016);
	date++;
	printf("   date++: ");
	printDate(date);
	
	setDate(date,15,10,2016);
	++date;
	printf("   ++date: ");
	printDate(date);

	setDate(date,15,10,2016);
	date+=151016;
	printf("   date+=151016: ");
	printDate(date);
	
	
	printf("===== TEST SUB DATE =====\n\n");
	setDate(date,9,9,3002);
	printDate(date2);
	subDate = date - date2;
	printf("   subDate: date - date2 =");
	printDate(subDate);
	
	setDate(date,15,10,2016);
	date--;
	printf("   date--: ");
	printDate(date);
	
	setDate(date,15,10,2016);
	--date;
	printf("   --date: ");
	printDate(date);
	
	setDate(date,13,7,2430);
	date-=151016;
	printf("   date-=151016: ");
	printDate(date);
}
