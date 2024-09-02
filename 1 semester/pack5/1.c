#include <stdio.h>
typedef struct DateTime_s {
        int year , month , day ;
        int hours , minutes , seconds ;
    } DateTime;
DateTime min(const DateTime * arr , int cnt ){
    DateTime* min_date = arr;
    DateTime* start = arr;
    for (int i = 0; i < cnt; i++)
    {
        if (min_date->year > start->year){
            min_date = start;
        }
        else if (min_date->year == start->year){
            if (min_date->month > start->month){
                min_date = start;
            }
            else if (min_date->month == start->month){
                if (min_date->day > start->day){
                    min_date = start;
                }
                else if (min_date->day == start->day){
                    if (min_date->hours > start->hours){
                        min_date = start;
                    }
                    else if (min_date->hours == start->hours){
                        if (min_date->minutes > start->minutes){
                            min_date = start;
                        }
                        else if (min_date->minutes == start->minutes){
                            if (min_date->seconds > start-> seconds){
                                min_date = start;
                            }
                        }
                    }
                }
            }
        }
    start++;
    }
    DateTime min_date_v = *min_date;
    return min_date_v;

}
    
int main(){
    int n;
    scanf("%d", &n);
    DateTime dates[50001];
    for (int i = 0; i < n; i++){
        scanf("%d %d %d %d %d %d", &dates[i].year, &dates[i].month, &dates[i].day, &dates[i].hours, &dates[i].minutes, &dates[i].seconds);
    }
    DateTime min_date_v = min(dates, n);
    printf("%d %d %d %d %d %d", min_date_v.year, min_date_v.month, min_date_v.day, min_date_v.hours, min_date_v.minutes, min_date_v.seconds);
    
}