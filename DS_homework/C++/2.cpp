#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int compare(string);
int shanghaitech(string,string,string);
int Gregorian(string,string,string);
int month_to_num(string);
int leap_year(int);
int Judge_leap_year(int);
int num_day_of_year(int);
int digit_sum(int);
int how_many_day(int,int);
int which_month(int);
int num_day_of_year(int);
int when_to_stopYEAR(int,int,int);
int when_to_stopMONTH(int,int,int,int);
string judge_month_name(int,int);
int main(int argc, char const *argv[]){
    using namespace std;
    int simb = compare(argv[1]);            //judge whether the form is shanghaitech or gregorian
    if (simb == 1)
        shanghaitech(argv[1],argv[2],argv[3]) ;      // change the form from geogorian to shanghaitech
    else
        Gregorian(argv[1],argv[2],argv[3]) ;        // change the form from shanghaitech to gregorian
}
int compare(string x){          //judge whether the form is shanghaitech or gregorian
    if (x == "Jan" || x == "Feb" || x == "Mar" || x == "Apr" || x == "May" || x == "Jun" || x == "Jul" || x == "Aug" || x == "Sep" || x == "Oct" || x == "Nov" || x == "Dec")
        return 1;
    else
        return 2;
}
int Gregorian(string month,string date,string year){
    using namespace std;
    return 0;
}
int shanghaitech(string month, string date, string year){
    using namespace std;
    int num_year = atoi(year.c_str()); // change the year from string to integer
    int num_date = atoi(date.c_str()); // change the date from string to integer
    int num_month;
	num_month = month_to_num(month);   // change the month from string to integer
    int num_leap_year = num_year / 4 - num_year / 100 + num_year / 400 - num_year / 1000; // compute how many leap year before the input year 
    int num_day1 = 365 * (num_year - 1) + num_leap_year; // compute the number of days before the year
    int num_day2 = 61 * ((num_month - 1) / 2);
    if ((num_month - 1) % 2 == 1)
            num_day2 = num_day2 + 31;
    else{
		if ((num_month - 1) > 8)
			num_day2 = num_day2 + 1;
    }
    if ((num_month - 1) >= 2){
        if (leap_year(num_year))
            num_day2 = num_day2 - 1;
        else    
            num_day2 = num_day2 - 2;  
    }
    int num_day = num_day1 + num_day2 + num_date - 1;        // compute the number of days in the year
	//cout << num_day << endl;
	int start_day[3] = { 1,1,1 };
	int order = 0;
	int tem_num_day = 0;
    while (when_to_stopYEAR(num_day,tem_num_day,start_day[2])){
        tem_num_day = tem_num_day + num_day_of_year(start_day[2]);
        start_day[2] = start_day[2] + 1;
    }
    int rest_day = num_day - tem_num_day;
    tem_num_day = 0;
    while (when_to_stopMONTH(rest_day,tem_num_day,start_day[0],start_day[2])){
        tem_num_day = tem_num_day + how_many_day(start_day[0],start_day[2]);
        start_day[0] = start_day[0] + 1;
    }
    start_day[1] = rest_day - tem_num_day;
	string month_name = judge_month_name(start_day[0],start_day[2]);
	cout << month_name << ' ' << start_day[1] << ' ' << start_day[2];
	return 0;
}
string judge_month_name(int month,int year){
    string s;
    if (Judge_leap_year(year)){
        if (which_month(year) == 1){
			switch (month) {
				case 1: s = "Sist";
					break;
				case 2: s = "SIST";
					break;
				case 3: s = "Spst";
					break;
				case 4: s = "Slst";
					break;
				case 5: s = "Sem";
					break;
				case 6: s = "Siais";
					break;
				case 7: s = "Ihuman";
					break;
			}
            
        }
        else{
			switch (month) {
				case 1: s = "Sist";
					break;
				case 2: s = "Spst";
					break;
				case 3: s = "Slst";
					break;
				case 4: s = "Sem";
					break;
				case 5: s = "SEM";
					break;
				case 6: s = "Siais";
					break;
				case 7: s = "Ihuman";
					break;
			}
            
        }
    }
    else{
        switch (month){
            case 1 : s = "Sist";
                     break;
            case 2 : s = "Spst";
                     break;
            case 3 : s = "Slst";
                     break;
            case 4 : s = "Sem";
                     break;
            case 5 : s = "Siais";
                     break;
            case 6 : s = "Ihuman";
                     break;
        }
        return s;
    }
}
int when_to_stopYEAR(int d1,int d2,int year){
    if (d1 - d2 > num_day_of_year(year))
        return 1;
    else 
        return 0;
}
int when_to_stopMONTH(int d1,int d2,int month,int year){
    if (d1 - d2 > how_many_day(month,year))
        return 1;
    else    
        return 0;

}
int leap_year(int x){
    if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0 && x % 4000 != 0))   // whether the year is leap year or not
        return 1;
    else
        return 0;
}
int month_to_num(string x) {
	string mon[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	int i = 0;
	while (x != mon[i]) {
		i = i + 1;
    }
	return i + 1;
}
int Judge_leap_year(int year){
    int k = (year + digit_sum(year)) % 13;
    if (k == 0)
        return 1;
    else
        return 0;
}
int digit_sum(int year){
    int rest = year;
    int last = 0;
    int sum = 0;
    while (rest != 0){
        last = rest % 10;
        sum = sum + last;
        rest = (rest - last) / 10;
    }
    return sum;
}
int num_day_of_year(int n){
    if (Judge_leap_year(n)){
        int x = 366 + how_many_day(which_month(n),n);
        return x;
    }
    else
        return 366;
}
int which_month(int year){
    int m = (year - digit_sum(year)) % 6 + 1;
    return m;
}
int how_many_day(int month,int year){
    int d = 60 + (10 * year - month) % 3;
    return d;
}