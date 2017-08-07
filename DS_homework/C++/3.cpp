#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int compare(string);
int shanghaitech(string,string,string);
int Gregorian(string,string,string);
int month_to_numGRE(string);
int month_to_numSTU(string,int);
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
int how_many_leap_year_stu(int);
int extra_days(int);
int kind_of_yearSTU(int);
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
	int num_year = atoi(year.c_str()); // change the year from string to integer
	int num_date = atoi(date.c_str()); // change the date from string to integer
	int num_day1 = (num_year - 1) * 366 + extra_days(how_many_leap_year_stu(num_year));
	int num_month = month_to_numSTU(month, num_year);
	int num_day2 = 0;
	int form_of_day[7];
	if (kind_of_yearSTU(num_year) == 1) {
		for (int i = 0; i <= 5; i++) {
			form_of_day[i] = how_many_day(i + 1, num_year);
		}
	}
	else {
		if (kind_of_yearSTU(num_year) == 2) {
			form_of_day[0] = how_many_day(1, num_year);
			form_of_day[1] = form_of_day[0];
			for (int i = 0; i <= 6; i++) {
				form_of_day[i] = how_many_day(i, num_year);
			}
		}
		else {
			for (int i = 0; i <= 3; i++) {
				form_of_day[i] = how_many_day(i + 1, num_year);
				form_of_day[4] = form_of_day[3];
				form_of_day[5] = how_many_day(5, num_year);
				form_of_day[6] = how_many_day(6, num_year);
			}
		}
	}
	int i = 0;
	while (i < num_month - 1){
		num_day2 += form_of_day[i];
		i += 1;
	}
	int num_day = num_day1 + num_day2 + num_date - 1;
	cout << num_day << endl;

	
    return 0;
}
int how_many_leap_year_stu(int year) {
	int ShanghaiTechLeapYear[] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 108, 119, 150, 161, 172, 183, 194, 203, 214, 225, 236, 247, 258, 269, 320, 331, 342, 353, 364, 375, 386, 397, 406, 417, 428, 439, 470, 481, 492, 501, 512, 523, 534, 545, 556, 567, 578, 589, 609, 640, 651, 662, 673, 684, 695, 704, 715, 726, 737, 748, 759, 790, 810, 821, 832, 843, 854, 865, 876, 887, 898, 907, 918, 929, 960, 971, 982, 993, 1000, 1011, 1022, 1033, 1044, 1055, 1066, 1077, 1088, 1099, 1108, 1119, 1150, 1161, 1172, 1183, 1194, 1203, 1214, 1225, 1236, 1247, 1258, 1269, 1320, 1331, 1342, 1353, 1364, 1375, 1386, 1397, 1406, 1417, 1428, 1439, 1470, 1481, 1492, 1501, 1512, 1523, 1534, 1545, 1556, 1567, 1578, 1589, 1609, 1640, 1651, 1662, 1673, 1684, 1695, 1704, 1715, 1726, 1737, 1748, 1759, 1790, 1810, 1821, 1832, 1843, 1854, 1865, 1876, 1887, 1898, 1907, 1918, 1929, 1960, 1971, 1982, 1993, 2000, 2011, 2022, 2033, 2044, 2055, 2066, 2077, 2088, 2099, 2108, 2119, 2150, 2161, 2172, 2183, 2194, 2203, 2214, 2225, 2236, 2247, 2258, 2269, 2320, 2331, 2342, 2353, 2364, 2375, 2386, 2397, 2406, 2417, 2428, 2439, 2470, 2481, 2492, 2501, 2512, 2523, 2534, 2545, 2556, 2567, 2578, 2589, 2609, 2640, 2651, 2662, 2673, 2684, 2695, 2704, 2715, 2726, 2737, 2748, 2759, 2790, 2810, 2821, 2832, 2843, 2854, 2865, 2876, 2887, 2898, 2907, 2918, 2929, 2960, 2971, 2982, 2993, 3000, 3011, 3022, 3033, 3044, 3055, 3066, 3077, 3088, 3099, 3108, 3119, 3150, 3161, 3172, 3183, 3194, 3203, 3214, 3225, 3236, 3247, 3258, 3269, 3320, 3331, 3342, 3353, 3364, 3375, 3386, 3397, 3406, 3417, 3428, 3439, 3470, 3481, 3492, 3501, 3512, 3523, 3534, 3545, 3556, 3567, 3578, 3589, 3609, 3640, 3651, 3662, 3673, 3684, 3695, 3704, 3715, 3726, 3737, 3748, 3759, 3790, 3810, 3821, 3832, 3843, 3854, 3865, 3876, 3887, 3898, 3907, 3918, 3929, 3960, 3971, 3982, 3993, 4000, 4011, 4022, 4033, 4044, 4055, 4066, 4077, 4088, 4099, 4108, 4119, 4150, 4161, 4172, 4183, 4194, 4203, 4214, 4225, 4236, 4247, 4258, 4269, 4320, 4331, 4342, 4353, 4364, 4375, 4386, 4397, 4406, 4417, 4428, 4439, 4470, 4481, 4492, 4501, 4512, 4523, 4534, 4545, 4556, 4567, 4578, 4589, 4609, 4640, 4651, 4662, 4673, 4684, 4695, 4704, 4715, 4726, 4737, 4748, 4759, 4790, 4810, 4821, 4832, 4843, 4854, 4865, 4876, 4887, 4898, 4907, 4918, 4929, 4960, 4971, 4982, 4993, 5000, 5011, 5022, 5033, 5044, 5055, 5066, 5077, 5088, 5099, 5108, 5119, 5150, 5161, 5172, 5183, 5194, 5203, 5214, 5225, 5236, 5247, 5258, 5269, 5320, 5331, 5342, 5353, 5364, 5375, 5386, 5397, 5406, 5417, 5428, 5439, 5470, 5481, 5492, 5501, 5512, 5523, 5534, 5545, 5556, 5567, 5578, 5589, 5609, 5640, 5651, 5662, 5673, 5684, 5695, 5704, 5715, 5726, 5737, 5748, 5759, 5790, 5810, 5821, 5832, 5843, 5854, 5865, 5876, 5887, 5898, 5907, 5918, 5929, 5960, 5971, 5982, 5993, 6000, 6011, 6022, 6033, 6044, 6055, 6066, 6077, 6088, 6099, 6108, 6119, 6150, 6161, 6172, 6183, 6194, 6203, 6214, 6225, 6236, 6247, 6258, 6269, 6320, 6331, 6342, 6353, 6364, 6375, 6386, 6397, 6406, 6417, 6428, 6439, 6470, 6481, 6492, 6501, 6512, 6523, 6534, 6545, 6556, 6567, 6578, 6589, 6609, 6640, 6651, 6662, 6673, 6684, 6695, 6704, 6715, 6726, 6737, 6748, 6759, 6790, 6810, 6821, 6832, 6843, 6854, 6865, 6876, 6887, 6898, 6907, 6918, 6929, 6960, 6971, 6982, 6993, 7000, 7011, 7022, 7033, 7044, 7055, 7066, 7077, 7088, 7099, 7108, 7119, 7150, 7161, 7172, 7183, 7194, 7203, 7214, 7225, 7236, 7247, 7258, 7269, 7320, 7331, 7342, 7353, 7364, 7375, 7386, 7397, 7406, 7417, 7428, 7439, 7470, 7481, 7492, 7501, 7512, 7523, 7534, 7545, 7556, 7567, 7578, 7589, 7609, 7640, 7651, 7662, 7673, 7684, 7695, 7704, 7715, 7726, 7737, 7748, 7759, 7790, 7810, 7821, 7832, 7843, 7854, 7865, 7876, 7887, 7898, 7907, 7918, 7929, 7960, 7971, 7982, 7993, 8000, 8011, 8022, 8033, 8044, 8055, 8066, 8077, 8088, 8099, 8108, 8119, 8150, 8161, 8172, 8183, 8194, 8203, 8214, 8225, 8236, 8247, 8258, 8269, 8320, 8331, 8342, 8353, 8364, 8375, 8386, 8397, 8406, 8417, 8428, 8439, 8470, 8481, 8492, 8501, 8512, 8523, 8534, 8545, 8556, 8567, 8578, 8589, 8609, 8640, 8651, 8662, 8673, 8684, 8695, 8704, 8715, 8726, 8737, 8748, 8759, 8790, 8810, 8821, 8832, 8843, 8854, 8865, 8876, 8887, 8898, 8907, 8918, 8929, 8960, 8971, 8982, 8993, 9000, 9011, 9022, 9033, 9044, 9055, 9066, 9077, 9088, 9099, 9108, 9119, 9150, 9161, 9172, 9183, 9194, 9203, 9214, 9225, 9236, 9247, 9258, 9269, 9320, 9331, 9342, 9353, 9364, 9375, 9386, 9397, 9406, 9417, 9428, 9439, 9470, 9481, 9492, 9501, 9512, 9523, 9534, 9545, 9556, 9567, 9578, 9589, 9609, 9640, 9651, 9662, 9673, 9684, 9695, 9704, 9715, 9726, 9737, 9748, 9759, 9790, 9810, 9821, 9832, 9843, 9854, 9865, 9876, 9887, 9898, 9907, 9918, 9929, 9960, 9971, 9982, 9993};
	int i = 0;
	while (ShanghaiTechLeapYear[i] < year){
		i = i + 1;
	}
	return i;
}
int extra_days(int i) {
	int ShanghaiTechLeapYear[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 108, 119, 150, 161, 172, 183, 194, 203, 214, 225, 236, 247, 258, 269, 320, 331, 342, 353, 364, 375, 386, 397, 406, 417, 428, 439, 470, 481, 492, 501, 512, 523, 534, 545, 556, 567, 578, 589, 609, 640, 651, 662, 673, 684, 695, 704, 715, 726, 737, 748, 759, 790, 810, 821, 832, 843, 854, 865, 876, 887, 898, 907, 918, 929, 960, 971, 982, 993, 1000, 1011, 1022, 1033, 1044, 1055, 1066, 1077, 1088, 1099, 1108, 1119, 1150, 1161, 1172, 1183, 1194, 1203, 1214, 1225, 1236, 1247, 1258, 1269, 1320, 1331, 1342, 1353, 1364, 1375, 1386, 1397, 1406, 1417, 1428, 1439, 1470, 1481, 1492, 1501, 1512, 1523, 1534, 1545, 1556, 1567, 1578, 1589, 1609, 1640, 1651, 1662, 1673, 1684, 1695, 1704, 1715, 1726, 1737, 1748, 1759, 1790, 1810, 1821, 1832, 1843, 1854, 1865, 1876, 1887, 1898, 1907, 1918, 1929, 1960, 1971, 1982, 1993, 2000, 2011, 2022, 2033, 2044, 2055, 2066, 2077, 2088, 2099, 2108, 2119, 2150, 2161, 2172, 2183, 2194, 2203, 2214, 2225, 2236, 2247, 2258, 2269, 2320, 2331, 2342, 2353, 2364, 2375, 2386, 2397, 2406, 2417, 2428, 2439, 2470, 2481, 2492, 2501, 2512, 2523, 2534, 2545, 2556, 2567, 2578, 2589, 2609, 2640, 2651, 2662, 2673, 2684, 2695, 2704, 2715, 2726, 2737, 2748, 2759, 2790, 2810, 2821, 2832, 2843, 2854, 2865, 2876, 2887, 2898, 2907, 2918, 2929, 2960, 2971, 2982, 2993, 3000, 3011, 3022, 3033, 3044, 3055, 3066, 3077, 3088, 3099, 3108, 3119, 3150, 3161, 3172, 3183, 3194, 3203, 3214, 3225, 3236, 3247, 3258, 3269, 3320, 3331, 3342, 3353, 3364, 3375, 3386, 3397, 3406, 3417, 3428, 3439, 3470, 3481, 3492, 3501, 3512, 3523, 3534, 3545, 3556, 3567, 3578, 3589, 3609, 3640, 3651, 3662, 3673, 3684, 3695, 3704, 3715, 3726, 3737, 3748, 3759, 3790, 3810, 3821, 3832, 3843, 3854, 3865, 3876, 3887, 3898, 3907, 3918, 3929, 3960, 3971, 3982, 3993, 4000, 4011, 4022, 4033, 4044, 4055, 4066, 4077, 4088, 4099, 4108, 4119, 4150, 4161, 4172, 4183, 4194, 4203, 4214, 4225, 4236, 4247, 4258, 4269, 4320, 4331, 4342, 4353, 4364, 4375, 4386, 4397, 4406, 4417, 4428, 4439, 4470, 4481, 4492, 4501, 4512, 4523, 4534, 4545, 4556, 4567, 4578, 4589, 4609, 4640, 4651, 4662, 4673, 4684, 4695, 4704, 4715, 4726, 4737, 4748, 4759, 4790, 4810, 4821, 4832, 4843, 4854, 4865, 4876, 4887, 4898, 4907, 4918, 4929, 4960, 4971, 4982, 4993, 5000, 5011, 5022, 5033, 5044, 5055, 5066, 5077, 5088, 5099, 5108, 5119, 5150, 5161, 5172, 5183, 5194, 5203, 5214, 5225, 5236, 5247, 5258, 5269, 5320, 5331, 5342, 5353, 5364, 5375, 5386, 5397, 5406, 5417, 5428, 5439, 5470, 5481, 5492, 5501, 5512, 5523, 5534, 5545, 5556, 5567, 5578, 5589, 5609, 5640, 5651, 5662, 5673, 5684, 5695, 5704, 5715, 5726, 5737, 5748, 5759, 5790, 5810, 5821, 5832, 5843, 5854, 5865, 5876, 5887, 5898, 5907, 5918, 5929, 5960, 5971, 5982, 5993, 6000, 6011, 6022, 6033, 6044, 6055, 6066, 6077, 6088, 6099, 6108, 6119, 6150, 6161, 6172, 6183, 6194, 6203, 6214, 6225, 6236, 6247, 6258, 6269, 6320, 6331, 6342, 6353, 6364, 6375, 6386, 6397, 6406, 6417, 6428, 6439, 6470, 6481, 6492, 6501, 6512, 6523, 6534, 6545, 6556, 6567, 6578, 6589, 6609, 6640, 6651, 6662, 6673, 6684, 6695, 6704, 6715, 6726, 6737, 6748, 6759, 6790, 6810, 6821, 6832, 6843, 6854, 6865, 6876, 6887, 6898, 6907, 6918, 6929, 6960, 6971, 6982, 6993, 7000, 7011, 7022, 7033, 7044, 7055, 7066, 7077, 7088, 7099, 7108, 7119, 7150, 7161, 7172, 7183, 7194, 7203, 7214, 7225, 7236, 7247, 7258, 7269, 7320, 7331, 7342, 7353, 7364, 7375, 7386, 7397, 7406, 7417, 7428, 7439, 7470, 7481, 7492, 7501, 7512, 7523, 7534, 7545, 7556, 7567, 7578, 7589, 7609, 7640, 7651, 7662, 7673, 7684, 7695, 7704, 7715, 7726, 7737, 7748, 7759, 7790, 7810, 7821, 7832, 7843, 7854, 7865, 7876, 7887, 7898, 7907, 7918, 7929, 7960, 7971, 7982, 7993, 8000, 8011, 8022, 8033, 8044, 8055, 8066, 8077, 8088, 8099, 8108, 8119, 8150, 8161, 8172, 8183, 8194, 8203, 8214, 8225, 8236, 8247, 8258, 8269, 8320, 8331, 8342, 8353, 8364, 8375, 8386, 8397, 8406, 8417, 8428, 8439, 8470, 8481, 8492, 8501, 8512, 8523, 8534, 8545, 8556, 8567, 8578, 8589, 8609, 8640, 8651, 8662, 8673, 8684, 8695, 8704, 8715, 8726, 8737, 8748, 8759, 8790, 8810, 8821, 8832, 8843, 8854, 8865, 8876, 8887, 8898, 8907, 8918, 8929, 8960, 8971, 8982, 8993, 9000, 9011, 9022, 9033, 9044, 9055, 9066, 9077, 9088, 9099, 9108, 9119, 9150, 9161, 9172, 9183, 9194, 9203, 9214, 9225, 9236, 9247, 9258, 9269, 9320, 9331, 9342, 9353, 9364, 9375, 9386, 9397, 9406, 9417, 9428, 9439, 9470, 9481, 9492, 9501, 9512, 9523, 9534, 9545, 9556, 9567, 9578, 9589, 9609, 9640, 9651, 9662, 9673, 9684, 9695, 9704, 9715, 9726, 9737, 9748, 9759, 9790, 9810, 9821, 9832, 9843, 9854, 9865, 9876, 9887, 9898, 9907, 9918, 9929, 9960, 9971, 9982, 9993 };
	int k = 0;
	int j = 0;
	while (k <= i - 1) {
		j += how_many_day(which_month(ShanghaiTechLeapYear[k]), ShanghaiTechLeapYear[k]);
		k += 1;
	}
	return j;
}
int shanghaitech(string month, string date, string year){
    using namespace std;
    int num_year = atoi(year.c_str()); // change the year from string to integer
    int num_date = atoi(date.c_str()); // change the date from string to integer
    int num_month;
	num_month = month_to_numGRE(month);   // change the month from string to integer
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
	int form_of_day[7];
	if (kind_of_yearSTU(start_day[2]) == 1){
		for (int i = 0; i <= 5; i++) {
			form_of_day[i] = how_many_day(i + 1, start_day[2]);
		}
	}
	else {
		if (kind_of_yearSTU(start_day[2]) == 2) {
			form_of_day[0] = how_many_day(1, start_day[2]);
			form_of_day[1] = form_of_day[0];
			for (int i = 0; i <= 6; i++) {
				form_of_day[i] = how_many_day(i, start_day[2]);
			}
		}
		else {
			for (int i = 0; i <= 3; i++) {
				form_of_day[i] = how_many_day(i + 1, start_day[2]);
			}
			form_of_day[4] = form_of_day[3];
			form_of_day[5] = how_many_day(5, start_day[2]);
			form_of_day[6] = how_many_day(6, start_day[2]);
		}
	}
    while (when_to_stopMONTH(rest_day,tem_num_day,start_day[0],start_day[2])){
		tem_num_day += form_of_day[start_day[0] - 1];
		start_day[0] += 1;
    }
    start_day[1] = rest_day - tem_num_day + 1;
	string month_name = judge_month_name(start_day[0],start_day[2]);
	cout << month_name << ' ' << start_day[1] << ' ' << start_day[2];
	return 0;
}
string judge_month_name(int month, int year){
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
int month_to_numGRE(string x) {
	string mon[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	int i = 0;
	while (x != mon[i]) {
		i = i + 1;
    }
	return i + 1;
}
int month_to_numSTU(string x, int y) {
	int i = 0;
	if (Judge_leap_year(y)) {
		if (which_month(y) == 1) {
			string mon1[7] = { "Sist","SIST", "Spst", "Slst", "Sem", "Siais", "Ihuman" };
			while (mon1[i] != x)
				i = i + 1;

		}
		else {
			string mon1[7] = { "Sist", "Spst", "Slst", "Sem","SEM" ,"Siais", "Ihuman" };
			while (mon1[i] != x)
				i = i + 1;

		}
	}
	else {
		string mon1[6] = { "Sist", "Spst", "Slst", "Sem", "Siais", "Ihuman" };
		while (mon1[i] != x)
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
int kind_of_yearSTU(int n) {
	if (Judge_leap_year(n))
		return 1;
	else {
		if (which_month(n) == 1)
			return 2;
		else
			return 3;
	}
}